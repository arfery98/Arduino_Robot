#include <POP32_IO.h>
#include <POP32.h>
#include "Adafruit_TCS34725.h"
#include <Wire.h>

// -------------------------   RGB   ---------------------------------
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_154MS, TCS34725_GAIN_60X);
// ตัวแปรสำหรับเก็บค่าสีที่อ่านได้
struct ColorValue {
  uint16_t r, g, b, c;
};
// กำหนดค่าสีมาตรฐานสำหรับแต่ละสี (ต้องปรับค่าตามการ calibrate จริง)
const ColorValue COLOR_RED = { 22700, 6700, 6025, 32600 };
const ColorValue COLOR_GREEN = { 4600, 8900, 5875, 18350 };
const ColorValue COLOR_BLUE = { 4750, 6450, 8650, 18625 };
const ColorValue COLOR_YELLOW = { 48900, 46500, 16200, 53100 };
const ColorValue COLOR_BLACK = { 3600, 3725, 3600, 9700 };
const ColorValue COLOR_WHITE = { 48900, 55850, 43825, 65525 };

int Speed, SlowSpeed, ACCSpeed, BaseSpeed, LeftBaseSpeed, RightBaseSpeed, TurnSpeed, MaxSpeed, SonarSpeed, DistanceRef, SpeedJC, RobotSpeed, Base;
int LeftSpeed, RightSpeed, LeftSpeedBack, RightSpeedBack;
int TurnSpeedSlow;
int Error, PreError, Kp, Kd, Ki, Kt, BackLeftBaseSpeed, BackRightBaseSpeed, BackLeftBaseSpeedYl, BackRightBaseSpeedYl, TurnSpeed2;
int KpB, KdB, KtB, KiB, Integral;
int RefL2, RefL1, RefC, RefR1, RefR2, RefBL2, RefBL1, RefBR1, RefBR2, SumError;
int L2, L1, C, R1, R2, BL2, BL1, BR1, BR2;
long BaseTimer0, Timer0, BaseTimer1, Timer1, BaseTimer2, Timer2, Timer3, Timer;
int SW_OK_Status, Error99Check = 0, digital_sw = 0;
int KnobBase;
int CanStatus = 0;
int canindex;
int segment;
int s0, s1, s2, s3, nLED, outpin;
int Refs0, Refs1, Refs2, Refs3, RefnLED, Refoutpin;
int R, G, B, Y, BC, W;

int CanSonarRef = 15;  //ระยะเช็คกระป๋อง

int FontSensorNumber = 5, BackSensorNumber = 3;

// ขา A ของ encoder
const int encoderPin = 5;

// ตัวแปรสำหรับนับ pulses
volatile long encoderCount = 0;

// ค่าคงที่สำหรับการคำนวณระยะทาง
const float WHEEL_DIAMETER = 1.8;      // เส้นผ่านศูนย์กลางล้อ (cm)
const int PULSES_PER_REVOLUTION = 20;  // จำนวน pulses ต่อรอบของล้อ


#define No 0
#define Yes 1

#define Mode0 0
#define Mode1 1
#define Mode2 2
#define Mode3 3
#define Mode4 4

#define WheelDrive 1    //0:ขับเคลื่อน 2 ล้อ , 1:ขับเคลื่อน 4 ล้อ
#define SwitchTime 200  //เวลาในการตรวจสอบการกดสวิชในหน่วย ms



int Mode = Mode0;
int PidStatus = 0;  //0:กรณีโค้งน้อยๆ 1:กรณีโค้งเยอะๆ
#define NUM_COLORS 6



// ตัวแปรสำหรับเก็บลำดับสีที่อ่านได้
// red = 1, green =2 , blue = 3, yellow= 4, balck = 5, white = 6
int detectedColors[6];
int colorCount = 0;



