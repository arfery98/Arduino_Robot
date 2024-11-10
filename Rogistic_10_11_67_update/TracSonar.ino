int sensorPin = A8;  // ขาแอนะล็อกที่เชื่อมต่อกับ out ของ ZX Sonar1m
float voltage = 0;
float distance = 0;

int Sonar() {
  int Sonar;

  //Sonar = (analog(8)/40); //ZX-sonar
  Sonar = analog(8);  //infrared
  Sonar -= 1150;
  if (Sonar <= 0) Sonar = 1;
  Sonar = 6000 / Sonar;
  return (Sonar);
}

int CheckCan()  //check มีกระป๋องไหม 0:ไม่มี 1:มี
{
  MotorStop();
  delay(100);
  for (int i = 0; i < 5; i++) {
    delay(10);
    if (Sonar() < CanSonarRef) return (1);  //มีกระป๋อง
  }
  CanSonarRef = 10000;  //ไม่ต้องเช็คกระป๋องอีก
  return (0);           //ไม่มีกระป๋อง
}


void TracSonar() {

  BaseSpeed = SonarSpeed;
  InitialSpeed();
  while (Sonar() > DistanceRef) {
    TracPID();
    StartTimer();
    while ((ReadTimer() < Kt) && (Sonar() > DistanceRef)) {
      CalError();
    }
  }
  OffMotor();
  BaseSpeed = Speed;
  InitialSpeed();
}
void DetecSonar() {
  while (true) {
    voltage = analogRead(sensorPin) * (3.27 / 1023.0);  // แปลงค่า ADC เป็นแรงดัน
    distance = voltage * 10;                            // สมมุติว่า 1V = 100 cm (ควรปรับค่าให้ตรงตามสเปค)

    char distanceStr[10];
    dtostrf(distance, 4, 1, distanceStr);
    float distanceValue = atof(distanceStr);

    oled.clear();
    oled.textSize(1);
    oled.text(0, 0, "Distance: ");
    oled.text(0, 10, distanceStr);
    oled.text(50, 10, "cm");
    oled.show();
    delay(100);
  }
}

void CheckDist() {
  const float conversionFactor = 3.27 / 1023.0 * 10;  // ค่าคงที่สำหรับการแปลงค่า ADC เป็นระยะทาง

  while (true) {
    // อ่านค่าจากเซ็นเซอร์และคำนวณระยะทาง
    float voltage = analogRead(sensorPin);        // อ่านค่า ADC จากเซ็นเซอร์
    float distance = voltage * conversionFactor;  // แปลงค่าเป็นระยะทางโดยใช้ conversionFactor

    if (distance <= 10) {
      MotorStop();
      GripDelay();  // ลงแล้วคีบ
      break;
    } else {
      Forward1();
    }
    delay(20);
  }
}

void PutCan() {
  const float conversionFactor = 3.27 / 1023.0 * 10;  // ค่าคงที่สำหรับการแปลงค่า ADC เป็นระยะทาง

  while (true) {
    // อ่านค่าจากเซ็นเซอร์และคำนวณระยะทาง
    float voltage = analogRead(sensorPin);        // อ่านค่า ADC จากเซ็นเซอร์
    float distance = voltage * conversionFactor;  // แปลงค่าเป็นระยะทางโดยใช้ conversionFactor

    if (distance <= 4) {
      MotorStop();
      Put1();  // 
      break;
    } else {
      FD2(20, 20);
    }
    delay(20);
  }
}

void CheckWall() {
  const float conversionFactor = 3.27 / 1023.0 * 10;  // ค่าคงที่สำหรับการแปลงค่า ADC เป็นระยะทาง

  while (true) {
    // อ่านค่าจากเซ็นเซอร์และคำนวณระยะทาง
    float voltage = analogRead(sensorPin);        // อ่านค่า ADC จากเซ็นเซอร์
    float distance = voltage * conversionFactor;  // แปลงค่าเป็นระยะทางโดยใช้ conversionFactor

    if (distance <= 5) {
      MotorStop();
      ServoRe();
                    //ใส่คีบ
      GripDelay();  // /* ยังไม่ทำคีบ   */
      break;
    } else {
      FD2(20, 20);
    }
    delay(20);
  }
}


void CheckDistCanY() {  //เช็คกระป๋องสีเหลือง
  const float conversionFactor = 3.27 / 1023.0 * 10;
  float voltage = analogRead(sensorPin);
  float distance = voltage * conversionFactor;

  if (distance <= 25) {
    ServoDown();
    delay(1000);
    Grip();
    delay(500);
    BackwardSpeedTime(SlowSpeed, 20);
    MotorStop();
    ServoUp();
    delay(200);
    TurnLeft();
    delay(100);
    TurnLeft();
    //UTurnLeft2();
    MotorStop();
    delay(300);
    BackwardSpeedTime(SlowSpeed, 100);
    MoveCanned();
  } else {
    Canyellow();
    MoveCannedError();
  }
}
void CheckDistCanB() {  //เช็คกระป๋องสีน้ำเงิน
  const float conversionFactor = 3.27 / 1023.0 * 10;
  float voltage = analogRead(sensorPin);
  float distance = voltage * conversionFactor;

  if (distance <= 25) {
    ServoDown();
    delay(600);
    GripBoxX();
    delay(200);
    ServoUp();
    delay(200);
    TurnRight();
    TracJC();
    TurnRight();
    MotorStop();
    delay(300);
    
    MoveCanned();
  } else {
    Canblue();
    MoveCannedError();
  }
}
void CheckDistCanBlack() { //เช็คกระป๋องสีดำ
  const float conversionFactor = 3.27 / 1023.0 * 10;
  float voltage = analogRead(sensorPin);
  float distance = voltage * conversionFactor;

  if (distance <= 25) {
    ServoDown();
    delay(600);
    GripBoxX();
    delay(200);
    ServoUp();
    delay(200);
    TurnLeft1();
    TracJC();
    TurnLeft();
    MotorStop();
    delay(300);
    MoveCanned();
  } else {
    Canblack();
    MoveCannedError();
  }
}
void CheckDistCanR() {  //เช็คกระป๋องสีแดง
  const float conversionFactor = 3.27 / 1023.0 * 10;
  float voltage = analogRead(sensorPin);
  float distance = voltage * conversionFactor;

  if (distance <= 25) {
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
    MoveCanned();
  } else {
    Canred();
    MoveCannedError();
  }
}
void CheckDistCanG() {   //เช็คกระป๋องสีเขียว
  const float conversionFactor = 3.27 / 1023.0 * 10;
  float voltage = analogRead(sensorPin);
  float distance = voltage * conversionFactor;

  if (distance <= 25) {
    ServoDown();
    delay(600);
    GripBoxX();
    delay(200);
    ServoUp();
    delay(200);
    UTurnLeft2();
    TracJCSpeed();
    MotorStop();
    MoveCanned();
  } else {
    Cangreen();
    MoveCannedError();
  }
}
void CheckDistCanW() {   //เช็คกระป๋องสีขาว
  const float conversionFactor = 3.27 / 1023.0 * 10;
  float voltage = analogRead(sensorPin);
  float distance = voltage * conversionFactor;

  if (distance <= 25) {
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
    MoveCanned();
  } else {
    Canwhite();
    MoveCannedError();
  }
}
