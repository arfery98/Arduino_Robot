void TracJCStopC() {
  //InitialSpeed();
  //TracSpeedTime(SpeedJC, 10000 / SpeedJC);
  CalErrorC();
  while (Error < 99) {
    TracPID();
    StartTimer();
    CalErrorC();
    while ((ReadTimer() < Kt) && (Error < 99)) {
      CalErrorC();
    }
  }
}

void TracC() {
  TracJCStopC();
  TuneC();
}
void TuneC() {
  Forward();
  if (SpeedJC<= 30) delay(5000 / SpeedJC);
  else if (Base <= 60) delay(3500 / Base);
  else if (Base <= 70) delay(2000 / Base);
  else if (Base <= 80) delay(1000 / Base);
  else if (Base <= 90) delay(200 / Base);
  //else if(BaseSpeed<=100) delay(500/BaseSpeed);
}
void CalErrorC()
{
  CalError5SensorC(); 
}
void ConvertADCC()
{
  Read5Analog();
  if(L2<RefL2) L2 = 0;else L2 = 1;  //0:ดำ 1:ขาว
  if(L1<RefL1) L1 = 0;else L1 = 1;
  if(C<RefC) C = 0;else C = 1;
  if(R1<RefR1) R1 = 0;else R1 = 1;
  if(R2<RefR2) R2 = 0;else R2 = 1;
}
void CalError5SensorC() {
  /* ConvertADC(); */
  /* if((L2==1)&&(L1==1)&&(C==1)&&(R1==1)&&(R2==0)) Error = 4; 
  else if((L2==1)&&(L1==1)&&(C==1)&&(R1==0)&&(R2==0)) Error = 3; 
  else if((L2==1)&&(L1==1)&&(C==1)&&(R1==0)&&(R2==1)) Error = 2; 
  else if((L2==1)&&(L1==1)&&(C==0)&&(R1==0)&&(R2==0)) Error = 2; 
  else if((L2==1)&&(L1==1)&&(C==0)&&(R1==0)&&(R2==1)) Error = 1; 
  else if((L2==1)&&(L1==1)&&(C==0)&&(R1==1)&&(R2==1)) Error = 0; 
  else if((L2==1)&&(L1==0)&&(C==0)&&(R1==0)&&(R2==1)) Error = 0;
  else if((L2==1)&&(L1==0)&&(C==0)&&(R1==1)&&(R2==1)) Error = -1;
  else if((L2==1)&&(L1==0)&&(C==1)&&(R1==1)&&(R2==1)) Error = -2;
  else if((L2==0)&&(L1==0)&&(C==0)&&(R1==1)&&(R2==1)) Error = -2;
  else if((L2==0)&&(L1==0)&&(C==1)&&(R1==1)&&(R2==1)) Error = -3; 
  else if((L2==0)&&(L1==1)&&(C==1)&&(R1==1)&&(R2==1)) Error = -4; 
  else if((L2==1)&&(L1==1)&&(C==1)&&(R1==1)&&(R2==1)&&(Error99Check==1))  Error = 99;      //white all
  else if((L2==0)&&(L1==0)&&(C==0)&&(R1==0)&&(R2==0)) Error = 100;   //Left and Right Junction 
  else if((L2==0)&&(L1==0)&&(C==0)&&(R1==0)) Error = 101;           //Left Junction 
  else if((L1==0)&&(C==0)&&(R1==0)&&(R2==0)) Error = 102;           //Right Junction 
  Error99Check=0; */
  //int Status =0 ;
while ((L2==1)&&(C==0||R1==0||L1==0)&&(R2==1))
{
  ConvertADC();
  /* if((L2==1)&&(C==0)&&(R2==1))  ;
  else if((L2==0)&&(C==0)&&(R2==0))MotorStop(); 
  else if((L2==1)&&(C==1)&&(R2==1))MotorStop();  
  Status = 1; */
  /* Forward();
  delay(100); */
}
 beep(1);
MotorStop();
/*for(int i=0; i<6; i++){
  Forward();
  delay(200);
  beep(1);
}
MotorStop(); */
}

void TracPIDC()  {
  int Output, LeftSpeed, RightSpeed, KpTemp;
  if(abs(Error)<2) KpTemp=1; else KpTemp=Kp;
  Output = (KpTemp*Error) + (Ki*SumError) + (Kd*(Error-PreError));
  LeftSpeed = LeftBaseSpeed + Output;
  RightSpeed = RightBaseSpeed - Output;
  if(LeftSpeed>MaxSpeed) LeftSpeed = MaxSpeed;
  else 
  {
    if(PidStatus!=0) {if(LeftSpeed<-MaxSpeed) LeftSpeed = -MaxSpeed;}
    else if(LeftSpeed<0) LeftSpeed = 0;//new pid
  }
  if(RightSpeed>MaxSpeed) RightSpeed = MaxSpeed;
  else 
  {
    if(PidStatus!=0) {if(RightSpeed<-MaxSpeed) RightSpeed = -MaxSpeed;}
    else if(RightSpeed<0) RightSpeed = 0;//new pid
  }
  if(WheelDrive==0)
  {
    motor(1,LeftSpeed); 
    motor(2,RightSpeed);
  }
  else
  {
    motor(1,LeftSpeed);
    motor(2,LeftSpeed); 
    motor(3,RightSpeed);
    motor(4,RightSpeed);
  }
  PreError = Error;
  SumError += Error;
}