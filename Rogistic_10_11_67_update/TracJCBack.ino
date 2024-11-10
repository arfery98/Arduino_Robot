void TracJCStopBack() 
{  
  InitialSpeed();
  TracSpeedTimeBack(BaseSpeed,10000/BaseSpeed);
  CalErrorBack();
  while(Error<100)
  {
      TracPIDBack();
      StartTimer();
      while((ReadTimer()<KtB)&&(Error<100))
      {
        CalErrorBack();           
      }
  }
}
void TracJCBack() 
{
  TracJCStopBack();
  Backward();
  if(BaseSpeed<=50) delay(6000/BaseSpeed);
  else if(BaseSpeed<=60) delay(4500/BaseSpeed); 
  else if(BaseSpeed<=70) delay(3000/BaseSpeed);
  else if(BaseSpeed<=80) delay(2000/BaseSpeed);
  else if(BaseSpeed<=90) delay(500/BaseSpeed);
  //else delay(500/BaseSpeed);
}
void TracSpeedTimeBack(int TracSpeed, int TracTime) {
  BaseSpeed = TracSpeed;
  InitialSpeed();
  StartTimer();
  CalErrorBack();
  while(ReadTimer()<TracTime)
  {
    TracPIDBack();
    delay(Kt);
    CalErrorBack();
  }
  BaseSpeed = Speed;
  InitialSpeed();
}
void TracJCSpeedTimeBack(int MotorSpeed, int TimeDelay) {
  Speed = MotorSpeed;
  TracJCStopBack();
  Backward();
  delay(TimeDelay);
  //BaseSpeed = Speed;
  InitialSpeed();
}
void TracJCStopBack0()
{
  //TracSpeedTimeBack(ACCSpeed,10000/ACCSpeed);
  if(BaseSpeed>=95) TracJCSpeedTimeBack(95,0);
  else TracJCBack();
}
void TracJCSpeedBack() 
{
  BaseSpeed = ACCSpeed;
  TracJCStopBack();
  Backward();
  while(Error>=100)
  {
    CalError();
  }
  delay(6000/BaseSpeed);
  BaseSpeed = Speed;
  InitialSpeed();
}
void TracJCCB() 
{
  TracJCStopBack();
  Forward();
  if(BaseSpeed<=50) delay(6000/BaseSpeed);
  else if(BaseSpeed<=60) delay(8000/BaseSpeed); 
  else if(BaseSpeed<=70) delay(3000/BaseSpeed);
  else if(BaseSpeed<=80) delay(2000/BaseSpeed);
  else if(BaseSpeed<=90) delay(500/BaseSpeed);
  //else delay(500/BaseSpeed);
}
void TurnLeft4() {
  MotorStop();
  if (WheelDrive == 0) sl(TurnSpeed);
  else SL(TurnSpeed);
  delay(6000 / TurnSpeed);
  if (TurnSpeed > 90) {
    if (WheelDrive == 0) sl(90);
    else SL(90);
  }
  ConvertADCBack1();
  if (TurnSpeed <= 50) {
    while ((C == 1)) { ConvertADCBack1(); }
  } else if (TurnSpeed <= 60) {
    while ((BL2 == 1)) { ConvertADCBack1(); }
  } else {
    while ((BR2 == 1)) { ConvertADCBack1(); }
  }
  MotorStop();
}
void TurnBackDelayTrac() {
  TracJCStopBack1() ;
  if (WheelDrive == 0) tl(SpeedJC);
  else TL(SpeedJC);
  delay(200);
  if (BR2 == 0) {
    while (BL2 == 1) {
      ConvertADCBack();
    }
    MotorStop();
  }
  if (WheelDrive == 0) tr(SpeedJC);
  else TR(SpeedJC);
  delay(200);
  if (BL2 == 0) {
    while (BR2 == 1) {
      ConvertADCBack();
    }
    MotorStop();
  }
}
void TracJCStopBack1() 
{  
  InitialSpeed();
  TracSpeedTimeBack(SpeedJC,200);
  CalErrorBack();
  while(Error<100)
  {
      TracPIDBack();
      StartTimer();
      while((ReadTimer()<KtB)&&(Error<100))
      {
        CalErrorBack();           
      }
  }
}
