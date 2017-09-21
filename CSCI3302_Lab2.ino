#include <sparki.h>
unsigned long time;


  double x = 0; // move left or right directions
  double y = 0; //move forward or backward  
  double theta = 0;
  double wr = 5/2; 
  double vel;
  double phi;
  double phi2;
  double pi = 3.14159265359;   

void setup() 
{
  sparki.servo(SERVO_CENTER);
  
  vel = 2.8;//x/(Time/1000);
  phi2 = 42;
  
 //calculate the angular rotation (phi) by measuring a 2pi wheel rotation
}

void loop() {
  unsigned long Time1 = millis();
  
  if ((theta > 360) && (abs(x) < 0)){
    sparki.moveStop();
    sparki.print("X: "); //left line sensor on screen
    sparki.println(x);
    sparki.print("Y: "); //center line sensor on screen
    sparki.println(y);
    sparki.print("Movement: "); //right line sensor on screen
    sparki.println(theta);
    
    delay(50000);
  }
  
  int threshold = 800;
  
  int lineLeft   = sparki.lineLeft(); // measure the left IR sensor
  int lineCenter = sparki.lineCenter(); // measure the center IR sensor
  int lineRight  = sparki.lineRight();  // measure the right IR sensor

  if( lineCenter < threshold ) // if line is below left line sensor
  {  
    sparki.moveForward();
    y = y + .1*vel*sin(theta*(pi/180));
    x = x + .1*vel*cos(theta*(pi/180));
  }
  else{
    if( lineLeft < threshold ) //if line is below left line sensor
    {  
      sparki.moveLeft();
      theta = theta - .1*(phi2);  
    }
  
    if( lineRight < threshold ) //if line is below right line sensor
    { 
      sparki.moveRight();
      theta = theta + .1*(phi2);
    }
  }
  
  sparki.clearLCD();
  
 
  sparki.print("X: ");
  sparki.println(x);
  sparki.print("Y: "); 
  sparki.println(y);
  sparki.print("Movement: "); 
  sparki.println(theta);
  unsigned long Time2 = millis();
  unsigned long delayTime = Time2-Time1;
  delay(100-delayTime); //wait 100 ms including code execution
  sparki.updateLCD();
}


