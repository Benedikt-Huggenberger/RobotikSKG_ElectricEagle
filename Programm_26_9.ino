#include <Wire.h>
#include <Motoron.h>
#include <CD74HC4067.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_BNO055.h>
#include <utility/imumaths.h>

const int controlPins[] = {2, 3, 4, 5};  // S0–S3
const int enablePin = 6;  // \overline{E}
const int sigPin = A0;   // SIG (Z)

Adafruit_BNO055 bno = Adafruit_BNO055(55);  //SCL ist A15 sda A 14

int sensor [16] ;
int ballposition = sensor[0];
int ball_position;
int magnetsensor;

CD74HC4067 my_mux(4, 5, 6, 7); 

MotoronI2C motoron;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  


  if (!bno.begin()) {
    Serial.println("BNO055 nicht gefunden!");
    /*while (1);*/
  }

  Serial.println("Motoron reinitialisieren...");
  motoron.reinitialize();

  delay(100);



  // Safe Start global deaktivieren
  Serial.println("Safe Start deaktivieren...");
  motoron.clearResetFlag();  // ✅ KEIN Parameter!

  delay(100);

  for (int i = 0; i < 4; i++) {
    pinMode(controlPins[i], OUTPUT);
  }
  pinMode(enablePin, OUTPUT);
  pinMode(sigPin, INPUT);
  digitalWrite(enablePin, LOW);
   delay(1000);
  bno.setExtCrystalUse(true);


}

void loop() { 

       sensors_event_t event;
       bno.getEvent(&event);
        float heading = event.orientation.x;
        Serial.print(heading);                                        //Drehen je 90 Grad ca. 153.25ms delay bei 800         306.5ms delay bei 400 nicht ganz

      
      V(800);
      delay(450);
      DL(800);
      delay(75);
      Stop();
      V(800);
      delay(350);
      DR(800);
      delay(100);
      Stop();
      /*V(800);
      delay(150);
      DR(800);
      delay(75);
      V(800);
      delay(400);
      DL(800);
      delay(75);
      V(800);
      delay(200);*/
      Stop();
      delay(1000000);
}
    void V(int power){                              //Geradeaus
      Serial.println("Geradeaus");
      motoron.setSpeed(1,power);
      motoron.setSpeed(3,-power);

      

}
    void DR(int power){                               //Rechts Drehen
      Serial.println("Drehen Rechts");
      motoron.setSpeed(1,-power);
      motoron.setSpeed(2,-power);
      motoron.setSpeed(3,-power);

}
    void Stop(){        
      Serial.println("Stop");
      motoron.setSpeed(1,0);
      motoron.setSpeed(2,0);
      motoron.setSpeed(3,0);

    }
    void DL(int power){                             //Links Drehen
      Serial.println("Drehen Links");
      motoron.setSpeed(1,power);
      motoron.setSpeed(2,power);
      motoron.setSpeed(3,power);

}
    void H(int power){                            //Rückwärts
      Serial.println("Hinten");
      motoron.setSpeed(1,power);
      motoron.setSpeed(3,-power);

    }

    void L(int power){                                      //Links fahren
    Serial.println("Links");
    motoron.setSpeed(2,-power);
    /*motoron.setSpeed(1,-power/6);
    motoron.setSpeed(3,power/2);
    */

    }

    void R(int power){                                      //Links fahren
    Serial.println("Rechts");
    motoron.setSpeed(2,power);
    motoron.setSpeed(1,-power/3);

    }

    void mux()
    {
      for(int i = 0 ; i < 16; i++){
          my_mux.channel(i);
          int value = analogRead(sigPin);  // Liest das Signal vom ausgewählten Kanal
          delay(.5);
      }

    }

  

  

 

 
