void RobotStart() {
  ForwardSpeedTime(60, 200);
}

void Forward() {
  if (WheelDrive == 0) fd2(LeftBaseSpeed, RightBaseSpeed);
  else FD2(LeftBaseSpeed, RightBaseSpeed);
}
void Forward1() {
  FD2(20, 20);
}
void Forward555() {
  FD2(20, 20);
  delay(5000);
}
void ForwardDelay(int Time) {
  Forward();
  delay(Time);
}
void ForwardSpeedDelay(int Time) {
  BaseSpeed = ACCSpeed;
  InitialSpeed();
  Forward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}
void ForwardSpeedTime(int MotorSpeed, int Time) {
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Forward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}
void Backward() {
  if (WheelDrive == 0) bk2(BackLeftBaseSpeed, BackRightBaseSpeed);
  else BK2(BackLeftBaseSpeed, BackRightBaseSpeed);
}
void Backward1(int MotorSpeed, int Time)  //ถอยหลัง
{
  TuneMotor(MotorSpeed);
  BK2(LeftSpeedBack, RightSpeedBack);
  delay(Time);
}
void BackwardYl() {
  if (WheelDrive == 0) bk2(BackLeftBaseSpeedYl, BackRightBaseSpeedYl);
  else BK2(BackLeftBaseSpeedYl, BackRightBaseSpeedYl);
}
void BackwardDelay(int Time) {
  Backward();
  delay(Time);
}
void BackwardDelayYl(int Time) {
  BackwardYl();
  delay(Time);
}
void BackwardSpeedTime(int MotorSpeed, int Time) {
  BaseSpeed = MotorSpeed;
  InitialSpeed();
  Backward();
  delay(Time);
  BaseSpeed = Speed;
  InitialSpeed();
}
void MotorStop() {
  OffMotor();
  //delay(10);
}
void OffMotor() {
  if (WheelDrive == 0) ao();
  else AO();
}
void ChangeSpeed(int NewSpeed, int NewACCSpeed) {
  Speed = NewSpeed;
  ACCSpeed = NewACCSpeed;
  BaseSpeed = NewSpeed;
  TurnSpeed = NewSpeed;
}
void TuneMotor(int MotorSpeed)  //ปรับจูนมอเตอร์
{
  if (MotorSpeed <= 60) {
    LeftSpeed = MotorSpeed - 0;       //เอียงขวา
    RightSpeed = MotorSpeed - 0;      //เอียงซ้าย
    LeftSpeedBack = MotorSpeed - 0;   //เอียงขวา
    RightSpeedBack = MotorSpeed - 0;  //เอียงซ้าย
  } else                              //ความเร็วมากกว่า 60
  {
    LeftSpeed = MotorSpeed - 0;       //เอียงขวา
    RightSpeed = MotorSpeed - 3;      //เอียงซ้าย
    LeftSpeedBack = MotorSpeed - 0;   //เอียงขวา
    RightSpeedBack = MotorSpeed - 8;  //เอียงซ้าย
  }
}

void TuneMotorSlow(int MotorSpeed)  //ปรับจูนมอเตอร์
{
  if (MotorSpeed <= 60) {
    LeftSpeed = MotorSpeed - 0;       //เอียงขวา
    RightSpeed = MotorSpeed - 0;      //เอียงซ้าย
    LeftSpeedBack = MotorSpeed - 0;   //เอียงขวา
    RightSpeedBack = MotorSpeed - 0;  //เอียงซ้าย
  } else                              //ความเร็วมากกว่า 60
  {
    LeftSpeed = MotorSpeed - 0;       //เอียงขวา
    RightSpeed = MotorSpeed - 3;      //เอียงซ้าย
    LeftSpeedBack = MotorSpeed - 0;   //เอียงขวา
    RightSpeedBack = MotorSpeed - 8;  //เอียงซ้าย
  }
}