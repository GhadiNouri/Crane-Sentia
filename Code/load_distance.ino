#include <Arduino.h>
#include "HX711.h"

HX711 scale;

#define DOUT 2
#define SCK 3
#define BZ 7
#define Buz 10
#define Echo 12
#define Trig 13

long SW; //variable for the duration of sound wave travel
int Area; //variable for the distance measurement

void setup() {
  Serial.begin(57600);
  Serial.println("HX711 Demo");
  Serial.println("Initializing the scale");

  scale.begin(DOUT, SCK);

  Serial.println("Before setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());      // print a raw reading from the ADC

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);  // print the raw reading from the ADC divided by the SCALE parameter

  scale.set_scale(1.0 / 100);
  scale.tare();               // reset the scale to 0

  Serial.println("After setting up the scale:");
  Serial.print("read: \t\t");
  Serial.println(scale.read());                 // print a raw reading from the ADC

  Serial.print("get units: \t\t");
  Serial.println(scale.get_units(5), 1);        // print the raw reading from the ADC divided by the SCALE parameter set with set_scale

  Serial.println("Readings:");

  pinMode(BZ, OUTPUT);
  digitalWrite(BZ, LOW);
}

void Measurment() {
  pinMode(Echo, INPUT); //set echo as input
  pinMode(Trig, OUTPUT); //set trig as output
  digitalWrite(Trig, LOW); //clear the trig
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH); // set the trig active at 10 milli
  delayMicroseconds(10);
  digitalWrite(Trig, LOW); 

  SW = pulseIn(Echo, HIGH); //(pin, mode, timeout in microsec)
  Area = (SW * 0.034) / 2; //convert the sound wave to cm distance

  Serial.print("Distance is: ");
  Serial.print(Area);
  Serial.println(" cm");
}

void SaftyTrack() {
  // Safty = not less than 2m, represented by 20cm
  // Middle = between 2m & 4m, represented by 40cm
  // Best = more than 6m, represented by 60cm
 
  if (Area <= 20) {
    // Dangerous, leave a space!
    tone(Buz, 1000);
  } else if (Area >= 21 && Area <= 59) {
    // Be careful, you're near
    tone(Buz, 3000);
  } else {
    // We're good at this distance
    noTone(Buz);
  }
  
  delay(1000);
}

void loop() {
  float Value = scale.get_units();

  Serial.print(" Scale Value:\t");
  Serial.println(Value, 1);
  if(Value>1000.0)// Value>1kg
  {
    digitalWrite(BZ,HIGH);//turn the buzzer on
  }else {
    digitalWrite(BZ, LOW); //turn the buzzer off
  }
  
  Measurment();
  SaftyTrack();

  delay(1000);
}