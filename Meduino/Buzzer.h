#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
  private:
    int pin;
    
  public:
    Buzzer();
    void setPin(int numero_pin);
    void init();
    void sonner (int note, int duree);
    ~Buzzer();
};

#endif
