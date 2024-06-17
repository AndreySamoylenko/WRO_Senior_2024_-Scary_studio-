void turnl(int side, int speed, int way) {
  int dat = 0;
  int dat1 = 0;
  if (side == 1)
    dat = 2;
  else
    dat = 1;

  if (side == 3) {
    dat = 5;
  }

  if (side == 3) {
    dat = 6;
  }
  
  if (way == -1)
    if (dat == 1)
      dat = 3;
    else
      dat = 4;

  while (sensors(dat) < 160) {
    drive(side * speed, -side * speed);
  }
  while (sensors(dat) > 80) {
    drive(side * speed, -side * speed);
  }
  //   while (sensors(dat1) > 90) {
  //    drive(side * speed, -side * speed);
  //  }
  while (sensors(dat) < 90) {
    drive(side * speed, -side * speed);
  }
  drive(-side * 255, side * 255);
  delay(abs(speed) * 0.3);
  stop();

}
