#include <ros.h>
#include <ros/param.h>

#define SafetyLightPIN 13

ros::NodeHandle nh;

bool vehicle_status = false               //vehicle_status parameter is either True or false(autonomous mode or not)


void setup()
{
  pinMode(SafetyLightPIN, OUTPUT);  //set up pin to output 

  nh.initNode();
}

void loop()
{

  if (nh.connected() && nh.getParam("vehicle_status", vehicle_status))     //if ros is connected and vehicle status parameter is True
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
