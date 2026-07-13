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

int main() {
    return 0;
}

int Winkel_Genau(){                                      //checken welcher sensor von den beiden benachtbarten näher ist
    if(werte[sensor + 1] < werte[sensor - 1]) {          //gegen uhrzeigersinn größer
        Diff_sensoren(true);
    }
    else if(werte[sensor + 1] > werte[sensor - 1]) {     //im uhrzeigersinn größer

    }
    else {
        return(sensor*22,5);
    }
}

int Diff_sensoren(bool größer) {
    if (größer == true) {
        return((werte[sensor + 1]/werte[sensor - 1])*100);
    }
    else if (größer == false) {
        return((werte[sensor - 1]/werte[sensor])*100);
    }
}