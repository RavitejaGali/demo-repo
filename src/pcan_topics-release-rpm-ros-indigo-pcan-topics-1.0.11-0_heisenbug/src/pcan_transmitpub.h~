#ifndef PCAN_TRANSMITPUB_H
#define PCAN_TRANSMITPUB_H

#include <QMainWindow>
#include <QApplication>
#include <QVBoxLayout>
#include <QSlider>
#include <QLineEdit>
#include <QMessageBox>
#include <QDebug>
#include<ros/ros.h>
#include<std_msgs/String.h>

class MainWindow: public QMainWindow {
    Q_OBJECT
    QSlider *slider;
    QLineEdit *lineEdit;
    int value;


public:
    MainWindow();


    ~MainWindow();
public slots:
      void onValueChanged(int value);
//void ros_init();

//private:

    //void display();
};
#endif

