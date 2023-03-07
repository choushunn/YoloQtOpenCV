#pragma once
#ifndef VIDEOPROCESSING_H
#define VIDEOPROCESSING_H

#include <QObject>

//OpenCV
//#include <opencv2/opencv.hpp>
//OpenCV的图像编码模块
#include <opencv2/imgcodecs.hpp>
//OpenCV的图像处理模块
#include <opencv2/imgproc.hpp>
//高性能图形ui模块
#include <opencv2/highgui.hpp>
//深度学习推理
#include <opencv2/dnn.hpp>


using namespace cv;
using namespace dnn;

class VideoProcessing  : public QObject
{
    Q_OBJECT
public:
    VideoProcessing(QObject *parent = nullptr);


public slots:
    // 槽函数，用于接收视频帧并发送信号
    void processFrame(cv::Mat frame);
    // 槽函数，用于接收检测视频帧的结果并发送信号
    void processDetectionResults(cv::Mat frame);

signals:
    // 信号，用于发送检测结果
    void sendDtectObjects(cv::Mat frame);
};


#endif // VIDEOPROCESSING_H
