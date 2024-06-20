
void trashMost() {
  //--------------------BLACK TRASH--------------------
  pidx(0.2, 0.02, 3, 60, 0, 0, 9);
  table_serv.write(28);
  turn(120, -1, 95);
  MoveSync(-90, -90, 0, 75, 5);
  ramkDown();
  delay(200);
  MoveSync(0, 90, 0, 20, 5);
  MoveSync(90, 90, 0, 55, 5);
  turn(120, 1, 95);
}

void trashNeMost() {
  MoveSync(-110, -110, 0, 230, 5);
  turn(100, 1, 90);
  ramkUp();
  MoveSync(-90, -90, 0, 138, 12);
  ramkDown();
  delay(300);//забрали желтый
  MoveSync(90, 90, 0, 20, 12);

  turn(80, -1, 91);

  MoveSync(-90, -90, 0, 130, 0);
  ramk.write(30);
  MoveSync(-90, -90, 0, 150, 12);
  ramkTube();   // забрали чёрный
  wait_button(0);
  
  driveToWall(645);
  ramkTubeUp(4); // сделали трубу
  delay(500);
  ramkDown();
  delay(200);
  MoveSync(120, 120, 0, 120, 90);
  turn(110, 1, 90);
  MoveSync(190, 190, 0, 200, 0);
  drive(100, 100);
  delay(700);
  stop();
  table_serv.write(28);
  MoveSync(-110, -110, 0, 70, 60);
  turn(100, 1, 91);
  MoveSync(60, 60, 1, 160, 40);
    wait_button(0);
  bread = 1;
  getColors();

  indicate1(colorr, 6);
  indicate1(colorl, 8);
  if (USE_LED == 1)
    lent.show();
  MoveSync(-100, -100, 0, 56, 60);
  turn(100, -1, 90);
  manRightDown(2);
  manLeftDown(2);
  delay(300);
  char colorsss[2] = {colorl, colorr};
  sborGB(logicGrab(colorsss));
  bread = 0;
  drive(100, 100);
  delay(900);
  MoveSync(-120, -120, 0, 160, 90);
  turn(90, -1, 90);
  MoveSync(250, 250, 0, 400, 0);
  MoveSync(50, 50, 0, 50, 50);
  wait_button(0);
}

void sbros() {
  turn(120, 1, 100);
  ramk.write(30);
  MoveSync(-90, -90, 0, 200, 0);
  ramkDown();
  MoveSync(-90, -90, 0, 100, 5);
  MoveSync(0, -90, 0, 120, 0);
  MoveSync(-200, -200, 1, 390, 0);
  MoveSync(-80, -80, 0, 100, 20);
  ramkUp();
  delay(200);
  MoveSync(120, 120, 0, 40, 20);
  MoveSync(120, 0, 0, 430, 0);
  stop();
  ramkDown();
  drive(90, 90);
  delay(700);
  stop();
}
