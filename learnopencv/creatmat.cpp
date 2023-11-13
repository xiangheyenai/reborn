//#include <opencv2\opencv.hpp>
//#include <iostream>
//
//using namespace std;
//using namespace cv;
// 
//int juzhen()//矩阵的输出形式
//{
//	system("color F0");
//	//mat矩阵常用属性，cols列数，rows行数，step以字节为单位的矩阵有效宽度，elemSize（）每个元素的字节数，total（）矩阵中元素的个数，channels矩阵的通道数
//	Mat a(3, 3, CV_8UC1);//前两个数据是行列数，第三个CV是输出通道，后面可以跟输出的内容
//	Mat b(Size(4, 4), CV_8UC1);//另外一种行列定义方法
//	Mat c0(5, 5, CV_8UC1,Scalar(4,5,6));
//	Mat c1(5, 5, CV_8UC2, Scalar(4, 5, 6));
//	Mat c2(5, 5, CV_8UC3, Scalar(4, 5, 6));
//	Mat d = (cv::Mat_<int>(1, 5) << 1, 2, 3, 4, 5);
//	Mat e = Mat::diag(d);//对角矩阵，将单行矩阵的每一项放到对角上排列
//	Mat f = Mat(e, Range(2, 4), Range(2, 4));//接收e矩阵的起始终止行列
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
//int readimg()//读图
//{
//	Mat img;
//	Mat a = (Mat_<int>(3, 3) << 1, 2, 3, 4, 5, 6, 7, 8, 9);
//	img = imread("nilu.png");//图片后不加任何东西代表彩色读取
//	Mat gray = imread("nilu.png", IMREAD_GRAYSCALE);//灰色读取
//
//
//	/*namedWindow("img", WINDOW_AUTOSIZE);
//	namedWindow("gray", WINDOW_NORMAL);
//	imshow("img", img);
//	imshow("gray", gray);
//	imwrite("C:\\Users\\程浩栋\\Desktop\\pic\\newnilu.jpg", gray);*/
//	waitKey(0);
//	return 0;
//}
//
//int shipin()//打开一个视频
//{
//	VideoCapture vedio;
//	//vedio.open("D:\\opencv\\learnopencv\\learnopencv\\mao.mp4");
//	vedio.open(0);//打开默认摄像头
//	if (!vedio.isOpened())
//	{
//		cout << "请检查视频文件是否正确" << endl;
//		return -1;
//	}
//
//	cout << "视频帧率：" << vedio.get(CAP_PROP_FPS) << endl;
//	cout << "视频宽度：" << vedio.get(CAP_PROP_FRAME_WIDTH) << endl;
//	cout << "视频高度：" << vedio.get(CAP_PROP_FRAME_HEIGHT) << endl;
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
//int luzhishipin()//打开摄像头并录制视频
//{
//	Mat img;
//	VideoCapture vedio(0);
//	if (!vedio.isOpened())
//	{
//		cout << "打开摄像头失败捏" << endl;
//		return -1;
//	}
//
//	vedio >>img;//获取图像
//	if (img.empty())//检测是否成功读取图像
//	{
//		cout << "未获取到图像" << endl;
//		return -1;
//	}
//
//	bool color = (img.type() == CV_8UC3);//判断视频是否彩色
//
//	VideoWriter writer;
//	int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');//选择编码格式
//
//	double fps = 30;//帧率设置
//	string name = "视觉组的佬都很帅.avi";
//	writer.open(name, codec, fps, img.size(), color);
//
//	if (!writer.isOpened())
//	{
//		cout << "打开视频文件失败，请确认是否为合法输入" << endl;
//		return -1;
//	}
//
//	while (1)
//	{
//		if (!vedio.read(img))
//		{
//			cout << "摄像头已断开或视频读取完成" << endl;
//			break;
//		}
//		writer.write(img);
//		imshow("Live", img);//显示图像
//		uchar c = waitKey(1000 / 30);
//		if (c == 27)//esc退出录制
//		{
//			break;
//		}
//	}
//	return 0;
//
//
//}
//
//int con()//图像格式转换
//{
//	Mat img = imread("nilu.png");
//	Mat img32;
//	//convertTo函数将图像的像素值从一个数据类型转换为另一个数据类型。
//	//CV_32F是OpenCV中定义的一个常量，表示32位浮点型数据类型。
//	img.convertTo(img32, CV_32F, 1 / 255.0, 0);//四个参数依次是：输出图像；转换后的数据类型；缩放系数；平移系数
//	Mat HSV, HSV32;
//	cvtColor(img, HSV, COLOR_BGR2HSV);//四个参数：原始图像；目标图像；颜色转换标志；最后一个是目标图像的通道数，若省略则默认参数为0，从原始图像中自动导出通道数
//	cvtColor(img32, HSV32, COLOR_BGR2HSV);//cvtcolor用于图像格式转换
//
//	Mat gray0, gray1;
//	cvtColor(img, gray0, COLOR_BGR2GRAY);
//	cvtColor(img32, gray1, COLOR_BGR2GRAY);//GRAY颜色模型：Gray=R*0.3+G*0.59+B*0.11
//	return 0;
//}
//
////CV_8U：8位无符号整数（0-255）
////CV_8S：8位有符号整数（ - 128到127）
////CV_16U：16位无符号整数（0 - 65535）
////CV_16S：16位有符号整数（ - 32768到32767）
////CV_32S：32位有符号整数
////CV_32F：32位浮点数
////CV_64F：64位浮点数
//
//int fenli()//通道分离与合并
//{
//	Mat img = imread("nilu.png");
//	Mat img32;
//	img.convertTo(img32, CV_32F, 1 / 255.0, 0);
//	Mat gray0, gray1;
//	cvtColor(img, gray0, COLOR_BGR2GRAY);
//	cvtColor(img32, gray1, COLOR_BGR2GRAY);
//
//	Mat imgs[3];//分离后的通道要用数组去接收
//	split(img, imgs);//两参数：要分离的图像；接收通道的数组
//	Mat img0, img1, img2;
//	img0 = imgs[0];
//	img1 = imgs[1];
//	img2 = imgs[2];
//
//	Mat imgh;
//	merge(imgs, 3, imgh);//三个参数：被合并的通道数组；合并后的通道数；输出图像
//
//	Mat zero = Mat::zeros(Size(img.cols, img.rows), CV_8UC1);
//	vector<Mat>imgsv;
//	imgsv.push_back(img1);
//	imgsv.push_back(img2);
//	imgsv.push_back(img0);
//
//	Mat imgsvh;
//	merge(imgsv, imgsvh);//由这个输出图像可以看出确实是bgr的输出形式
//
//	return 0;
//}
//
//int xunzhao()//图像最大最小值的寻找
//{
//	Mat img = imread("nilu.png");
//	Mat white = imread("white.png");
//	Mat black = imread("black.png");
//
//	Mat Min, Max;
//	resize(white, white, img.size());//使white和black图片与img图片的大小参数相同
//	resize(black, black, img.size());
//	max(img, white, Max);//max和min对图像的比较，要求括号内的两图像大小参数相同
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
//	//找寻一个图像中最大和最小值的点，五个参数：输入单通道矩阵；指向最小值的指针；指向最大值的指针；指向最小位置的指针；最大位置的指针；掩码矩阵，用来确定寻找最大最小值的范围
//
//
//	return 0;
//}
//
//
//int huoqiefei()//图像的或、抑或、且、非
//{
//
//	Mat img = imread("nilu.png");
//	Mat mark = imread("white.png");
//	resize(mark, mark, img.size());
//	Mat result1,result2;
//	bitwise_and(img, mark, result1);//0~255的数用二进制的形式表示，按位与
//	bitwise_not(img, mark, result2);//按位非
//	//bitwise_or;bitwise_xor或和抑或
//
//	Mat imgv;
//	cvtColor(mark, mark, COLOR_BGR2GRAY);
//	bitwise_not(img, imgv,mark);//四个参数：图像一；图像二；输出图像；掩码图像
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
//int erzhihua()//图像的二值化
//{
//	Mat img = imread("nilu.png");
//	if (img.empty())
//	{
//		cout << "请检查图片名称是否正确" << endl;
//		return -1;
//	}
//
//	Mat gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	Mat img1, img2, gray1, gray2,gray3,gray4,gray5;
//	//彩色图像二值化
//	threshold(img, img1, 125, 255, THRESH_BINARY);//固定阈值的二值化threshold，五个参数：原图；二值化后的图；阈值；二值化后的最大值；二值化方法标志
//	threshold(img, img2, 125, 255, THRESH_BINARY_INV);
//
//	//灰色图像的二值化
//	threshold(gray, gray1, 125, 255, THRESH_BINARY);
//	threshold(gray, gray2, 125, 255, THRESH_BINARY_INV);
//
//	//灰度图像TOZERO变换
//	threshold(gray, gray3, 125, 255, THRESH_TOZERO);
//	threshold(gray, gray4, 125, 255, THRESH_BINARY_INV);
//
//	//灰度图像TRUNC变换
//	threshold(gray, gray5, 125, 255, THRESH_TRUNC);
//
//	//灰度图像大津法和三角形法二值化
//	Mat imgj = imread("jianbian.png",IMREAD_GRAYSCALE);
//	Mat imgj1, imgj2;
//	threshold(imgj, imgj1, 100, 255, THRESH_BINARY|THRESH_OTSU);
//	threshold(imgj, imgj2, 125, 255, THRESH_BINARY | THRESH_TRIANGLE);
//
//	//自适应阈值的二值化，七个参数：待二值化的图像（图像只能是CV_8UC1的数据类型）；二值化后的图像；二值化的最大值；确定阈值的方法（高斯法或均值法）；二值化方法；自适应确定阈值的像素邻域大小（一般为奇数）；从平均值或加权平均值中减去的常数，可正可负
//	Mat img_mean, img_gauss;
//	adaptiveThreshold(imgj, img_mean, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 55, 0);
//	adaptiveThreshold(imgj, img_gauss, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY, 55, 0);
//
//}
//
//int lutchazhao()//LUT查找表原理，三个参数：输入图像矩阵（数据类型只能是CV_8U） ；lut查找类型数组；输出图像
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
//	/*1表示lut_one的行数为1，表示它是一个单行的矩阵。
//	256表示lut_one的列数为256，表示它有256个元素。
//	CV_8UC1表示lut_one的数据类型为8位无符号整数型（uchar），通道数为1，即灰度图像。
//	lut1是一个uchar类型的数组，它包含了256个元素，这些元素将被用来初始化lut_one的数据。*/
//
//	Mat img = imread("nilu.png");
//	Mat gray, out0,out1;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	LUT(gray, lut_one, out0);
//	LUT(img, lut_one, out1);
//
//}
//
//int canshu()//图像参数的改变
//{
//	//图像大小改变
//	Mat gray = imread("nilu.png", IMREAD_GRAYSCALE);
//	Mat gs, gb1, gb2, gb3;
//	
//	//参数：原图；输出图；图像大小；横向发大倍数；纵向放大倍数；放大或缩小运用的计算方式。注意优先看图像大小size，若有size，则后面的放大倍数可任意值
//	resize(gray, gs, Size(60, 105), 0, 0, INTER_AREA);//区域插值，主要用于图像缩小操作
//	resize(gs, gb1, Size(240, 420), 0, 0, INTER_NEAREST);//最近插值
//	resize(gs, gb2, Size(240, 420), 0, 0, INTER_LINEAR);//双线性插值
//	resize(gs, gb3, Size(240, 420), 0, 0, INTER_CUBIC);//双三次插值
//
//	//图像翻转
//	Mat imgx, imgy, imgxy;
//	flip(gray, imgx, 0);//三个参数：原图；输出图像；翻转方向
//	flip(gray, imgy, 1);//最后一个值大于0，沿y轴翻转，等于0，x轴，小于0，中心对称翻转
//	flip(gray, imgxy, -1);
//
//	//图像拼接
//	Mat img1, img2, img3;
//	hconcat(gb1, gb2, img1);//横向连接
//	hconcat(gb2, gb3, img2);
//
//	vconcat(img1, img2, img3);//纵向连接
//
//	return 0;
//
//}
//
//int fangshe()//仿射变换
//{
//	Mat img = imread("nilu.png");
//	Mat rotation0, img0;//仿射变换后的矩阵和图像
//
//	double angle = 30;//设置旋转角度
//	
//	Size dst_size(img.rows, img.cols);//设置输出图像的尺寸
//	Point2f center(img.rows / 2.0, img.cols / 2.0);//设置图像的旋转中心
//	rotation0 = getRotationMatrix2D(center, angle, 1);//计算仿射变换矩阵，参数：旋转中心；旋转角度；缩放系数
//
//	warpAffine(img, img0, rotation0, dst_size);//进行仿射变换，四个参数：原图；旋转后图像；仿射变换矩阵；旋转后图像尺寸
//
//	//三点法仿射变换
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
//int toushibianhuan()//图像透视变换
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
//	rotation = getPerspectiveTransform(src_points, dst_points);//三个参数：原图四点坐标数组；变换后四点坐标数组；透视变换方法（可省略，但默认为高斯消元法）
//	warpPerspective(img, img_warp, rotation, Size(914,914));//计算透视变换矩阵
//
//
//
//	return 0;
//
//}
//
//int jihetuxing()//绘制几何图形
//{
//	Mat img = Mat::zeros(Size(512, 512), CV_8UC3);
//	//圆
//	circle(img, Point(50, 50), 25, Scalar(255, 255, 255), -1);
//	circle(img, Point(100, 50), 25, Scalar(255, 255, 255), 1);
//
//	//直线,最后面是线宽、线型、
//	line(img, Point(100, 100), Point(200, 200), Scalar(255, 255, 255), 2, LINE_4, 0);
//
//	//椭圆
//	ellipse(img, Point(300, 250), Size(100, 70), 0, 0, 200, Scalar(255, 255, 255), -1);
//
//	//矩形
//	rectangle(img, Point(50, 400), Point(100, 450), Scalar(125, 125, 125), -1);
//
//	//多边形，用二维数组来绘制
//	//fillPoly(img,pts,npts,3,Scalar(255,255,255));绘制的图片；二维顶点数组；顶点个数数组；生成3个多边形；颜色
//
//	//文字生成，不能有中文
//	putText(img, "elysia", Point(100, 400), 2, 1, Scalar(255, 255, 255));
//
//	return 0;
//}
//
//int kaobei()//ROI区域截取，深拷贝和浅拷贝
//{
//	Mat img1 = imread("nilu.png");
//	Mat img2 = imread("black.png");
//
//	Mat ROI1, ROI2, ROI2_copy, mask, img3, img_copy;
//
//	resize(img2, mask, Size(200, 200));
//
//	//深拷贝是在内存空间新生成一份图像矩阵，这使得改变原图像并不会让拷贝后的图像跟着改变
//	//浅拷贝让原图像和新图像都指向原图像的矩阵地址，改变原图像会使得拷贝后的图片跟着改变
//	img3 = img1;//浅拷贝
//
//	//深拷贝的两种方式
//	img1.copyTo(img_copy);
//
//	//两种在图中截取ROI区域的方式
//	Rect rect(206, 206, 200, 200);//定义ROI区域，前两个参数是截图的左上角坐标，然后后两个是宽度和高度
//	ROI1 = img1(rect);//截图
//
//	ROI2 = img1(Range(300, 500), Range(300, 500));//第二种截图方式，截图的行范围是300~500，列范围也是
//
//	img1(Range(300, 500), Range(300, 500)). copyTo(ROI2_copy);//深拷贝
//
//	mask.copyTo(ROI1);//在图像中加入部分图像
//
//	return 0;
//}
//
//int gaosi()//高斯图像金字塔
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
//		pyrDown(Guass[i], guass);//下采样
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
//int lapu()//拉普拉斯图像金字塔,报错了....
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
//		pyrDown(Guass[i], guass);//下采样
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
//int huadongtiao()//创建滑动条
//{
//	img = imread("nilu.png");
//	namedWindow("img");
//	imshow("img", img);
//
//	int value = 100;
//	//6个参数：滑动条名称；
//	createTrackbar("百分比", "img",&value,600,callBack,0);
//
//
//	waitKey(0);
//	return 0;
//}
//Mat imgPoint; Point prePoint;
//void mouse(int event, int x, int y, int flags,void*);
//int mouse_response()//鼠标响应
//{
//	
//	img = imread("nilu.png");
//	img.copyTo(imgPoint);
//
//	imshow("图像窗口_1", img);
//	imshow("图像窗口_2", imgPoint);
//	//鼠标事件响应函数
//	//三个参数：窗口名字；响应回调函数；传递给回调函数的可选参数
//	setMouseCallback("图像窗口_1", mouse, 0);
//
//
//	waitKey(0);
//	return 0;
//}
////响应回调函数
////五个参数：鼠标响应事件标志（瞬时，如点击）；鼠标指针x坐标；y坐标；响应标志（长时间，如拖拽）；传递给回调函数的可选参数
//void mouse(int event,int x,int y,int flags,void*)
//{
//	if (event == EVENT_RBUTTONDOWN)
//	{
//		cout << "请点击鼠标左键开始绘制" << endl;
//	}
//	if (event == EVENT_LBUTTONDOWN)
//	{
//		prePoint = Point(x, y);
//		cout << "轨迹起始点坐标：" << prePoint << endl;
//	}
//
//	if (event == EVENT_MOUSEMOVE && (flags & EVENT_FLAG_LBUTTON))//鼠标按住左键移动第3章图像基本操作
//	{//通过绘制直线显示鼠标移动轨迹
//		Point pt(x, y);
//		line(img, prePoint, pt, Scalar(255, 255, 255), 2, 5, 0);
//		prePoint = pt;
//		imshow("图像窗口_1", img);
//		//通过改变图像像素显示鼠标移动轨迹
//		imgPoint.at<Vec3b >(y, x) = Vec3b(255, 255, 255);
//		imgPoint.at<Vec3b>(y, x - 1) = Vec3b(255, 255, 255);
//		imgPoint.at<Vec3b >(y, x + 1) = Vec3b(255, 255, 255);
//		imgPoint.at<Vec3b>(y + 1, x) = Vec3b(255, 255, 255);
//		imgPoint.at<Vec3b >(y + 1, x) = Vec3b(255, 255, 255);
//		imshow("图像窗口_2", imgPoint);
//	}
//
//}
//
//int zhifangtu()//统计像素直方图
//{
//	img = imread("jianbian.png");
//	if (img.empty())
//	{
//		cout << "请确认图像文件是否正确"<<endl;
//		return -1;
//	}
//
//	Mat gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//
//	//设置提取直方图的相关变量
//	Mat hist;//用于存放直方图计算结果
//	const int channels[1] = { 0 };//通道索引，灰色图像只有一个通道，如果是彩色图像可以设置0,1,2三个通道分别代指R,G,B通道
//	const int bins[1] = { 256 };//直方图的维度，其实就是灰度值的最大值
//	float inRanges[2] = { 0,255 };
//	const float* ranges[1] = { inRanges };//像素灰度值范围
//
//	calcHist(&gray, 1, channels, Mat(), hist, 1, bins, ranges);//计算直方图
//	//Mat()就代表没有使用掩码图像
//	 
//	
//	//准备绘制直方图
//	int hist_w = 650;
//	int hist_h = 974;
//	int width = 2;
//	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
//	for (int i = 1; i < hist.rows; i++)
//	{
//		//rectangle用于绘制直方图的柱状图，两个点分别是左上角点坐标和右下角点坐标
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
//int equally()//直方图均衡化，显示的直方图大量集中在左侧，说明图像很暗，反之则亮
//{
//	//均衡化的图像能够更好地观察图像的纹理、细节
//	
//	img = imread("nilu.png");
//	if (img.empty())
//	{
//		cout << "请确认图像文件是否正确" << endl;
//		return -1;
//	}
//
//	Mat gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//
//	Mat equalling;
//
//	//两个参数：需要均衡化的图像；均衡化的输出图像
//	equalizeHist(gray, equalling);
//	imshow("gray",gray);
//	imshow("equal",equalling);
//
//	Mat hist;//用于存放直方图计算结果
//	const int channels[1] = { 0 };//通道索引，灰色图像只有一个通道，如果是彩色图像可以设置0,1,2三个通道分别代指R,G,B通道
//	const int bins[1] = { 256 };//直方图的维度，其实就是灰度值的最大值
//	float inRanges[2] = { 0,255 };
//	const float* ranges[1] = { inRanges };//像素灰度值范围
//
//	calcHist(&equalling, 1, channels, Mat(), hist, 1, bins, ranges);//计算直方图
//	//没有这条计算代码的话无法显示直方图的图像
//
//
//	int hist_w = 650;
//	int hist_h = 974;
//	int width = 2;
//	Mat histImage = Mat::zeros(hist_h, hist_w, CV_8UC3);
//	for (int i = 1; i < hist.rows; i++)
//	{
//		//rectangle用于绘制直方图的柱状图，两个点分别是左上角点坐标和右下角点坐标
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
//		//rectangle用于绘制直方图的柱状图，两个点分别是左上角点坐标和右下角点坐标
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
//int zhifangtupipei()//直方图匹配,没完全理解
//{
//	Mat img2 = imread("nilu.png");
//	Mat img1 = imread("jianbian.png");
//
//	Mat hist1, hist2;
//
//	//计算两张图像的直方图
//	const int channels[1] = { 0 };//通道索引，灰色图像只有一个通道，如果是彩色图像可以设置0,1,2三个通道分别代指R,G,B通道
//	const int bins[1] = { 256 };//直方图的维度，其实就是灰度值的最大值
//	float inRanges[2] = { 0,255 };
//	const float* ranges[1] = { inRanges };//像素灰度值范围
//	calcHist(&img1, 1, channels, Mat(), hist1, 1, bins, ranges);//计算直方图
//	calcHist(&img2, 1, channels, Mat(), hist2, 1, bins, ranges);//计算直方图
//
//	//归一化两张图像的直方图
//	drawHist(hist1, NORM_L1, "hist1");
//	drawHist(hist2, NORM_L1, "hist2");
//
//	//计算两张图像直方图的累计概率
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
//	//构建累计概率误差矩阵
//	float diff_cdf[256][256];
//	for (int i = 0; i < 256; i++)
//	{
//		for (int j = 0; j < 256; j++)
//		{
//			diff_cdf[i][j] = fabs(hist1_cdf[i] - hist2_cdf[j]);
//		}
//	}
//
//	//生成LUT的映射表
//
//	Mat lut(1, 256, CV_8U);
//	for (int i = 0; i < 256; i++)
//	{
//		//查找源灰度级为i的映射灰度
//		//和i的积累概率差值最小的规定化灰度
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
//	imshow("待匹配", img1);
//	imshow("匹配的模版图像", img2);
//	imshow("直方图匹配结果", result);
//
//	calcHist(&result, 1, channels, Mat(), hist3, 1, bins, ranges);//计算直方图
//	drawHist(hist3, NORM_L1, "hist3");
//	waitKey(0);
//
//
//	return 0;
//}
//
//int mubanpipei()//模版匹配
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
//	imshow("原图", img);
//	imshow("模版",temp);
//	imshow("结果",result);
//
//	waitKey(0);
//	return 0;
//}
//
//
//int juanji()//图像的卷积，作用：减少噪点，模糊图片，增加精度
//{
//	//待卷积矩阵
//	uchar points[25] = { 1,2,3,4,5,
//	6,7,8,9,10,
//	11,12,13,14,15,
//	16,17,18,19,20,
//	21,22,23,24,25 };
//
//	Mat img(5, 5, CV_8UC1, points);
//
//	//卷积模版
//	Mat kernel = (Mat_<float>(3, 3) << 1, 2, 1,
//		2, 0, 2,
//		1, 2, 1);
//
//	Mat kernel_norm = kernel / 12;//卷积归一化（把模版中所有元素加起来，再让模版去除以这个数）
//
//
//	//未归一化卷积结果和归一化卷积结果
//	Mat result, result_norm;
//	//七个参数：输入图像；输出图像；输出图像的数据类型；卷积核，CV32FC1类型的矩阵；
//	//内核的基准点（默认值为Point(-1,-1),代表内核基准带你位于kernel的中心位置；偏值；像素外推法选择标志
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
//			if (image.type() == CV_8UC1)//如果图像是单通道
//			{
//				image.at<uchar>(j, k) = 255;
//			}
//			else if (image.type() == CV_8UC3)//三通道
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
//int zaosheng()//图片的噪声处理:椒盐噪声和高斯噪声的产生
//{
//	img = imread("nilu1.png");
//	Mat img0 = imread("nilu1.png", IMREAD_GRAYSCALE);
//	
//	Mat img_g, img0_g;//用来接收两个高斯噪化之后的图像
//	img.copyTo(img_g);
//	img0.copyTo(img0_g);
//	Mat img_s, img0_s;//接收椒盐噪化的结果
//	img.copyTo(img_s);
//	img0.copyTo(img0_s);
//
//	imshow("nilu原图", img);
//	imshow("灰色nilu原图", img0);
//
//	Pepper(img_s, 10000);
//	Pepper(img0_s, 10000);
//
//
//	imshow("nilu椒盐噪化", img_s);
//	imshow("灰色nilu椒盐噪化噪化", img0_s);
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
//	RNG rng;//RNG随机数
//	rng.fill(img_nos, RNG::NORMAL, 10, 20);//高斯噪声的生成函数
//	rng.fill(img0_nos, RNG::NORMAL, 15, 30);
//
//	imshow("三通道高斯噪声", img_nos);
//	imshow("单通道高斯噪声", img0_nos);
//
//	img_g = img_g + img_nos;
//	img0_g = img0_g + img0_nos;
//
//	imshow("nilu添加噪声", img_g);
//	imshow("灰色nilu添加噪声", img0_g);
//
//	imwrite("D:\\opencv\\learnopencv\\learnopencv\\nilu_g.png",img_g);
//	imwrite("D:\\opencv\\learnopencv\\learnopencv\\nilu0_g.png", img0_g);
//
//	waitKey(0);
//	return 0;
//}
//
//
//int xianxinglvbo()//线性滤波
//{
//	//Mat img_g = imread("nilu_g.png");//三通道噪声图
//	Mat img0_g = imread("nilu0_g.png");//单通道噪声图
//	Mat img_s = imread("nilu0_s.png");
//	Mat yuan = imread("nilu1.png");//不含噪声图
// 
//
//	Mat r_3, r_9;//存放不含噪声的滤波结果，数字代表滤波尺寸
//	Mat r_3g, r_9g;//高斯噪声滤波
//	Mat r_3s, r_9s;//椒盐噪声滤波
//
//	//滤波函数
//
//
//	//均值滤波
//	blur(yuan, r_3, Size(3, 3));
//	blur(yuan, r_9, Size(9, 9));
//	blur(img_s, r_3s, Size(3, 3));
//	blur(img_s, r_9s, Size(9, 9));
//	blur(img0_g, r_3g, Size(3, 3));
//	blur(img0_g, r_9g, Size(9, 9));
//
//
//	Mat r_n, r;//接受方框滤波
//	boxFilter(img0_g, r_n, -1, Size(3, 3), Point(-1, -1), true);//进行归一化
//	boxFilter(img0_g, r, -1, Size(3, 3), Point(-1, -1), false);//不进行归一化
//	//不进行归一化的操作会让亮的地方变全白，只有原图特别暗的地方显示纹路
//
//
//	//高斯滤波，对高斯噪声的处理较好
//	Mat r_5G, r_9G;
//	Mat r_5gG, r_9gG;//存放含有高斯滤波的滤波结果，后面的数字表示滤波器尺寸
//	Mat r_5sG, r_9sG;//存放含有椒盐噪声的...
//	
//	//高斯滤波函数
//
//	GaussianBlur(yuan, r_5G, Size(5, 5), 10, 20);
//	GaussianBlur(yuan, r_9G, Size(9, 9), 10, 20);
//	GaussianBlur(img0_g, r_5gG, Size(5, 5), 10, 20);
//	GaussianBlur(img0_g, r_9gG, Size(9, 9), 10, 20);
//	GaussianBlur(img_s, r_5sG, Size(5, 5), 10, 20);
//	GaussianBlur(img_s, r_9sG, Size(9, 9), 10, 20);
//
//	//以上三种，无论哪种滤波形式，都对椒盐噪声的处理不是很好
//
//	return 0;
//}
//
//
//int zhongzhilvbo()//中值滤波
//{
//	//原理：滤波器内像素排序；寻找中位数；替换像素
//	Mat zhongzhi = imread("中值滤波原理.png");
//
//	Mat img0_g = imread("nilu0_g.png");//单通道噪声图（高斯）
//	Mat img0_s = imread("nilu0_s.png");//椒盐
//	Mat yuan = imread("nilu1.png");//不含噪声图
//
//	Mat g3, g9, s3, s9, y3, y9;
//	medianBlur(img0_g, g3, 3);
//	medianBlur(img0_s, s3, 3);
//	medianBlur(yuan, y3, 3);
////三个参数：原图；输出图；滤波器尺寸（必须是大于1的奇数）
//	medianBlur(img0_g, g9, 9);
//	medianBlur(img0_s, s9, 9);
//	medianBlur(yuan, y9, 9);
//
//	//中值滤波只对椒盐噪声的处理效果比较好
//	
//	return 0;
//}
//
//
//int lvbofenli()//滤波的可分离性
//{
//	Mat kefenli = imread("可分离滤波的含义.png");
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
//	//X和Y方向和联合滤波器的构建
//	Mat a = (Mat_<float>(3, 1) << -1, 3, -1);//设置一个一行三列的矩阵
//	//reshape()是矩阵变化函数，A = reshape（A，m，n）；或者 A = reshape（A，[m,n]）; 
//	//都是将A 的行列排列成m行n列。
//	Mat b=a.reshape(1, 1);//设置三个一行一列的矩阵
//	Mat ab = a * b;
//
//	//验证高斯滤波的可分离性
//	Mat gaussX = getGaussianKernel(3, 1);//这个函数是生成高斯滤波器的函数
//	Mat gaussdata, gaussdataXY;
//	GaussianBlur(data, gaussdata, Size(3, 3), 1, 1, BORDER_CONSTANT);
//	sepFilter2D(data, gaussdataXY, -1, gaussX, gaussX, Point(-1, -1), 0, BORDER_CONSTANT);
//
//
//	//线性滤波的可分离性
//	Mat dataXY, dataY, dataYX, dataXY_sep;
//
//	filter2D(data, dataY, -1, a, Point(-1, -1), 0, BORDER_CONSTANT);
//	filter2D(dataY, dataYX, -1, b, Point(-1, -1), 0, BORDER_CONSTANT);
//	filter2D(data, dataXY, -1, ab, Point(-1, -1), 0, BORDER_CONSTANT);
//
//	sepFilter2D(data, dataXY_sep, -1, b, b, Point(1, 1), 0, BORDER_CONSTANT);
//    //八个参数：原图；输出图像；输出图像的数据类型（深度）；X方向的滤波器；Y方向的滤波器
//	//内核的基准点，默认为（-1，-1）代表内核基准点位于滤波器的中心位置；偏值；像素外推法标志
//	
//	//输出高斯滤波的计算结果
//	cout << gaussdata << endl;
//
//	cout << gaussdataXY << endl;
//
//	//输出分离滤波和联合滤波的计算结果
//
//	cout << dataY << endl;
//	cout << dataYX << endl;
//	cout << dataXY << endl;
//	cout << dataXY_sep << endl;
//	//根据数据我们可以看出，使用分离滤波函数和分步对xy方向滤波的结果相同
//	//图像也可进行分步滤波。
//	
//
//	
//	return 0;
//}
//
//int bianyuan1()//边缘检测原理1
//{
//	Mat sobel = imread("D:\\opencv\\learnopencv\\learnopencv\\sobel算子边缘检测函数.png");
//	Mat scharr = imread("D:\\opencv\\learnopencv\\learnopencv\\scharr算子函数.jpg");
//	Mat suanzishengcheng = imread("D:\\opencv\\learnopencv\\learnopencv\\算子生成函数.png");
//
//
//	Mat img = imread("nilu1.png", IMREAD_GRAYSCALE);
//
//	Mat rx, ry, rxy;
//	//sobel算子计算边缘
//	//X方向一阶边缘
//	Sobel(img, rx, CV_16S, 1, 0, 3);
//	convertScaleAbs(rx, rx);
//
//	//Y方向一阶边缘
//	Sobel(img, ry, CV_16S, 0, 1, 5);//最后一个ksize，值为1和3都是同种处理方法
//	convertScaleAbs(ry, ry);
//
//	//整幅图像的一阶边缘
//	rxy = rx + ry;
//
//
//	Mat rx1, ry1, rxy1;
//	//scharr计算边缘
//	//X方向一阶边缘
//	Scharr(img, rx1, CV_16S, 1, 0);
//	convertScaleAbs(rx1, rx1);
//
//	//Y方向一阶边缘
//	Scharr(img, ry1, CV_16S, 0, 1);
//	convertScaleAbs(ry1, ry1);
//
//	//整幅图像的一阶边缘
//	rxy1 = rx1 + ry1;
//
//	cout << "接下来生成边缘检测器" << endl;
//
//
//	Mat so_x, so_y,//存放分离算子
//		sc_x, sc_y,
//		sob, sch;//存放最终算子
//
//	getDerivKernels(so_x, so_y, 1, 0, 3);
//	so_x = so_x.reshape(CV_8U, 1);
//	sob = so_y*so_x;
//
//	getDerivKernels(sc_x, sc_y, 1, 0, FILTER_SCHARR);
//	sc_x = sc_x.reshape(CV_8U, 1);
//	sch = sc_y * sc_x;  //计算滤波器
//
//
//	return 0;
//}
//
//
//int bianyuan2()//边缘检测2
//{
//	Mat img = imread("nilu0_g.png", IMREAD_GRAYSCALE);
//
//	Mat r, r_g, r_G;
//	//未滤波提取边缘
//	Laplacian(img, r, CV_16S, 3, 1, 0);
//	convertScaleAbs(r, r);
//
//	//滤波后提取拉普拉斯边缘
//	GaussianBlur(img, r_g, Size(3, 3), 5, 0);//高斯滤波
//	Laplacian(r_g, r_G, CV_16S, 3, 1, 0);
//	convertScaleAbs(r_G, r_G);
//
//
//	cout << "接下来进行Canny边缘检测" << endl;
//	Mat r_high, r_low, rG;
//
//	//大阈值检测图像边缘
//	Canny(img, r_high, 100, 200, 3);
//
//	//小阈值检测图像边缘
//	Canny(img, r_low, 20, 40, 3);
//
//	//高斯模糊后检测图像边缘
//	GaussianBlur(img, rG, Size(3, 3), 5);//高斯滤波
//	Canny(rG, rG, 100, 200, 3);
//
//
//	return 0;
//}
//
//int liantongyu()//连通域分析
//{
//	//connectedComponents()是只分割连通域的函数
//	// 四个参数：原图；输出图；标记时的邻域种类，4和8，默认为8；输出图像的数据类型
//	//connectedComponentsWithStats()分割并统计连通域信息的函数
//	//六个参数：原图；输出图；不同连通域后的输出图像；每个连通域的质心坐标；邻域种类；
//
//
//	Mat img = imread("nilu1.png");
//	
//	Mat nilu, niluBW;
//	cvtColor(img, nilu, COLOR_BGR2GRAY);
//
//	//二值化处理图像
//	threshold(nilu, niluBW, 125, 255, THRESH_BINARY);//大于125的值全变为255，小于125全变成0
//
//	//生成随机颜色，用于区分不同连通域
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
//	//以不同颜色标记处不同的连接域
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
//	cout << "接下来统计连通域信息" << endl;
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
//	//中心位置
//	int center_x = centroids.at<double>(i, 0);
//	int center_y = centroids.at<double>(i, 1);
//
//	//矩形边框
//	int x = stats.at<int>(i, CC_STAT_LEFT);
//	int y = stats.at<int>(i, CC_STAT_TOP);
//	int w = stats.at<int>(i, CC_STAT_WIDTH); 
//	int h = stats.at<int>(i, CC_STAT_HEIGHT);
//	int area = stats.at<int>(i, CC_STAT_AREA);
//
//	//中心位置绘制
//	circle(img, Point(center_x, center_y), 2, Scalar(0, 255, 0), 2, 8, 0);
//	//外接矩形
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
//int juli()//图像的距离变换
//{
//	//distanceTransform()距离变换函数
//	//五个参数，原图（单通道）；输出；选择计算两个像素之间距离方法的标志；掩码矩阵：3或5，但是欧式距离只能用5，所以建议所有都用5；数据类型
//	 
//	Mat distance = imread("D:\\opencv\\learnopencv\\learnopencv\\计算距离.png");
//	return 0;
//}
//
//int fushi()//图像腐蚀，让暗的地方更暗
//{
//	//先介绍结构元素生成函数
//	//getStructuringElement()三个参数：结构元素种类（0为矩形，1为十字，2为内接椭圆）；尺寸大小；中心点位置
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
//	Mat erodeSrc1,erodeSrc2;//存放腐蚀后的图像
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
//int pengzhang()//图像膨胀，让亮的地方更亮,函数参数也和erode()相同
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
//	Mat dilateSrc1, dilateSrc2;//存放膨胀后的图像
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
//int xingtaixue()//形态学的应用
//{
//	//morphologyEx()
//	//参数：原图；输出图；形态学操作的标志；结构元素；中心点；操作次数；
//	Mat xingtai = imread("D:\\opencv\\learnopencv\\learnopencv\\形态学对应参数.png");
//	
//
//	//每种处理方法都不同，用到的时候再查
//
//	return 0;
//}
//
////#include <opencv2\ximgproc.hpp>图像细化所需要的头文件
////实在不知道自己安装的问题在哪里
//
//
//int xihua()//图像细化,能让一些粗的、面积比较大的图像变细小
//{
//	Mat xihua = imread("D:\\opencv\\learnopencv\\learnopencv\\图像细化原理.jpg");
//	Mat hanshu = imread("D:\\opencv\\learnopencv\\learnopencv\\图像细化函数.jpg");
//	return 0;
//}
//
//int lunkuojiance()//轮廓检测，轮廓的概念是
//{
//	system("color F0");//更改输出界面颜色
//
//	Mat img = imread("米粒.jpg");
//	
//	imshow("原图", img);
//	Mat erzhi,gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	threshold(gray, erzhi, 150, 255, THRESH_BINARY | THRESH_OTSU);
//
//	//轮廓发现与绘制
//	vector<vector<Point>> contours;//轮廓
//	vector<Vec4i> hierarchy;//存放轮廓结构变量
//
//	findContours(gray, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point());
//	//第四个参数mode指定了轮廓的检索模式，第五个参数method指定了轮廓的近似方法。
//	
//	//mode参数可以取以下四个值：
//	//  RETR_EXTERNAL：只检索最外层的轮廓。
//	//	RETR_LIST：检索所有的轮廓，并将其保存到列表中。
//	//	RETR_CCOMP：检索所有的轮廓，并将其组织为两级层次结构。在第一级结构中，每个轮廓都是其子轮廓的父轮廓。在第二级结构中，包含所有的轮廓。
//	//	RETR_TREE：检索所有的轮廓，并将其组织为完整的层次结构树。
//
//	//method参数可以取以下三个值：
//	//CHAIN_APPROX_NONE：不进行压缩，存储所有的轮廓点。
//	//CHAIN_APPROX_SIMPLE：压缩水平、垂直和对角线方向上的冗余点，仅保留轮廓的端点。
//	//CHAIN_APPROX_TC89_L1和CHAIN_APPROX_TC89_KCOS：应用Teh - Chin链逼近算法中的一种。
//
//	//绘制轮廓
//
//	for (int i = 0; i < hierarchy.size(); i++)
//	{
//		cout << hierarchy[i] << endl;
//	}
//
//	for (int i = 0; i < contours.size(); i++)
//	{
//		drawContours(img, contours, i, Scalar(0, 0, 255), 2, 8);
//		imshow("轮廓检测结果", img);
//		waitKey(0);
//	}
//
//	return 0;
//
//}
//
//int jixuanlunkuo()//计算轮廓的一些性质
//{
//	system("color F0"); // 更改输出界面颜色
//		//用四个点表示三角形轮廓
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
//	//对图像的轮廓检测和计算
//
//	Mat img = imread("米粒.jpg");
//
//	imshow("原图", img);
//	Mat erzhi, gray;
//	cvtColor(img, gray, COLOR_BGR2GRAY);
//	threshold(gray, erzhi, 150, 255, THRESH_BINARY | THRESH_OTSU);
//
//	imshow("erzhi", erzhi);
//	imshow("gray", gray);
//
//	vector<vector<Point>> contours;//轮廓
//	vector<Vec4i> hierarchy;//存放轮廓结构变量
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
//int duobianxing()//轮廓外接多边形 
//{
//	Mat img = imread("各种物体.jpg");
//
//	Mat img1, img2;
//	img.copyTo(img1);
//	img.copyTo(img2);
//
//	imshow("img", img);
//
//	//去除噪声以及二值化
//	Mat canny;
//	Canny(img, canny, 100, 300, 3, false);
//	imshow("canny", canny);
//
//	//膨胀运算，填补细小缝隙
//	Mat kernel = getStructuringElement(0, Size(3, 3));
//	dilate(canny, canny, kernel);
//
//	//轮廓发现与检测
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	findContours(canny, contours, hierarchy, 0, 2, Point());
//
//	//寻找轮廓的外接矩形
//	for (int n = 0; n < contours.size(); n++)
//	{
//		//最大外接矩形
//		Rect rect = boundingRect(contours[n]);
//		rectangle(img1, rect, Scalar(0, 0, 255), 2, 8, 0);//绘制矩形函数
//
//		//最小外接矩形
//		RotatedRect rrect = minAreaRect(contours[n]);
//		Point2f points[4];
//		rrect.points(points);
//		Point2f cpt = rrect.center;
//		//旋转矩形可以转变为旋转椭圆进行输出，而不能直接rectangle去输出
//		ellipse(img2, rrect, Scalar(0,255,0), 2);
//
//		//或者用划线的方式去表示旋转后的矩形
//		//检测旋转矩形与中心位置
//		for (int i = 0; i < 4; i++)
//		{
//			if (i == 3)
//			{
//				line(img2, points[i], points[0], Scalar(0, 255, 0), 2, 8, 0);
//				break;
//			}
//			line(img2, points[i], points[i + 1], Scalar(0, 255, 0), 2, 8, 0);
//		}
//        //绘制矩形的中心
//		circle(img2, cpt, 4, Scalar(255, 0, 0), -1, 8, 0);
//	}
//	
//	//输出绘制外接矩形的结果
//	imshow("max", img1);
//	imshow("min", img2);
//
//
//	cout << "接下来进行多边形的拟合" << endl;
//	waitKey(0);
//
//	Mat img3 = imread("多边形.jpg");
//
//	//去除噪声以及二值化
//	Mat canny2;
//	Canny(img3, canny2, 100, 300, 3, false);
//	imshow("canny2", canny2);
//
//	//膨胀运算，填补细小缝隙
//	Mat kernel2 = getStructuringElement(0, Size(3, 3));
//	dilate(canny2, canny2, kernel2);
//
//	//轮廓发现与检测
//	vector<vector<Point>> contours2;
//	vector<Vec4i> hierarchy2;
//	findContours(canny2, contours2, hierarchy2, 0, 2, Point());
//
//	//绘制多边形
//	for (int i = 0 ; i < contours2.size(); i++)
//	{
//		//用最小外接矩形求取轮廓中心
//		RotatedRect rrect = minAreaRect(contours2[i]);
//		Point2f center = rrect.center;
//		circle(img3, center, 2, Scalar(0, 255, 0), 2, 8, 0);
//
//		Mat result;
//		approxPolyDP(contours2[i], result, 4, true);
//		drawapp(result, img3);
//		cout << "corners:" << result.rows << endl;
//
//		//判断形状和绘制轮廓
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
//int tubao()//凸包检测
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
//	//轮廓发现
//	vector<vector<Point>> contours;
//	vector<Vec4i> hierarchy;
//	findContours(binary, contours, hierarchy, 0, 2, Point());
//	for (int n = 0; n < contours.size(); n++)
//	{
//		//计算凸包
//		vector<Point> hull;
//		convexHull(contours[n], hull);//凸包检测函数
//		//参数：输入的2D点集；输出凸包的订单；顺逆方向标志；数据类型
//
//		//绘制凸包
//		for (int i = 0; i < hull.size(); i++)
//		{
//			//绘制凸包顶点
//			circle(img, hull[i], 4, Scalar(255, 0, 0), 2, 8, 0);
//			//连接凸包
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
//int zhixian()//直线检测，三种霍夫变换检测直线
//{
//	return 0;
//}
//
//
//
//
//
//
