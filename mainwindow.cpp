#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Init();

}

MainWindow::~MainWindow()
{
    //释放摄像头
    if(m_cap){
        if(m_cap->isOpened()){
            m_cap->release();
        }
        delete m_cap;
    }

    delete ui;
}

/**
 * @brief 初始化UI参数
 * @param
 */
void MainWindow::Init(){
    qDebug() << "this is init function.";
    //读取可用相机列表
    CheckCamera();
    // 创建VideoProcessing视频流处理对象
    videoProcessing = new VideoProcessing(this);
    // 创建Yolov5Detection检测处理对象并移动到单独的线程中运行
    yoloDetection = new Yolov5Detection();

    //yoloDetection检测线程
    yoloDetectionThread = new QThread();
    yoloDetection->moveToThread(yoloDetectionThread);
    yoloDetectionThread->start();


    //连接 MainWindow的detectObjects信号和VideoProcessing的processFrame槽函数
    connect(this, &MainWindow::sendFrame, videoProcessing, &VideoProcessing::processFrame);
    // 连接VideoProcessing的detectObjects信号和YoloDetection的detectObjects槽函数
    connect(videoProcessing, &VideoProcessing::sendDtectObjects, yoloDetection, &Yolov5Detection::detectObjects);
    // 连接YoloDetection的sendResults信号和MainWindow的detectionResults槽函数
    connect(yoloDetection, &Yolov5Detection::sendObjectsResults, this, &MainWindow::showDetectionResults);
}


/**
 * @brief 检测相机并显示
 * @param
 */
void MainWindow::CheckCamera(){
    //查询相机
    const QList<QCameraDevice> cameras = QMediaDevices::videoInputs();

    for (const QCameraDevice &cameraDevice : cameras) {
        qDebug() << cameraDevice.description() << cameraDevice.id() << cameraDevice.isDefault();
        ui->m_cmb_cam_name->addItem(cameraDevice.description());
    }

    if(ui->m_cmb_cam_name->count() <= 0){
        ui->m_cmb_cam_name->setDisabled(true);
        ui->m_btn_open_camera->setDisabled(true);
        ui->m_btn_open_camera->setText("未找到设备");
    }else{
        m_cap = new VideoCapture();
        ui->m_cmb_cam_name->setDisabled(false);
        ui->m_btn_open_camera->setDisabled(false);
        ui->m_btn_open_camera->setText("打开");
    }

}

/**
 * @brief 打开摄像头
 * @param
 */
void MainWindow::OpenCamera(){
    if(ui->m_cmb_cam_name->count() <= 0)
    {
        return;
    }
    int cam_index = ui->m_cmb_cam_name->currentIndex();
    qDebug() << "The Camera is opening "<< cam_index;

    bool ret = m_cap->open(cam_index, cv::CAP_ANY);
    if(ret)
    {
        qDebug() << "The Camera is open"<< ui->m_cmb_cam_name->currentIndex();
        //放到其他线程读取
        future_readFrame = QtConcurrent::run(&MainWindow::ReadCameraFrame, this);
        ui->m_btn_open_camera->setText("关闭");
    }else{
        m_cap->release();
        qDebug() << "The Camera is open failed."<< ui->m_cmb_cam_name->currentIndex();
        return;
    }
}

/**
 * @brief 读取视频帧
 * @param
 */
void MainWindow::ReadCameraFrame(){
    cv::Mat frame;
    while (m_cap->isOpened())
    {
        for(int i=0;i<2;i++){
            m_cap->read(frame);
        }
        bool ret = m_cap->read(frame);
        if(ret)
        {
            //检测
            qDebug() << "1->read frame success.";
            emit sendFrame(frame);
        }
        else
        {
            QThread::msleep(1);           // 防止频繁读取或者读取不到
        }
    }
}

/**
 * @brief 槽函数
 * @param
 */
void MainWindow::showDetectionResults(cv::Mat frame){

    qDebug() << "4->show frame success.";
    cv::resize(frame,frame,cv::Size(ui->m_lbl_display->width(),ui->m_lbl_display->height()));
    if(!m_cap->isOpened()){
        ui->m_lbl_display->setText("相机已关闭");
    }else{
        ui->m_lbl_display->setPixmap(QPixmap::fromImage(MatToQImage(frame)));
    }
}


/**
 * @brief 槽函数
 * @param
 */
void MainWindow::on_m_btn_open_camera_clicked(bool checked)
{
    if(checked && !m_cap->isOpened()){
        qDebug() << "the Camera is open.";
        //打开相机
        yoloDetectionThread->start();
        OpenCamera();
        ui->m_btn_open_camera->setText("关闭");
    }else{
        yoloDetectionThread->quit();
        yoloDetectionThread->exit();
        future_readFrame.cancel();
        m_cap->release();
        qDebug() << "the Camera is close.";
        ui->m_btn_open_camera->setText("打开");
    }
}



/**
 * @brief       Mat转QImage
 * @param mat
 * @return
 */
QImage MainWindow::MatToQImage(const Mat &mat)
{
    switch (mat.type())
    {
    case CV_8UC1:
    {
        QImage img(mat.data, mat.cols, mat.rows, mat.cols, QImage::Format_Grayscale8);
        return img;
    }
    case CV_8UC3:
    {
        QImage img(mat.data, mat.cols, mat.rows, mat.cols * 3, QImage::Format_RGB888);
        return img.rgbSwapped();
    }
    case CV_8UC4:
    {
        QImage img(mat.data, mat.cols, mat.rows, mat.cols * 4, QImage::Format_ARGB32);
        return img;
    }
    default:
    {
        return QImage();
    }
    }
}

/**
 * @brief 槽函数
 * @param
 */
void MainWindow::on_m_btn_open_file_clicked()
{
    QString str = QFileDialog::getOpenFileName(this, "视频文件", "./", "视频文件(*)");
    if(str.isNull()) return;

    ui->m_line_url->setText(str);
}

/**
 * @brief 槽函数
 * @param
 */
void MainWindow::on_m_btn_play_clicked()
{
    if(!m_cap->isOpened())
    {
        QString url = ui->m_line_url->text();
        if(url.isEmpty()) return;
        bool ret = m_cap->open(url.toStdString());
        if(ret)
        {
            ui->m_btn_play->setText("停止");
        }
    }
    else
    {
        if(m_cap){
            m_cap->release();
        }
        ui->m_btn_play->setText("播放");
    }
}

