#include <sparki.h>

  double pi = 3.14159265359;
  double r = 0.0258;
  double d = 0.0841;

  double x_velocity;
  double theta_velocity;
  
  double phi_r;
  double phi_l;
  
  double x_r = 0; // X coordinate on global plane
  double y_r = 0; // Y coordinate on global plane
  double theta_r = 0; // Rotation angle (yaw) on global plane 
  
  double x_target = 0.20;
  double y_target = 0.20;
  double theta_target = pi/4;

void setup() {
  // put your setup code here, to run once:
  sparki.servo(SERVO_CENTER);
}

void loop() {
  // put your main code here, to run repeatedly:
/*
 * 
- calculate x_r and theta_r using the control law based on the current position
------------
- calculate the equivalent robot speeds
- use the speeds to do odometry

This way you have to change the code underneath the ----- ever again.
 */

  unsigned long Time1 = millis();

  x_velocity = 0.1*sqrt((pow((x_r - x_target),2))+(pow((y_r - y_target),2)));
  theta_velocity = (2*(theta_r-(pi+(atan2((y_r-y_target),(x_r-x_target))))))
    +(0.1*(theta_target - theta_r));
  //theta_velocity = (1*(theta_r-(pi+(atan2((x_r-x_target),(y_r-y_target))))))
    //+(0.1*(theta_target - theta_r));

  phi_r = ((2*x_velocity/r)+(theta_velocity*d))/2; 
  phi_l = ((2*x_velocity/r)-(theta_velocity*d))/2;  

  y_r = y_r + .1*(((phi_l*0.028)+(phi_r*0.028))/2)*sin(theta_r);
  x_r = x_r + .1*(((phi_l*0.028)+(phi_r*0.028))/2)*cos(theta_r);  
  theta_r = theta_r + (((phi_l*0.73)-(phi_r*0.73))/2)*0.1;

  if ((phi_l*100) >= 0){
    sparki.motorRotate(MOTOR_LEFT, DIR_CCW, (phi_l*100));    
  }
  else{
    sparki.motorRotate(MOTOR_LEFT, DIR_CW, abs(phi_l*100));
  }
  if ((phi_r*100) >= 0){
    sparki.motorRotate(MOTOR_RIGHT, DIR_CW, (phi_r*100));    
  }
  else{
    sparki.motorRotate(MOTOR_RIGHT, DIR_CCW, abs(phi_r*100));
  }

  sparki.clearLCD();
  sparki.print("X: ");
  sparki.println(x_r*100);
  sparki.print("Y: ");
  sparki.println(y_r*100);
  sparki.print("alpha: ");
  sparki.println((theta_r-(pi+(atan2((y_r-y_target),(x_r-x_target)))))*(180/pi));
  sparki.print("theta: ");
  sparki.println(theta_r*(180/pi));
  sparki.print("left wheel: ");
  sparki.println(phi_l*100);
  sparki.print("right wheel: ");
  sparki.println(phi_r*100);
  unsigned long Time2 = millis();
  unsigned long loopTime = Time2-Time1;
  delay(100-loopTime); //wait 100 ms including code execution
  sparki.updateLCD();
}
