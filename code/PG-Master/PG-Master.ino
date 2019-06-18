//#include "Pint.ino"
#include <Pixy.h>
#include <Wire.h>
#include <SPI.h>
#include <math.h>
#include <EEPROM.h>
//#include "Adafruit_VL53L0X.h"
//#include <Adafruit_Sensor.h>
//#include <Adafruit_BNO055.h>
//#include <utility/imumaths.h>
Pixy pcam;
IntervalTimer myTimer;
#define Buzzer 21
#define Shoot 10
#define PWMlf 38
#define digitalPINlf 39
#define PWMlb  14
#define digitalPINlb  37
#define PWMrf  2
#define digitalPINrf 8
#define PWMrb  7
#define digitalPINrb  6
//Adafruit_VL53L0X lox = Adafruit_VL53L0X();
//Adafruit_BNO055 bno = Adafruit_BNO055(55);
//adafruit_bno055_offsets_t calibrationData;
//sensors_event_t event;
//adafruit_bno055_offsets_t newCalib;
float GYa, GBa, reduction = 0, mamadagha;
int FO, FI, RO, RI, BO, BI, LO, LI, NFO, NFI, NRO, NRI, NBO, NBI, NLO, NLI;
int Ba, DShift, BA, BC, Bx, By, DistanceB, GYx, GYy, DistanceGY, GBx, GBy, DistanceGB, Gy;
int OS[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0}, OSP[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int Compass = 0, Compass2, Cmp = 0, setcmp = 0, set_s = 0, refresher = 0;
int  i = 0, setbno, dis_back, Shootflag = 0, bnox, eeAddress = 25, Calibrate_BNO = 0, SHC = 0, yell;
bool fa = 0, fb = 0, ra = 0, rb = 0, ba = 0, bb = 0, la = 0, lb = 0, goalieTeach, Ball;
bool flag = true, south = false;
int  BAxcenter, BayCenter, k, shif;
void setup() {
  //------------VL53L0X_d----------------
  //  lox.begin();
  //------------start_robot--------------
  myTimer.begin(Counter, 100000);
  Serial.begin(9600);
  Serial5.begin(9600);
  pcam.init();
  Wire2.begin();
  set_pins();
  eeprom_read();
}

void loop() {
  SET();
  OC();
  col_ang();
  if (Ball) fallout();
  else STOP();
  //chop();
}
