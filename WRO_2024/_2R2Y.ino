void R2Y2() {
  manLeftDown(2);
  RightGrab();
  pidenc(0.3, 0.02, 3, (256 + 100), 0, (312), 90);
  DoubleGrab();
  pidenc(0.3, 0, 2, (256 + 100), 0, (302), 90);
  LeftGrab();
  beep(100);
}

void sborGB(int pos) {
  //   wait_button(0);
  switch (pos) {
    case 12:
      DoubleGrab();
      break;

    case 22:
      RightGrab();
      if (bread == 1) {
        table_serv.write(29);
        beep(100);
      }
      MoveSync(80, 80, 0, 98 - 16 * bread, 8);
      RightGrab();

      break;

    case 11:
      LeftGrab();
      MoveSync(-80, -80, 0, 98 - 10 * bread, 8);
      LeftGrab();
      if (bread == 1)
        MoveSync(80, 80, 0, 98 - 10, 8);

      break;

    case 21:
      MoveSync(80, 80, 0, 95, 8);
      RightGrab();
      MoveSync(-80, -80, 0, 196 - bread * 16, 7);
      LeftGrab();
      break;



  }
  manRightUp();
  manLeftUp();
}

void sborGBinv(int pos) {
  //   wait_button(0);
  switch (pos) {
    case 12:
      DoubleGrab();
      break;

    case 22:
      RightGrab();
      MoveSync(-80, -80, 0, 98, 8);
      RightGrab();
      break;

    case 11:
      LeftGrab();
      MoveSync(80, 80, 0, 98, 8);
      LeftGrab();
      MoveSync(-80, -80, 0, 98, 8);
      break;

    case 21:
      MoveSync(-80, -80, 0, 95, 8);
      RightGrab();
      MoveSync(80, 80, 0, 196, 7);
      LeftGrab();
      MoveSync(-80, -80, 0, 95, 8);
      break;



  }
  manRightUp();
  manLeftUp();
  MoveSync(-190, -190, 1, pos == 22 ? 160 : 240, 40);

}

int logicGrab(char cubes[2]) {
  int aaa = 0;
  if (left_grob == cubes[0])
    aaa = 10;
  else
    aaa = 20;
  if (right_grob == cubes[1])
    aaa += 2;
  else
    aaa += 1;
  return aaa;
}

void the_T() {
  for (int i = 150; i > 100; i--)
  {
    t_servo.write(i);
    delay(9);
  }

  for (int i = 97; i > 65; i--) {
    manup_l.write(i);
    t_servo.write(map(i, 65, 97, 47, 80 + 5));
    delay(45);
  }
  t_up();
}
