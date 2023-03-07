#include "detection.h"
#include "qdebug.h"

Yolov5Detection::Yolov5Detection(QObject *parent) : QObject(parent)
{
    string yolov5_model_path = "E:\\CPP\\YoloQtOpenCV\\models/yolov5s.onnx";
    yolov5 = new Yolov5();
    if(yolov5->readModel(net, yolov5_model_path, false)){
        qDebug() << "read net ok!";
    }else{
        qDebug() << "read net failed!";
//        cout << "read net failed!" << endl;
        //        emit 模型读取失败信号
    }

    //生成随机颜色
//    vector<Scalar> color;
//    randomColor(m_color);
//    string yolov8_model_path = "/home/mc/Projects/Yolov5QtOpenCV/yolov5/yolov8s.onnx";
//    yolov8_onnx = new Yolov8Onnx();
//    if (yolov8_onnx->ReadModel(yolov8_model_path, true, 0)) {
//        cout << "read net ok!" << endl;
//    }
//    else {
//        cout << "read net failed!" << endl;
//    }

}


Yolov5Detection::~Yolov5Detection(){

}

//void Yolov5Detection::detectObjects(cv::Mat frame){
//    qDebug() << "3->detect Objects" ;
//    vector<Output> result;
//    if (yolov8_onnx->OnnxDetect(frame, result)) {
//        DrawPred(frame, result, yolov8_onnx->_className, m_color);
//    }
//    else {
//        qDebug() << "3->Detect Failed!";
//    }
//    // 将检测结果发送回VideoProcessing类
//    emit sendObjectsResults(frame);
//}

void Yolov5Detection::detectObjects(cv::Mat frame){
    qDebug() << "3->detect Objects" ;
    vector<Output> result;
    if (yolov5->Detect(frame, net, result)) {
        yolov5->drawPred(frame, result, m_color);
    }
    else {
        qDebug() << "3->Detect Failed!";
    }
    // 将检测结果发送回VideoProcessing类
    emit sendObjectsResults(frame);
}






