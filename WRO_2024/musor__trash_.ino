
void trashMost() {
  //--------------------BLACK TRASH--------------------
  pidx(0.2, 0.02, 3, 60, 0, 0, 100);
  table_serv.write(28);
  turn(90, -1, 95);
  MoveSync(-90, -90, 0, 75, 1);
  ramkDown();
  delay(200);
  MoveSync(0, 90, 0, 20, 1);
  MoveSync(90, 90, 0, 55, 1);
  turn(90, 1, 95);
}

void trashNeMost() {
  MoveSync(-90, -90, 0, 230, 1);
  turn(90, 1, 86);
  ramkUp();
  MoveSync(-90, -90, 0, 125, 1);
  ramkDown();
  turn(90, -1, 91);

  MoveSync(-90, -90, 0, 140, 0);
  ramk.write(30);
  MoveSync(-90, -90, 0, 130, 1);
  ramkTube();
  delay(300);
  MoveSync(-90, -90, 0, 70, 1);

  ramkTubeUp(4);
  delay(200);
  ramkDown();
  MoveSync(90, 90, 0, 110, 1);
  turn(90, 1, 90);
  MoveSync(90, 90, 0, 200, 0);
  drive(100, 100);
  delay(500);
  stop();
  MoveSync(-90, -90, 0, 75, 1);
  table_serv.write(28);
  turn(90, 1, 88);
  MoveSync(90, 90, 0, 80, 1);
  getColors();
  indicate1(colorr, 7);
  indicate1(colorl, 0);
  if (USE_LED == 1)
    lent.show();
  MoveSync(-80, -80, 0, 50, 1);
  turn(90, -1, 90);
  sborGB(11);

  drive(100, 100);
  delay(800);
  MoveSync(-90, -90, 0, 163, 100);
  turn(90, -1, 90);
  MoveSync(90, 90, 0, 270, 0);
}

void sbros() {
  turn(90, 1, 100);
  ramk.write(30);
  MoveSync(-90, -90, 0, 200, 0);
  ramkDown();
  MoveSync(-90, -90, 0, 100, 1);
  MoveSync(0, -90, 0, 120, 0);
  MoveSync(-90, -90, 0, 450, 1);
  ramkUp();
  delay(200);
  MoveSync(90, 0, 0, 420, 0);
  drive(90, 90);
  delay(500);
  stop();
}
