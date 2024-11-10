void ShowSonar()
{
  oled.clear();
  oled.text(0,0,"Sonar=%d",Sonar());
  oled.show();                  //แสดงบนหน้าจอ
}

void Read7Analog()  //อ่านค่าเซ็นเซอร์หน้า 7 ตัว
{
   
  L2 = analog(1);
  L1 = analog(2);
  C = analog(3);
  R1 = analog(4);
  R2 = analog(5);
  
}
void Convert7Analog() //แปลงค่า analog หน้า เป็น digital 0:ดำ,1:ขาว
{
  Read7Analog();
 
  if(L2<RefL2) L2=0; else L2=1; 
  if(L1<RefL1) L1=0; else L1=1; 
  if(C<RefC) C=0; else C=1; 
  if(R1<RefR1) R1=0; else R1=1; 
  if(R2<RefR2) R2=0; else R2=1; 
   
}
