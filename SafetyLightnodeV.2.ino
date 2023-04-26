#include <ros.h>
#include <std_msgs/Bool.h>

#define SafetyLightPIN 13

ros::NodeHandle nh;

std_msgs::Bool autonomous_mode_msg;               //autonomous_mode_msg is either True or false(autonomous mode or not)


void autonomousModeCallback(const std_msgs::Bool& msg)      //Callback function that gets data msg from topic  
{
  autonomous_mode_msg = msg;
}

ros::Subscriber<std_msgs::Bool> autonomousmode_subscriber("autonomous_mode", &autonomousModeCallback);    //subscribe to topic and call callback function

void setup()
{
  pinMode(SafetyLightPIN, OUTPUT);  //set up pin to output 

  nh.initNode();
  nh.subscribe(autonomousmode_subscriber);      //Intialize node and subscriber
}

void loop()
{

  if (nh.connected() && autonomous_mode_msg.data)     //if ros is connected and autonomous_mode_msg.data is True
  {
    digitalWrite(SafetyLightPIN, HIGH); // Set output to HIGH
  }
  else
  {
    digitalWrite(SafetyLightPIN, LOW); // Set output to LOW
  }

  nh.spinOnce();
  delay(100);
}
