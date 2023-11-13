#include "iostream"
#include <vector>
#include <opencv2\opencv.hpp>
#include "ArmorParam.h"
#include "LightDescriptor.h"
#include "ArmorDescriptor.h"
using namespace std;
using namespace cv;

Mat separateColors(Mat img,char *color)
{
	vector<Mat> channels;
	split(img, channels);

	Mat grayimg;

	if (strcmp(color, "red") == 0)
	{
		grayimg = channels.at(2) - channels.at(0);
	}
	else if (strcmp(color, "blue") == 0)
	{
		grayimg = channels.at(0) - channels.at(2);
	}
	return grayimg;

}

ArmorParam _param;


float light_min_area = 100;//灯条最小面积
float light_max_angle = 45.0;//灯条最大的倾斜角
float light_min_size = 5.0;
float light_contour_min_solidity = 0.5;//灯条最小凸度
float light_max_ratio = 0.4;//灯条最大长宽比

void adjustRec(RotatedRect& lightRec)
{
	if (lightRec.angle < 45)
	{
		lightRec.angle += 45;
	}
	else if (lightRec.angle > 135)
	{
		lightRec.angle -= 45;
	}
}

void filterContours(vector<vector<Point>>& lightContours, vector<LightDescriptor>& lightInfos)
{
	for (const auto& contour : lightContours) {
		//得到面积
		float lightContourArea = contourArea(contour);
		//面积太小的不要
		if (lightContourArea < light_min_area) continue;
		//椭圆拟合区域得到外接矩形
			RotatedRect lightRec = fitEllipse(contour);
		//矫正灯条的角度，将其约束为-45~45°
		
		//宽高比、凸度筛选灯条  注：凸度=轮廓面积/外接矩形面积
		if (lightRec.size.width / lightRec.size.height > light_max_ratio ||
			lightContourArea / lightRec.size.area() < light_contour_min_solidity)
			continue;
		
		lightRec.size.width *= 1.1;
		lightRec.size.width *= 1.1;

		//直接将灯条保存
		lightInfos.push_back(LightDescriptor(lightRec));
	}
}


template<typename T>
float distance(const cv::Point_<T>& pt1, const cv::Point_<T>& pt2)
{
	return std::sqrt(std::pow((pt1.x - pt2.x), 2) + std::pow((pt1.y - pt2.y), 2));
}




class ArmorDetector {
public:
	//匹配灯条，筛选出装甲板
	vector<ArmorDescriptor> matchArmor(vector<LightDescriptor>& lightInfos) {
		vector<ArmorDescriptor> armors;
		//按灯条中心x从小到大排序
		sort(lightInfos.begin(), lightInfos.end(), [](const LightDescriptor& ld1, const LightDescriptor& ld2) {
			//Lambda函数,作为sort的cmp函数
			return ld1.center.x < ld2.center.x;
			});
		for (size_t i = 0; i < lightInfos.size(); i++) {
			//遍历所有灯条进行匹配
			for (size_t j = i + 1; (j < lightInfos.size()); j++) {
				const LightDescriptor& leftLight = lightInfos[i];
				const LightDescriptor& rightLight = lightInfos[j];

				//角差
				float angleDiff_ = abs(leftLight.angle - rightLight.angle);
				//长度差比率
				float LenDiff_ratio = abs(leftLight.length - rightLight.length) / max(leftLight.length, rightLight.length);
				//筛选
				if (angleDiff_ > _param.light_max_angle_diff_ ||
					LenDiff_ratio > _param.light_max_height_diff_ratio_) {

					continue;
				}
				//左右灯条相距距离
				float dis = distance(leftLight.center, rightLight.center);
				//左右灯条长度的平均值
				float meanLen = (leftLight.length + rightLight.length) / 2;
				//左右灯条中心点y的差值
				float yDiff = abs(leftLight.center.y - rightLight.center.y);
				//y差比率
				float yDiff_ratio = yDiff / meanLen;
				//左右灯条中心点x的差值
				float xDiff = abs(leftLight.center.x - rightLight.center.x);
				//x差比率
				float xDiff_ratio = xDiff / meanLen;
				//相距距离与灯条长度比值
				float ratio = dis / meanLen;
				//筛选
				if (yDiff_ratio > _param.light_max_y_diff_ratio_ ||
					xDiff_ratio < _param.light_min_x_diff_ratio_ ||
					ratio > _param.armor_max_aspect_ratio_ ||
					ratio < _param.armor_min_aspect_ratio_) {
					continue;
				}


				Mat _grayImg; //ROI区域的灰度图
				//按比值来确定大小装甲
				int armorType = ratio > _param.armor_big_armor_ratio ? BIG_ARMOR : SMALL_ARMOR;
				// 计算旋转得分
				float ratiOff = (armorType == BIG_ARMOR) ? max(_param.armor_big_armor_ratio - ratio, float(0)) : max(_param.armor_small_armor_ratio - ratio, float(0));
				float yOff = yDiff / meanLen;
				float rotationScore = -(ratiOff * ratiOff + yOff * yOff);
				//得到匹配的装甲板
				ArmorDescriptor armor(leftLight, rightLight, armorType, _grayImg, rotationScore, _param);

				armors.emplace_back(armor);
				break;
			}
		}
		return armors;
	}


private:
	int _enemy_color;
	int _self_color;

