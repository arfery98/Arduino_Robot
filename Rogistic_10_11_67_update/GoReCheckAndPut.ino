/*---------------- Base Center   --------------------   */
void BaseCenter() {
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



/*-------------- ไปคีบธรรมดา ------------------- */
void GoCanRed() {
  ServoUp();
  delay(200);
  MotorStop();
  TurnLeft();
  TracJC();
  TurnRight();
  TracJC();
  TracJC();
  MotorStop();
}

void GoCanBlack() {
  ServoUp();
  delay(300);
  MotorStop();
  TurnRight();
  TracJC();
  TurnLeft();
  /*  ServoUp();
  delay(300);
  MotorStop();
  TracJCSpeed();
  MotorStop();
  TracJC();
  MotorStop();
  TurnRight();
  TracJC();
  TurnLeft();
  ServoDown();
  delay(600);
  GripBoxX();
  delay(200);
  ServoUp();
  delay(200); */
}

void GoCanBlue() {
  ServoUp();
  delay(300);
  MotorStop();
  TurnLeft();
  TracJC();
  TurnRight();

  /* ServoUp();
  delay(300);
  MotorStop();
  TracJCSpeed();
  TracJCSpeed();
  TracJC();
  TurnLeft();
  TracJC();
  TurnRight();
  ServoDown();
  delay(600);
  GripBoxX();
  delay(200);
  ServoUp();
  delay(200);
  TurnRight();
  TracJC();
  TurnRight();
  TracJCSpeed();
  TracJC();
  TurnLeft1();
  delay(400);
  Put1();
  GripBack();
  TurnLeft1(); */
}

void GoCanYellow() {
  BackwardSpeedTime(SlowSpeed, 50);
  MotorStop();
  /* ServoUp();
  delay(300);
  MotorStop();
  TracJCSpeed();
  TracJCSpeed();
  TracJCSpeed();
  TracJC();
  MotorStop();
  ServoDown();
  delay(500); */
  /* GripBoxX1();
  delay(200);
  ServoUp();
  delay(200);
  UTurnLeft(); */
}

void GoCanWhite() {
  ServoUp();
  delay(300);
  MotorStop();
  TurnRight();
  TracJC();
  TurnLeft();
  TracJC();
  TracJC();
  MotorStop();
  /* ServoUp();
  delay(300);
  MotorStop();
  TracJCSpeed();
  TracJC();
  TurnRight();
  TracJC();
  TurnLeft();
  TracJCSpeed();
  TracJC();
  MotorStop();
  ServoDown();
  delay(500); */
  /* GripBoxX1();
  delay(200);
  ServoUp();
  delay(200);
  UTurnLeft(); */
}

void GoCanGreen() {
  ServoUp();
  delay(300);
  MotorStop();
  TracJC();
  MotorStop();
  /* ServoUp();
  delay(300);
  MotorStop();
  TracJCSpeed();
  TracJCSpeed();
  TracJC();
  MotorStop();
  ServoDown();
  delay(500); */
  /* GripBoxX1();
  delay(200);
  ServoUp();
  delay(200);
  UTurnLeft();*/
}

/*-------------- ไปวางกระป๋องธรรมดา   -----------------  */
void WalkPut4() {
  TracJCSpeed();
  TracJCForPut();
  TurnRightPut();
  PutCan();
  GripBack();
  //TracJC();
  /* TurnRight1();
  delay(400); 
  Put1();*/

  //BackwardDelayYl(350);


  TurnRight();
  TracJCSpeed();
  TracJC();
  MotorStop();
}


void WalkPut2() {
  TracJCSpeed();
  TracJCSpeed();
  TracJCForPut();
  TurnRightPut();
  PutCan();
  GripBack();


  //BackwardDelayYl(350);
  TurnRight();
  TracJCSpeed();
  TracJCSpeed();
  TracJC();
  MotorStop();
}


void WalkPut1() {
  TracJCSpeed();
  TracJCSpeed();
  TracJCForPut();
  TurnLeftPut();
  PutCan();
  /* TracJC();
  TurnLeft1();
  delay(400);
  Put1();
  delay(100); */
  GripBack();


  //BackwardDelayYl(350);
  TurnLeft1();
  TracJCSpeed();
  TracJCSpeed();
  TracJC();
  MotorStop();
}
void WalkPut3() {
  TracJCSpeed();
  TracJCForPut();
  TurnLeftPut();
  PutCan();
  /* TracJC();
  TurnLeft1();
  delay(400);
  Put1(); */
  GripBack();


  //BackwardDelayYl(350);
  TurnLeft1();
  TracJCSpeed();
  TracJC();
  MotorStop();
}

void WalkPut5() {
  TracJCForPut();
  TurnLeftPut();
  PutCan();
  GripBack();
  /* TracJC();
  TurnLeft1();
  delay(400);
  Put1();
  
 */

  //BackwardDelayYl(350);
  TurnLeft1();
  TracJC();
  MotorStop();
}
void WalkPut6() {
  /* TracJC();
  TurnRight1();
  delay(400);
  Put1(); */
  TracJCForPut();
  TurnRightPut();
  PutCan();
  GripBack();


  //BackwardDelayYl(350);
  TurnRight();
  TracJC();
  MotorStop();
}




/*--------------- ไปคีบกระป๋องสำรอง --------------------------*/

void Canblue() {
  TracJC();
  TracJC();
  TurnRight();
  TracJC();
  TracJC();
  TracJCL();
  TurnLeft();
}
void Canyellow() {
  TracJC();
  TurnRight();
  TracJC();
  TracJCL();
  TurnLeft();
  CheckWall();
}
void Canblack() {
  TracJC();
  delay(100);
  TracJC();
  TurnRight();
  delay(100);
  /* Wait Code  */
  CheckWall();
}
void Canred() {
  TurnRight();
  TracJC();
  TracJC();
  TracJCL();
  TurnLeft();
}
void Cangreen() {
  TurnRight();
  TracJC();
  TracJCL();
  TurnLeft();
}
void Canwhite() {
  TurnRight();
  TracJCL();
  TurnLeft();
}


/*---------------------------- ไปวางกระป๋องชำรุด -----------------------*/

void back1() {
  TracJCBack();
  UTurnRight();
  TracJCR();
  delay(200);
  TurnRight();
  delay(200);
  TracJC();
  TracJC();
  TurnLeft();
  TracJC();
  TracJC();
  TracJCForPut();
  TurnLeftPut();
}
void back2() {
  TracJCBack();
  UTurnRight();
  TracJCR();
  TurnRight();
  TracJC();
  TracJC();
  TurnLeft();
  TracJC();
  TracJC();
  TracJCForPut();
  TurnRight();
}
void back3() {
  TracJCBack();
  UTurnRight();
  TracJCR();
  TurnRight();
  TracJC();
  TracJC();
  TurnLeft();
  TracJC();
  TracJCForPut();
  TurnLeftPut();
}
void back4() {
  TracJCBack();
  UTurnRight();
  TracJCR();
  TurnRight();
  TracJC();
  TracJC();
  TurnLeft();
  TracJC();
  TracJCForPut();
  TurnRightPut();
}
void back5() {
  TracJCBack();
  UTurnRight();
  TracJCR();
  TurnRight();
  TracJC();
  TracJC();
  TurnLeft();
  TracJCForPut();
  TurnLeftPut();
}
void back6() {
  TracJCBack();
  UTurnRight();
  TracJCR();
  TurnRight();
  TracJC();
  TracJC();
  TurnLeft();
  TracJCForPut();
  TurnRightPut();
}

//--------------------------------   ---------------------------------------------------

void CanDamaged1(){//เก็บกระป๋องชำรุดตำแหน่ง 1
  TracJC();  
  
  //TurnRightForGrip();   /*  1.ใส่แทร็ค TracJCForPut();  2.TurnRightPut()  3.CheckWall();        */
//ใส่Tarc + sonar
  //GripBoxX();
  TurnLeft();
  TracJCSpeed();
  TracJCSpeed();
  TracJC();
  MotorStop();
  TracJC();
  TurnRight();
  TracJC();
  TracJCL();
  //TurnLeftForGrip();
  //ใส่Tarc + sonar
}
void CanDamaged2(){//เก็บกระป๋องชำรุดตำแหน่ง 2
  TracJC();
  //TurnLeftForGrip();
  //ใส่Tarc + sonar
  GripBoxX();
  TurnRight();
  TracJCSpeed();
  TracJCSpeed();
  TracJC();
  MotorStop();
  TracJC();
  TurnRight();
  TracJC();
  TracJCL();
  //TurnLeftForGrip();
  //ใส่Tarc + sonar
}
void CanDamaged3(){//เก็บกระป๋องชำรุดตำแหน่ง 3
  TracJC();
  TracJC();
  //TurnRightForGrip();
  //ใส่Tarc + sonar
  GripBoxX();
  TurnLeft();
  TracJCSpeed();
  TracJC();
  MotorStop();
  TracJC();
  TurnRight();
  TracJC();
  TracJCL();
  //TurnLeftForGrip();
  //ใส่Tarc + sonar
}
void CanDamaged4(){//เก็บกระป๋องชำรุดตำแหน่ง 4
  TracJC();
  TracJC();
  //TurnLeftForGrip();
  //ใส่Tarc + sonar
  GripBoxX();
  TurnRight();
  TracJCSpeed();
   TracJC();
  MotorStop();
  TracJC();
  TurnRight();
  TracJC();
  TracJCL();
  //TurnLeftForGrip();
  //ใส่Tarc + sonar
}
void CanDamaged5(){//เก็บกระป๋องชำรุดตำแหน่ง 5
  TracJC();
  TracJC();
  TracJC();
  //TurnRightForGrip();
  //ใส่Tarc + sonar
  GripBoxX();
  TurnLeft();
  TracJC();
  MotorStop();
  TracJC();
  TurnRight();
  TracJC();
  TracJCL();
  //TurnLeftForGrip();
  //ใส่Tarc + sonar
}
void CanDamaged6(){//เก็บกระป๋องชำรุดตำแหน่ง 6
  TracJC();
  TracJC();
  TracJC();
  //TurnLeftForGrip();
  //ใส่Tarc + sonar
  GripBoxX();
  TurnRight();
  TracJC();
  MotorStop();
  TracJC();
  TurnRight();
  TracJC();
  TracJCL();
  //TurnLeftForGrip();
  //ใส่Tarc + sonar
}
