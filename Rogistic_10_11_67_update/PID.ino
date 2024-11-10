void CalError()
{
  CalError5Sensor(); 
}
void ConvertADC()
{
  Read5Analog();
  if(L2<RefL2) L2 = 0;else L2 = 1;  //0:ดำ 1:ขาว
  if(L1<RefL1) L1 = 0;else L1 = 1;
  if(C<RefC) C = 0;else C = 1;
  if(R1<RefR1) R1 = 0;else R1 = 1;
  if(R2<RefR2) R2 = 0;else R2 = 1;
}
void CalError5Sensor() {
  ConvertADC();
  if((L2==1)&&(L1==1)&&(C==1)&&(R1==1)&&(R2==0)) Error = 4; 
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
  Error99Check=0;
}


void TracPID()  {
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
void CalErrorBack()
{
  CalErrorBack4Sensor(); 
}
void ConvertADCBack()
{
  Read4AnalogBack();
  if(BL2<RefBL2) BL2 = 0; else BL2 = 1;    //0:ดำ 1:ขาว
  if(BL1<RefBL1) BL1 = 0; else BL1 = 1;    //0:ดำ 1:ขาว
  if(BR1<RefBR1) BR1 = 0; else BR1 = 1;
  if(BR2<RefBR2) BR2 = 0; else BR2 = 1;
}
void ConvertADCBack1()
{
  Read4AnalogBack();
  if(BL2<RefBL2) BL2 = 0; else BL2 = 1;    //0:ดำ 1:ขาว
  if(BL1<RefBL1) BL1 = 0; else BL1 = 1;    //0:ดำ 1:ขาว
  if(BR1<RefBR1) BR1 = 0; else BR1 = 1;
  if(BR2<RefBR2) BR2 = 0; else BR2 = 1;
}
void CalErrorBack4Sensor() {
  ConvertADCBack();
  if((BL2==1)&&(BL1==1)&&(BR1==1)&&(BR2==0)) Error = 3; 
  else if((BL2==1)&&(BL1==1)&&(BR1==0)&&(BR2==0)) Error = 2;   
  else if((BL2==1)&&(BL1==1)&&(BR1==0)&&(BR2==1)) Error = 1; 
  else if((BL2==1)&&(BL1==1)&&(BR1==1)&&(BR2==1)) Error = 0;  
  else if((BL2==1)&&(BL1==0)&&(BR1==1)&&(BR2==1)) Error = -1; 
  else if((BL2==0)&&(BL1==0)&&(BR1==1)&&(BR2==1)) Error = -2; 
  else if((BL2==0)&&(BL1==1)&&(BR1==1)&&(BR2==1)) Error = -3; 
  else if((BL2==0)&&(BL1==0)&&(BR1==0)&&(BR2==0)) Error = 100;
  else if((BL2==0)&&(BL1==0)&&(BR1==0)) Error = 101; 
  else if((BL1==0)&&(BR1==0)&&(BR2==0)) Error = 102;  
}
void TracPIDBack()  {
  int Output, LeftSpeed, RightSpeed;
  Output = (KpB*Error) + (KiB*SumError) + (KdB*(Error-PreError));
  LeftSpeed = BackLeftBaseSpeed + Output;
  RightSpeed = BackRightBaseSpeed - Output;
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
    motor(1,-LeftSpeed); 
    motor(2,-RightSpeed);
  }
  else
  {
    motor(1,-LeftSpeed);
    motor(2,-LeftSpeed); 
    motor(3,-RightSpeed);
    motor(4,-RightSpeed);
  }
  PreError = Error;
  SumError += Error;
}
void TrackPID(int MotorSpeed) //เคลื่อนที่ตามช่องแบบ PID
{
  int Output,LeftOutput,RightOutput,MaxSpeed=100;
  
  TuneMotor(MotorSpeed);
  Output = (Kp*Error)+(Ki*Integral)+Kd*(Error-PreError);
  LeftOutput = LeftSpeed+Output;
  RightOutput = RightSpeed-Output;
  if(LeftOutput>MaxSpeed) LeftOutput = MaxSpeed;
  if(LeftOutput<-MaxSpeed) LeftOutput = -MaxSpeed; 
  if(RightOutput>MaxSpeed) RightOutput = MaxSpeed;
  if(RightOutput<-MaxSpeed) RightOutput = -MaxSpeed; 
  motor(1,LeftOutput);
  motor(2,LeftOutput);
  motor(3,RightOutput);
  motor(4,RightOutput);
  PreError = Error;
  Integral += Error;
}


//**************************************************//


void TrackPIDSlow(int MotorSpeed) //เคลื่อนที่ตามช่องแบบ PID
{
  int Output,LeftOutput,RightOutput,MaxSpeed=100;
  
  //MotorSpeed = SlowSpeed;

  TuneMotorSlow(TurnSpeedSlow);
  Output = (Kp*Error)+(Ki*Integral)+Kd*(Error-PreError);
  LeftOutput = LeftSpeed+Output;
  RightOutput = RightSpeed-Output;
  if(LeftOutput>MaxSpeed) LeftOutput = MaxSpeed;
  if(LeftOutput<-MaxSpeed) LeftOutput = -MaxSpeed; 
  if(RightOutput>MaxSpeed) RightOutput = MaxSpeed;
  if(RightOutput<-MaxSpeed) RightOutput = -MaxSpeed; 
  motor(1,LeftOutput);
  motor(2,LeftOutput);
  motor(3,RightOutput);
  motor(4,RightOutput);
  PreError = Error;
  Integral += Error;
}