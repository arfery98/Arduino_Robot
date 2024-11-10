void ServoUp() {
  servo(2, 170);
}
void ServoUp1() {
  servo(2, 160);
}
void ServoRe() {
  servo(2, 45);
}
void ServoC() {
  servo(2, 0);
}
void ServoDown() {
  servo(2, 5);
}
void ServoRGB0() {
  servo(3, 0);
}
void ServoGrip() {
  servo(1, 50);
}
void ServoPut0() {
  servo(1, 90);
}
void ServoPut() {
  servo(1, 125);
}
void ServoGripUp() {
  servo(2, 25);

}
void ServoGripDown() {
  servo(2, 130);
}

void Grip() {
  OffMotor();
  ServoGrip();
  delay(10);  //ค่าเดิม 100
}
void Grip1() {
  OffMotor();
  ServoGrip();
  delay(100);  //ค่าเดิม 100
}
void Put() {
  OffMotor();
  ServoPut();
  delay(300);
}
void GripUp() {
  OffMotor();
  ServoGripUp();
  delay(300);
}
void GripDown() {
  OffMotor();
  ServoGripDown();
  delay(300);
}
