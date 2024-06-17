void manLeftUp() {
  manup_l.write(MANUPL);
}


void RightGrab() {
  if (manup_r.read() > MANDOWNISHR) {
    manRightDown(2);
    delay(200);
  }
  manRightDown(1);
  claw_r.write(CLAWROPENISH);
  delay(200);
  manRightDown(0);
  delay(300);
  claw_r.write(CLAWRCLOSE);
  delay(250);
  count_c_r ++;
  manRightDown(2);
  listmover();
}



void LeftGrab() {
  if (manup_l.read() > MANDOWNISHL) {
    manLeftDown(2);
    delay(200);
  }
  manLeftDown(1);
  delay(100);
  claw_l.write(CLAWLOPENISH);
  delay(300);
  manLeftDown(0);
  delay(350);
  claw_l.write(CLAWLCLOSE);
  delay(300);
  count_c_l ++;
  manLeftDown(2);
  listmovel();
}


void DoubleGrab() {
  if (manup_l.read() > MANDOWNISHL or manup_r.read() > MANDOWNISHR) {
    if (manup_l.read() > MANDOWNISHL)
      manLeftDown(2);
    if (manup_r.read() > MANDOWNISHR)
      manRightDown(2);
    delay(200);
  }
  manLeftDown(1);
  manRightDown(1);
  delay(100);
  claw_l.write(CLAWLOPENISH);
  claw_r.write(CLAWROPENISH);
  delay(300);
  manLeftDown(0);
  manRightDown(0);
  delay(350);
  claw_l.write(CLAWLCLOSE);
  claw_r.write(CLAWRCLOSE);
  delay(300);
  manRightDown(2);
  manLeftDown(2);

  count_c_l ++;
  count_c_r ++;
  listmovel();
  listmover();
}

void manLeftDown(int pos) {
  if (pos == 0)
    manup_l.write(MANDOWNL);
  else if (pos == 1)
    manup_l.write(MANDOWNISHL);
  else if (pos == 2)
    manup_l.write(MANDOWNISHISHL);
  else if (pos == 3)
    manup_l.write(MANDOWNL - 7);
  else if (pos == 5)
    manup_l.write(MANDOWNISHL);

}

void leftClaw(int pos) {
  switch (pos) {
    case 0:
      claw_l.write(CLAWLCLOSE);
      break;
    case 1:
      claw_l.write(CLAWLCLOSECUBE);
      break;
    case 2:
      claw_l.write(CLAWLOPEN);
      break;
    case 3:
      claw_l.write(CLAWLOPENISH);
      break;
  }
}

void manRightUp() {
  manup_r.write(MANUPR);
}

void manRightDown(int pos) {
  if (pos == 0)
    manup_r.write(MANDOWNR);
  else if (pos == 1)
    manup_r.write(MANDOWNISHR);
  else if (pos == 2)
    manup_r.write(MANDOWNISHISHR);
  else if (pos == 3)
    manup_r.write(MANDOWNDROPR);
  else if (pos == 4)
    manup_r.write(MANDOWNISHR);

}

void rightClaw(int pos) {
  switch (pos) {
    case 0:
      claw_r.write(CLAWRCLOSE);
      break;
    case 1:
      claw_r.write(CLAWRCLOSECUBE);
      break;
    case 2:
      claw_r.write(CLAWROPEN);
      break;
    case 3:
      claw_r.write(CLAWROPENISH);
      break;
  }
}

void allClaws(int pos) {
  switch (pos) {
    case 0:
      claw_r.write(CLAWRCLOSE);
      claw_l.write(CLAWLCLOSE);
      break;
    case 1:
      claw_r.write(CLAWRCLOSECUBE);
      claw_l.write(CLAWLCLOSECUBE);
      break;
    case 2:
      claw_r.write(CLAWROPEN);
      claw_l.write(CLAWLOPEN);
      break;
    case 3:
      claw_r.write(CLAWROPENISH);
      claw_l.write(CLAWLOPENISH);
      break;
  }
  delay(100);
}

void SingleGrab(int var) {
  if (var < 3)
    if (var == 1) {
      claw_r.write(CLAWRCLOSECUBE);
      delay(100);
      manup_r.write(MANDOWNR - 4);
      delay(600);
      claw_r.write(CLAWRCLOSE);
      manRightUp();
      delay(600);
    }
    else
    {
      delay(100);
      delay(600);
      manRightUp();
      delay(600);
    }

  else {
    if (var == 3) {
      delay(1);
    }
    else
      delay(0);

  }

}

void ramkDown() {
  ramk.write(10);
}

void ramkUp() {
  ramk.write(70);
}
void ramkVeryUp() {
  ramk.write(120);
}

void ramkTube() {
  ramk.write(17);
}

void ramkTubeUp(int del) {
  for (int i = ramk.read(); i < 70; i++) {
    ramk.write(i);
    delay(del);

  }
}
