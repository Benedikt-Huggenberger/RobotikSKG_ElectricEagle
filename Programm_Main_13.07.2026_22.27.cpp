//||
/*#include <Wire.h>
#include <utility/imumaths.h>
#include "Ultrasonic.h"*/
#include "math.h"

int Punkte_X[4];
int Punkte_Y[4];
int sensor = 0;
int AB1 = 0;
int AB2 = 0;
int AB3 = 0;
int AB4 = 0;
int AB_Sensoren = 100;      //mm
int AB_Feld_x = 0;
int AB_Feld_y = 0;
//ultrasonic.MeasureInCentimeters();
Ultrasonic ultrasonic1(46);
Ultrasonic ultrasonic2(48);
Ultrasonic ultrasonic3(50);
Ultrasonic ultrasonic4(52);
int niedrigwert;
int werte[15];
int naechster = 0;
int vorheriger = 0;
int prev_x = 0;
int prev_y = 0;

void main() {
    return 0;
}

void Regressionsgerade() {

    int n = 5;
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX  += Punkte_X[i];
        sumY  += Punkte_Y[i];
        sumXY += Punkte_X[i] * Punkte_Y[i];
        sumX2 += Punkte_X[i] * Punkte_X[i];
    }

    // Steigung b und y-Achsenabschnitt a: y = a + b*x
    double b = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double m = (sumY - b * sumX) / n;



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


double Diff_sensoren(bool größer) {
    if (größer == true) {
        return (double)werte[naechster] / werte[vorheriger];
    }
    else{
        return (double)werte[vorheriger] / werte[naechster];
    }
}

double Winkel_Genau(){                                    //checken welcher sensor von den beiden benachtbarten näher ist
    naechster = (sensor + 1) % 16;
    vorheriger = (sensor - 1 + 15) % 16;

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

void Pos_Ball(int ABS_Ball, int ) {
}