void TracJCStop() {
  InitialSpeed();
  TracSpeedTime(BaseSpeed, 10000 / BaseSpeed);
  CalError();
  while (Error < 99) {
    TracPID();
    StartTimer();
    CalError();
    while ((ReadTimer() < Kt) && (Error < 99)) {
      CalError();
    }
  }
}

void TracJCStopSlow() {
  //InitialSpeed();
  InitialSpeedSlow();
  TracSpeedTime(SlowSpeed, 10000 / SlowSpeed);
  CalError();
  while (Error < 99) {
    //TracPID();
    TrackPIDSlow(SlowSpeed);
    StartTimer();
    CalError();
    while ((ReadTimer() < Kt) && (Error < 99)) {
      CalError();
    }
  }
}
void TracJCFrist() {
  TracSpeedTime(30, 350);
  CalError();
  while (Error < 99) {
    TracPID();
    StartTimer();
    CalError();
    while ((ReadTimer() < Kt) && (Error < 99)) {
      CalError();
    }
  }
}
void TracJC() {
  TracJCStop();
  TuneJC();
}
void TuneJC() {
  Forward();
  if (BaseSpeed <= 50) delay(5000 / BaseSpeed);
  else if (BaseSpeed <= 60) delay(3500 / BaseSpeed);
  else if (BaseSpeed <= 70) delay(2000 / BaseSpeed);
  else if (BaseSpeed <= 80) delay(1000 / BaseSpeed);
  else if (BaseSpeed <= 90) delay(200 / BaseSpeed);
}
void TracJCForPut() {  //ก่อนเลี้ยววาง
  TracJCStop();
  TuneJCForPut();
}
void TuneJCForPut() {   //เดินหน้าหลังแทร็ค ---> เลี้ยว
  Forward();
  if (BaseSpeed <= 50) delay(9850 / BaseSpeed);
}
void TracJCStraight() {
  TracJC();
  ForwardDelay(5000 / BaseSpeed);
}
void TracJCStraight1() {
  TracJC();
  Forward1();
}
void TracJCSlowStop() {
  BaseSpeed = SlowSpeed;
  TracJCStop();
  BaseSpeed = Speed;
  InitialSpeed();
}
void TracJCSlow() {
  TracJCSlowStop();
  Forward();
  while (Error >= 100) {
    CalError();
  }
}
void TracJCSpeedTime(int MotorSpeed, int TimeDelay) {
  Speed = MotorSpeed;
  TracJCStop();
  Forward();
  delay(TimeDelay);
  //BaseSpeed = Speed;
  InitialSpeed();
}


