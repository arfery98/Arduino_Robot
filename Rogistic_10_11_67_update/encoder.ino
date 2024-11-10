// ฟังก์ชั่นนับ pulses (เรียกโดย interrupt)
void countPulse() {
  encoderCount++;
}

// ฟังก์ชั่นคำนวณระยะทางจาก pulses
float calculateDistance() {
  float revolutions = encoderCount / (float)PULSES_PER_REVOLUTION;
  float distance = PI * WHEEL_DIAMETER * revolutions;
  return distance;
}

// ฟังก์ชั่นควบคุมการเคลื่อนที่
void moveRobot(float targetDistance, int speed) {
  encoderCount = 0;  // รีเซ็ตตัวนับ

  while (calculateDistance() < targetDistance) {
    // เริ่มขับมอเตอร์
    FD2(19, 20);
    oled.clear();  //เคลียร์หน้าจอ
    oled.text(6, 0, "Distance: %f", calculateDistance());
    oled.show();
  }
  // หยุดมอเตอร์
  MotorStop();
}