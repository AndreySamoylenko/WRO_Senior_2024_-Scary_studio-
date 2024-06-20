void most() {
  ramkUp();
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
  delay(2700);
  digitalWrite(PASSIVE_B, 0);
  manLeftUp();
  manRightUp();
  delay(350);
  table_serv.write(92);
  MoveSync(70, 0, 0, 20, 12);
  MoveSync(50, 50, 0, 10, 12);
  getColors();

  //  wait_button(0);
  digitalWrite(PASSIVE_A, 1);
  digitalWrite(PASSIVE_B, 0);
  drive(-255, -255);
  delay(350);
  drive(0, 0);
  digitalWrite(PASSIVE_A, 0);

  allClaws(1);
  manRightDown(1);
  manLeftDown(1);
  delay(600);
  claw_r.write(CLAWROPENISH);
  claw_l.write(CLAWLOPENISH + 20);
  delay(200);

  manup_r.write(MANDOWNR - 3);
  manup_l.write(MANDOWNL + 3);
  delay(400);

  claw_l.write(CLAWLCLOSE);
  claw_r.write(CLAWRCLOSE);
  count_c_l = 1;
  count_c_r = 1;
  delay(250);

  manLeftUp();
  manRightUp();

  delay(300);
  if (colorr == colorl)
    table_serv.write(155);
  else
    listmovel();

  listmover();

  digitalWrite(PASSIVE_A, 1);
  digitalWrite(PASSIVE_B, 0);
  delay(300);
  if (colorr == colorl) {
    manLeftDown(2);
  }

  delay(3400);
  digitalWrite(PASSIVE_A, 0);
  delay(300);
  //  pidenc(0.3, 0.03, 3, -80, 0, 400, 50);
  left_grob = (colorr == 'b' ? 'g' : 'b');
  right_grob = colorr;
  if (colorr == colorl) {
    manLeftDown(3);    delay(300);
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
    colorl = ' ';
    listmovel();
  }
  else {
    pidenc(0.3, 0.03, 3, -100, 1, (305), 0);
    left_grob = colorl;
  }
  pidenc(0.3, 0.03, 3, -100, 0, (335), 5);
  if (START_TYPE == 0) {
    table_serv.write(28);
    pidenc(0.3, 0.03, 3, -120, 1, (305), 12);
    pidx(0.3, 0.03, 3, 80, 0, 0, 9);
    pidenc(0.3, 0.03, 3, -120, 1, (245), 12);
    MoveSync(-90, 0, 0, 145, 70);
    MoveSync(0, -90, 0, 140, 70);
    manRightDown(2);
    manLeftDown(2);
  
    sborGB(logicGrab(start_cubes));

    MoveSync(0, -90, 0, 140, 70);
    MoveSync(-90, 0, 0, 145, 70);
    pidenc(0.3, 0.03, 3, 90, 0, 300, 20);
  }
  manRightUp();
  manLeftUp();
}
