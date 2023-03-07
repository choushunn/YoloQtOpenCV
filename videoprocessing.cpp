#include "videoprocessing.h"
#include "qdebug.h"

VideoProcessing::VideoProcessing(QObject *parent) : QObject(parent)
{

}

// 槽函数，用于接收视频帧并发送信号
void VideoProcessing::processFrame(cv::Mat frame)
{
    cv::resize(frame, frame, cv::Size(640,640));
    //水平翻转图像
    cv::flip(frame, frame, 1);
    // 将视频帧发送给YOLOv5模型的检测线程进行处理    
    emit sendDtectObjects(frame);
    qDebug() << "2->process Frame" ;
}


void VideoProcessing::processDetectionResults(cv::Mat frame)
{
    qDebug() << "4->process Detection Results" ;
}
