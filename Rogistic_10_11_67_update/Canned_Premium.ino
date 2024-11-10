void ShowAllCanned() {
  canindex = getCanIndex(4);  //ใส่สีลำดับที่...
  oled.clear();               //เคลียร์หน้าจอ
  oled.textSize(2);           //กำหนดขนาดตัวอักษร
  oled.text(0, 0, "YELLOW");
  oled.text(1, 0, "to");
  oled.text(2, 0, "%d", canindex);
  oled.show();
  GoCanYellow();    //ไปหากระป๋อง
  delay(1000);
  CheckDistCanY();  //เช็คว่ามีรึป่าว ถ้าไม่มีจะวิ่งไปเอาของสำรองเอง

  canindex = getCanIndex(5);  //ใส่สีลำดับที่...
  oled.clear();               //เคลียร์หน้าจอ
  oled.textSize(2);           //กำหนดขนาดตัวอักษร
  oled.text(0, 0, "BLACK");
  oled.text(1, 0, "to");
  oled.text(2, 0, "%d", canindex);
  oled.show();
  GoCanBlack();
  delay(1000);
  CheckDistCanBlack();

  canindex = getCanIndex(3);  //ใส่สีลำดับที่...
  oled.clear();               //เคลียร์หน้าจอ
  oled.textSize(2);           //กำหนดขนาดตัวอักษร
  oled.text(0, 0, "BLUE");
  oled.text(1, 0, "to");
  oled.text(2, 0, "%d", canindex);
  oled.show();
  GoCanBlue();
  delay(1000);
  CheckDistCanB();

  canindex = getCanIndex(2);  //ใส่สีลำดับที่...
  oled.clear();               //เคลียร์หน้าจอ
  oled.textSize(2);           //กำหนดขนาดตัวอักษร
  oled.text(0, 0, "GREEN");
  oled.text(1, 0, "to");
  oled.text(2, 0, "%d", canindex);
  oled.show();
  GoCanGreen();
  delay(1000);
  CheckDistCanG();

  canindex = getCanIndex(1);  //ใส่สีลำดับที่...
  oled.clear();               //เคลียร์หน้าจอ
  oled.textSize(2);           //กำหนดขนาดตัวอักษร
  oled.text(0, 0, "RED");
  oled.text(1, 0, "to");
  oled.text(2, 0, "%d", canindex);
  oled.show();
  GoCanRed();
  delay(1000);
  CheckDistCanR();

  canindex = getCanIndex(6);  //ใส่สีลำดับที่...
  oled.clear();               //เคลียร์หน้าจอ
  oled.textSize(2);           //กำหนดขนาดตัวอักษร
  oled.text(0, 0, "WHITE");
  oled.text(1, 0, "to");
  oled.text(2, 0, "%d", canindex);
  oled.show();
  GoCanWhite();
  delay(1000);
  CheckDistCanW();
}

void MoveCanned() {     //ย้ายไปวางธรรมดา
  if (canindex == 1) {  //ย้ายไปวางช่อง 1
    WalkPut1();
  } else if (canindex == 2) {  //ย้ายไปวางช่อง 2
    WalkPut2();
  } else if (canindex == 3) {  //ย้ายไปวางช่อง 3
    WalkPut3();
  } else if (canindex == 4) {  //ย้ายไปวางช่อง 4
    WalkPut4();
  } else if (canindex == 5) {  //ย้ายไปวางช่อง 5
    WalkPut5();
  } else if (canindex == 6) {  //ย้ายไปวางช่อง 6
    WalkPut6();
  }
}

void MoveCannedError() {
  if (canindex == 1) {  //ย้ายไปวางช่อง 1
    back1();
  } else if (canindex == 2) {  //ย้ายไปวางช่อง 2
    back2();
  } else if (canindex == 3) {  //ย้ายไปวางช่อง 3
    back3();
  } else if (canindex == 4) {  //ย้ายไปวางช่อง 4
    back4();
  } else if (canindex == 5) {  //ย้ายไปวางช่อง 5
    back5();
  } else if (canindex == 6) {  //ย้ายไปวางช่อง 6
    back6();
  }
}

void MoveBrick() {
  if (canindex == 1) {  //ย้ายไปวางช่อง 1
    
  } else if (canindex == 2) {  //ย้ายไปวางช่อง 2
    
  } else if (canindex == 3) {  //ย้ายไปวางช่อง 3
    
  } else if (canindex == 4) {  //ย้ายไปวางช่อง 4
    
  } else if (canindex == 5) {  //ย้ายไปวางช่อง 5
    
  } else if (canindex == 6) {  //ย้ายไปวางช่อง 6
    
  }
}

void center() {
  TracJCL();
  TurnLeft();
  TracJCL();
  ServoUp();
  delay(200);
  MotorStop();
  TracJCL();
  TracJCL();
  TracJCL();
  TracJCL();
  TurnLeft();
  TracJC();
  TracJC();
  TurnRight();
  delay(1500);
}

void BackCenterRed() {
  ServoDown();
  delay(500);

  GripBoxX();
  delay(150);
  ServoUp();
  delay(300);
  MotorStop();
  UTurnLeft3();
  delay(300);
  TracJC();
  TracJC();
  TurnLeft();
  TracJC();
  TurnRight();
  MotorStop();
  delay(300);
}


void BackCenterGreen() {
  ServoDown();
  delay(600);
  GripBoxX();
  delay(200);
  ServoUp();
  delay(200);
  UTurnLeft2();
  TracJCSpeed();
  MotorStop();
}


void BackCenterWhite() {
  ServoDown();
  delay(600);
  GripBoxX();
  delay(200);
  ServoUp();
  delay(200);
  UTurnLeft2();
  TracJC();
  TracJC();
  TurnRight();
  TracJC();
  TurnLeft();
  MotorStop();
  delay(300);
}
