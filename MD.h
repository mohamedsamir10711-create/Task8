#ifndef MOTOR_DRIVERS_H
#define MOTOR_DRIVERS_H

#include <Arduino.h>

class L298N {
  private:
    int pinIN1, pinIN2, pinENA;
  public:
    L298N(int in1, int in2, int ena);
    void begin();
    void drive(int speed);
    void stop();
};

class CytronMD {
  private:
    int pinDIR, pinPWM;
  public:
    CytronMD(int dir, int pwm);
    void begin();
    void drive(int speed);
    void stop();
};

class BTS7960 {
  private:
    int pinRPWM, pinLPWM;
  public:
    BTS7960(int rpwm, int lpwm);
    void begin();
    void drive(int speed);
    void stop();
};

#endif