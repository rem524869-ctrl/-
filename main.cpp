#include <iostream>
#include<opencv2/opencv.hpp>


using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{
    //使用opencv读取摄像头数据，并显示到窗口中
    //视频本身也是一张张图片   重复   不断地修改图片 - 循环
    Mat frame;//保存每一帧的摄像头图片

    VideoCapture capture(0);//参数为0的时候，表示调用电脑的默认摄像头
    while(capture.read(frame))
    {
        //1.调动摄像头
        imshow("video",frame);
        Mat blurImg;//模糊图片
        blur(frame,blurImg,Size(50,50));//模糊处理函数
        imshow("blur",blurImg);

        //2.获得背景图片和人物拿着红布图片
        Mat backImg = imread("D:/demo/demo4/background.png");//背景图片
//        Mat hideImg = imread("D:/demo/demo4/hide.png");//人物拿着红布照片
//        imshow("back",backImg);
//        imshow("hide",hideImg);

        //3.图片转化为HSV的格式
        Mat hsv;
        cvtColor(frame,hsv,COLOR_BGR2HSV);//颜色转化函数
//        imshow("hsv",hsv);

        //4.识别出红色区域  注意：红色有两个区域
        Mat mask,mask1;
        inRange(hsv,Scalar(0,120,100),Scalar(10,255,255),mask);
        inRange(hsv,Scalar(170,120,100),Scalar(180,255,255),mask1);
    //    imshow("mask",mask);
    //    imshow("mask1",mask1);
        mask = mask+mask1;//此时的mask就是完整的红布区域模板
//        imshow("mask",mask);

        //5.取反操作
        Mat uMask;//红布区域以外的抠图模板
        bitwise_not(mask,uMask);
        imshow("uMask",uMask);

        //6.开始进行抠图   背景图片 ->mask ? uMask ?
        Mat bkMask;
        bitwise_and(backImg,backImg,bkMask,mask);
        imshow("bkMask",bkMask);

        Mat bkUmask;
        bitwise_and(frame,frame,bkUmask,uMask);
        imshow("bkUmask",bkUmask);

        //7.最后两个图片，像素相融合
        add(bkMask,bkUmask,frame);
        imshow("finalImg",frame);
        waitKey(30);//参数为0等待用户按下任意键  >0  比如30  休眠30毫秒
    }



    return 0;
}
