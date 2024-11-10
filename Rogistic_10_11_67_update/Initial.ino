void Corlor() {
  R = 1;
  G = 2;
  B = 3;
  Y = 4;
  BC = 5;
  W = 6;
}

void InitialRef() {
  RefL2 = 3172;
  RefL1 = 2549;
  RefC = 2531;
  RefR1 = 2352;
  RefR2 = 2025;

  RefBL2 = 1924;
  RefBL1 = 2748;
  RefBR1 = 2392;
  RefBR2 = 2600;
}
void InitialSpeed() {
  //MaxSpeed = BaseSpeed;
  MaxSpeed = 100;
  Ki = 0;
  Error = 0;
  PreError = 0;
  KiB = 0;
  if (BaseSpeed <= 50) {
    LeftBaseSpeed = BaseSpeed - 1;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 1;
    BackRightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 5;  //forward PID
    Kd = 40;
    Kt = 10;
    KpB = 5;  //Backward PID
    KdB = 40;
    KtB = 10;
  } else if (BaseSpeed <= 60) {
    LeftBaseSpeed = BaseSpeed - 3;
    RightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 0;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 6;  //forward PID
    Kd = 50;
    Kt = 10;
    KpB = 6;  //Backward PID
    KdB = 50;
    KtB = 10;
  } else if (BaseSpeed <= 70) {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 1;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 1;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 7;  //forward PID
    Kd = 50;
    Kt = 10;
    KpB = 7;  //Backward PID
    KdB = 60;
    KtB = 10;
  } else if (BaseSpeed <= 80) {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 1;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 1;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 8;  //forward PID
    Kd = 60;
    Kt = 10;
    KpB = 8;  //Backward PID
    KdB = 70;
    KtB = 10;
  } else if (BaseSpeed <= 90) {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 1;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 1;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 9;  //forward PID
    Kd = 70;
    Kt = 10;
    KpB = 9;  //Backward PID
    KdB = 80;
    KtB = 10;
  } else {
    LeftBaseSpeed = BaseSpeed - 0;
    RightBaseSpeed = BaseSpeed - 1;
    BackLeftBaseSpeed = BaseSpeed - 0;
    BackRightBaseSpeed = BaseSpeed - 1;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 10;  //forward PID
    Kd = 80;
    Kt = 10;
    KpB = 10;  //Backward PID
    KdB = 90;
    KtB = 10;
  }
}

//****************************************************//


void InitialSpeedSlow() {
  MaxSpeed = SlowSpeed;
  MaxSpeed = 100;
  Ki = 0;
  Error = 0;
  PreError = 0;
  KiB = 0;
  if (SlowSpeed <= 50) {
    LeftBaseSpeed = SlowSpeed - 0;
    RightBaseSpeed = SlowSpeed - 0;
    BackLeftBaseSpeed = SlowSpeed - 0;
    BackRightBaseSpeed = SlowSpeed - 1.5;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 1.5;
    Kp = 5;  //forward PID
    Kd = 40;
    Kt = 10;
    KpB = 5;  //Backward PID
    KdB = 40;
    KtB = 10;


    /*Kp = 15;       //forward PID 
     Kd = 50;
    Kt = 10;
    KpB = 9;       backward PID
    KdB = 25;
    KtB = 10; */

  } else if (SlowSpeed <= 60) {
    LeftBaseSpeed = SlowSpeed - 3;
    RightBaseSpeed = SlowSpeed - 0;
    BackLeftBaseSpeed = SlowSpeed - 0;
    BackRightBaseSpeed = SlowSpeed - 0;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 6;  //forward PID
    Kd = 50;
    Kt = 10;
    KpB = 6;  //Backward PID
    KdB = 50;
    KtB = 10;
  } else if (SlowSpeed <= 70) {
    LeftBaseSpeed = SlowSpeed - 0;
    RightBaseSpeed = SlowSpeed - 1;
    BackLeftBaseSpeed = SlowSpeed - 0;
    BackRightBaseSpeed = SlowSpeed - 1;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 7;  //forward PID
    Kd = 50;
    Kt = 10;
    KpB = 7;  //Backward PID
    KdB = 60;
    KtB = 10;
  } else if (SlowSpeed <= 80) {
    LeftBaseSpeed = SlowSpeed - 0;
    RightBaseSpeed = SlowSpeed - 1;
    BackLeftBaseSpeed = SlowSpeed - 0;
    BackRightBaseSpeed = SlowSpeed - 1;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 8;  //forward PID
    Kd = 60;
    Kt = 10;
    KpB = 8;  //Backward PID
    KdB = 70;
    KtB = 10;
  } else if (SlowSpeed <= 90) {
    LeftBaseSpeed = SlowSpeed - 0;
    RightBaseSpeed = SlowSpeed - 1;
    BackLeftBaseSpeed = SlowSpeed - 0;
    BackRightBaseSpeed = SlowSpeed - 1;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 9;  //forward PID
    Kd = 70;
    Kt = 10;
    KpB = 9;  //Backward PID
    KdB = 80;
    KtB = 10;
  } else {
    LeftBaseSpeed = SlowSpeed - 0;
    RightBaseSpeed = SlowSpeed - 1;
    BackLeftBaseSpeed = SlowSpeed - 0;
    BackRightBaseSpeed = SlowSpeed - 1;
    BackLeftBaseSpeedYl = SpeedJC - 0;
    BackRightBaseSpeedYl = SpeedJC - 0;
    Kp = 10;  //forward PID
    Kd = 80;
    Kt = 10;
    KpB = 10;  //Backward PID
    KdB = 90;
    KtB = 10;
  }
}
