
void main_loop() {
  //  /*
  most();
  //--------------------BLACK TRASH--------------------
  trashMost();
  pidx(0.2, 0.02, 3, 60, 0, 0, 60);
  pidenc(0.3, 0.02, 3, -100, 1, 1100, 0);
  pidenc(0.3, 0.03, 3, -250, 0, 700, 0);
  pidenc(0.3, 0.03, 3, -90, 0, 600, 0);

  trashNeMost();
  turn(90,-1,40);
  turnl(1, 90, 1);
  pidenc(0.4, 0.03, 4, 70, 1, 500, 0);
  pidenc(0.3, 0.02, 3, 255, 0, 1400, 0);
  pidenc(0.3, 0.02, 3, 170, 0, 600, 0);
  pidx(0.2, 0.02, 3, 60, 0, 0, 100);
  MoveSync(-180, -180, 0, 30, 20);

  sbros();

  ramkDown();
  delay(100);
  MoveSync(-90, -90, 0, 87, 90);


  MoveSync(-160, -0, 0, 300, 9);
  ramkTube();

  driveToWall(490);
  ramkTubeUp(6);
  delay(90);
  MoveSync(120, 120, 1, 100, 0);
  MoveSync(250, 250, 0, 400, 0);
  MoveSync(90, 90, 0, 100, 90);

  turn(150, -1, 30);
  turnl(1, 90, 1);

  pidenc(0.2, 0.03, 3, 115, 1, 400, 0);
  ramkUp();
  allClaws(0);
  if (START_TYPE == 0) {
    table_serv.write(156);
  }
  pidenc(0.2, 0.03, 3, 255, 0, 1000, 0);
  pidenc(0.2, 0.03, 3, 215, 0, 800, 0);
  pidx(0.2, 0.02, 3, 80, 0, 0, 90);

  if (START_TYPE == 1) {
    table_serv.write(28);
    manRightDown(2);
    manLeftDown(2);
    pidenc(0.2, 0.03, 3, (-135), 0, 530, 9);
    MoveSync(-90, 0, 0, 140, 9);
    MoveSync(0, -90, 0, 142, 9);
    //    wait_button(0);
    sborGB(logicGrab(start_cubes));
    MoveSync(0, -90, 0, 142, 9);
    MoveSync(-90, 0, 0, 140, 9);
    table_serv.write(156);
    pidx(0.2, 0.02, 3, 80, 0, 0, 90);

  }
  MoveSync(0, -120, 0, 220, 70);
  MoveSync(-120, 0, 0, 240, 70);

  if (left_grob == 'b') {
    MoveSync(-90, -90, 1, 90, 70);
    delay(200);
    RightUnload(9);
    MoveSync(-90, -90, 1, 80, 70);
    delay(200);
    LeftUnload(9);
  }
  else {
    LeftUnload(9);
    MoveSync(-90, -90, 1, 290, 70);
    delay(200);
    RightUnload(9);
  }
  if (START_TYPE == 1) {
    MoveSync(150, 150, 1, 250, 20);
    MoveSync(23, 250, 1, 350, 20);
    MoveSync(250, 250, 1, 240, 160);
  }
  else {
    turn(120, -1, 20);
    ramkDown();
    MoveSync(-255, -255, 1, 450, 20);
  }

}
