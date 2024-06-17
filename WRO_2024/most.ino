void most() {
  ramkUp();
  delay(100);
  table_serv.write(158);
  delay(300);
  pidx(0.3, 0.03, 3, 80, 0, 0, 0);
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
  MoveSync(60, 50, 0, 20, 1);
  getColors();
  listmovel();
  listmover();
  //  wait_button(0);
  digitalWrite(PASSIVE_A, 1);
  digitalWrite(PASSIVE_B, 0);
  drive(-180, -180);
  delay(400);
  drive(0, 0);
  digitalWrite(PASSIVE_A, 0);

  allClaws(1);
  manRightDown(1);
  manLeftDown(1);
  delay(600);
  claw_r.write(CLAWROPENISH - 5);
  claw_l.write(CLAWLOPENISH);
  delay(100);

  manup_r.write(MANDOWNR - 3);
  manup_l.write(MANDOWNL + 3);
  delay(300);

  claw_l.write(CLAWLCLOSE);
  claw_r.write(CLAWRCLOSE);
  count_c_l = 1;
  count_c_r = 1;
  delay(250);

  manLeftUp();
  manRightUp();

  delay(300);
  if (colorr == colorl)
    table_serv.write(158);
  digitalWrite(PASSIVE_A, 1);
  digitalWrite(PASSIVE_B, 0);
  delay(300);
  if (colorr == colorl) {
    manLeftDown(2);
  }

  delay(3500);
  digitalWrite(PASSIVE_A, 0);
  delay(500);
  pidenc(0.3, 0.03, 3, -80, 0, 400, 1);
  if (colorr == colorl) {
    manLeftDown(3);
    delay(300);
    claw_l.write(CLAWLOPEN);
    delay(200);
    manLeftUp();
    delay(300);
    pidenc(0.2, 0.02, 3, -100, 1, (335), 1);
    delay(200);
    RightGrab();
    delay(200);
    manRightUp();
    count_c_l = 0;
    colorl = ' ';
    listmovel();
    left_grob = (colorr == 'b' ? 'g' : 'b');
  }
  else {
    pidenc(0.2, 0.02, 3, -100, 1, (345), 1);
    left_grob = colorl;
  }
  if (START_TYPE == 0) {
    table_serv.write(28);
    delay(200);
    pidx(0.3, 0.03, 3, 80, 0, 0, 100);
    MoveSync(-90, 0, 0, 150, 100);
    MoveSync(0, -90, 0, 143, 100);
    manRightDown(2);
    manLeftDown(2);
    MoveSync(-90, -90, 0, 60, 100);

    sborGB(22);

    MoveSync(0, -90, 0, 143, 100);
    MoveSync(-90, 0, 0, 150, 100);

    pidenc(0.3, 0.03, 3, 80, 0, 200, 100);



  }
  manRightUp();
  manLeftUp();






}
