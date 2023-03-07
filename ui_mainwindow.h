/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QComboBox *m_cmb_cam_name;
    QPushButton *m_btn_open_camera;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QLabel *m_lbl_display;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *m_line_url;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *m_btn_open_file;
    QPushButton *m_btn_play;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1084, 733);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(20, 30, 241, 111));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName("verticalLayout_3");
        m_cmb_cam_name = new QComboBox(groupBox);
        m_cmb_cam_name->setObjectName("m_cmb_cam_name");

        verticalLayout_3->addWidget(m_cmb_cam_name);

        m_btn_open_camera = new QPushButton(groupBox);
        m_btn_open_camera->setObjectName("m_btn_open_camera");
        m_btn_open_camera->setCheckable(true);

        verticalLayout_3->addWidget(m_btn_open_camera);

        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setGeometry(QRect(270, 30, 791, 631));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        m_lbl_display = new QLabel(frame);
        m_lbl_display->setObjectName("m_lbl_display");
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_lbl_display->sizePolicy().hasHeightForWidth());
        m_lbl_display->setSizePolicy(sizePolicy);
        m_lbl_display->setMinimumSize(QSize(320, 320));
        m_lbl_display->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(m_lbl_display);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(20, 150, 241, 131));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        m_line_url = new QLineEdit(groupBox_2);
        m_line_url->setObjectName("m_line_url");

        verticalLayout_2->addWidget(m_line_url);

        frame_2 = new QFrame(groupBox_2);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout = new QHBoxLayout(frame_2);
        horizontalLayout->setObjectName("horizontalLayout");
        m_btn_open_file = new QPushButton(frame_2);
        m_btn_open_file->setObjectName("m_btn_open_file");
        m_btn_open_file->setCheckable(true);

        horizontalLayout->addWidget(m_btn_open_file);

        m_btn_play = new QPushButton(frame_2);
        m_btn_play->setObjectName("m_btn_play");
        m_btn_play->setCheckable(true);

        horizontalLayout->addWidget(m_btn_play);


        verticalLayout_2->addWidget(frame_2);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1084, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        m_btn_open_camera->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        m_lbl_display->setText(QCoreApplication::translate("MainWindow", "TextLabel", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "GroupBox", nullptr));
        m_btn_open_file->setText(QCoreApplication::translate("MainWindow", "\346\211\223\345\274\200", nullptr));
        m_btn_play->setText(QCoreApplication::translate("MainWindow", "\346\222\255\346\224\276", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
