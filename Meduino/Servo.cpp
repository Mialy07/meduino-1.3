#include "Servo.h"
#include <Arduino.h>
void bouge(int vitesse,int angle_initial,int angle_final,Servo monServo)
{
  unsigned long dernierMouvement = 0;
  if (millis() - dernierMouvement >= vitesse) 
  {
    dernierMouvement = millis();
    if (angle_initial <= angle_final) 
    {
      angle_initial++;
      monServo.write(angle_initial);
    } 
    else if (angle_initial >= angle_final) 
    {
      angle_initial--;
      monServo.write(angle_initial);
    }
  }
}
