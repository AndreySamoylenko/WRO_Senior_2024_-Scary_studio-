
void RightUnload(int del) {
  manRightDown(0);
  delay(400);
  claw_r.write(CLAWROPEN);
  delay(300);
  for (int i = manup_r.read(); i < MANUPR; i++) {
    manup_r.write(i);
    delay(del);
  }
  count_c_r = 0;
  delay(100);
  beep(100);
  //  claw_r.write(CLAWROPENISH);
  colorr = ' ';
  for (int i = 0; i < 4; i++)
    colorsr[i] = ' ';
  ultra_lgbt_flag = 1;
  lenta_color(colorsr);
}


void LeftUnload(int del) {
  manLeftDown(0);
  delay(400);
  claw_l.write(CLAWLOPEN);
  delay(300);
  for (int i = manup_l.read(); i > MANUPL; i--) {
    manup_l.write(i);
    delay(del);
  }
  count_c_l = 0;
  delay(100);
  beep(100);
  //  claw_l.write(CLAWLOPENISH);
  colorr = ' ';
  for (int i = 0; i < 4; i++)
    colorsl[i] = ' ';
  ultra_lgbt_flag = 0;
  lenta_color(colorsl);
}
