void Put1()  //วางกระป๋อง
{
  MotorStop();
  ServoDown();
  delay(600);
  ServoPut();
  delay(600);
}
void Put2()  //วางกระป๋อง
{
  //TracSpeedTime(SlowSpeed, 0);
  //ForwardSpeedTime(20, 490);
  MotorStop();
  ServoDown();
  delay(1000);
  ServoPut();
  delay(500);
  //BackwardSpeedTime(SlowSpeed, 1);
}
void GripDelay()  //วางกระป๋อง
{
  //TracSpeedTime(SlowSpeed, 0);
  //ForwardSpeedTime(20, 490);
  MotorStop();
  ServoC();
  delay(1000);
  ServoGrip();
  delay(500);
  //BackwardSpeedTime(SlowSpeed, 1);
}
void GripDelay2()  //วางกระป๋อง
{
  //TracSpeedTime(SlowSpeed, 0);
  //ForwardSpeedTime(20, 490);
  MotorStop();
  ServoC();
  delay(1000);
  ServoGrip();
  delay(500);
  //BackwardSpeedTime(SlowSpeed, 1);
}
void PutDelay()  //วางกระป๋อง
{
  //TracSpeedTime(SlowSpeed, 0);
  //ForwardSpeedTime(20, 490);
  MotorStop();
  ServoUp1();
  delay(1000);
  ServoPut();
  delay(500);
  //BackwardSpeedTime(SlowSpeed, 1);
}
void GripBack()  //คีบกระป๋องแล้วถอยหลังแขนลง
{
  ServoUp();
  delay(100);
  BackwardSpeedTime(SpeedJC, 300);
  MotorStop();
  ServoDown();
}
void GripBackT()  //คีบกระป๋องแล้วถอยหลัง
{
  Grip();
  delay(300);
  ServoUp();
  delay(300);
  BackwardSpeedTime(SpeedJC, 300);
}
void GripBoxY()  //ด้านหลัง
{
  TracSpeedTime(SlowSpeed, 300);
  Grip();
  TracJCStopBack0();
  //TracJCBack();
  //BackwardSpeedTime(SlowSpeed,250);
}
void GripBoxY1()  //ด้านหลัง
{
  TracSpeedTime(SlowSpeed, 260);
  Grip();
  TracJCStopBack0();
  //TracJCBack();
  //BackwardSpeedTime(SlowSpeed,250);
}
void GripBoxX()  //ด้านข้างซ้ายขวา
{
  TracSpeedTime(SpeedJC, 200);
  Grip();
  //BackwardSpeedTime(SlowSpeed, 100);
  MotorStop();
}
void GripBoxXY()  //ด้านข้างซ้ายขวา
{
  TracSpeedTime(SpeedJC, 100);
  Grip();
  BackwardSpeedTime(SlowSpeed, 20);
  MotorStop();
}
void GripBoxX1()  //ด้านข้างซ้ายขวา
{
  TracSpeedTime(SlowSpeed, 300);
  Grip1();
  BackwardSpeedTime(SlowSpeed, 90);
}

void GripCanSpare() {
}


void PutCanSonarL() {
}

void PutCanSonarR() {
}
