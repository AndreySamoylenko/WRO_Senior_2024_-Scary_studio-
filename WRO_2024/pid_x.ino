void pidx(float kp, float ki, float kd, float sped, int razgon, int overdrive,  int stop) {
  float speed = abs(sped);
  uint8_t GayFlag = 0;


  if (speed > 256) {
    GayFlag = 1;
  }
  else {
    GayFlag = 0;
  }

  if (GayFlag == 1) {
    sped = 256 - sped;
    speed = abs(sped);
  }


  dat1 = 255;
  dat2 = 255;

  float kp1 = kp;
  float kd1 = kd;
  float ki1 = ki;

  countr = 0;
  countl = 0;
  int minx = 20;
  if (GayFlag)
    minx = 45;
  int err_i = 0;
  float sum = 0;
  float errors[10] = {0};
  e_old = 0;

  while (dat1 > minx or dat2 > minx) {

    if (GayFlag) {
      dat1 = sensors(6);
      dat2 = sensors(5);
    }
    else {
      if (sped > 0) {
        dat1 = sensors(1);
        dat2 = sensors(2);
      }
      else {
        dat1 = sensors(4);
        dat2 = sensors(3);
      }
    }
    float e = (dat2 - dat1);
    if (abs(e) < 4)
      e = 0;

    errors[err_i] = e;
    err_i = (err_i + 1) % 10;
    sum = sum + e - errors[err_i];

    float Up = e * kp1;
    float Ud = (e - errors[err_i]) * kd1;
    float Ui = sum * ki1;

    float U = Up + Ui + Ud;

    if (razgon == 1) {
      float enc = (countl + countr) / 2;
      speed = MIN_SPEED + (abs(sped) - MIN_SPEED) * enc / 500;
      if (speed >= abs(sped)) {
        kp1 = kp ;
        kd1 = kd ;
        ki1 = ki ;
        razgon = 0;
      }
    }

    float mot1 = speed - U;
    float mot2 = speed + U;

    mot1 = constrain(mot1, 0, 1.3 * speed);
    mot2 = constrain(mot2, 0, 1.3 * speed);
    drive(mot1 * sped / abs(sped), mot2 * sped / abs(sped));
  }

  if (overdrive > 0)
    pidenc(kp, ki, kd, sped * 0.8, 0, overdrive, stop);
  else if (stop>0) {
    drive (-250 * sped / abs(sped), -250 * sped / abs(sped));
    delay((abs(sped) / 255) * stop);
    drive (0, 0);
    beep(100);
  }
}

void pidenc(float kp, float ki, float kd, float sped, int razgon, int dist, int stop) {
  float speed = abs(sped);
  uint8_t GayFlag = 0;


  if (speed > 256) {
    GayFlag = 1;
  }
  else {
    GayFlag = 0;
  }

  if (GayFlag == 1) {
    sped = 256 - sped;
    speed = abs(sped);
  }


  dat1 = 255;
  dat2 = 255;

  float kp1 = kp;
  float kd1 = kd;
  float ki1 = ki;

  countr = 0;
  countl = 0;

  int err_i = 0;
  float sum = 0;
  float errors[10] = {0};
  e_old = 0;

  while ((countl + countr) / 2 < dist) {

    if (GayFlag) {
      dat1 = sensors(6);
      dat2 = sensors(5) - 30;
    }
    else {
      if (sped > 0) {
        dat1 = sensors(1);
        dat2 = sensors(2);
      }
      else {
        dat1 = sensors(4);
        dat2 = sensors(3);
      }
    }
    float e = (dat2 - dat1);
    if (abs(e) < 4)
      e = 0;

    errors[err_i] = e;
    err_i = (err_i + 1) % 10;
    sum = sum + e - errors[err_i];

    float Up = e * kp1;
    float Ud = (e - errors[err_i]) * kd1;
    float Ui = sum * ki1;

    float U = Up + Ui + Ud;

    if (razgon == 1) {
      float enc = (countl + countr) / 2;
      speed = MIN_SPEED + (abs(sped) - MIN_SPEED) * enc / 500;
      if (speed >= abs(sped)) {
        kp1 = kp ;
        kd1 = kd ;
        ki1 = ki ;
        razgon = 0;
      }
    }

    float mot1 = speed - U;
    float mot2 = speed + U;

    mot1 = constrain(mot1, 0, 1.3 * speed);
    mot2 = constrain(mot2, 0, 1.3 * speed);
    drive(mot1 * sped / abs(sped), mot2 * sped / abs(sped));
  }

  if (stop >0) {
    drive (-255 * sped / abs(sped), -255 * sped / abs(sped));
    delay(((abs(sped) + abs (sped)) / 2) / 255 * stop);
    drive (0, 0);
    delay(100);
  }
}

void prikol() {
  int sped = -120;
  int speed = abs(sped);

  dat1 = 255;
  dat2 = 255;

  countr = 0;
  countl = 0;

  int err_i = 0;
  float sum = 0;
  float errors[10] = {0};
  e_old = 0;

  while (dat1 > 30 or dat2 > 30) {

    dat1 = sensors(6);
    dat2 = sensors(5);

    float e = (sensors(3) - sensors(4));
    if (abs(e) < 4)
      e = 0;

    errors[err_i] = e;
    err_i = (err_i + 1) % 10;
    sum = sum + e - errors[err_i];

    float Up = e * 0.3;
    float Ud = (e - errors[err_i]) * 3;
    float Ui = sum * 0.03;

    float U = Up + Ui + Ud;

    float mot1 = 90 - U;
    float mot2 = 90 + U;

    mot1 = constrain(mot1, 0, 1.3 * 90);
    mot2 = constrain(mot2, 0, 1.3 * 90);
    drive(mot1 * sped / abs(sped), mot2 * sped / abs(sped));
  }
}
