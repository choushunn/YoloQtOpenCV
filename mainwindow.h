#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCamera>
#include <QMediaDevices>
#include <QImage>
#include <QFileDialog>
#include <QtConcurrent>
#include <QThread>
#include <QTimer>
//OpenCV
//#include <opencv2/opencv.hpp>
#include <opencv2/core.hpp>
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

#include "videoprocessing.h"
#include "detection.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    VideoCapture *m_cap;
    cv::Mat m_frame;
    QFuture<void> future_readFrame;
private:
    void Init();
    void CheckCamera();
    void OpenCamera();
    void ReadCameraFrame();
    QImage MatToQImage(const Mat &mat);


private slots:
    void on_m_btn_open_camera_clicked(bool checked);
    //接收检测结果并显示
    void showDetectionResults(cv::Mat frame);

    void on_m_btn_open_file_clicked();

    void on_m_btn_play_clicked();

signals:
    //发送读取帧信号
    void sendFrame(cv::Mat frame);

private:
    VideoProcessing *videoProcessing; // 视频流处理对象
    Yolov5Detection *yoloDetection; // YOLOv5模型检测对象
    QThread *yoloDetectionThread; // YOLOv5模型检测线程
    QThread *videoProcessingThread; // 视频流线程
};
#endif // MAINWINDOW_H
