void most() {
  ramkUp();
  t_up();
  delay(100);
  table_serv.write(158);
  delay(300);
  pidx(0.4, 0.03, 3, 130, 0, 0, 0);
  MoveSync(100, 100, 0, 45, 0);
  manLeftDown(1);
  manRightDown(1);
  drive(250, 250);
  digitalWrite(PASSIVE_A, 0);
  digitalWrite(PASSIVE_B, 1);
  delay(1000);
  delay(300);
  drive(0, 0);
  delay(2900);
  digitalWrite(PASSIVE_B, 0);
  manLeftUp();
  manRightUp();
  delay(350);
  table_serv.write(92);
  MoveSync(70, 70, 0, 20, 12);
  getColors();

  //  wait_button(0);
  digitalWrite(PASSIVE_A, 1);
  digitalWrite(PASSIVE_B, 0);
  drive(-255, -255);
  delay(350);
  drive(0, 0);
  digitalWrite(PASSIVE_A, 0);

  claw_r.write(CLAWRCLOSE + 33);
  claw_l.write(CLAWLCLOSE + 33);
  delay(200);
  //  wait_button(0);
  manup_r.write(MANDOWNISHR - 0);
  manup_l.write(MANDOWNISHL + 0);
  delay(500);
  claw_r.write(CLAWROPENISH);
  claw_l.write(CLAWLOPENISH);
  //  wait_button(0);
  delay(600);

  manup_r.write(MANDOWNR - 2);
  manup_l.write(MANDOWNL + 2);
  delay(400);

  claw_l.write(CLAWLCLOSE);
  claw_r.write(CLAWRCLOSE);
  count_c_l = 1;
  count_c_r = 1;
  delay(250);

  manLeftUp();
  manRightUp();

  delay(300);
  table_serv.write(155);
  if (colorr != colorl)
    listmovel();

  listmover();

  digitalWrite(PASSIVE_A, 1);
  digitalWrite(PASSIVE_B, 0);
  delay(300);
  manLeftDown(2);
  manRightDown(2);


  delay(3900);
  digitalWrite(PASSIVE_A, 0);
  delay(300);
  //  pidenc(0.3, 0.03, 3, -80, 0, 400, 50);
  left_grob = (colorr == 'b' ? 'g' : 'b');
  right_grob = colorr;
  if (colorr == colorl) {
    pidenc(0.3, 0.03, 3, -90, 0, 200, 12);
    manLeftDown(0);
    delay(300);
    claw_l.write(CLAWLOPEN);
    delay(200);
    manLeftUp();
    delay(300);
    pidenc(0.3, 0.03, 3, -100, 0, (305), 5);
    delay(200);
    RightGrab();
    delay(200);
    manRightUp();
    count_c_l = 0;
    colorl = (colorr == 'b' ? 'g' : 'b');
  }
  else {
    pidenc(0.3, 0.03, 3, -100, 0, (305), 0);
    left_grob = colorl;
  }
  pidenc(0.3, 0.03, 3, -100, 0, (335), 5);
  if (START_TYPE == 0) {
    manRightUp();
    manLeftUp();
    delay(300);
    table_serv.write(28);
    pidenc(0.3, 0.03, 3, -120, 1, (305), 12);
    pidx(0.3, 0.03, 3, 80, 0, 0, 9);
    pidenc(0.3, 0.03, 3, -120, 1, (275), 12);
    MoveSync(-90, 0, 0, 149, 70);
    MoveSync(0, -90, 0, 144, 70);
    manRightDown(2);
    manLeftDown(2);

    sborGB(logicGrab(start_cubes));

    MoveSync(0, -90, 0, 144, 70);
    MoveSync(-90, 0, 0, 149, 70);
    pidenc(0.3, 0.03, 3, 90, 0, 300, 20);
  }
  manRightUp();
  manLeftUp();
}
