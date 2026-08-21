#include "Led.h"
#include "Buzzer.h"
#include "Servo.h"
#include "Infrarouge.h"

#define PIN1 13
#define PIN2 9

Led led;
Buzzer buzz;
Servo monServo;
Infrarouge ir;
  
void setup() 
{
  Serial.begin(9600);

  led = Led();
  led.setPin(PIN1);
  led.init();

  buzz = Buzzer();
  buzz.setPin(PIN2);
  buzz.init();

  ir.setPin(8);


  monServo.attach(9);
  monServo.write(90);
}

void separation_message(String message,Servo monServo)
{
    int separateur = message.indexOf('+');
    int temps_initial;
    int temps;
    
    if (separateur != -1)
    {
        int boite;
        int quantite;
        boite = message.substring(0, separateur).toInt();
        quantite = message.substring(separateur + 1).toInt();
        led.blink();
        buzz.sonner(400,10000);

        if(boite=1)
        {
          bouge(15,90,0,monServo);
          delay(500);
          bouge(15,0,90,monServo);
          delay(500); 
          Serial.println("niodina ny boite 1");
        }
        else
        {
          bouge(15,90,180,monServo);
          delay(500);
          bouge(15,180,90,monServo);
          delay(500);  
          Serial.println("niodina ny boite 2"); 
        }
        temps_initial=millis(); 
        while(millis()-temps_initial<=1000)
        {
          if(ir.getValue()==1)
          {
            Serial.println("TAKEN");
          }
        }
        Serial.println("Tsy nalainy!!");
    }
}

void loop() 
{
    if (Serial.available())
    {        
        String message = Serial.readStringUntil('\n');
        separation_message(message,monServo);        
    }
    
}
