#include "robowebtools/robowebtools.hpp"

int main(int argc, char **argv)
{  
  ros::init(argc, argv, "robowebtools");
  ros::NodeHandle n;
  
  //ros::Subscriber sub = n.subscribe<std_msgs::UInt8>("/reset", 100, &countCallback);
  ros::Publisher pub = n.advertise<std_msgs::Int8>("/update", 1);
  std_msgs::Int8 msg;
  
  int  temp = 0;
  
  
  while(ros::ok())
  {    
    ros::spinOnce();
    
    std::cout << "How much do you want to add? ";
    std::cin >> temp;
    
    msg.data = temp;
    pub.publish(msg);
  }
  
  return 0;
}
