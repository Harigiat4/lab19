/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/PCD/Desktop/IOTEngineering/Labs/lab19/src/lab19.ino"
#include "WatchDog_WCL.h"
#include "oled-wing-adafruit.h"

void setup();
void loop();
#line 4 "c:/Users/PCD/Desktop/IOTEngineering/Labs/lab19/src/lab19.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

OledWingAdafruit display;
WatchDog wd;

void setup()
{
  pinMode(D5, INPUT);
  wd.initialize(5000);

  display.setup();
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  if (System.resetReason() == RESET_REASON_WATCHDOG)
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("You did not pet");
    display.display();
  }
  else
  {
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 0);
    display.println("Normal");
    display.display();
  }
}

void loop()
{
  if (digitalRead(D5) == HIGH)
  {
    wd.pet();
  }
}