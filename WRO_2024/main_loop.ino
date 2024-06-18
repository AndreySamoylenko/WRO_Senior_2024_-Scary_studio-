
void main_loop() {
  //  /*
  most();
  //--------------------BLACK TRASH--------------------
  trashMost();
  pidx(0.2, 0.02, 3, 60, 0, 0, 60);
  pidenc(0.3, 0.02, 3, -100, 1, 1100, 0);
  pidenc(0.3, 0.03, 3, -200, 0, 700, 0);
  pidenc(0.3, 0.03, 3, -90, 0, 600, 0);

  trashNeMost();
  turn(90,-1,30);
  turnl(1,90,1);
  pidenc(0.4, 0.03, 4, 70, 1, 500, 0);
  pidenc(0.3, 0.02, 3, 238, 0, 1400, 0);
  pidenc(0.3, 0.02, 3, 128, 0, 600, 0);
  pidx(0.2, 0.02, 3, 60, 0, 0, 100);
 /* MoveSync(-90, -90, 0, 10, 20);

  sbros();

  ramkDown();
  delay(100);
  MoveSync(-90, -90, 0, 84, 90);


  MoveSync(-130, -0, 0, 300, 100);
  ramkTube();
  wait_button(0);
  driveToWall(90);
  ramkTubeUp(3);
  delay(90);
  MoveSync(96, 90, 1, 100, 0);
  MoveSync(235, 230, 0, 400, 0);
  MoveSync(95, 90, 0, 100, 90);

  turn(150, 1, 40);
  turnl(-1, 90, 1);

  pidenc(0.2, 0.03, 3, 115, 1, 400, 0);
  ramkUp();
  allClaws(0);
  if (START_TYPE == 0) {
    table_serv.write(156);
  }
  pidenc(0.2, 0.03, 3, 255, 0, 1000, 0);
  pidenc(0.2, 0.03, 3, 135, 0, 800, 0);
  pidx(0.2, 0.02, 3, 80, 0, 0, 130);

  if (START_TYPE == 1) {
    table_serv.write(28);
    manRightDown(2);
    manLeftDown(2);
    pidenc(0.2, 0.03, 3, (-135), 0, 450, 9);
    MoveSync(-90, 0, 0, 140, 9);
    MoveSync(0, -90, 0, 136, 9);
    wait_button(0);
    sborGB(logicGrab(start_cubes));
    MoveSync(0, -90, 0, 136, 9);
    MoveSync(-90, 0, 0, 140, 9);
    pidx(0.2, 0.02, 3, 80, 0, 0, 130);

  }
  MoveSync(0, -120, 0, 220, 70);
  MoveSync(-120, 0, 0, 240, 70);
  if (START_TYPE == 0) {
    if (left_grob == 'b') {
      MoveSync(-90, -90, 1, 130, 70);
      delay(200);
      RightUnload();
      MoveSync(-90, -90, 1, 50, 70);
      delay(200);
      LeftUnload();
    }
    else {
      LeftUnload();
      MoveSync(-90, -90, 1, 320, 70);
      delay(200);
      RightUnload();
    }
    turn(90, -1, 20);
    ramkDown();
    MoveSync(-255, -255, 1, 450, 20);
  }
  else {
    delay(0);
  }

*/
}
