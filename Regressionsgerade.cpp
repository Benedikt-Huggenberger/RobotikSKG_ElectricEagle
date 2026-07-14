//||
/*#include <Wire.h>
#include <utility/imumaths.h>
#include "Ultrasonic.h"*/
#include "math.h"
#include "iostream"

float Punkte_X[] = {1.0, 2.0, 3.0, 4.0, 5.0};
float Punkte_Y[] = {1.1, 1.9, 3.2, 3.8, 5.1};

void Regressionsgerade() {

    int n = 5;
    double sumX = 0, sumY = 0, sumXY = 0, sumX2 = 0;

    for (int i = 0; i < n; i++) {
        sumX  += Punkte_X[i];
        sumY  += Punkte_Y[i];
        sumXY += Punkte_X[i] * Punkte_Y[i];
        sumX2 += Punkte_X[i] * Punkte_X[i];
    }

    double m = (n * sumXY - sumX * sumY) / (n * sumX2 - sumX * sumX);
    double b = (sumY - m * sumX) / n;

    std::cout << "Geradengleichung: y = " << m << " * x + " << b << std::endl;

}

int main() {
    Regressionsgerade();
    return 0;
}