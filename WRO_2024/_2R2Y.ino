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
  switch (pos) {

    case 12:
      DoubleGrab();
      break;

    case 22:
      RightGrab();
      MoveSync(80, 80, 0, 98, 100);
      RightGrab();
      break;

    case 11:
      LeftGrab();
      MoveSync(-80, -80, 0, 102, 100);
      LeftGrab();
      break;
  }
  manRightUp();
  manLeftUp();
}
