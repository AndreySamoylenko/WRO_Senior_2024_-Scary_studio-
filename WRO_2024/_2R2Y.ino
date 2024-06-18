void R2Y2() {
  manLeftDown(2);
  RightGrab();
  pidenc(0.3, 0.02, 3, (256 + 100), 1, (340), 100);
  DoubleGrab();
  pidenc(0.3, 0, 2, (256 + 100), 1, (340), 100);
  LeftGrab();
  beep(100);
}

void sborGB(int pos) {
//   wait_button(0);
  switch (pos) {
    case 12:
      beep(50);
      beep(150);
      DoubleGrab();
      break;

    case 22:
      beep(150);
      beep(150);
      RightGrab();
      MoveSync(80, 80, 0, 98, 80);
      RightGrab();
      break;

    case 11:
      beep(50);
      beep(50);
      LeftGrab();
      MoveSync(-80, -80, 0, 98, 80);
      LeftGrab();
      break;

    case 21:
      beep(150);
      beep(50);
      MoveSync(80, 80, 0, 95, 80);
      RightGrab();
      MoveSync(-80, -80, 0, 190, 70);
      LeftGrab();
      break;



  }
  manRightUp();
  manLeftUp();
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
