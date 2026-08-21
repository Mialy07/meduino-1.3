#ifndef INFRAROUGE_H
#define INFRAROUGE_H

#include <Arduino.h>

class Infrarouge {
  private:
    int pin;
    int valeur;

  public:
    Infrarouge();
    void setPin(int numero_pin);
    void setMode(int mode = INPUT);
    int getValue();
    ~Infrarouge();
};

#endif
