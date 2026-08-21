#include "Led.h"

Led::Led() {}

void Led::setPin(int numero) {
  pin = numero;
  init();
}

void Led::init() {
  pinMode(pin, OUTPUT);
}

void Led::allumer() {
  digitalWrite(pin, HIGH);
}

void Led::eteindre() {
  digitalWrite(pin, LOW);
}

void Led::blink(int fois, double delai) {
  for (int i = 0; i < fois; i++) {
    allumer();
    delay(delai);
    eteindre();
    delay(delai);
  }
}

Led::~Led(){}

int Led::getPin() {
  return this->pin;
}
