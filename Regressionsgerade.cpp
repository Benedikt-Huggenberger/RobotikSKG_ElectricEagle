//||
/*#include <Wire.h>
#include <utility/imumaths.h>
#include "Ultrasonic.h"*/
#include "math.h"

int Punkte_X[4];
int Punkte_Y[4];

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