	cv::Rect _roi; //ROI区域

	cv::Mat _srcImg; //载入的图片保存于该成员变量中
	cv::Mat _roiImg; //从上一帧获得的ROI区域
	cv::Mat _grayImg; //ROI区域的灰度图
	vector<ArmorDescriptor> _armors;

	ArmorParam _param;

};



int main()//识别装甲板
{
	Mat img = imread("装甲板2.png");
	cout << "请输入敌方灯条颜色" << endl;
	char color[] = "blue";
	Mat gray = separateColors(img, color);
	int brightness_threshold = 120;
	Mat brightimg;
	threshold(gray, brightimg, brightness_threshold, 255, THRESH_BINARY);
	Mat element = getStructuringElement(2, Size(3, 3));//0矩形，1交叉、2椭圆

	dilate(brightimg, brightimg, element,Point(-1,-1),1,BORDER_CONSTANT,0);

	vector<vector<Point>> lightContours;
	findContours(brightimg, lightContours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

	Mat debugimg = img.clone();
	for (size_t i = 0; i < lightContours.size(); i++) {
		drawContours(debugimg, lightContours, i, Scalar(0, 0, 255), 1, 8);
		cout << "-----" << endl;
	}

	//筛选灯条
	vector<LightDescriptor> lightInfos;
	filterContours(lightContours, lightInfos);

	Mat filterimg = img.clone();

	for (const auto& lightInfo : lightInfos)
	{
		RotatedRect lightRec = lightInfo.rec();
		Point2f verticles[4];
		lightRec.points(verticles);
		for (int i = 0; i < 4; i++)
		{
			line(filterimg, verticles[i], verticles[(i+1)%4], Scalar(0, 255, 0), 2);
		}
	}

	//匹配灯条对
	ArmorDetector armorDetector;
	vector<ArmorDescriptor>_armors = armorDetector.matchArmor(lightInfos);
	if (_armors.empty()) {
		return  -1;
	}

	//绘制装甲板区域
	for (size_t i = 0; i < _armors.size(); i++) {
		vector<Point2i> points;
		for (int j = 0; j < 4; j++) {
			points.push_back(Point(static_cast<int>(_armors[i].vertex[j].x), static_cast<int>(_armors[i].vertex[j].y)));
		}

		polylines(debugimg, points, true, Scalar(0, 255, 0), 1, 8, 0);//绘制两个不填充的多边形
	}
	imshow("aromors", debugimg);







	return 0;
}