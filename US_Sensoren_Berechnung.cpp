//||
/*#include <Wire.h>
#include <utility/imumaths.h>
#include "Ultrasonic.h"*/
#include "math.h"

int sensor = 0;
int AB1 = 0;
int AB2 = 0;
int AB3 = 0;
int AB4 = 0;
int AB_Sensoren = 100;      //mm
float Roboter_x = 0;
float Roboter_y = 0;
int prev_x = 0;
int prev_y = 0;
//ultrasonic.MeasureInCentimeters();
Ultrasonic ultrasonic1(46);
Ultrasonic ultrasonic2(48);
Ultrasonic ultrasonic3(50);
Ultrasonic ultrasonic4(52);

int main() {
    return 0;
}

void FeldMessen() {
    AB_Feld_x = (AB1 + AB3 + AB_Sensoren);
    AB_Feld_y = (AB2 + AB4 + AB_Sensoren);
}
void US_lesen() {
    AB1 = ultrasonic1.MeasureINCentimeters();
    AB2 = ultrasonic2.MeasureINCentimeters();
    AB3 = ultrasonic3.MeasureINCentimeters();
    AB4 = ultrasonic4.MeasureINCentimeters();
}
int ABS_X() {
    if (!(AB_Feld_x - (AB1 + AB3+ AB_Sensoren)<220 && AB_Feld_x - (AB1 + AB3+ AB_Sensoren)>20)) {
        return AB3+AB_Sensoren/2;
        prev_x = AB3+AB_Sensoren/2;
    }
    else {
        return prev_x;
    }
}
int ABS_Y() {
    if (!(AB_Feld_x - (AB2 + AB4+ AB_Sensoren)<20 && AB_Feld_x - (AB2 + AB4+ AB_Sensoren)>20)) {
        return AB2+AB_Sensoren/2;
        prev_y = AB4+AB_Sensoren/2;
    }
    else {
        return prev_y;
    }
}
int Target(){
    int k = 60;                                                     //Variabler Tuning faktor
    float fahrtWinkel = (sensor*22.5) + k * sin(sensor*22.5);
    return(fahrtWinkel);
}