

// ฟังก์ชันสำหรับเปรียบเทียบค่าสี
int identifyColor(ColorValue current) {
  // คำนวณความแตกต่างของค่าสีกับค่ามาตรฐาน
  float diffRed = abs(current.r - COLOR_RED.r) + abs(current.g - COLOR_RED.g) + abs(current.b - COLOR_RED.b) + abs(current.c - COLOR_RED.c);
  float diffWhite = abs(current.r - COLOR_WHITE.r) + abs(current.g - COLOR_WHITE.g) + abs(current.b - COLOR_WHITE.b) + abs(current.c - COLOR_WHITE.c);
  float diffGreen = abs(current.r - COLOR_GREEN.r) + abs(current.g - COLOR_GREEN.g) + abs(current.b - COLOR_GREEN.b) + abs(current.c - COLOR_GREEN.c);
  float diffBlack = abs(current.r - COLOR_BLACK.r) + abs(current.g - COLOR_BLACK.g) + abs(current.b - COLOR_BLACK.b) + abs(current.c - COLOR_BLACK.c);
  float diffYellow = abs(current.r - COLOR_YELLOW.r) + abs(current.g - COLOR_YELLOW.g) + abs(current.b - COLOR_YELLOW.b) + abs(current.c - COLOR_YELLOW.c);
  float diffBlue = abs(current.r - COLOR_BLUE.r) + abs(current.g - COLOR_BLUE.g) + abs(current.b - COLOR_BLUE.b) + abs(current.c - COLOR_BLUE.c);

  // หาค่าที่น้อยที่สุด
  float minDiff = min(diffRed, min(diffWhite, min(diffGreen, min(diffBlack, min(diffYellow, diffBlue)))));

  if (minDiff == diffRed) return 1;
  if (minDiff == diffGreen) return 2;
  if (minDiff == diffBlue) return 3;
  if (minDiff == diffYellow) return 4;
  if (minDiff == diffBlack) return 5;
  if (minDiff == diffWhite) return 6;

  return 0;
}

// ฟังก์ชันแสดงชื่อสี
const char* getColorName(int color) {
  switch (color) {
    case 1:
      return "RED";
    case 2:
      return "GREEN";
    case 3:
      return "BLUE";
    case 4:
      return "YELLOW";
    case 5:
      return "BLACK";
    case 6:
      return "WHITE";
    default:
      return "UNKNOWN";
  }
}

// ฟังก์ชันสำหรับตรวจจับสีและบันทึกลำดับ
void detectAndStoreColor() {
  ColorValue current;
  tcs.getRawData(&current.r, &current.g, &current.b, &current.c);

  int color = identifyColor(current);
  if (colorCount == 0 || color != detectedColors[colorCount - 1]) {
    if (colorCount < 6) {
      detectedColors[colorCount] = color;
      oled.clear();
      oled.textSize(1);
      oled.text(3, 0, getColorName(color));
      oled.show();
      colorCount++;
    }
  }
}

// ฟังก์ชันตรวจสอบและแก้ไขการตรวจสีไม่พบหรือซ้ำ
void checkAndCorrectColors() {
  // สร้าง array สำหรับเก็บจำนวนสีที่พบ
  int availableColors[NUM_COLORS] = { 0 };

  // เก็บจำนวนสีที่พบ
  for (int i = 0; i < NUM_COLORS; i++) {
    if (detectedColors[i] >= 1 && detectedColors[i] <= NUM_COLORS) {
      availableColors[detectedColors[i] - 1]++;
    }
  }

  // ค้นหาและแทนที่สีที่หาไม่พบ
  for (int i = 0; i < NUM_COLORS; i++) {
    if (detectedColors[i] == 0) {
      // ค้นหาตำแหน่งสีที่มีจำนวนเป็น 0 และแทนที่ด้วยสีใหม่
      for (int j = 0; j < NUM_COLORS; j++) {
        if (availableColors[j] == 0) {
          detectedColors[i] = j + 1;
          availableColors[j]++;
          break;
        }
      }
    }
  }

  // ค้นหาและแทนที่สีที่ซ้ำ
  for (int i = 0; i < NUM_COLORS; i++) {
    for (int j = i + 1; j < NUM_COLORS; j++) {
      if (detectedColors[i] == detectedColors[j]) {
        // ค้นหาตำแหน่งสีที่มีจำนวนเป็น 0 และแทนที่สีที่ซ้ำด้วยสีใหม่
        for (int k = 0; k < NUM_COLORS; k++) {
          if (availableColors[k] == 0) {
            detectedColors[j] = k + 1;
            availableColors[k]++;
            break;
          }
        }
      }
    }
  }
}

/* void ColorDetection() {
  TracJCStop();
  //ทดสอบการเดินตามเวลา
  //ForwardSpeedTime(20, 1650);
  FD2(20, 20);
  delay(1650);
  //หยุดที่แถบ 1
  MotorStop();
  delay(500);
  for (int i = 0; i < 6; i++) {
    //อ่านค่าสี
    detectAndStoreColor();
    //เดินหน้าต่อไป
    FD2(20, 20);
    delay(590);
    MotorStop();
    delay(500);
  }
  oled.clear();
  oled.textSize(1);
  for (int i = 0; i < 6; i++) {
    oled.text(i, 0, getColorName(detectedColors[i]));
  }
  oled.show();
} */
void ColorDetection() {
  MotorStop();
  TracJCStop();
  //moveRobot(30.0, 20);
  ForwardSpeedTime(20, 1050);
  for (int i = 0; i < 5; i++) {
    //อ่านค่าสี
    detectAndStoreColor();
    //เดินหน้าต่อไป
    moveRobot(7, 20);
    delay(1500);
  }

  detectAndStoreColor();
  delay(1000);
  //ตรวจสอบและแก้ไขการตรวจสีไม่พบหรือซ้ำ
  checkAndCorrectColors();

  oled.clear();
  oled.textSize(1);
  for (int i = 0; i < 6; i++) {
    oled.text(i, 0, getColorName(detectedColors[i]));
  }
  oled.show();
}

/*  detectedColors[0]={6};
 detectedColors[1]={2};
 detectedColors[2]={5};
 detectedColors[3]={1};
 detectedColors[4]={3};
 detectedColors[5]={4}; */


void ShowCodeColor() {
  while (1) {  // หรือ while(true)
    ColorValue current;
    tcs.getRawData(&current.r, &current.g, &current.b, &current.c);
    int colorCode = identifyColor(current);
    const char* colorName = getColorName(colorCode);

    oled.clear();
    oled.text(0, 0, "Detect color.");
    oled.text(2, 0, "R %d", (int)current.r);
    oled.text(3, 0, "G %d", (int)current.g);
    oled.text(4, 0, "B %d", (int)current.b);
    oled.text(5, 0, "C %d", (int)current.c);
    oled.text(6, 0, colorName);
    oled.show();
    delay(100);
  }
}

int getCanIndex(int color) {
  int ind = 0;
  for (int i = 0; i < 6; i++) {
    if (detectedColors[i] == color) {
      ind = i;
      break;
    }
  }
  return ind + 1;
}

int getBrickIndex(int color) {
  int ind = 0;
  for (int i = 0; i < 6; i++) {
    if (detectedColors[i] == color) {
      ind = i;
      break;
    }
  }
  return ind + 1;
}