void selectMode() {
  while (Read_sw_OK() == 0) {
    segment = map(knob(), 0, 4000, 0, 15);  //กำหนดค่าไว้ 30 เมนู
    oled.clear();                           //เคลียร์หน้าจอ
    oled.mode(0);                           //หมุนหน้าจอ 0 องศา
    oled.textSize(1);                       //กำหนดขนาดตัวอักษร
    oled.text(0, 0, "  ANR Robotics");
    oled.text(1, 0, "FN@ANR");
    oled.text(2, 0, "press OK to start.");
    oled.text(3, 0, "Menu : %d", segment);
    if (segment == 1) {
      oled.text(5, 0, "     ");
    } else if (segment == 2) {
      oled.text(5, 0, "   ShowCodeColor");
    } else if (segment == 3) {
      oled.text(5, 0, "   ShowPID");
    } else if (segment == 4) {
      oled.text(5, 0, "   ColorDetection");
    } else if (segment == 5) {
      oled.text(5, 0, "  ");
    } else if (segment == 6) {
      oled.text(5, 0, "   CheckDistCanY");
    } else if (segment == 7) {
      oled.text(5, 0, "   ");
    } else if (segment == 8) {
      oled.text(5, 0, "   CheckDistCanY");
    } else if (segment == 9) {
      oled.text(5, 0, "   GoCanBlue");
    } else if (segment == 10) {
      oled.text(5, 0, "   GoCanBlack");
    } else if (segment == 11) {
      oled.text(5, 0, "   GoCanRed");
    } else if (segment == 12) {
      oled.text(5, 0, "   GoCanGreen");
    } else if (segment == 13) {
      oled.text(5, 0, "   GoCanWhite");
    } else if (segment == 14) {
      oled.text(5, 0, "   ");
    } else if (segment == 15) {
      oled.text(5, 0, "   ");
    }
    oled.text(6, 0, "Pass OK to start");
    oled.show();
    delay(10);
  }
}


void setup() {
  attachInterrupt(digitalPinToInterrupt(encoderPin), countPulse, RISING);
  tcs.begin();
  Speed = 50;
  ACCSpeed = 50;
  SlowSpeed = 25;
  BaseSpeed = Speed;
  TurnSpeed = Speed;
  TurnSpeed2 = 25;
  SonarSpeed = 50;
  SpeedJC = 25;
  InitialSpeed();
  InitialRef();
  beep(0);
  Put2();
  ServoUp1();
  ServoRGB0();
  SW_OK_Status = No;
}

void loop() {
  segment = 0;
  selectMode();
  delay(10);
  StartTimer2();
  if (segment == 1) {

  } else if (segment == 2) {
    ShowCodeColor();
    sw_ok_unpress();
    Wait_sw_ok_press();
  } else if (segment == 3) {
    Show8Analog();
    sw_ok_unpress();
    Wait_sw_ok_press();
  } else if (segment == 4) {
    TracJCStopSlow();
    ColorDetection();
    Finish();
    //ShowAllCanned();
  } else if (segment == 5) {
    ColorDetection();
    center();
    detectedColors[0] = { 6 };
    detectedColors[1] = { 2 };
    detectedColors[2] = { 5 };
    detectedColors[3] = { 1 };
    detectedColors[4] = { 3 };
    detectedColors[5] = { 4 };
    ShowAllCanned();
    Finish();
  } else if (segment == 6) {
    CheckDistCanY();
  } else if (segment == 7) {
    TracJC();
    TurnLeft();
    CheckWall();

  } else if (segment == 8) {
    CheckDistCanY();
    Finish();
  } else if (segment == 9) {
    CheckDistCanB();
    Finish();
  } else if (segment == 10) {
    CheckDistCanBlack();
    Finish();
  } else if (segment == 11) {
    CheckDistCanR();
    Finish();
  } else if (segment == 12) {
    CheckDistCanG();
    Finish();
  } else if (segment == 13) {
    CheckDistCanW();
    Finish();
  } else if (segment == 14) {
    Finish();
  } else if (segment == 15) {
  }
}
