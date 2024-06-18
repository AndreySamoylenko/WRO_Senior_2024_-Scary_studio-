
void trashMost() {
  //--------------------BLACK TRASH--------------------
  pidx(0.2, 0.02, 3, 60, 0, 0, 100);
  table_serv.write(28);
  turn(90, -1, 95);
  MoveSync(-90, -90, 0, 75, 5);
  ramkDown();
  delay(200);
  MoveSync(0, 90, 0, 20, 5);
  MoveSync(90, 90, 0, 55, 5);
  turn(90, 1, 95);
}

void trashNeMost() {
  MoveSync(-90, -90, 0, 230, 5);
  turn(90, 1, 86);
  ramkUp();
  MoveSync(-90, -90, 0, 123, 5);
  ramkDown();
  turn(90, -1, 91);

  MoveSync(-90, -90, 0, 130, 0);
  ramk.write(30);
  MoveSync(-90, -90, 0, 140, 5);
  ramkTube();
  delay(300);
  MoveSync(-90, -90, 0, 30, 12);
  driveToWall(68);
  ramkTubeUp(4);
  delay(200);
  ramkDown();
  MoveSync(120, 120, 0, 120, 90);
  turn(90, 1, 88);
  MoveSync(120, 120, 0, 200, 0);
  drive(100, 100);
  delay(500);
  stop();
  table_serv.write(28);
  MoveSync(-90, -90, 0, 75, 60);
  turn(90, 1, 88);
  MoveSync(70, 70, 1, 140, 40);
  getColors();
  indicate1(colorr, 6);
  indicate1(colorl, 8);
  if (USE_LED == 1)
    lent.show();
  MoveSync(-80, -80, 0, 50, 60);
  turn(90, -1, 90);
  manRightDown(2);
  manLeftDown(2);
  delay(300);
  char colorsss[2] = {colorl, colorr};
  sborGB(logicGrab(colorsss));

  drive(100, 100);
  delay(800);
  MoveSync(-90, -90, 0, 163, 100);
  turn(90, -1, 88);
  MoveSync(90, 90, 0, 270, 0);
}

void sbros() {
  turn(90, 1, 100);
  ramk.write(30);
  MoveSync(-90, -90, 0, 200, 0);
  ramkDown();
  MoveSync(-90, -90, 0, 100, 5);
  MoveSync(0, -90, 0, 120, 0);
  MoveSync(-90, -90, 0, 490, 20);
  ramkUp();
  delay(200);
  MoveSync(90, 90, 0, 40, 20);
  MoveSync(90, 0, 0, 420, 0);
  ramkDown();
  drive(90, 90);
  delay(500);
  stop();
}
