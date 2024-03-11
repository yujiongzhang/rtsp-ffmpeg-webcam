#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //初始化  设置预置的用户名密码；
    ui->url_edit->setText("192.168.1.168:8554/0");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_open_rtsp_clicked()
{
    QString urls;

    ipaddress = ui->url_edit->text();


    // 使用水下摄像头则使用以下固定的 RTSP码流格式
    // rtsp://192.168.1.168:8554/0
    // rtmp://192.168.1.168:1935/live/ls_00_0

    urls.append("rtsp://");
    urls.append(ipaddress);

//    urls.append("rtmp://192.168.1.168:1935/live/ls_00_0");

    qDebug() << "RTSP URL is:" << urls;

    QString url = urls.trimmed();
    ui->playwidget->setUrl(url);
    ui->playwidget->open();


}

void MainWindow::on_close_rtsp_clicked()
{
    ui->playwidget->close();
}
