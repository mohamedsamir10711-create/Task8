#include "MD.h"

//L298N Implementation 
L298N::L298N(int in1, int in2, int ena) {
  pinIN1 = in1;
  pinIN2 = in2;
  pinENA = ena;
}
void L298N::begin() {
  pinMode(pinIN1, OUTPUT);
  pinMode(pinIN2, OUTPUT);
  pinMode(pinENA, OUTPUT);
  stop();
}
void L298N::drive(int speed) {
  speed = constrain(speed, -255, 255);
  if (speed > 0) {
    digitalWrite(pinIN1, HIGH);
    digitalWrite(pinIN2, LOW);
    analogWrite(pinENA, speed);
  } else if (speed < 0) {
    digitalWrite(pinIN1, LOW);
    digitalWrite(pinIN2, HIGH);
    analogWrite(pinENA, -speed);
  } else {
    stop();
  }
}
void L298N::stop() {
  digitalWrite(pinIN1, LOW);
  digitalWrite(pinIN2, LOW);
  analogWrite(pinENA, 0);
}

//Cytron MD10A Implementation 
CytronMD::CytronMD(int dir, int pwm) {
  pinDIR = dir;
  pinPWM = pwm;
}
void CytronMD::begin() {
  pinMode(pinDIR, OUTPUT);
  pinMode(pinPWM, OUTPUT);
  stop();
}
void CytronMD::drive(int speed) {
  speed = constrain(speed, -255, 255);
  if (speed > 0) {
    digitalWrite(pinDIR, HIGH);
    analogWrite(pinPWM, speed);
  } else if (speed < 0) {
    digitalWrite(pinDIR, LOW);
    analogWrite(pinPWM, -speed);
  } else {
    stop();
  }
}
void CytronMD::stop() {
  analogWrite(pinPWM, 0);
}

//BTS7960 Implementation
BTS7960::BTS7960(int rpwm, int lpwm) {
  pinRPWM = rpwm;
  pinLPWM = lpwm;
}
void BTS7960::begin() {
  pinMode(pinRPWM, OUTPUT);
  pinMode(pinLPWM, OUTPUT);
  stop();
}
void BTS7960::drive(int speed) {
  speed = constrain(speed, -255, 255);
  if (speed > 0) {
    analogWrite(pinLPWM, 0);
    analogWrite(pinRPWM, speed);
  } else if (speed < 0) {
    analogWrite(pinRPWM, 0);
    analogWrite(pinLPWM, -speed);
  } else {
    stop();
  }
}
void BTS7960::stop() {
  analogWrite(pinRPWM, 0);
  analogWrite(pinLPWM, 0);
}