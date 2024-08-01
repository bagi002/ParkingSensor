#include <Arduino.h>
#include <parkingSE.h>
#include <parkingIN.h>
#include <TimerOne.h>


int echo = 10;
int trig = 9;

int i = 0;

  bool ocitavanje = false;
  bool interfejs = false;

ParkingSE senzor(trig, echo);
Interfejs inter(4, 5, 6, 7, 8);

void brojac(){
  i++;

}

void obradaProlaza(){

  if(i%2 == 0){
    ocitavanje = true;
  }

  if(i%8 == 0){
    interfejs = true;
  }
}

void setup() {
  Serial.begin(9600);
  Timer1.initialize(20000);
  Timer1.attachInterrupt(brojac);
}

void loop() {
  obradaProlaza();

  if(ocitavanje){
    ocitavanje = false;
    senzor.ocitaj();
  }

  if(interfejs){
    interfejs = false;
    inter.azuriraj(senzor.getStanje());
  }
}


