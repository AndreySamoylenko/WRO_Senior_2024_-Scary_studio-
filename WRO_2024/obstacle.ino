void obstacle() {
  delay(200);
  digitalWrite(STATE_PIN, 0);
  t_up();
  table_serv.write(158);
  delay(300);
  pidenc(0.25, 0.03, 3, -100, 0, 150, 40);
  delay(50);
  ramkUp();
  MoveSync(0, 130, 0, 290, 80);
  MoveSync(130, 0, 0, 635, 8);
//  wait_button(0);
  manRightUp();
  MoveSync(130, 130, 0, 150, 0);
  drive(120, 120);
  delay(400);
  drive(60, 60);
  delay(300);
  stop();
  delay(300);

  MoveSync(-90, -90, 0, 124, 60);
  manLeftDown(7);
  delay(100);
  beep(100);
  for (int i = 150; i > 100; i--)
  {
    t_servo.write(i);
    delay(9);
  }

  for (int i = 97; i > 65; i--) {
    manup_l.write(i);
    t_servo.write(map(i, 65, 97, 47, 80));
    delay(45);
  }
  table_serv.write(155);
  t_up();
  manRightDown(2);
  manLeftDown(2);
  delay(200);
//  wait_button(0);
  char finish_cubes[2] = {' ', ' '};
  //  wait_button(0);
  if (colorsl[3] == ' ' and colorsr[3] == ' ') {
    manLeftDown(1);
    delay(100);
    claw_l.write(CLAWLOPENISH + 4);
    delay(300);
    manLeftDown(0);
    delay(350);
    claw_l.write(CLAWLOPEN);
    delay(1000);
    get_color_man();
    indicate1(colorl, 6);
    colorr = (colorl == 'b' ? 'g' : 'b');
    if (colorl != left_grob)
      beep(400);
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
      MoveSync(-180, -180, 0, 200, 20);
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
  //  MoveSync(-170, -170, 0, 240, 12);
  MoveSync(-170, 0, 0, 550, 12);
  //  MoveSync(-110, -110, 0, 100, 0);
  while (sensors(3) > 40)
    drive(-180, -180);
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
    MoveSync(-90, -90, 0, 110, 60);
    delay(200);
    LeftUnload(12);
  }
  else {
    LeftUnload(10);
    MoveSync(-90, -90, 0, 290, 60);
    delay(200);
    RightUnload(12);
  }
  if (START_TYPE == 1) {
    MoveSync(255, 255, 0, 330, 20);
    table_serv.write(94);
    t_servo.write(110);
    MoveSync(23, 255, 0, 380, 20);
    manLeftDown(1);
    //    MoveSync(255, 255, 0, 100, 20);
  }
  else {
    MoveSync(-255, 0, 0, 100, 0);
    ramkDown();
    MoveSync(-255, -255, 0, 400, 20);
  }
  delay(350);
  digitalWrite(RELAY_PIN, 0);
}
