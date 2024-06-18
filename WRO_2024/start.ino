void start() {
  ramkUp();
  allClaws(3);
  table_serv.write(157);

  beep(300);
  delay(100);

  MoveSync(-150, 0, 0, 100, 100);
  MoveSync(0, -150, 0, 95, 100);
  pidenc(0.2, 0.02, 3, (256 + 120), 0, 610 , 90);
  
  R2Y2();
  manLeftUp();
  manRightUp();

  // доезд до синезеленых кубов возле старта
  pidenc(0.2, 0.02, 3, (256 + 130), 1, (640), 110);
  turn(90, -1, 89);
  MoveSync(90, 90, 0, 50, 100);
  getColors();// собстна скан
  indicate1(colorr, 8);
  indicate1(colorl, 6);
  if (USE_LED == 1)
    lent.show();
  start_cubes[1] = colorr;
  start_cubes[0] = colorl;
  colorr = 'r';
  colorl = 'y';
  MoveSync(-80, -80, 0, 95, 100);
  turn(90, 1, 90);

  if (START_TYPE == 0) {
    // подъезд к линии для переезда на другую часть поля
    pidenc(0.2, 0.02, 3, 200, 0, 300, 0);
    pidenc(0.2, 0.02, 3, 100, 0, 200, 120);
    turnl(1, 90, 1);
    // собстна переезд
    pidenc(0.2, 0.02, 3, 130, 0, 580, 0);
    MoveSync(150, 150, 0, 120, 0);
    pidenc(0.2, 0.02, 3, 130, 0, 820, 30);
    stop();
    // подъезд к красно-жёлтым кубам
    MoveSync(100, 0, 1, 298, 100);
    MoveSync(90, 90, 0, 30, 1);
    pidenc(0.2, 0.02, 3, (255 + 120), 0, 330, 140);
    table_serv.write(156);

    R2Y2();

    turn(90, 1, 88);
    MoveSync(150, 150, 1, 100, 0);
    MoveSync(250, 250, 0, 320, 0);
    MoveSync(100, 100, 0, 80, 100);
    turn(90, -1, 88);


    MoveSync(60, 60, 0, 190, 70);

  }
  else {
    // подъезд к линии для переезда на другую часть поля
    pidenc(0.2, 0.02, 3, 200, 0, 1000, 0);
    pidenc(0.2, 0.02, 3, 100, 0, 200, 140);
    turnl(1, 90, 1);
    // собстна переезд
    pidenc(0.2, 0.02, 3, 160, 0, 580, 0);
    MoveSync(220, 220, 0, 120, 0);
    pidenc(0.2, 0.02, 3, 130, 0, 820, 20);
    stop();

    MoveSync(100, 0, 1, 294,9);
    MoveSync(100, 100, 0, 200, 150);
    pidenc(0.2, 0.02, 3, (255 + 120), 0, 210, 140);
    R2Y2();
    pidenc(0.2, 0.02, 3, (255 + 120), 0, 300, 140);
    turn(100, -1, 88);
    pidenc(0.2, 0.02, 3, (255 + 120), 0, 580, 140);
    turn(100, -1, 88);
  }
  table_serv.write(156);
  delay(150);

  LeftUnload();
  ramkVeryUp();
  MoveSync(80, 80, 1, 90, 100);
  delay(250);
  RightUnload();
  MoveSync(-80, -80, 0, 40, 100);
  turn(90, 1, 90);
  pidx(0, 0, 0, 120, 0, 150, 9);
  turnl(-1, 90, 1);

}
