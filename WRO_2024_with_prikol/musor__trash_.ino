
void trashMost() {
  //--------------------BLACK TRASH--------------------
  pidx(0.2, 0.02, 3, 60, 0, 0, 9);

  //  table_serv.write(28);
  turn(120, -1, 105);
  ramkUp();
  MoveSync(-90, -90, 0, 75, 5);
  ramkDown();
  delay(200);
  MoveSync(90, 90, 0, 75, 5);
  turnl(1, 120, -1);

  //  ramkDown();

}

void trashNeMost() {
  MoveSync(-160, -160, 0, 220, 22);
  turn(100, 1, 89);
  ramkUp();
  MoveSync(-120, -120, 0, 150, 22);
  ramkDown();
  delay(300);//забрали желтый
  MoveSync(90, 90, 0, 14, 12);
  turn(90, -1, 89);

  MoveSync(-120, -120, 0, 150, 0);// едем в сторону трубы
  ramk.write(30); // приподнятое положение рамки чтобы собрать черный и не потерять остальные
  MoveSync(-90, -90, 0, 170, 22); // продолжаем ехать в сторону трубы
  ramkDown();
  delay(250);
  MoveSync(90, 90, 0, 50, 12);
  MoveSync(0, -90, 0, 15, 12);
  ramkTube();
  delay(400);
  driveToWall(545); // подъезд к трубе
  ramkTubeUp(10);
  ramkTubeUp(7);
  delay(400);
  ramkDown(); // не отпускаем мусор
  delay(200);
  MoveSync(120, 120, 0, 160, 90); // отЪехали от трубы
  turn(100, 1, 88);
  MoveSync(190, 190, 0, 180, 0);
  table_serv.write(28);
  drive(100, 100); // доезд до стены перед кубами
  delay(700);
  stop();

  delay(150);
  MoveSync(-110, -110, 0, 40, 60);// отъехали от стены
  turn(100, 1, 100);
  MoveSync(80, 80, 1, 180, 40); //  подЪезд к кубам
  getColors();  // считываем цвет кубиков

  MoveSync(0, 90, 1, 28, 40);
  bread = 1;


  indicate1(colorr, 6);
  indicate1(colorl, 8);
  if (USE_LED == 1)
    lent.show();  // выводим на ленту цвета кубов
  MoveSync(-100, -100, 0, 51, 60); // отъезжаем от  кубов
  turn(90, -1, 93);
  MoveSync(-80, -80, 0, 20, 9);
  manRightDown(2);
  manLeftDown(2);
  delay(300);
//  wait_button(0);
  bread = 1;
  char colorsss[2] = {colorl, colorr};
  sborGB(logicGrab(colorsss));
  bread = 0;
  drive(100, 100);
  delay(900);
  MoveSync(-120, -120, 0, 140, 90);
  turn(110, -1, 92);
  MoveSync(250, 250, 0, 490, 0);
  MoveSync(50, 50, 0, 60, 20);
  //  wait_button(0);
}

void sbros() {

  turn(120, 1, 100);
  ramk.write(30);
  MoveSync(-160, -160, 0, 200, 0);
  ramkDown();
  MoveSync(-160, -160, 0, 100, 5);
  MoveSync(0, -160, 0, 135, 0);
  MoveSync(-250, -250, 1, 370, 0);

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
