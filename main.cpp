#pragma execution_character_set("utf-8")
#include "mainwindow.h"
#include <QApplication>
#include <QTextCodec>
#include <QDesktopWidget>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTextCodec *codec = QTextCodec::codecForName("utf-8");
    QTextCodec::setCodecForLocale(codec);

    MainWindow w;
    w.show();
    return a.exec();
}
