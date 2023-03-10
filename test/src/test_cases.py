#!/usr/bin/env python3
import unittest
import rostest
import rospy
from std_msgs.msg import String
from time import sleep

class SheebTest(unittest.TestCase):

    tested_variable = False

    def callback(self, data):                   #callback function if initiated turns variable True
        self.tested_variable = True
    
    def test_run(self):
        rospy.init_node('test_cases')
        rospy.Subscriber('/chatter', String, self.callback)             #/chatter can be changed to the topic desired for testing, String can be changed to data sturcture data structure

        #whatever we want to test here
        #The tested_variable should change to TRUE for the test to return Success you can use the callback function
        
        counter = 0
        while not rospy.is_shutdown() and counter < 5 and (not self.tested_variable):           #adjust counter for number of seconds
            sleep(1)
            counter = counter + 1
            
        self.assertTrue(self.tested_variable)       #if tested_variable is TRUE, Test succeeds
        
        
        
if __name__ == '__main__':
    rostest.rosrun('test', 'test_cases', SheebTest)         #'test' can be changed 

