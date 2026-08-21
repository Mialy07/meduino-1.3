#ifndef LED_H
#define LED_H

#include <Arduino.h>

class Led {
  private:
    int pin, state;

  public:
    Led();
    void setPin(int numero);
    ~Led();
    void init();
    void allumer();
    void eteindre();
    void blink(int fois = 5, double delai = 500);
    int getPin();
};

#endif
