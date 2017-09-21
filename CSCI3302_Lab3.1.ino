#include <sparki.h>

struct Array{
  
};
double pi = 3.14159265359;
double r = 0.0258;
double d = 0.0841;

int MapArray[4][4] = {{0, 0, 1, 1},
                      {1, 0, 1, 0},
                      {0, 0, 1, 0},
                      {1, 1, 0, 0}};
  
double x_velocity;
double theta_velocity;
  
double phi_r;
double phi_l;
double x_r = 0; // X coordinate on global plane
double y_r = 0; // Y coordinate on global plane
double theta_r = 0; // Rotation angle (yaw) on global plane 

void setup() {
  // put your setup code here, to run once:
sparki.servo(SERVO_CENTER);
/*struct Array * map[4][4];
Array * temp[][];
for(int i = 0; i < 4; i++){
  for(int j = 0; j < 4; j++){
    //struct Array *temp;
    temp = &map[i][j];
    sparki.clearLCD(); 
    sparki.print(*map[i][j]); 
    sparki.updateLCD();
    }
  }*/
}

int Index_assignment(int x, int y){
  int number;
  for(int i = 0; i < x; i++){
    for(int j = 0; j < y; j++){
      number++;
    }
    if(x == y){
      return number;
    }
  }
}
int data_structure(int MapSize){
  int Map[0][0];
  for(int i = 0; i < MapSize; i++){
    for(int j = 0; j < MapSize; j++){
      Map[i][j];
    }
  }
}

int TwoD_Coordinate(int index[], int coor_x, int coor_y){
  for(int i = 0; i < 16; i++){
    coor_y = index[i]/5;
    coor_x = 3 - (index[i] % 4);
  } 
}

int costIndex(int Curr_index, int End_index, int cost, int obstacle){
  if (End_index - Curr_index == abs(1) || abs(4) && obstacle == 0){
    cost = 1;
  }else{
    cost = 99;
  }
}

void loop() {
sparki.clearLCD();
sparki.print("1 0r 0: ");
sparki.println(MapArray[2][4]);
sparki.updateLCD();
}
