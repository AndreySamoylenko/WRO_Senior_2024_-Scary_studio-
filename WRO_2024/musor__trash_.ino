
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
  MoveSync(-110, -110, 0, 220, 22);
  turn(100, 1, 90);
  ramkUp();
  MoveSync(-90, -90, 0, 135, 22);
  ramkDown();
  delay(300);//забрали желтый
  MoveSync(90, 90, 0, 35, 40);// отъехали от него

  turn(90, -1, 93);

  MoveSync(-90, -90, 0, 140, 0);// едем в сторону трубы
  ramk.write(30); // приподнятое положение рамки чтобы собрать черный и не потерять остальные
  MoveSync(-90, -90, 0, 140, 22); // продолжаем ехать в сторону трубы
  ramkDown();
  delay(150);
  ramkTube();   // забрали чёрный и приподняли рамку
  delay(100);

  //  wait_button(0);

  driveToWall(615); // доезд по датчику
  ramkTubeUp(3); // сделали трубу
  delay(400);
  ramkDown(); // не отпускаем мусор
  delay(200);
  MoveSync(120, 120, 0, 120, 90); // отЪехали от трубы
  turn(110, 1, 90);
  MoveSync(190, 190, 0, 180, 0);
  drive(100, 100); // доезд до стены перед кубами
  delay(700);
  stop();
  table_serv.write(28);
  delay(150);
  MoveSync(-110, -110, 0, 40, 60);// отъехали от стены
  turn(100, 1, 100);
  MoveSync(80, 80, 1, 180, 40); // 
  getColors();

  MoveSync(0, 90, 1, 30, 40);
  bread = 1;


  indicate1(colorr, 6);
  indicate1(colorl, 8);
  if (USE_LED == 1)
    lent.show();
  MoveSync(-100, -100, 0, 53, 60);
  turn(90, -1, 93);
  MoveSync(-80, -80, 0, 20, 9);
  manRightDown(2);
  manLeftDown(2);
  delay(300);
  bread = 1;
  char colorsss[2] = {colorl, colorr};
  sborGB(logicGrab(colorsss));
  bread = 0;
  drive(100, 100);
  delay(900);
  MoveSync(-120, -120, 0, 145, 90);
  turn(90, -1, 93);
  MoveSync(250, 250, 0, 460, 0);
  MoveSync(50, 50, 0, 50, 50);
  //  wait_button(0);
}

void sbros() {
  turn(120, 1, 100);
  ramk.write(30);
  MoveSync(-90, -90, 0, 200, 0);
  ramkDown();
  MoveSync(-90, -90, 0, 100, 5);
  MoveSync(0, -90, 0, 130, 0);
  MoveSync(-200, -200, 1, 370, 0);
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
