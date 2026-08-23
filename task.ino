#include "pins.h"
#include "MD.h"

L298N motorA(L298N_IN1, L298N_IN2, L298N_ENA);
CytronMD motorB(CYTRON_DIR, CYTRON_PWM);
BTS7960 motorC(BTS_RPWM, BTS_LPWM);

void setup() {
  analogWriteResolution(8); 
  motorA.begin();
  motorB.begin();
  motorC.begin();
}

void loop() {
  // Test L298N
  motorA.drive(200); 
  delay(1000);
  motorA.stop();
  delay(1000);
}