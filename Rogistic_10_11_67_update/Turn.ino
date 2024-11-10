void TurnLeft() {
  MotorStop();
  if (WheelDrive == 0) sl(TurnSpeed);
  else SL(TurnSpeed);
  delay(17000 / TurnSpeed);
  if (TurnSpeed > 90) {
    if (WheelDrive == 0) sl(90);
    else SL(90);
  }
  MotorStop();
}
void TurnLeftPut() {  //เลี้ยวซ้ายวางของโซนาร์
  MotorStop();
  if (WheelDrive == 0) sl(TurnSpeed2);
  else SL(TurnSpeed2);
  delay(25250 / TurnSpeed2);
  if (TurnSpeed2 = 20) {
    if (WheelDrive == 0) sl(20);
    else SL(20);
  }
  MotorStop();
}
void TurnLeftforBlack() {
  MotorStop();
  if (WheelDrive == 0) sl(TurnSpeed2);
  else SL(TurnSpeed2);
  delay(31250 / TurnSpeed2);
  if (TurnSpeed2 = 20) {
    if (WheelDrive == 0) sl(20);
    else SL(20);
  }
  MotorStop();
}
void TurnLeft1() {
  MotorStop();
  if (WheelDrive == 0) sl(TurnSpeed);
  else SL(TurnSpeed);
  delay(18000 / TurnSpeed);
  if (TurnSpeed > 90) {
    if (WheelDrive == 0) sl(90);
    else SL(90);
  }
  MotorStop();
}
void TurnLeft2() {
  MotorStop();
  if (WheelDrive == 0) sl(TurnSpeed);
  else SL(TurnSpeed);
  delay(18000 / TurnSpeed);
  if (TurnSpeed > 90) {
    if (WheelDrive == 0) sl(90);
    else SL(90);
  }
  MotorStop();
}
void TurnLeft3() {
  MotorStop();
  if (WheelDrive == 0) sl(TurnSpeed);
  else SL(TurnSpeed);
  delay(16000 / TurnSpeed);
  if (TurnSpeed > 90) {
    if (WheelDrive == 0) SL(90);
  }
  MotorStop();
}
void TurnRight() {
  MotorStop();
  if (WheelDrive == 0) sr(TurnSpeed);
  else SR(TurnSpeed);
  delay(17000 / TurnSpeed);
  if (TurnSpeed > 90) {
    if (WheelDrive == 0) sr(90);
    else SR(90);
  }
  MotorStop();
}
void TurnRightPut() {  //เลี้ยวขวาวางของโซนาร์
  MotorStop();
  SR(TurnSpeed2);
  delay(25250 / TurnSpeed2);
  if (TurnSpeed2 > 20) {
    SR(20);
  }

  MotorStop();
}
void TurnRight1() {
  MotorStop();
  if (WheelDrive == 0) sr(TurnSpeed);
  else SR(TurnSpeed);
  delay(18000 / TurnSpeed);
  if (TurnSpeed > 90) {
    if (WheelDrive == 0) sr(90);
    else SR(90);
  }

  MotorStop();
}
void UTurnLeft2() {
  TurnLeft1();
  TurnLeft();
}
void UTurnLeft3() {
  TurnLeft1();
  TurnLeft1();
}
void UTurnLeft() {
  MotorStop();
  if (WheelDrive == 0) sl(TurnSpeed);
  else SL(TurnSpeed);
  delay(20000 / TurnSpeed);
  if (TurnSpeed > 70) {
    if (WheelDrive == 0) sl(60);
    else SL(60);
  }
  ConvertADC();
  if (TurnSpeed <= 50) {
    while ((C == 1)) { ConvertADC(); }
  } else if (TurnSpeed <= 60) {
    while ((L1 == 1)) { ConvertADC(); }
  } else {
    while ((L2 == 1)) { ConvertADC(); }
  }
  MotorStop();
}
void UTurnRight() {
  MotorStop();
  if (WheelDrive == 0) sr(TurnSpeed);
  else SR(TurnSpeed);
  delay(18000 / TurnSpeed);
  if (TurnSpeed > 70) {
    if (WheelDrive == 0) sr(60);
    else SR(60);
  }
  ConvertADC();
  if (TurnSpeed <= 50) {
    while ((C == 1)) { ConvertADC(); }
  } else if (TurnSpeed <= 60) {
    while ((R1 == 1)) { ConvertADC(); }
  } else {
    while ((R2 == 1)) { ConvertADC(); }
  }
  MotorStop();
}

void Left(int Speed, int Time) {
  MotorStop();
  if (WheelDrive == 0) sl(Speed);
  else SL(Speed);
  delay(Time);
  MotorStop();
}
void Right(int Speed, int Time) {
  MotorStop();
  if (WheelDrive == 0) sr(Speed);
  else SR(Speed);
  delay(Time);
  MotorStop();
}
void LeftYl(int SpeedJC, int Time) {
  MotorStop();
  if (WheelDrive == 0) sl(SpeedJC);
  else SL(SpeedJC);
  delay(Time);
  MotorStop();
}
void RightYl(int SpeedJC, int Time) {
  MotorStop();
  if (WheelDrive == 0) sr(SpeedJC);
  else SR(SpeedJC);
  delay(Time);
  MotorStop();
}
/* void TurnLeftDelay(int Speed, int Time) {
  if (WheelDrive == 0) tl(Speed);
  else TL(Speed);
  delay(Time);
}
void TurnRightDelay(int Speed, int Time) {
  if (WheelDrive == 0) tr(Speed);
  else TR(Speed);
  delay(Time);
} */
void TurnLeftDelay(int SpeedJC, int Time) {
  if (WheelDrive == 0) tl(SpeedJC);
  else TL(SpeedJC);
  delay(Time);
}
void TurnRightDelay(int SpeedJC, int Time) {
  //SpeedJC = MotorSpeed;
  if (WheelDrive == 0) tr(SpeedJC);
  else TR(SpeedJC);
  delay(Time);
}
void CurveRight(int MotorSpeed, int Time)  //โค้งทางขวาอ้อมสิ่งกีดขวาง
{
  MotorStop();
  Right(MotorSpeed, 130);
  if (WheelDrive == 0) fd2(MotorSpeed * 0.58, MotorSpeed);
  else FD2(MotorSpeed * 0.58, MotorSpeed);
  delay(900);
  ConvertADC();
  while (L1 == 0) { ConvertADC(); }
  while (L1 == 1) { ConvertADC(); }
  //ForwardSpeedTime(MotorSpeed,Time);
  delay(Time);
  TurnRight();
}
void CurveLeft(int MotorSpeed, int Time)  //โค้งทางซ้ายอ้อมสิ่งกีดขวาง
{
  MotorStop();
  Left(MotorSpeed, 130);
  if (WheelDrive == 0) fd2(MotorSpeed, MotorSpeed * 0.58);
  else FD2(MotorSpeed, MotorSpeed * 0.58);
  delay(900);
  ConvertADC();
  while (R1 == 0) { ConvertADC(); }
  while (R1 == 1) { ConvertADC(); }
  //ForwardSpeedTime(MotorSpeed,Time);
  delay(Time);
  TurnLeft();
}
