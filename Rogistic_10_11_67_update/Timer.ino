void StartTimer()  {
  Timer = millis();
}
long int ReadTimer()  {
  return(millis() - Timer);
}
void StartTimer2()  {
  Timer2 = millis();
}
long int ReadTimer2()  {
  return(millis() - Timer2);
}
void StartTimer3()  {
  Timer3 = millis();
}
long int ReadTimer3()  {
  return(millis() - Timer3);
}
void StartTimer0()  //เริ่มจับเวลา Timer0
{
  BaseTimer0 = millis();  //อ่านเวลาปัจจุบันในหน่วง ms
  Timer0 = 0;
}
long ReadTimer0() //อ่านค่า Timer 0
{
  Timer0 = millis() - BaseTimer0;
  return(Timer0);
}
void StartTimer1()  //เริ่มจับเวลา Timer1
{
  BaseTimer1 = millis();  //อ่านเวลาปัจจุบันในหน่วง ms
  Timer1 = 0;
}
long ReadTimer1() //อ่านค่า Timer 1
{
  Timer1 = millis() - BaseTimer1;
  return(Timer1);
}
void StartTimer4()  //เริ่มจับเวลา Timer2
{
  BaseTimer2 = millis();  //อ่านเวลาปัจจุบันในหน่วง ms
  Timer2 = 0;
}
long ReadTimer4() //อ่านค่า Timer 2
{
  Timer2 = millis() - BaseTimer2;
  return(Timer2);
}