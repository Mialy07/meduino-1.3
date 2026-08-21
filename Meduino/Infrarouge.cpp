#include "Infrarouge.h"

Infrarouge::Infrarouge() {}

void Infrarouge::setPin(int numero_pin) {
  this->pin = numero_pin;
  this->setMode(INPUT);
}

void Infrarouge::setMode(int mode) {
  pinMode(this->pin, mode);
}

int Infrarouge::getValue() {
  this->valeur = digitalRead(this->pin);
  return this->valeur;
}

Infrarouge::~Infrarouge() {}
