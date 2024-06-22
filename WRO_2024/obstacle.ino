void obstacle() {
  delay(200);
  digitalWrite(STATE_PIN, 0);
  t_up();
  table_serv.write(156);
  delay(300);
  pidenc(0.25, 0.03, 3, -100, 0, 190, 8);
  ramkUp();
  MoveSync(0, 170, 0, 290, 80);
  MoveSync(170, 0, 0, 628, 48);
  manLeftDown(0);
  manRightUp();
  MoveSync(170, 170, 0, 150, 0);
  drive(120, 120);
  delay(1000);
  MoveSync(-90, -90, 0, 124, 60);
  beep(100);


  t_servo.write(90);
  //  wait_button(0);

  for (int i = 105; i > 70; i--) {
    manup_l.write(i);
    t_servo.write(map(i, 70, 105, 40, 90));
    delay(30);
  }
  t_up();
  manRightDown(2);
  manLeftDown(2);
  delay(200);
  char finish_cubes[2] = {' ', ' '};
  wait_button(0);
  if (colorsl[3] == ' ' and colorsr[3] == ' ') {
    manLeftDown(1);
    delay(100);
    claw_l.write(CLAWLOPENISH);
    delay(300);
    manLeftDown(0);
    delay(350);
    get_color_man();
    colorr = (colorl == 'b' ? 'g' : 'b');
    if (colorl == left_grob) {
      manRightDown(1);
      claw_l.write(CLAWLCLOSE);
      claw_r.write(CLAWROPENISH);
      delay(300);
      manRightDown(0);
      delay(300);
      claw_r.write(CLAWRCLOSE);
      delay(300);
      count_c_l ++;
      count_c_r ++;
      manRightUp();
      manLeftUp();
      listmover();
      listmovel();
    }
    else {
      manLeftDown(1);
      delay(100);
      claw_l.write(CLAWLCLOSE);
      delay(300);
      manLeftDown(2);
      manRightDown(2);
      sborGBinv(21);
    }
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
  MoveSync(-170, -170, 0, 240, 12);
  MoveSync(-170, 0, 0, 550, 12);
  MoveSync(-110, -110, 0, 100, 0);
  while (sensors(3) > 40)
    drive(-110, -110);
  MoveSync(-110, -110, 0, 60, 4);

  turnl(1, 120, -1);

  pidenc(0.25, 0.03, 3, -100, 0, 230, 0);
  pidx(0.3, 0.02, 3, 80, 0, 0, 80);

  MoveSync(0, -120, 0, 230, 60);
  MoveSync(-120, 0, 0, 250, 60);

  if (left_grob == 'b') {
    MoveSync(-90, -90, 0, 90, 60);
    delay(200);
    RightUnload(9);
    MoveSync(-90, -90, 0, 80, 60);
    delay(200);
    LeftUnload(12);
  }
  else {
    LeftUnload(9);
    MoveSync(-90, -90, 0, 290, 60);
    delay(200);
    RightUnload(12);
  }
  if (START_TYPE == 1) {
    MoveSync(150, 150, 0, 350, 20);
    MoveSync(23, 250, 0, 370, 20);
    MoveSync(250, 250, 0, 270, 160);
  }
  else {
    MoveSync(-255, 0, 0, 100, 0);
    ramkDown();
    MoveSync(-255, -255, 0, 400, 20);
  }

}
