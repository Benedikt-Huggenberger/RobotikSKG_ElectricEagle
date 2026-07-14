//||
/*#include <Wire.h>
#include <utility/imumaths.h>
#include "Ultrasonic.h"*/
#include "math.h"
#include <iostream>

int sensor = 0;
int AB1 = 0;
int AB2 = 0;
int AB3 = 0;
int AB4 = 0;
int AB_Sensoren = 100;      //mm
float  Roboter_x = 100;
float  Roboter_y = 100;
int ABS_Ball = 14.142;
int Winkel_genau = 45;
float  Ball_x = 0;
float  Ball_y = 0;

void Pos_Ball(int ABS_Ball, int Winkel) {                           //Berechnung Ball Position Abhängig von Position des Roboters
    Ball_x = Roboter_x + cos(Winkel*M_PI/180)*ABS_Ball;
    Ball_y = Roboter_y + sin(Winkel*M_PI/180)*ABS_Ball;
}

int main(){
return 0;
}