//#include <opencv2\opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
// 
//int juzhen()//����������ʽ
//{
//	system("color F0");
//	//mat���������ԣ�cols������rows������step���ֽ�Ϊ��λ�ľ�����Ч��ȣ�elemSize����ÿ��Ԫ�ص��ֽ�����total����������Ԫ�صĸ�����channels�����ͨ����
//	Mat a(3, 3, CV_8UC1);//ǰ������������������������CV�����ͨ����������Ը����������
//	Mat b(Size(4, 4), CV_8UC1);//����һ�����ж��巽��
//	Mat c0(5, 5, CV_8UC1,Scalar(4,5,6));
//	Mat c1(5, 5, CV_8UC2, Scalar(4, 5, 6));
//	Mat c2(5, 5, CV_8UC3, Scalar(4, 5, 6));
//	Mat d = (cv::Mat_<int>(1, 5) << 1, 2, 3, 4, 5);
//	Mat e = Mat::diag(d);//�ԽǾ��󣬽����о����ÿһ��ŵ��Խ�������
//	Mat f = Mat(e, Range(2, 4), Range(2, 4));//����e�������ʼ��ֹ����
//
//	cout << c0 << endl;
//	cout << c1 << endl;
//	cout << c2 << endl;
//	cout << d << endl;
//	cout << e << endl;
//	cout << f << endl;
//
//
//	//cout << c0.at<int>(0, 0) << endl;
//	cout << (int)c0.at<uchar>(0, 0) << endl;
//	Vec2b vc = c1.at<Vec2b>(0, 1);
//	cout << vc << endl;
//	cout << (int)vc[0] << endl;
//	cout << (double)(*(c2.data + c2.step[0] * 2 + c2.step[1] * 2 + 3));
//	cout << vc[1] << endl;
//	return 0;
//
//}
//
//int readimg()//��ͼ
//{
//	Mat img;
//	Mat a = (Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
//	img = imread("nilu.png");//ͼƬ�󲻼��κζ��������ɫ��ȡ
//	Mat gray = imread("nilu.png", IMREAD_GRAYSCALE);//��ɫ��ȡ
//
//
//	/*namedWindow("img", WINDOW_AUTOSIZE);
//	namedWindow("gray", WINDOW_NORMAL);
//	imshow("img", img);
//	imshow("gray", gray);
//	imwrite("C:\\Users\\�̺ƶ�\\Desktop\\pic\\newnilu.jpg", gray);*/
//	waitKey(0);
//	return 0;
//}
//
//int shipin()//��һ����Ƶ
//{
//	VideoCapture vedio;
//	//vedio.open("D:\\opencv\\learnopencv\\learnopencv\\mao.mp4");
//	vedio.open(0);//��Ĭ������ͷ
//	if (!vedio.isOpened())
//	{
//		cout << "������Ƶ�ļ��Ƿ���ȷ" << endl;
//		return -1;
//	}
//
//	cout << "��Ƶ֡�ʣ�" << vedio.get(CAP_PROP_FPS) << endl;
//	cout << "��Ƶ��ȣ�" << vedio.get(CAP_PROP_FRAME_WIDTH) << endl;
//	cout << "��Ƶ�߶ȣ�" << vedio.get(CAP_PROP_FRAME_HEIGHT) << endl;
//	
//	while (1)
//	{
//		Mat frame;
//		vedio >> frame;
//		if (frame.empty())
//			break;
//		
//		imshow("vedio",frame);
//
//		uchar c = waitKey(1000/120);
//		if (c == 'q')
//		   break;
//	}
//	return 0;
//
//}
//
//int luzhishipin()//������ͷ��¼����Ƶ
//{
//	Mat img;
//	VideoCapture vedio(0);
//	if (!vedio.isOpened())
//	{
//		cout << "������ͷʧ����" << endl;
//		return -1;
//	}
//
//	vedio >>img;//��ȡͼ��
//	if (img.empty())//����Ƿ�ɹ���ȡͼ��
//	{
//		cout << "δ��ȡ��ͼ��" << endl;
//		return -1;
//	}
//
//	bool color = (img.type() == CV_8UC3);//�ж���Ƶ�Ƿ��ɫ
//
//	VideoWriter writer;
//	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');//ѡ������ʽ
//
//	double fps = 30;//֡������
//	string name = "�Ӿ�����ж���˧.avi";
//	writer.open(name, codec, fps, img.size(), color);
//
//	if (!writer.isOpened())
//	{
//		cout << "����Ƶ�ļ�ʧ�ܣ���ȷ���Ƿ�Ϊ�Ϸ�����" << endl;
//		return -1;
//	}
//
//	while (1)
//	{
//		if (!vedio.read(img))
//		{
//			cout << "����ͷ�ѶϿ�����Ƶ��ȡ���" << endl;
//			break;
//		}
//		writer.write(img);
//		imshow("Live", img);//��ʾͼ��
//		uchar c = waitKey(1000 / 30);
//		if (c == 27)//esc�˳�¼��
//		{
//			break;
//		}
//	}
//	return 0;
//
//
//}
//
//int con()//ͼ���ʽת��
//{
//	Mat img = imread("nilu.png");
//	Mat img32;
//	//convertTo������ͼ�������ֵ��һ����������ת��Ϊ��һ���������͡�
//	//CV_32F��OpenCV�ж����һ����������ʾ32λ�������������͡�
//	img.convertTo(img32, CV_32F, 1 / 255.0, 0);//�ĸ����������ǣ����ͼ��ת������������ͣ�����ϵ����ƽ��ϵ��
//	Mat HSV, HSV32;
//	cvtColor(img, HSV, COLOR_BGR2HSV);//�ĸ�������ԭʼͼ��Ŀ��ͼ����ɫת����־�����һ����Ŀ��ͼ���ͨ��������ʡ����Ĭ�ϲ���Ϊ0����ԭʼͼ�����Զ�����ͨ����
//	cvtColor(img32, HSV32, COLOR_BGR2HSV);//cvtcolor����ͼ���ʽת��
//
//	Mat gray0, gray1;
//	cvtColor(img, gray0, COLOR_BGR2GRAY);
//	cvtColor(img32, gray1, COLOR_BGR2GRAY);//GRAY��ɫģ�ͣ�Gray=R*0.3+G*0.59+B*0.11
//	return 0;
//}
//
////CV_8U��8λ�޷���������0-255��
////CV_8S��8λ�з��������� - 128��127��
////CV_16U��16λ�޷���������0 - 65535��
////CV_16S��16λ�з��������� - 32768��32767��
////CV_32S��32λ�з�������
////CV_32F��32λ������
////CV_64F��64λ������
//
//int fenli()//ͨ��������ϲ�
//{
//	Mat img = imread("nilu.png");
//	Mat img32;
//	img.convertTo(img32, CV_32F, 1 / 255.0, 0);
//	Mat gray0, gray1;
//	cvtColor(img, gray0, COLOR_BGR2GRAY);
//	cvtColor(img32, gray1, COLOR_BGR2GRAY);
//
//	Mat imgs[3];//������ͨ��Ҫ������ȥ����
//	split(img, imgs);//��������Ҫ�����ͼ�񣻽���ͨ��������
//	Mat img0, img1, img2;
//	img0 = imgs[0];
//	img1 = imgs[1];
//	img2 = imgs[2];
//
//	Mat imgh;
//	merge(imgs, 3, imgh);//�������������ϲ���ͨ�����飻�ϲ����ͨ���������ͼ��
//
//	Mat zero = Mat::zeros(Size(img.cols, img.rows), CV_8UC1);
//	vector<Mat>imgsv;
//	imgsv.push_back(img1);
//	imgsv.push_back(img2);
//	imgsv.push_back(img0);
//
//	Mat imgsvh;
//	merge(imgsv, imgsvh);//��������ͼ����Կ���ȷʵ��bgr�������ʽ
//
//	return 0;
//}
//
//int xunzhao()//ͼ�������Сֵ��Ѱ��
//{
//	Mat img = imread("nilu.png");
//	Mat white = imread("white.png");
//	Mat black = imread("black.png");
//
//	Mat Min, Max;
//	resize(white, white, img.size());//ʹwhite��blackͼƬ��imgͼƬ�Ĵ�С������ͬ
//	resize(black, black, img.size());
//	max(img, white, Max);//max��min��ͼ��ıȽϣ�Ҫ�������ڵ���ͼ���С������ͬ
//	min(img, black, Min);
//
//	Mat gray, gray_white;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	cvtColor(white, gray_white, COLOR_BGR2GRAY);
//
//	double minval, maxval;
//	Point minloc, maxloc;
//
//	minMaxLoc(gray, &minval, &maxval, &maxloc, &minloc, gray_white);
//	//��Ѱһ��ͼ����������Сֵ�ĵ㣬������������뵥ͨ������ָ����Сֵ��ָ�룻ָ�����ֵ��ָ�룻ָ����Сλ�õ�ָ�룻���λ�õ�ָ�룻�����������ȷ��Ѱ�������Сֵ�ķ�Χ
//
//
//	return 0;
//}
//
//
//int huoqiefei()//ͼ��Ļ��ֻ��ҡ���
//{
//
//	Mat img = imread("nilu.png");
//	Mat mark = imread("white.png");
//	resize(mark, mark, img.size());
//	Mat result1,result2;
//	bitwise_and(img, mark, result1);//0~255�����ö����Ƶ���ʽ��ʾ����λ��
//	bitwise_not(img, mark, result2);//��λ��
//	//bitwise_or;bitwise_xor����ֻ�
//
//	Mat imgv;
//	cvtColor(mark, mark, COLOR_BGR2GRAY);
//	bitwise_not(img, imgv,mark);//�ĸ�������ͼ��һ��ͼ��������ͼ������ͼ��
//	Mat mark_black = imread("black.png");
//	resize(mark_black, mark_black, img.size());
//	min(img, mark_black, img);
//
//	
//
//
//
//	return 0;
//}
//
//int erzhihua()//ͼ��Ķ�ֵ��
//{
//	Mat img = imread("nilu.png");
//	if (img.empty())
//	{
//		cout << "����ͼƬ�����Ƿ���ȷ" << endl;
//		return -1;
//	}
//
//	Mat gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	Mat img1, img2, gray1, gray2,gray3,gray4,gray5;
//	//��ɫͼ���ֵ��
//	threshold(img, img1, 125, 255, THRESH_BINARY);//�̶���ֵ�Ķ�ֵ��threshold�����������ԭͼ����ֵ�����ͼ����ֵ����ֵ��������ֵ����ֵ��������־
//	threshold(img, img2, 125, 255, THRESH_BINARY_INV);
//
//	//��ɫͼ��Ķ�ֵ��
//	threshold(gray, gray1, 125, 255, THRESH_BINARY);
//	threshold(gray, gray2, 125, 255, THRESH_BINARY_INV);
//
//	//�Ҷ�ͼ��TOZERO�任
//	threshold(gray, gray3, 125, 255, THRESH_TOZERO);
//	threshold(gray, gray4, 125, 255, THRESH_BINARY_INV);
//
//	//�Ҷ�ͼ��TRUNC�任
//	threshold(gray, gray5, 125, 255, THRESH_TRUNC);
//
//	//�Ҷ�ͼ���򷨺������η���ֵ��
//	Mat imgj = imread("jianbian.png",IMREAD_GRAYSCALE);
//	Mat imgj1, imgj2;
//	threshold(imgj, imgj1, 100, 255, THRESH_BINARY|THRESH_OTSU);
//	threshold(imgj, imgj2, 125, 255, THRESH_BINARY | THRESH_TRIANGLE);
//
//	//����Ӧ��ֵ�Ķ�ֵ�����߸�����������ֵ����ͼ��ͼ��ֻ����CV_8UC1���������ͣ�����ֵ�����ͼ�񣻶�ֵ�������ֵ��ȷ����ֵ�ķ�������˹�����ֵ��������ֵ������������Ӧȷ����ֵ�����������С��һ��Ϊ����������ƽ��ֵ���Ȩƽ��ֵ�м�ȥ�ĳ����������ɸ�
//	Mat img_mean, img_gauss;
//	adaptiveThreshold(imgj, img_mean, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);
//	adaptiveThreshold(imgj, img_gauss, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 55, 0);
//
//}
//
//int lutchazhao()//LUT���ұ�ԭ����������������ͼ�������������ֻ����CV_8U�� ��lut�����������飻���ͼ��
//{
//	uchar lut1[256];
//	for (int i = 0; i < 256; i++)
//	{
//		if (i <= 100)
//			lut1[i] = 0;
//		if (i > 100 && i <= 200)
//			lut1[i] = 100;
//		if (i > 200)
//			lut1[i] = 255;
//	}
//	Mat lut_one(1, 256, CV_8UC1, lut1);
//	/*1��ʾlut_one������Ϊ1����ʾ����һ�����еľ���
//	256��ʾlut_one������Ϊ256����ʾ����256��Ԫ�ء�
//	CV_8UC1��ʾlut_one����������Ϊ8λ�޷��������ͣ�uchar����ͨ����Ϊ1�����Ҷ�ͼ��
//	lut1��һ��uchar���͵����飬��������256��Ԫ�أ���ЩԪ�ؽ���������ʼ��lut_one�����ݡ�*/
//
//	Mat img = imread("nilu.png");
//	Mat gray, out0,out1;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	LUT(gray, lut_one, out0);
//	LUT(img, lut_one, out1);
//
//}
//
//int canshu()//ͼ������ĸı�
//{
//	//ͼ���С�ı�
//	Mat gray = imread("nilu.png", IMREAD_GRAYSCALE);
//	Mat gs, gb1, gb2, gb3;
//	
//	//������ԭͼ�����ͼ��ͼ���С�����򷢴���������Ŵ������Ŵ����С���õļ��㷽ʽ��ע�����ȿ�ͼ���Сsize������size�������ķŴ���������ֵ
//	resize(gray, gs, Size(60, 105), 0, 0, INTER_AREA);//�����ֵ����Ҫ����ͼ����С����
//	resize(gs, gb1, Size(240, 420), 0, 0, INTER_NEAREST);//�����ֵ
//	resize(gs, gb2, Size(240, 420), 0, 0, INTER_LINEAR);//˫���Բ�ֵ
//	resize(gs, gb3, Size(240, 420), 0, 0, INTER_CUBIC);//˫���β�ֵ
//
//	//ͼ��ת
//	Mat imgx, imgy, imgxy;
//	flip(gray, imgx, 0);//����������ԭͼ�����ͼ�񣻷�ת����
//	flip(gray, imgy, 1);//���һ��ֵ����0����y�ᷭת������0��x�ᣬС��0�����ĶԳƷ�ת
//	flip(gray, imgxy, -1);
//
//	//ͼ��ƴ��
//	Mat img1, img2, img3;
//	hconcat(gb1, gb2, img1);//��������
//	hconcat(gb2, gb3, img2);
//
//	vconcat(img1, img2, img3);//��������
//
//	return 0;
//
//}
//
//int fangshe()//����任
//{
//	Mat img = imread("nilu.png");
//	Mat rotation0, img0;//����任��ľ����ͼ��
//
//	double angle = 30;//������ת�Ƕ�
//	
//	Size dst_size(img.rows, img.cols);//�������ͼ��ĳߴ�
//	Point2f center(img.rows / 2.0, img.cols / 2.0);//����ͼ�����ת����
//	rotation0 = getRotationMatrix2D(center, angle, 1);//�������任���󣬲�������ת���ģ���ת�Ƕȣ�����ϵ��
//
//	warpAffine(img, img0, rotation0, dst_size);//���з���任���ĸ�������ԭͼ����ת��ͼ�񣻷���任������ת��ͼ��ߴ�
//
//	//���㷨����任
//	Point2f src_points[3];
//	Point2f dst_points[3];
//	src_points[0] = Point2f(0, 0);
//	src_points[1] = Point2f(0, (float)(img.cols - 1));
//	src_points[2] = Point2f((float)(img.rows-1), (float)(img.cols - 1));
//	dst_points[0] = Point2f((float)(img.rows)*0.05, (float)(img.cols )*0.20);
//	dst_points[1] = Point2f((float)(img.rows) * 0.1, (float)(img.cols) * 0.70);
//	dst_points[2] = Point2f((float)(img.rows) * 0.6, (float)(img.cols) * 0.85);
//
//	Mat rotation1, img1;
//	rotation1 = getAffineTransform(src_points, dst_points);
//	warpAffine(img, img1, rotation1, dst_size);
//
//	return 0;
//
//}
//
//int toushibianhuan()//ͼ��͸�ӱ任
//{
//	Mat img = imread("erweima.png");
//	Point2f src_points[4];
//	Point2f dst_points[4];
//
//	src_points[0] = Point2f(470, 385);
//	src_points[1] = Point2f(688, 259);
//	src_points[2] = Point2f(695, 515);
//	src_points[3] = Point2f(914, 389);
//	dst_points[0] = Point2f(0, 0);
//	dst_points[1] = Point2f(0, 914);
//	dst_points[2] = Point2f(914, 0);
//	dst_points[3] = Point2f(914, 914);
//
//	Mat rotation, img_warp;
//	rotation = getPerspectiveTransform(src_points, dst_points);//����������ԭͼ�ĵ��������飻�任���ĵ��������飻͸�ӱ任��������ʡ�ԣ���Ĭ��Ϊ��˹��Ԫ����
//	warpPerspective(img, img_warp, rotation, Size(914,914));//����͸�ӱ任����
//
//
//
//	return 0;
//
//}
//
//int jihetuxing()//���Ƽ���ͼ��
//{
//	Mat img = Mat::zeros(Size(512, 512), CV_8UC3);
//	//Բ
//	circle(img, Point(50, 50), 25, Scalar(255, 255, 255), -1);
//	circle(img, Point(100, 50), 25, Scalar(255, 255, 255), 1);
//
//	//ֱ��,��������߿����͡�
//	line(img, Point(100, 100), Point(200, 200), Scalar(255, 255, 255), 2, LINE_4, 0);
//
//	//��Բ
//	ellipse(img, Point(300, 250), Size(100, 70), 0, 0, 200, Scalar(255, 255, 255), -1);
//
//	//����
//	rectangle(img, Point(50, 400), Point(100, 450), Scalar(125, 125, 125), -1);
//
//	//����Σ��ö�ά����������
//	//fillPoly(img,pts,npts,3,Scalar(255,255,255));���Ƶ�ͼƬ����ά�������飻����������飻����3������Σ���ɫ
//
//	//�������ɣ�����������
//	putText(img, "elysia", Point(100, 400), 2, 1, Scalar(255, 255, 255));
//
//	return 0;
//}
//
//int kaobei()//ROI�����ȡ�������ǳ����
//{
//	Mat img1 = imread("nilu.png");
//	Mat img2 = imread("black.png");
//
//	Mat ROI1, ROI2, ROI2_copy, mask, img3, img_copy;
//
//	resize(img2, mask, Size(200, 200));
//
//	//��������ڴ�ռ�������һ��ͼ�������ʹ�øı�ԭͼ�񲢲����ÿ������ͼ����Ÿı�
//	//ǳ������ԭͼ�����ͼ��ָ��ԭͼ��ľ����ַ���ı�ԭͼ���ʹ�ÿ������ͼƬ���Ÿı�
//	img3 = img1;//ǳ����
//
//	//��������ַ�ʽ
//	img1.copyTo(img_copy);
//
//	//������ͼ�н�ȡROI����ķ�ʽ
//	Rect rect(206, 206, 200, 200);//����ROI����ǰ���������ǽ�ͼ�����Ͻ����꣬Ȼ��������ǿ�Ⱥ͸߶�
//	ROI1 = img1(rect);//��ͼ
//
//	ROI2 = img1(Range(300, 500), Range(300, 500));//�ڶ��ֽ�ͼ��ʽ����ͼ���з�Χ��300~500���з�ΧҲ��
//
//	img1(Range(300, 500), Range(300, 500)). copyTo(ROI2_copy);//���
//
//	mask.copyTo(ROI1);//��ͼ���м��벿��ͼ��
//
//	return 0;
//}
//
//int gaosi()//��˹ͼ�������
//{
//	Mat img = imread("nilu.png");
//
//	vector<Mat> Guass;
//	int level = 3;
//
//	Guass.push_back(img);
//
//	for (int i = 0; i < level; i++)
//	{
//		Mat guass;
//		pyrDown(Guass[i], guass);//�²���
//		Guass.push_back(guass);
//	}
//
//	for (int i = 0; i < level; i++)
//	{
//		string name = to_string(i);
//		imshow(name, Guass[i]);
//	}
//
//	waitKey(0);
//	return 0;
//}
//
//int lapu()//������˹ͼ�������,������....
//{
//	Mat img = imread("black.png");
//
//	vector<Mat> Guass;
//	int level = 3;
//
//	Guass.push_back(img);
//
//	for (int i = 0; i < level; i++)
//	{
//		Mat guass;
//		pyrDown(Guass[i], guass);//�²���
//		Guass.push_back(guass);
//	}
//
//	vector<Mat> Lap;
//	for (int i = Guass.size()-1; i >= 0; i--)
//	{
//		Mat lap, upGuass;
//		if (i == Guass.size()-1)
//		{
//			Mat down;
//			pyrDown(Guass[i], down);
//			pyrUp(down, upGuass);
//			lap = Guass[i] - upGuass;
//			Lap.push_back(lap);
//		}
//		else
//		{
//        pyrUp(Guass[i], upGuass);
//		resize(upGuass, upGuass, Guass[i].size());
//		lap = Guass[i] - upGuass;
//		Lap.push_back(lap);
//		}
//        
//
//		
//	}
//
//	for (int i = 0; i < Guass.size(); i++)
//	{
//		string name = to_string(i);
//		Mat guass, lap;
//		guass = Guass[i];
//		lap = Lap[Guass.size() - 1 - i];
//
//	}
//
//	return 0;
//}
//
//
//
//Mat img;
//void callBack(int value,void*)
//{
//	float a = value / 100.0;
//	Mat img2;
//	img2 = img * a;
//	imshow("img", img2);
//}
//
//int huadongtiao()//����������
//{
//	img = imread("nilu.png");
//	namedWindow("img");
//	imshow("img", img);
//
//	int value = 100;
//	//6�����������������ƣ�
//	createTrackbar("�ٷֱ�", "img",&value,600,callBack,0);
//
//
//	waitKey(0);
//	return 0;
//}
//Mat imgPoint; Point prePoint;
//void mouse(int event, int x, int y, int flags,void*);
//int mouse_response()//�����Ӧ
//{
//	
//	img = imread("nilu.png");
//	img.copyTo(imgPoint);
//
//	imshow("ͼ�񴰿�_1", img);
//	imshow("ͼ�񴰿�_2", imgPoint);
//	//����¼���Ӧ����
//	//�����������������֣���Ӧ�ص����������ݸ��ص������Ŀ�ѡ����
//	setMouseCallback("ͼ�񴰿�_1", mouse, 0);
//
//
//	waitKey(0);
//	return 0;
//}
////��Ӧ�ص�����
////��������������Ӧ�¼���־��˲ʱ�������������ָ��x���ꣻy���ꣻ��Ӧ��־����ʱ�䣬����ק�������ݸ��ص������Ŀ�ѡ����
//void mouse(int event,int x,int y,int flags,void*)
//{
//	if (event == EVENT_RBUTTONDOWN)
//	{
//		cout << "������������ʼ����" << endl;
//	}
//	if (event == EVENT_LBUTTONDOWN)
//	{
//		prePoint = Point(x, y);
//		cout << "�켣��ʼ�����꣺" << prePoint << endl;
//	}
//
//	if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON))//��갴ס����ƶ���3��ͼ���������
//	{//ͨ������ֱ����ʾ����ƶ��켣
//		Point pt(x, y);
//		line(img, prePoint, pt, Scalar(255, 255, 255), 2, 5, 0);
//		prePoint = pt;
//		imshow("ͼ�񴰿�_1", img);
//		//ͨ���ı�ͼ��������ʾ����ƶ��켣
//		imgPoint.at<Vec3b >(y, x) = Vec3b(255, 255, 255);
//		imgPoint.at<Vec3b>(y, x - 1) = Vec3b(255, 255, 255);
//		imgPoint.at<Vec3b >(y, x + 1) = Vec3b(255, 255, 255);
//		imgPoint.at<Vec3b>(y + 1, x) = Vec3b(255, 255, 255);
//		imgPoint.at<Vec3b >(y + 1, x) = Vec3b(255, 255, 255);
//		imshow("ͼ�񴰿�_2", imgPoint);
//	}
//
//}
//
//int zhifangtu()//ͳ������ֱ��ͼ
//{
//	img = imread("jianbian.png");
//	if (img.empty())
//	{
//		cout << "��ȷ��ͼ���ļ��Ƿ���ȷ"<<endl;
//		return -1;
//	}
//
//	Mat gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//
//	//������ȡֱ��ͼ����ر���
//	Mat hist;//���ڴ��ֱ��ͼ������
//	const int channels[1] = { 0 };//ͨ����������ɫͼ��ֻ��һ��ͨ��������ǲ�ɫͼ���������0,1,2����ͨ���ֱ��ָR,G,Bͨ��
//	const int bins[1] = { 256 };//ֱ��ͼ��ά�ȣ���ʵ���ǻҶ�ֵ�����ֵ
//	float inRanges[2] = { 0,255 };
//	const float* ranges[1] = { inRanges };//���ػҶ�ֵ��Χ
//
//	calcHist(&gray, 1, channels, Mat(), hist, 1, bins, ranges);//����ֱ��ͼ
//	//Mat()�ʹ���û��ʹ������ͼ��
//	 
//	
//	//׼������ֱ��ͼ
//	int hist_w = 650;
//	int hist_h = 974;
//	int width = 2;
//	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
//	for (int i = 1; i < hist.rows; i++)
//	{
//		//rectangle���ڻ���ֱ��ͼ����״ͼ��������ֱ������Ͻǵ���������½ǵ�����
//		rectangle(histImage,
//			Point(width * (i - 1), hist_h - 1),
//			Point(width * i - 1, hist_h - cvRound(hist.at<float>(i - 1) / 15)),
//			Scalar(255, 255, 255), 1);
//
//	}
//
//	imshow("histImage", histImage);
//	imshow("gray", gray);
//	waitKey(0);
//	return 0;
//
//}
//
//int equally()//ֱ��ͼ���⻯����ʾ��ֱ��ͼ������������࣬˵��ͼ��ܰ�����֮����
//{
//	//���⻯��ͼ���ܹ����õع۲�ͼ�������ϸ��
//	
//	img = imread("nilu.png");
//	if (img.empty())
//	{
//		cout << "��ȷ��ͼ���ļ��Ƿ���ȷ" << endl;
//		return -1;
//	}
//
//	Mat gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//
//	Mat equalling;
//
//	//������������Ҫ���⻯��ͼ�񣻾��⻯�����ͼ��
//	equalizeHist(gray, equalling);
//	imshow("gray",gray);
//	imshow("equal",equalling);
//
//	Mat hist;//���ڴ��ֱ��ͼ������
//	const int channels[1] = { 0 };//ͨ����������ɫͼ��ֻ��һ��ͨ��������ǲ�ɫͼ���������0,1,2����ͨ���ֱ��ָR,G,Bͨ��
//	const int bins[1] = { 256 };//ֱ��ͼ��ά�ȣ���ʵ���ǻҶ�ֵ�����ֵ
//	float inRanges[2] = { 0,255 };
//	const float* ranges[1] = { inRanges };//���ػҶ�ֵ��Χ
//
//	calcHist(&equalling, 1, channels, Mat(), hist, 1, bins, ranges);//����ֱ��ͼ
//	//û�������������Ļ��޷���ʾֱ��ͼ��ͼ��
//
//
//	int hist_w = 650;
//	int hist_h = 974;
//	int width = 2;
//	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
//	for (int i = 1; i < hist.rows; i++)
//	{
//		//rectangle���ڻ���ֱ��ͼ����״ͼ��������ֱ������Ͻǵ���������½ǵ�����
//		rectangle(histImage,
//			Point(width * (i - 1), hist_h - 1),
//			Point(width * i - 1, hist_h - cvRound(hist.at<float>(i - 1) / 15)),
//			Scalar(255, 255, 255), 1);
//
//	}
//
//	imshow("histImage", histImage);
//
//	waitKey(0);
//	return 0;
//}
//
//void drawHist(Mat &hist, int type, string name)
//{
//	int hist_w = 650;
//	int hist_h = 974;
//	int width = 2;
//	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
//	for (int i = 1; i < hist.rows; i++)
//	{
//		//rectangle���ڻ���ֱ��ͼ����״ͼ��������ֱ������Ͻǵ���������½ǵ�����
//		rectangle(histImage,
//			Point(width * (i - 1), hist_h - 1),
//			Point(width * i - 1, hist_h - cvRound(hist.at<float>(i - 1) / 15)),
//			Scalar(255, 255, 255), 1);
//
//	}
//
//	imshow(name, histImage);
//
//}
//int zhifangtupipei()//ֱ��ͼƥ��,û��ȫ���
//{
//	Mat img2 = imread("nilu.png");
//	Mat img1 = imread("jianbian.png");
//
//	Mat hist1, hist2;
//
//	//��������ͼ���ֱ��ͼ
//	const int channels[1] = { 0 };//ͨ����������ɫͼ��ֻ��һ��ͨ��������ǲ�ɫͼ���������0,1,2����ͨ���ֱ��ָR,G,Bͨ��
//	const int bins[1] = { 256 };//ֱ��ͼ��ά�ȣ���ʵ���ǻҶ�ֵ�����ֵ
//	float inRanges[2] = { 0,255 };
//	const float* ranges[1] = { inRanges };//���ػҶ�ֵ��Χ
//	calcHist(&img1, 1, channels, Mat(), hist1, 1, bins, ranges);//����ֱ��ͼ
//	calcHist(&img2, 1, channels, Mat(), hist2, 1, bins, ranges);//����ֱ��ͼ
//
//	//��һ������ͼ���ֱ��ͼ
//	drawHist(hist1, NORM_L1, "hist1");
//	drawHist(hist2, NORM_L1, "hist2");
//
//	//��������ͼ��ֱ��ͼ���ۼƸ���
//	float hist1_cdf[256] = { hist1.at<float>(0) };
//	float hist2_cdf[256] = { hist2.at<float>(0) };
//
//	for (int i = 1; i < 256; i++)
//	{
//		hist1_cdf[i] = hist1_cdf[i - 1] + hist1.at<float>(i);
//		hist2_cdf[i] = hist2_cdf[i - 1] + hist2.at<float>(i);
//
//	}
//
//	//�����ۼƸ���������
//	float diff_cdf[256][256];
//	for (int i = 0; i < 256; i++)
//	{
//		for (int j = 0; j < 256; j++)
//		{
//			diff_cdf[i][j] = fabs(hist1_cdf[i] - hist2_cdf[j]);
//		}
//	}
//
//	//����LUT��ӳ���
//
//	Mat lut(1, 256, CV_8U);
//	for (int i = 0; i < 256; i++)
//	{
//		//����Դ�Ҷȼ�Ϊi��ӳ��Ҷ�
//		//��i�Ļ��۸��ʲ�ֵ��С�Ĺ涨���Ҷ�
//		float min = diff_cdf[i][0];
//		int index = 0;
//		for (int j = 1; j < 256; j++)
//		{
//			if (min > diff_cdf[i][j])
//			{
//				min = diff_cdf[i][j];
//				index = j;
//			}
//		}
//		lut.at<uchar>(i) = (uchar)index;
//	}
//
//	Mat result, hist3;
//	LUT(img1, lut, result);
//	imshow("��ƥ��", img1);
//	imshow("ƥ���ģ��ͼ��", img2);
//	imshow("ֱ��ͼƥ����", result);
//
//	calcHist(&result, 1, channels, Mat(), hist3, 1, bins, ranges);//����ֱ��ͼ
//	drawHist(hist3, NORM_L1, "hist3");
//	waitKey(0);
//
//
//	return 0;
//}
//
//int mubanpipei()//ģ��ƥ��
//{
//	Mat img = imread("nilu.png");
//	Mat temp = imread("nilu1.png");
//
//	Mat result;
//
//	/*if (img.channels() != temp.channels()) {
//		cv::cvtColor(img, img, COLOR_GRAY2BGR);
//		cv::cvtColor(temp, temp, COLOR_GRAY2BGR);
//	}
//
//
//	if (img.depth() != temp.depth()) {
//		if (img.depth() < temp.depth()) {
//			img.convertTo(img, temp.depth());
//		}
//		else {
//			temp.convertTo(temp, img.depth());
//		}
//	}*/
//
//	matchTemplate(img, temp, result, TM_CCOEFF_NORMED);
//	
//	double maxVal, minVal;
//
//	Point maxLoc, minLoc;
//
//	minMaxLoc(result, &minVal, &maxVal, &minLoc, &maxLoc);
//
//	rectangle(img, Point(maxLoc.x, maxLoc.y), Point(maxLoc.x + temp.cols, maxLoc.y + temp.rows), Scalar(0, 0, 255), 2);
//
//	imshow("ԭͼ", img);
//	imshow("ģ��",temp);
//	imshow("���",result);
//
//	waitKey(0);
//	return 0;
//}
//
//
//int juanji()//ͼ��ľ�������ã�������㣬ģ��ͼƬ�����Ӿ���
//{
//	//���������
//	uchar points[25] = { 1,2,3,4,5,
//	6,7,8,9,10,
//	11,12,13,14,15,
//	16,17,18,19,20,
//	21,22,23,24,25 };
//
//	Mat img(5, 5, CV_8UC1, points);
//
//	//���ģ��
//	Mat kernel = (Mat_<float>(3, 3) << 1, 2, 1,
//		2, 0, 2,
//		1, 2, 1);
//
//	Mat kernel_norm = kernel / 12;//�����һ������ģ��������Ԫ�ؼ�����������ģ��ȥ�����������
//
//
//	//δ��һ���������͹�һ��������
//	Mat result, result_norm;
//	//�߸�����������ͼ�����ͼ�����ͼ����������ͣ�����ˣ�CV32FC1���͵ľ���
//	//�ں˵Ļ�׼�㣨Ĭ��ֵΪPoint(-1,-1),�����ں˻�׼����λ��kernel������λ�ã�ƫֵ���������Ʒ�ѡ���־
//	filter2D(img, result, CV_32F, kernel, Point(-1, -1), 2, BORDER_CONSTANT);
//	filter2D(img, result_norm, CV_32F, kernel_norm, Point(-1, -1), 2, BORDER_CONSTANT);
//
//	cout << "result:" << endl << result << endl;
//	cout << "result_norm:" << endl << result_norm << endl;
//
//	img = imread("nilu1.png");
//	Mat img_fillter;
//	filter2D(img, img_fillter, 0, kernel_norm, Point(-1, -1), 2, BORDER_CONSTANT);
//	imshow("img", img);
//	imshow("img_fillter", img_fillter);
//
//	waitKey(0);
//	return 0;
//
//}
//
//
//void Pepper(Mat image, int n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		int j, k;
//		j = rand() % image.rows;
//		k = rand() % image.cols;
//		int write_black = rand() % 2;
//
//		if (write_black == 0)
//		{
//			if (image.type() == CV_8UC1)//���ͼ���ǵ�ͨ��
//			{
//				image.at<uchar>(j, k) = 255;
//			}
//			else if (image.type() == CV_8UC3)//��ͨ��
//			{
//				image.at<Vec3b>(j, k)[0] = 255;
//				image.at<Vec3b>(j, k)[1] = 255;
//				image.at<Vec3b>(j, k)[2] = 255;
//			}
//		}
//		else
//		{
//			if (image.type() == CV_8UC1)
//			{
//				image.at<uchar>(j, k) = 0;
//			}
//			else if (image.type() == CV_8UC3)
//			{
//				image.at<Vec3b>(j, k)[0] = 0;
//				image.at<Vec3b>(j, k)[1] = 0;
//				image.at<Vec3b>(j, k)[2] = 0;
//			}
//		}
//	}
//}
//
//
//
//int zaosheng()//ͼƬ����������:���������͸�˹�����Ĳ���
//{
//	img = imread("nilu1.png");
//	Mat img0 = imread("nilu1.png", IMREAD_GRAYSCALE);
//	
//	Mat img_g, img0_g;//��������������˹�뻯֮���ͼ��
//	img.copyTo(img_g);
//	img0.copyTo(img0_g);
//	Mat img_s, img0_s;//���ս����뻯�Ľ��
//	img.copyTo(img_s);
//	img0.copyTo(img0_s);
//
//	imshow("niluԭͼ", img);
//	imshow("��ɫniluԭͼ", img0);
//
//	Pepper(img_s, 10000);
//	Pepper(img0_s, 10000);
//
//
//	imshow("nilu�����뻯", img_s);
//	imshow("��ɫnilu�����뻯�뻯", img0_s);
//
//	imwrite("D:\\opencv\\learnopencv\\learnopencv\\nilu_s.png", img_s);
//	imwrite("D:\\opencv\\learnopencv\\learnopencv\\nilu0_s.png", img0_s);
//
//	waitKey(0);
//
//
//	Mat img_nos =Mat:: zeros(img.rows, img.cols, img.type());
//	Mat img0_nos= Mat::zeros(img0.rows, img0.cols, img0.type());
//
//	RNG rng;//RNG�����
//	rng.fill(img_nos, RNG::NORMAL, 10, 20);//��˹���������ɺ���
//	rng.fill(img0_nos, RNG::NORMAL, 15, 30);
//
//	imshow("��ͨ����˹����", img_nos);
//	imshow("��ͨ����˹����", img0_nos);
//
//	img_g = img_g + img_nos;
//	img0_g = img0_g + img0_nos;
//
//	imshow("nilu�������", img_g);
//	imshow("��ɫnilu�������", img0_g);
//
//	imwrite("D:\\opencv\\learnopencv\\learnopencv\\nilu_g.png",img_g);
//	imwrite("D:\\opencv\\learnopencv\\learnopencv\\nilu0_g.png", img0_g);
//
//	waitKey(0);
//	return 0;
//}
//
//
//int xianxinglvbo()//�����˲�
//{
//	//Mat img_g = imread("nilu_g.png");//��ͨ������ͼ
//	Mat img0_g = imread("nilu0_g.png");//��ͨ������ͼ
//	Mat img_s = imread("nilu0_s.png");
//	Mat yuan = imread("nilu1.png");//��������ͼ
// 
//
//	Mat r_3, r_9;//��Ų����������˲���������ִ����˲��ߴ�
//	Mat r_3g, r_9g;//��˹�����˲�
//	Mat r_3s, r_9s;//���������˲�
//
//	//�˲�����
//
//
//	//��ֵ�˲�
//	blur(yuan, r_3, Size(3, 3));
//	blur(yuan, r_9, Size(9, 9));
//	blur(img_s, r_3s, Size(3, 3));
//	blur(img_s, r_9s, Size(9, 9));
//	blur(img0_g, r_3g, Size(3, 3));
//	blur(img0_g, r_9g, Size(9, 9));
//
//
//	Mat r_n, r;//���ܷ����˲�
//	boxFilter(img0_g, r_n, -1, Size(3, 3), Point(-1, -1), true);//���й�һ��
//	boxFilter(img0_g, r, -1, Size(3, 3), Point(-1, -1), false);//�����й�һ��
//	//�����й�һ���Ĳ����������ĵط���ȫ�ף�ֻ��ԭͼ�ر𰵵ĵط���ʾ��·
//
//
//	//��˹�˲����Ը�˹�����Ĵ���Ϻ�
//	Mat r_5G, r_9G;
//	Mat r_5gG, r_9gG;//��ź��и�˹�˲����˲��������������ֱ�ʾ�˲����ߴ�
//	Mat r_5sG, r_9sG;//��ź��н���������...
//	
//	//��˹�˲�����
//
//	GaussianBlur(yuan, r_5G, Size(5, 5), 10, 20);
//	GaussianBlur(yuan, r_9G, Size(9, 9), 10, 20);
//	GaussianBlur(img0_g, r_5gG, Size(5, 5), 10, 20);
//	GaussianBlur(img0_g, r_9gG, Size(9, 9), 10, 20);
//	GaussianBlur(img_s, r_5sG, Size(5, 5), 10, 20);
//	GaussianBlur(img_s, r_9sG, Size(9, 9), 10, 20);
//
//	//�������֣����������˲���ʽ�����Խ��������Ĵ����Ǻܺ�
//
//	return 0;
//}
//
//
//int zhongzhilvbo()//��ֵ�˲�
//{
//	//ԭ���˲�������������Ѱ����λ�����滻����
//	Mat zhongzhi = imread("��ֵ�˲�ԭ��.png");
//
//	Mat img0_g = imread("nilu0_g.png");//��ͨ������ͼ����˹��
//	Mat img0_s = imread("nilu0_s.png");//����
//	Mat yuan = imread("nilu1.png");//��������ͼ
//
//	Mat g3, g9, s3, s9, y3, y9;
//	medianBlur(img0_g, g3, 3);
//	medianBlur(img0_s, s3, 3);
//	medianBlur(yuan, y3, 3);
////����������ԭͼ�����ͼ���˲����ߴ磨�����Ǵ���1��������
//	medianBlur(img0_g, g9, 9);
//	medianBlur(img0_s, s9, 9);
//	medianBlur(yuan, y9, 9);
//
//	//��ֵ�˲�ֻ�Խ��������Ĵ���Ч���ȽϺ�
//	
//	return 0;
//}
//
//
//int lvbofenli()//�˲��Ŀɷ�����
//{
//	Mat kefenli = imread("�ɷ����˲��ĺ���.png");
//	
//	float points[25] = 
//	{ 1,2,3,4,5,
//	6,7,8,9,10,
//	11,12,13,14,15,
//	16,17,18,19,20,
//	21,22,23,24,25 };
//
//	Mat data(5, 5, CV_32FC1, points);
//
//	//X��Y����������˲����Ĺ���
//	Mat a = (Mat_<float>(3, 1) << -1, 3, -1);//����һ��һ�����еľ���
//	//reshape()�Ǿ���仯������A = reshape��A��m��n�������� A = reshape��A��[m,n]��; 
//	//���ǽ�A ���������г�m��n�С�
//	Mat b=a.reshape(1, 1);//��������һ��һ�еľ���
//	Mat ab = a * b;
//
//	//��֤��˹�˲��Ŀɷ�����
//	Mat gaussX = getGaussianKernel(3, 1);//������������ɸ�˹�˲����ĺ���
//	Mat gaussdata, gaussdataXY;
//	GaussianBlur(data, gaussdata, Size(3, 3), 1, 1, BORDER_CONSTANT);
//	sepFilter2D(data, gaussdataXY, -1, gaussX, gaussX, Point(-1, -1), 0, BORDER_CONSTANT);
//
//
//	//�����˲��Ŀɷ�����
//	Mat dataXY, dataY, dataYX, dataXY_sep;
//
//	filter2D(data, dataY, -1, a, Point(-1, -1), 0, BORDER_CONSTANT);
//	filter2D(dataY, dataYX, -1, b, Point(-1, -1), 0, BORDER_CONSTANT);
//	filter2D(data, dataXY, -1, ab, Point(-1, -1), 0, BORDER_CONSTANT);
//
//	sepFilter2D(data, dataXY_sep, -1, b, b, Point(1, 1), 0, BORDER_CONSTANT);
//    //�˸�������ԭͼ�����ͼ�����ͼ����������ͣ���ȣ���X������˲�����Y������˲���
//	//�ں˵Ļ�׼�㣬Ĭ��Ϊ��-1��-1�������ں˻�׼��λ���˲���������λ�ã�ƫֵ���������Ʒ���־
//	
//	//�����˹�˲��ļ�����
//	cout << gaussdata << endl;
//
//	cout << gaussdataXY << endl;
//
//	//��������˲��������˲��ļ�����
//
//	cout << dataY << endl;
//	cout << dataYX << endl;
//	cout << dataXY << endl;
//	cout << dataXY_sep << endl;
//	//�����������ǿ��Կ�����ʹ�÷����˲������ͷֲ���xy�����˲��Ľ����ͬ
//	//ͼ��Ҳ�ɽ��зֲ��˲���
//	
//
//	
//	return 0;
//}
//
//int bianyuan1()//��Ե���ԭ��1
//{
//	Mat sobel = imread("D:\\opencv\\learnopencv\\learnopencv\\sobel���ӱ�Ե��⺯��.png");
//	Mat scharr = imread("D:\\opencv\\learnopencv\\learnopencv\\scharr���Ӻ���.jpg");
//	Mat suanzishengcheng = imread("D:\\opencv\\learnopencv\\learnopencv\\�������ɺ���.png");
//
//
//	Mat img = imread("nilu1.png", IMREAD_GRAYSCALE);
//
//	Mat rx, ry, rxy;
//	//sobel���Ӽ����Ե
//	//X����һ�ױ�Ե
//	Sobel(img, rx, CV_16S, 1, 0, 3);
//	convertScaleAbs(rx, rx);
//
//	//Y����һ�ױ�Ե
//	Sobel(img, ry, CV_16S, 0, 1, 5);//���һ��ksize��ֵΪ1��3����ͬ�ִ�����
//	convertScaleAbs(ry, ry);
//
//	//����ͼ���һ�ױ�Ե
//	rxy = rx + ry;
//
//
//	Mat rx1, ry1, rxy1;
//	//scharr�����Ե
//	//X����һ�ױ�Ե
//	Scharr(img, rx1, CV_16S, 1, 0);
//	convertScaleAbs(rx1, rx1);
//
//	//Y����һ�ױ�Ե
//	Scharr(img, ry1, CV_16S, 0, 1);
//	convertScaleAbs(ry1, ry1);
//
//	//����ͼ���һ�ױ�Ե
//	rxy1 = rx1 + ry1;
//
//	cout << "���������ɱ�Ե�����" << endl;
//
//
//	Mat so_x, so_y,//��ŷ�������
//		sc_x, sc_y,
//		sob, sch;//�����������
//
//	getDerivKernels(so_x, so_y, 1, 0, 3);
//	so_x = so_x.reshape(CV_8U, 1);
//	sob = so_y*so_x;
//
//	getDerivKernels(sc_x, sc_y, 1, 0, FILTER_SCHARR);
//	sc_x = sc_x.reshape(CV_8U, 1);
//	sch = sc_y * sc_x;  //�����˲���
//
//
//	return 0;
//}
//
//
//int bianyuan2()//��Ե���2
//{
//	Mat img = imread("nilu0_g.png", IMREAD_GRAYSCALE);
//
//	Mat r, r_g, r_G;
//	//δ�˲���ȡ��Ե
//	Laplacian(img, r, CV_16S, 3, 1, 0);
//	convertScaleAbs(r, r);
//
//	//�˲�����ȡ������˹��Ե
//	GaussianBlur(img, r_g, Size(3, 3), 5, 0);//��˹�˲�
//	Laplacian(r_g, r_G, CV_16S, 3, 1, 0);
//	convertScaleAbs(r_G, r_G);
//
//
//	cout << "����������Canny��Ե���" << endl;
//	Mat r_high, r_low, rG;
//
//	//����ֵ���ͼ���Ե
//	Canny(img, r_high, 100, 200, 3);
//
//	//С��ֵ���ͼ���Ե
//	Canny(img, r_low, 20, 40, 3);
//
//	//��˹ģ������ͼ���Ե
//	GaussianBlur(img, rG, Size(3, 3), 5);//��˹�˲�
//	Canny(rG, rG, 100, 200, 3);
//
//
//	return 0;
//}
//
//int liantongyu()//��ͨ�����
//{
//	//connectedComponents()��ֻ�ָ���ͨ��ĺ���
//	// �ĸ�������ԭͼ�����ͼ�����ʱ���������࣬4��8��Ĭ��Ϊ8�����ͼ�����������
//	//connectedComponentsWithStats()�ָͳ����ͨ����Ϣ�ĺ���
//	//����������ԭͼ�����ͼ����ͬ��ͨ�������ͼ��ÿ����ͨ����������ꣻ�������ࣻ
//
//
//	Mat img = imread("nilu1.png");
//	
//	Mat nilu, niluBW;
//	cvtColor(img, nilu, COLOR_BGR2GRAY);
//
//	//��ֵ������ͼ��
//	threshold(nilu, niluBW, 125, 255, THRESH_BINARY);//����125��ֵȫ��Ϊ255��С��125ȫ���0
//
//	//���������ɫ���������ֲ�ͬ��ͨ��
//	RNG rng(10086);
//	Mat out;
//	int num = connectedComponents(niluBW, out, 8, CV_16U);
//	vector<Vec3b>colors;
//
//	for (int i = 0; i < num; i++)
//	{
//		Vec3b vec3 = Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
//		colors.push_back(vec3);
//	}
//
//	//�Բ�ͬ��ɫ��Ǵ���ͬ��������
//	Mat r = Mat::zeros(nilu.size(), img.type());
//	int w = r.cols;
//	int h = r.rows;
//	for (int row = 0; row < h; row++)
//	{
//		for (int col = 0; col < w; col++)
//		{
//			int label = out.at<uint16_t>(row, col);
//			if (label == 0)
//			{
//				continue;
//			}
//			r.at<Vec3b>(row, col) = colors[label];
//		}
//	}
//
//	cout << "������ͳ����ͨ����Ϣ" << endl;
//
//	Mat stats, centroids,out1;
//	int number = connectedComponentsWithStats(niluBW, out1, stats, centroids, 8, CV_16U);
//	vector<Vec3b>colors_new;
//	for (int i = 0; i < number; i++)
//	{
//		Vec3b vec3 = Vec3b(rng.uniform(0, 256), rng.uniform(0, 256), rng.uniform(0, 256));
//		colors_new.push_back(vec3);
//	}
//
//	for (int i = 1; i < number; i++)
//	{
//	//����λ��
//	int center_x = centroids.at<double>(i, 0);
//	int center_y = centroids.at<double>(i, 1);
//
//	//���α߿�
//	int x = stats.at<int>(i, CC_STAT_LEFT);
//	int y = stats.at<int>(i, CC_STAT_TOP);
//	int w = stats.at<int>(i, CC_STAT_WIDTH); 
//	int h = stats.at<int>(i, CC_STAT_HEIGHT);
//	int area = stats.at<int>(i, CC_STAT_AREA);
//
//	//����λ�û���
//	circle(img, Point(center_x, center_y), 2, Scalar(0, 255, 0), 2, 8, 0);
//	//��Ӿ���
//	Rect rect(x, y, w, h);
//	rectangle(img, rect, colors_new[i], 1, 8, 0);
//	putText(img, format("%d", i), Point(center_x, center_y),
//		FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 0, 5), 1);
//
//	cout << "number:" << i << "area:" << area << endl;
//
//	}
//
//	return 0;
//}
//
//int juli()//ͼ��ľ���任
//{
//	//distanceTransform()����任����
//	//���������ԭͼ����ͨ�����������ѡ�������������֮����뷽���ı�־���������3��5������ŷʽ����ֻ����5�����Խ������ж���5����������
//	 
//	Mat distance = imread("D:\\opencv\\learnopencv\\learnopencv\\�������.png");
//	return 0;
//}
//
//int fushi()//ͼ��ʴ���ð��ĵط�����
//{
//	//�Ƚ��ܽṹԪ�����ɺ���
//	//getStructuringElement()�����������ṹԪ�����ࣨ0Ϊ���Σ�1Ϊʮ�֣�2Ϊ�ڽ���Բ�����ߴ��С�����ĵ�λ��
//
//	Mat src=(Mat_<uchar>(6,6)
//		<<0,0,0,0,255,0,
//		0,255,255,255,255,255,
//		0,255,255,255,255,0,
//		0,255,255,255,255,0,
//		0,255,255,255,255,0,
//		0, 0, 0, 0, 0, 0);
//
//	Mat struct1,struct2;
//	struct1 = getStructuringElement(0, Size(3, 3));
//	struct2 = getStructuringElement(1, Size(3, 3));
//
//	Mat erodeSrc1,erodeSrc2;//��Ÿ�ʴ���ͼ��
//	erode(src, erodeSrc1, struct1);
//	erode(src, erodeSrc2, struct2);
//	Mat white = imread("white.png");
//	Mat erode_white1,erode_white2;
//	erode(white, erode_white1, struct1);
//	erode(white, erode_white2, struct2);
//
//
//	return 0;
//}
//
//int pengzhang()//ͼ�����ͣ������ĵط�����,��������Ҳ��erode()��ͬ
//{
//	Mat src = (Mat_<uchar>(6, 6)
//		<< 0, 0, 0, 0, 255, 0,
//		0, 255, 255, 255, 255, 255,
//		0, 255, 255, 255, 255, 0,
//		0, 255, 255, 255, 255, 0,
//		0, 255, 255, 255, 255, 0,
//		0, 0, 0, 0, 0, 0);
//
//	Mat struct1, struct2;
//	struct1 = getStructuringElement(0, Size(3, 3));
//	struct2 = getStructuringElement(1, Size(3, 3));
//
//	Mat dilateSrc1, dilateSrc2;//������ͺ��ͼ��
//	dilate(src, dilateSrc1, struct1);
//	dilate(src, dilateSrc2, struct2);
//	Mat white = imread("white.png");
//	Mat dilate_white1, dilate_white2;
//	dilate(white, dilate_white1, struct1);
//	dilate(white, dilate_white2, struct2);
//
//
//	return 0;
//}
//
//
//int xingtaixue()//��̬ѧ��Ӧ��
//{
//	//morphologyEx()
//	//������ԭͼ�����ͼ����̬ѧ�����ı�־���ṹԪ�أ����ĵ㣻����������
//	Mat xingtai = imread("D:\\opencv\\learnopencv\\learnopencv\\��̬ѧ��Ӧ����.png");
//	
//
//	//ÿ�ִ���������ͬ���õ���ʱ���ٲ�
//
//	return 0;
//}
//
////#include <opencv2\ximgproc.hpp>ͼ��ϸ������Ҫ��ͷ�ļ�
////ʵ�ڲ�֪���Լ���װ������������
//
//
//int xihua()//ͼ��ϸ��,����һЩ�ֵġ�����Ƚϴ��ͼ���ϸС
//{
//	Mat xihua = imread("D:\\opencv\\learnopencv\\learnopencv\\ͼ��ϸ��ԭ��.jpg");
//	Mat hanshu = imread("D:\\opencv\\learnopencv\\learnopencv\\ͼ��ϸ������.jpg");
//	return 0;
//}
//
//int lunkuojiance()//������⣬�����ĸ�����
//{
//	system("color F0");//�������������ɫ
//
//	Mat img = imread("����.jpg");
//	
//	imshow("ԭͼ", img);
//	Mat erzhi,gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	threshold(gray, erzhi, 150, 255, THRESH_BINARY | THRESH_OTSU);
//
//	//�������������
//	vector<vector<Point>> contours;//����
//	vector<Vec4i> hierarchy;//��������ṹ����
//
//	findContours(gray, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
//	//���ĸ�����modeָ���������ļ���ģʽ�����������methodָ���������Ľ��Ʒ�����
//	
//	//mode��������ȡ�����ĸ�ֵ��
//	//  RETR_EXTERNAL��ֻ����������������
//	//	RETR_LIST���������е������������䱣�浽�б��С�
//	//	RETR_CCOMP���������е���������������֯Ϊ������νṹ���ڵ�һ���ṹ�У�ÿ�������������������ĸ��������ڵڶ����ṹ�У��������е�������
//	//	RETR_TREE���������е���������������֯Ϊ�����Ĳ�νṹ����
//
//	//method��������ȡ��������ֵ��
//	//CHAIN_APPROX_NONE��������ѹ�����洢���е������㡣
//	//CHAIN_APPROX_SIMPLE��ѹ��ˮƽ����ֱ�ͶԽ��߷����ϵ�����㣬�����������Ķ˵㡣
//	//CHAIN_APPROX_TC89_L1��CHAIN_APPROX_TC89_KCOS��Ӧ��Teh - Chin���ƽ��㷨�е�һ�֡�
//
//	//��������
//
//	for (int i = 0; i < hierarchy.size(); i++)
//	{
//		cout << hierarchy[i] << endl;
//	}
//
//	for (int i = 0; i < contours.size(); i++)
//	{
//		drawContours(img, contours, i, Scalar(0, 0, 255), 2, 8);
//		imshow("���������", img);
//		waitKey(0);
//	}
//
//	return 0;
//
//}
//
//int jixuanlunkuo()//����������һЩ����
//{
//	system("color F0"); // �������������ɫ
//		//���ĸ����ʾ����������
//		vector<Point>contour;
//	contour.push_back(Point2f(0, 0));
//	contour.push_back(Point2f(10, 0));
//	contour.push_back(Point2f(10, 10));
//	contour.push_back(Point2f(5, 5));
//	double area = contourArea(contour);
//	cout << "area=" << area << endl;
//
//	double length0 = arcLength(contour, true);
//	double length1 = arcLength(contour, false);
//	cout<<"length0=" << length0 << endl;
//	cout << "lengthl=" << length1 << endl;
//
//	//��ͼ����������ͼ���
//
//	Mat img = imread("����.jpg");
//
//	imshow("ԭͼ", img);
//	Mat erzhi, gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	threshold(gray, erzhi, 150, 255, THRESH_BINARY | THRESH_OTSU);
//
//	imshow("erzhi", erzhi);
//	imshow("gray", gray);
//
//	vector<vector<Point>> contours;//����
//	vector<Vec4i> hierarchy;//��������ṹ����
//
//	findContours(gray, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
//	for (int i = 0; i < contours.size(); i++)
//	{
//        double area1 = contourArea(contours[i]);
//		cout << area1 << endl;
//	}
//
//	cout << "------------------" << endl;
//	for (int i = 0; i < contours.size(); i++)
//	{
//		double length2 = arcLength(contours[i], true);
//		cout << length2 << endl;
//	}
//	
//	waitKey(0);
//	return 0;
//}
//
//
//void drawapp(Mat result,Mat img2)
//{
//	for (int i = 0; i < result.rows; i++)
//	{
//		if (i == result.rows - 1)
//		{
//        Vec2i point1 = result.at<Vec2i>(i);
//		Vec2i point2 = result.at<Vec2i>(0);
//		line(img2, point1, point2, Scalar(0, 0, 255), 2, 8, 0);
//		break;
//		}
//
//		Vec2i point1 = result.at<Vec2i>(i);
//	    Vec2i point2 = result.at<Vec2i>(i+1);
//		line(img2, point1, point2, Scalar(0, 0, 255), 2, 8, 0);
//	}
//}
//
//
//
//
//int duobianxing()//������Ӷ���� 
//{
//	Mat img = imread("��������.jpg");
//
//	Mat img1, img2;
//	img.copyTo(img1);
//	img.copyTo(img2);
//
//	imshow("img", img);
//
//	//ȥ�������Լ���ֵ��
//	Mat canny;
//	Canny(img, canny, 100, 300, 3, false);
//	imshow("canny", canny);
//
//	//�������㣬�ϸС��϶
//	Mat kernel = getStructuringElement(0, Size(3, 3));
//	dilate(canny, canny, kernel);
//
//	//������������
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	findContours(canny, contours, hierarchy, 0, 2, Point());
//
//	//Ѱ����������Ӿ���
//	for (int n = 0; n < contours.size(); n++)
//	{
//		//�����Ӿ���
//		Rect rect = boundingRect(contours[n]);
//		rectangle(img1, rect, Scalar(0, 0, 255), 2, 8, 0);//���ƾ��κ���
//
//		//��С��Ӿ���
//		RotatedRect rrect = minAreaRect(contours[n]);
//		Point2f points[4];
//		rrect.points(points);
//		Point2f cpt = rrect.center;
//		//��ת���ο���ת��Ϊ��ת��Բ���������������ֱ��rectangleȥ���
//		ellipse(img2, rrect, Scalar(0,255,0), 2);
//
//		//�����û��ߵķ�ʽȥ��ʾ��ת��ľ���
//		//�����ת����������λ��
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 3)
//			{
//				line(img2, points[i], points[0], Scalar(0, 255, 0), 2, 8, 0);
//				break;
//			}
//			line(img2, points[i], points[i + 1], Scalar(0, 255, 0), 2, 8, 0);
//		}
//        //���ƾ��ε�����
//		circle(img2, cpt, 4, Scalar(255, 0, 0), -1, 8, 0);
//	}
//	
//	//���������Ӿ��εĽ��
//	imshow("max", img1);
//	imshow("min", img2);
//
//
//	cout << "���������ж���ε����" << endl;
//	waitKey(0);
//
//	Mat img3 = imread("�����.jpg");
//
//	//ȥ�������Լ���ֵ��
//	Mat canny2;
//	Canny(img3, canny2, 100, 300, 3, false);
//	imshow("canny2", canny2);
//
//	//�������㣬�ϸС��϶
//	Mat kernel2 = getStructuringElement(0, Size(3, 3));
//	dilate(canny2, canny2, kernel2);
//
//	//������������
//	vector<vector<Point>> contours2;
//	vector<Vec4i> hierarchy2;
//	findContours(canny2, contours2, hierarchy2, 0, 2, Point());
//
//	//���ƶ����
//	for (int i = 0 ; i < contours2.size(); i++)
//	{
//		//����С��Ӿ�����ȡ��������
//		RotatedRect rrect = minAreaRect(contours2[i]);
//		Point2f center = rrect.center;
//		circle(img3, center, 2, Scalar(0, 255, 0), 2, 8, 0);
//
//		Mat result;
//		approxPolyDP(contours2[i], result, 4, true);
//		drawapp(result, img3);
//		cout << "corners:" << result.rows << endl;
//
//		//�ж���״�ͻ�������
//		if (result.rows == 3)
//		{
//			putText(img3, "triangle", center, 0, 1, Scalar(0, 255, 0), 1, 8);
//		}
//
//		if (result.rows == 4)
//		{
//			putText(img3, "rectangle", center, 0, 1, Scalar(0, 255, 0), 1, 8);
//		}
//
//		if (result.rows == 8)
//		{
//			putText(img3, "poly_8", center, 0, 1, Scalar(0, 255, 0), 1, 8);
//		}
//		if (result.rows >12)
//		{
//			putText(img3, "circle", center, 0, 1, Scalar(0, 255, 0), 1, 8);
//		}
//	}
//
//	imshow("result", img3);
//
//
//
//	waitKey(0);
//	return 0;
//}
//
//int tubao()//͹�����
//{
//	Mat img = imread("hand.jpg");
//
//
//	Mat gray, binary;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	threshold(gray, binary, 170, 255, THRESH_BINARY_INV);
//
//	Mat k = getStructuringElement(MORPH_RECT, Size(3, 3), Point(-1, -1));
//	morphologyEx(binary, binary, MORPH_OPEN, k);
//	
//
//	//��������
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	findContours(binary, contours, hierarchy, 0, 2, Point());
//	for (int n = 0; n < contours.size(); n++)
//	{
//		//����͹��
//		vector<Point> hull;
//		convexHull(contours[n], hull);//͹����⺯��
//		//�����������2D�㼯�����͹���Ķ�����˳�淽���־����������
//
//		//����͹��
//		for (int i = 0; i < hull.size(); i++)
//		{
//			//����͹������
//			circle(img, hull[i], 4, Scalar(255, 0, 0), 2, 8, 0);
//			//����͹��
//			if (i == hull.size() - 1)
//			{
//				line(img, hull[i], hull[0], Scalar(0, 0, 255), 2, 8, 0);
//				break;
//			}
//			line(img, hull[i], hull[i + 1], Scalar(0, 0, 255), 2, 8, 0);
//		}
//	}
//
//
//	
//	waitKey(0);
//
//
//	return 0;
//}
//
//int zhixian()//ֱ�߼�⣬���ֻ���任���ֱ��
//{
//	return 0;
//}
//
//
//
//
//
//
