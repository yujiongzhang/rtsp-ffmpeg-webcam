#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_open_rtsp_clicked();

    void on_close_rtsp_clicked();

private:
    Ui::MainWindow *ui;

    QString ipaddress;

//    QString urls;
};
#endif // MAINWINDOW_H
