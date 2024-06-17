
void main_loop() {
  /*  most();
    //--------------------BLACK TRASH--------------------
    trashMost();
    pidx(0.2, 0.02, 3, 60, 0, 0, 100);
    pidenc(0.3, 0.02, 3, -180, 0, 1100, 0);
    pidenc(0.3, 0.03, 3, -220, 0, 1300, 0);

    trashNeMost();

    pidenc(0.3, 0, 3, 100, 1, 400, 0);
    pidenc(0.2, 0.03, 3, 238, 0, 1400, 0);
    pidenc(0.2, 0.03, 3, 128, 0, 200, 0);
    pidx(0.2, 0.02, 3, 80, 0, 0, 100);
    MoveSync(-90, -90, 0, 10, 5);

    sbros();

    ramkDown();
    delay(100);
    MoveSync(-90, -90, 0, 70, 100);

    MoveSync(-90, -0, 0, 305, 80);
    ramkTube();
    MoveSync(-90, -90, 0, 79, 100);
    ramkTubeUp(5);
    MoveSync(90, 90, 0, 600, 110);*/
  wait_button(0);
  turn(90, 1, 30);
  turnl(-1, 90, 1);
  pidenc(0.2, 0.03, 3, 115, 0, 400, 0);
  ramkUp();
  allClaws(0);
  pidenc(0.2, 0.03, 3, 255, 0, 1000, 0);
  table_serv.write(157);
  pidenc(0.2, 0.03, 3, 135, 0, 400, 0);
  pidx(0.2, 0.02, 3, 80, 0, 0, 130);
  MoveSync(0, -120, 0, 200, 20);
  MoveSync(-120, 0, 0, 210, 20);
  wait_button(0);
  if (START_TYPE == 0) {
    if (left_grob == 'b') {
      MoveSync(-90, -90, 1, 80, 70);
      RightUnload();
      MoveSync(-90, -90, 1, 90, 70);
      LeftUnload();
    }
    else {
       MoveSync(-90, -90, 1, 30, 70);
      LeftUnload();
      MoveSync(-90, -90, 1, 270, 70);
      RightUnload();
    }
    turn(90, -1, 20);
    MoveSync(-255, -255, 1, 450, 1);
  }
  else {
    delay(0);
  }


}
