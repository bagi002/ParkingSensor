#include <parkingIN.h>
#include <parkingSE.h>
#include <Arduino.h>


Interfejs::Interfejs(int zelena, int zuta1, int zuta2, int crvena,int zvucnik){
    this->zelena = zelena;
    this->zuta1 = zuta1;
    this->zuta2 = zuta2;
    this->crvena = crvena;
    this->zvucnik = zvucnik;
    daljina = SIGURNA;

    pinMode(zelena, OUTPUT);
    pinMode(zuta1, OUTPUT);
    pinMode(zuta2, OUTPUT);
    pinMode(crvena, OUTPUT);
    pinMode(zvucnik, OUTPUT);

    digitalWrite(zelena, LOW);
    digitalWrite(zuta1, LOW);
    digitalWrite(zuta2, LOW);
    digitalWrite(crvena, LOW);
    digitalWrite(zvucnik, LOW);

}

void Interfejs::azuriraj(udaljenost x){
    digitalWrite(zelena, LOW);
    digitalWrite(zuta1, LOW);
    digitalWrite(zuta2, LOW);
    digitalWrite(crvena, LOW);
    daljina = x;
    switch (x)
    {
    case SIGURNA:
        digitalWrite(zelena, HIGH);
        break;
    case PREPREKA:
        digitalWrite(zuta1, HIGH);
        break;
    case BLIZU:
        digitalWrite(zuta2, HIGH);
        break;
    case UDAR:
        digitalWrite(crvena, HIGH);
        break;
    default:
        break;
    }
}

void Interfejs::sviraj(int x){
    digitalWrite(zvucnik, zvuk[daljina][x]);
}