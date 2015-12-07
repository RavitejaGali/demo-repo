#include "pcan_transmitpub.h"
#include<iostream>
#include<ros/ros.h>
#include<std_msgs/String.h>
#include<string>
#include <sstream>

ros::Publisher pcan_transmit_pub;

MainWindow::MainWindow()
{
    slider = new QSlider(Qt::Horizontal);
    slider->setMinimum(0);
    slider->setMaximum(100);
    lineEdit = new QLineEdit();

    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     this, SLOT(onValueChanged(int)));
  //  ros::init(argc,argv,"pcan_transmitpub");
   // ros::NodeHandle n;
    //ros::Publisher pcan_transmit_pub=n.advertise<std_msgs::String>("pcan_transmitted",1000);


    QVBoxLayout *layout = new QVBoxLayout();
    layout->addWidget(slider);
    layout->addWidget(lineEdit);

    QWidget *wrapper = new QWidget();
    wrapper->setLayout(layout);
    setCentralWidget(wrapper);
}

MainWindow::~MainWindow()
{
}
//void MainWindow::ros_init(){
  //  ros::NodeHandle n;
   // pcan_transmitpub=n.advertise<std_msgs::String>("pcan_transmitted",1000);
//}

void MainWindow::onValueChanged(int value)

{
    int pos = slider->sliderPosition();
    QByteArray convertedValue = QByteArray::number(pos,16);
    QString m = QString(convertedValue);
    m= "0x"+m;
    QString id,len, canmsg;
    id="0x01 ";
    len="0x01 ";
    canmsg=id+len+m;
    //string canmsgrt;
    //canmsgrt=canmsg.toStdString();

/*ros::Rate loop_rate(10);
   // while(ros::ok()){

     // std::stringstream ss;
       //ss<<canmsgrt;
       //canmsgrt.data=ss.str();
       pcantransmit_pub.publish(canmsg);
       ros::spinOnce();
       loop_rate.sleep();*/

    //lineEdit->setText(canmsg);
}



int main(int argc, char *argv[])
{
   // ros_init();
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
