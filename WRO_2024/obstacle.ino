void obstacle() {
  delay(200);
  pidenc(0.25, 0.03, 3, -100, 0, 150, 8);
  ramkUp();
  MoveSync(0, 170, 0, 290, 8);
  table_serv.write(156);
  MoveSync(170, 0, 0, 620, 8);
  manLeftDown(2);
  manRightDown(2);
  MoveSync(170, 170, 0, 150, 0);
  drive(120, 120);
  delay(1000);
  MoveSync(-90, -90, 0, 124, 8);
  beep(100);


  //  t_down();
  for (int i = manup_l.read(); i > MANUPL; i--) {
    manup_l.write(i);
    //  t_servo.write(i+xz);
    delay(12);
  }
  //  t_up();
  char finish_cubes[2] = {' ', ' '};
  wait_button(0);
  if (colorsl[3] == ' ' and colorsr[3] == ' ') {
    delay(1);
  }
  else {
    if (colorsl[3] == ' ') {
      finish_cubes[0] =  colorsr[3];
      finish_cubes[1] =  colorsr[3];
    }
    else {
      finish_cubes[0] =  colorsl[3];
      finish_cubes[1] =  colorsl[3];
    }
    sborGBinv(33 - logicGrab(finish_cubes));
  }
  MoveSync(-170, -170, 0, 90, 12);
  MoveSync(-170, 0, 0, 500, 8);
  while (sensors(3) > 40)
    drive(-200, -200);
  MoveSync(-110,-110,0,60,4);

  turnl(1, 120, 1);

  pidenc(0.25, 0.03, 3, -100, 0, 230, 0);
  pidx(0.3, 0.02, 3, 80, 0, 0, 90);

  MoveSync(0, -120, 0, 220, 60);
  MoveSync(-120, 0, 0, 240, 60);

  if (left_grob == 'b') {
    MoveSync(-90, -90, 0, 90, 60);
    delay(200);
    RightUnload(9);
    MoveSync(-90, -90, 0, 80, 60);
    delay(200);
    LeftUnload(9);
  }
  else {
    LeftUnload(9);
    MoveSync(-90, -90, 0, 310, 60);
    delay(200);
    RightUnload(9);
  }
  if (START_TYPE == 1) {
    MoveSync(150, 150, 0, 250, 20);
    MoveSync(23, 250, 0, 350, 20);
    MoveSync(250, 250, 0, 240, 160);
  }
  else {
    turn(120, -1, 20);
    ramkDown();
    MoveSync(-255, -255, 0, 450, 20);
  }

}
