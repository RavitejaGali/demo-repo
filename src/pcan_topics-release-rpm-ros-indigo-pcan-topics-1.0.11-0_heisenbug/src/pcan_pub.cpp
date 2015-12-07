#include<iostream>
#include"ros/ros.h"
#include"std_msgs/String.h"
#include<sstream>
using namespace std;

//Increment Function
int inc(int a){
return a++;}

int main(int argc, char **argv)
{
ros::init(argc,argv,"pcan_pub");
ros::NodeHandle n;
ros::Publisher pcantransmitted_pub= n.advertise<std_msgs::String>("pcan_transmitted",1000);
ros::Rate loop_rate(100);
int count=0;
while(ros::ok())

{
int a=0;
char c;
for(int i=0;i<=100; i++){
cin>>c;
if(c=='k')
a=inc(i);
std_msgs::String msg;
stringstream ss, id, len, canmsg;
ss<<hex<<a;
cout<<ss.str()<<endl;
id<<"0x01 ";
len<<"0x01 ";
canmsg<<id.str()+len.str()+"0x"+ss.str();
cout<<canmsg.str()<<endl;
msg.data=canmsg.str();
pcantransmitted_pub.publish(msg);
ros::spinOnce();
loop_rate.sleep();
}

count++;}
return 0;
}
