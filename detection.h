#pragma once
#ifndef YOLOV5DETECTION_H
#define YOLOV5DETECTION_H

#include <QObject>

//OpenCV
#include <opencv2/core.hpp>
//OpenCV的图像编码模块
#include <opencv2/imgcodecs.hpp>
//OpenCV的图像处理模块
#include <opencv2/imgproc.hpp>
//高性能图形ui模块
#include <opencv2/highgui.hpp>
//深度学习推理
#include <opencv2/dnn.hpp>

#include <yolov5.h>
//#include <yolov8_onnx.h>
// 命名空间
using namespace std;
using namespace cv;

class Yolov5Detection : public QObject
{
    Q_OBJECT
public:
    Yolov5Detection(QObject *parent = nullptr);
    ~Yolov5Detection();

private:
    Yolov5 *yolov5;
//    Yolov8Onnx *yolov8_onnx;
    cv::dnn::Net net;
    vector<Scalar> m_color;

public slots:
    // 槽函数，用于接收视频帧并进行检测
    void detectObjects(cv::Mat frame);

signals:
    // 信号，用于发送检测结果
    void sendObjectsResults(cv::Mat frame);
};

#endif // YOLOV5DETECTION_H
