//||
#include <Wire.h>
#include <utility/imumaths.h>
#include "Ultrasonic.h"

int AB1 = 0;
int AB2 = 0;
int AB3 = 0;
int AB4 = 0;
int AB_Sensoren = 100;      //mm
int AB_Feld_x = 1100;
int AB_Feld_y = 1800;

Ultrasonic ultrasonic1(46);
Ultrasonic ultrasonic2(48);
Ultrasonic ultrasonic3(50);
Ultrasonic ultrasonic4(52);

if