void TracJCSpeed() {
  BaseSpeed = ACCSpeed;
  TracJCStop();
  Forward();
  delay(1000 / BaseSpeed);
  while (Error >= 100) {
    CalError();
  }
  delay(2000 / BaseSpeed);
  BaseSpeed = Speed;
  InitialSpeed();
}
void TracJCSpeed1() {
  BaseSpeed = 20;
  TracJCStop();
  Forward1();
  delay(1000 / BaseSpeed);
  while (Error >= 100) {
    CalError();
  }
  delay(2000 / BaseSpeed);
}
void TracSpeedTime(int TracSpeed, int TracTime) {
  BaseSpeed = TracSpeed;
  InitialSpeed();
  StartTimer();
  CalError();
  while (ReadTimer() < TracTime) {
    TracPID();
    delay(Kt);
    CalError();
  }
  BaseSpeed = Speed;
  InitialSpeed();
}
void TracSpeedTimeSlow(int BaseSpeed, int TracTime) {
  BaseSpeed = SlowSpeed;
  InitialSpeedSlow();
  StartTimer();
  CalError();
  while (ReadTimer() < TracTime) {
    TrackPIDSlow(SlowSpeed);
    delay(Kt);
    CalError();
  }
  InitialSpeedSlow();
}
void TracJCSpeedStop() {
  BaseSpeed = ACCSpeed;
  TracJCStop();
  BaseSpeed = Speed;
  InitialSpeed();
}
void TracJCSpeedStop99() {
  BaseSpeed = ACCSpeed;
  InitialSpeed();
  CalError();
  while (Error < 99) {
    TracPID();
    StartTimer();
    while ((ReadTimer() < Kt) && (Error < 99)) {
      Error99Check = 1;
      CalError();
    }
  }
  BaseSpeed = Speed;
  InitialSpeed();
}
void TracJCStop99() {
  InitialSpeed();
  CalError();
  while (Error < 99) {
    TracPID();
    StartTimer();
    while ((ReadTimer() < Kt) && (Error < 99)) {
      Error99Check = 1;
      CalError();
    }
  }
}
void TracJCStopLorR()  //ใช้เซ็นเซอร์ซ้ายหรือขวาในการเช็คแยก
{
  InitialSpeed();
  TracSpeedTime(BaseSpeed, 10000 / BaseSpeed);
  CalError();
  while ((L2 == 1) && (R2 == 1)) {
    TracPID();
    StartTimer();
    CalError();
    while ((ReadTimer() < Kt) && (Error < 100)) {
      CalError();
    }
  }
}
void TracJCLorR()  //ใช้เซ็นเซอร์ซ้ายหรือขวาในการเช็คแยก
{
  TracJCStopLorR();
  TuneJC();
}
void TracJCSpeedLorR()  //ใช้เซ็นเซอร์ซ้ายหรือขวาในการเช็คแยก
{
  BaseSpeed = ACCSpeed;
  TracJCStopLorR();
  Forward();
  while (Error >= 100) {
    CalError();
  }
  delay(3000 / BaseSpeed);
  BaseSpeed = Speed;
  InitialSpeed();
}
void TracJCStopL()  //ใช้เซ็นเซอร์ซ้ายในการเช็คแยก
{
  InitialSpeed();
  TracSpeedTime(BaseSpeed, 10000 / BaseSpeed);
  CalError();
  while ((L2 == 1)) {
    TracPID();
    StartTimer();
    CalError();
    while ((ReadTimer() < Kt) && (Error < 100)) {
      CalError();
    }
  }
}
void TracJCStopLSlow()  //ใช้เซ็นเซอร์ซ้ายในการเช็คแยก
{
  InitialSpeedSlow();
  TracSpeedTime(SlowSpeed, 10000 / SlowSpeed);
  CalError();
  while ((L2 == 1)) {
    TrackPIDSlow(SlowSpeed);
    StartTimer();
    CalError();
    while ((ReadTimer() < Kt) && (Error < 100)) {
      CalError();
    }
  }
}
void TracJCL()  //ใช้เซ็นเซอร์ซ้ายในการเช็คแยก
{
  TracJCStopL();
  TuneJC();
}
void TracJCStopR()  //ใช้เซ็นเซอร์ขวาในการเช็คแยก
{
  InitialSpeed();
  TracSpeedTime(BaseSpeed, 10000 / BaseSpeed);
  CalError();
  while ((R2 == 1)) {
    TracPID();
    StartTimer();
    CalError();
    while ((ReadTimer() < Kt) && (Error < 100)) {
      CalError();
    }
  }
}
void TracJCR()  //ใช้เซ็นเซอร์ขวาในการเช็คแยก
{
  TracJCStopR();
  TuneJC();
}
void TracJCRtest()  //ใช้เซ็นเซอร์ขวาในการเช็คแยก
{
  TracJCStopRforBlack();
  //TuneJC();
}

void TracBK() {
  TracJCStop();
  BackJC();
}
void BackJC() {
  Backward();
  if (BaseSpeed <= 50) delay(5000 / BaseSpeed);
  else if (BaseSpeed <= 60) delay(8000 / BaseSpeed);
  else if (BaseSpeed <= 70) delay(2000 / BaseSpeed);
  else if (BaseSpeed <= 80) delay(1000 / BaseSpeed);
  else if (BaseSpeed <= 90) delay(200 / BaseSpeed);
  //else if(BaseSpeed<=100) delay(500/BaseSpeed);
}
void TracJCSpeedBK() {
  BaseSpeed = ACCSpeed;
  TracJCStop();
  Backward();
  delay(10000 / BaseSpeed);
  while (Error >= 100) {
    CalError();
  }
  delay(2000 / BaseSpeed);
  BaseSpeed = Speed;
  InitialSpeed();
}
void TracJCL2()  //ใช้เซ็นเซอร์ซ้ายในการเช็คแยก(สีดำ)
{
  //TracJCStopLSlow();
  TracJCStopL();
  //TracJCStopSlow();
  FD2(20, 20);
  delay(425);
  //TuneJC2();
}
void TuneJC2() {
  Forward();
  if (BaseSpeed <= 50) delay(5750 / BaseSpeed);
  /*else if (BaseSpeed <= 60) delay(3500 / BaseSpeed);
  else if (BaseSpeed <= 70) delay(2000 / BaseSpeed);
  else if (BaseSpeed <= 80) delay(1000 / BaseSpeed);
  else if (BaseSpeed <= 90) delay(200 / BaseSpeed);
  //else if(BaseSpeed<=100) delay(500/BaseSpeed);*/
}
void TracJCStopRforBlack()  //ใช้เซ็นเซอร์ขวาในการเช็คแยก(สีดำ)
{
  TracSpeedTimeB(SlowSpeed, 10000 / SlowSpeed);
  CalError();
  while ((R2 == 1)) {
    TracPID();
    StartTimer();
    CalError();
    while ((ReadTimer() < Kt) && (Error < 99)) {
      CalError();
      break;
    }
  }
}
void TracSpeedTimeB(int TracSpeed, int TracTime) {
  SlowSpeed = TracSpeed;
  InitialSpeed();
  StartTimer();
  CalError();
  while (ReadTimer() < TracTime) {
    TracPID();
    delay(Kt);
    CalError();
  }
  SlowSpeed = Speed;
  InitialSpeed();
}