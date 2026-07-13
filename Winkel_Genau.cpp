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
int AB_Feld_x = 0;
int AB_Feld_y = 0;
int niedrigwert;
int werte[15];
int naechster = 0;
int vorheriger = 0;

int main() {
    return 0;
}


double Diff_sensoren(bool größer) {
    if (größer == true) {
        return (double)werte[sensor + 1] / werte[sensor - 1];
    }
    else if (größer == false) {
        return (double)werte[sensor - 1] / werte[sensor - 1];
    }
}

double Winkel_Genau(){                                    //checken welcher sensor von den beiden benachtbarten näher ist
    int naechster = (sensor + 1) % 15;
    int vorheriger = (sensor - 1 + 15) % 15;
    if(werte[naechster] < werte[vorheriger]) {          //gegen uhrzeigersinn größer
        return((sensor * 22.5)+(Diff_sensoren(true)*22.5));
    }
    else if(werte[naechster] > werte[vorheriger]) {     //im uhrzeigersinn größer
        return((sensor * 22.5)-(Diff_sensoren(true)*22.5));
    }
    else {
        return(sensor*22.5);
    }
}

