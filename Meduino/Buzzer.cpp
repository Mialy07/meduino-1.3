#include "Buzzer.h"

Buzzer::Buzzer() {}

void Buzzer::setPin(int numero_pin) {
  this->pin = numero_pin;
  init();
}

void Buzzer::init() {
  pinMode(this->pin, OUTPUT);
}

void Buzzer::sonner(int note, int duree) {
  tone (this->pin, note, duree);
}

Buzzer::~Buzzer() {}
