
void main_loop() {
//    /*

  most();

  //  trashMost();
  //  pidenc(0.3, 0.02, 3, -120, 1, 500, 0);
  pidx(0.2, 0.02, 3, 120, 0, 0, 60);
  pidenc(0.3, 0.02, 3, -180, 1, 400, 0);
  pidenc(0.3, 0.03, 3, -250, 0, 1400, 0);
  pidenc(0.3, 0.03, 3, -90, 0, 600, 0);

  trashNeMost();

  if (sensors(1) > 100 and sensors(2) > 100)
    turnl(-1, 120, 1);

  pidenc(0.4, 0.03, 4, 90, 1, 300, 0);
  pidenc(0.3, 0.02, 3, 255, 0, 1200, 0);
  pidenc(0.3, 0.02, 3, 190, 0, 300, 0);
//  */
  
  pidx(0.2, 0.02, 3, 60, 0, 0, 100);

  MoveSync(-255, -255, 0, 40, 20);

  trashMost();
  sbros();

  ramkDown();
  delay(100);
  MoveSync(-90, -90, 0, 125, 70); // отъезд от стены


  MoveSync(-120, -0, 0, 315, 20); // поворот к трубе
  ramkTube();
  delay(400);
  driveToWall(425); // подъезд к трубе
  ramkTubeUp(12);
  ramkTubeUp(6);
  //  MoveSync(-55, -55, 0, 20, 12);
  digitalWrite(STATE_PIN, 1);
  MoveSync(90,0,0,23,0);
  MoveSync(180, 180, 1, 100, 0);
  MoveSync(255, 255, 0, 400, 0);
  MoveSync(90, 90, 0, 100, 90);

  if (sensors(1) > 100 and sensors(2) > 100)
    turnl(-1, 90, 1);

  ramkUp();
  pidenc(0.3, 0.03, 3, 115, 1, 400, 0);
  allClaws(0);
  if (START_TYPE == 0) {
    table_serv.write(156);
  }
  pidenc(0.3, 0.03, 3, 255, 0, 1000, 0);
  pidenc(0.4, 0.03, 3, 235, 0, 800, 0);

  pidx(0.3, 0.03, 3, 80, 0, 0, 50);

  if (START_TYPE == 1) {
    table_serv.write(28);
    manRightDown(2);
    manLeftDown(2);
    pidenc(0.2, 0.03, 3, (-125), 0, 530, 9);
    MoveSync(-90, 0, 0, 140, 9);
    MoveSync(0, -90, 0, 142, 9);

    sborGB(logicGrab(start_cubes));
    MoveSync(0, -90, 0, 142, 9);
    MoveSync(-90, 0, 0, 140, 9);
    table_serv.write(156);
    pidx(0.2, 0.02, 3, 80, 0, 0, 90);

  }

MoveSync(0, -120, 0, 230, 60);
  MoveSync(-120, 0, 0, 250, 60);

  if (left_grob == 'b') {
    MoveSync(-90, -90, 0, 90, 60);
    delay(200);
    RightUnload(9);
    MoveSync(-90, -90, 0, 110, 60);
    delay(200);
    LeftUnload(12);
  }
  else {
    LeftUnload(10);
    MoveSync(-90, -90, 0, 290, 60);
    delay(200);
    RightUnload(12);
  }
  if (START_TYPE == 1) {
    MoveSync(255, 255, 0, 330, 20);
    table_serv.write(94);
    t_servo.write(110);
    MoveSync(23, 255, 0, 380, 20);
    manLeftDown(1);
    MoveSync(255, 255, 0, 100, 20);
  }
  else {
    MoveSync(-255, 0, 0, 100, 0);
    ramkDown();
    MoveSync(-255, -255, 0, 400, 20);
  }
  delay(350);
  digitalWrite(RELAY_PIN, 0);
  
//  obstacle();
}
