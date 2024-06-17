void obstacle() {
  delay(500);
  pidenc(0.25, 0.03, 3, -100, 0, 190, 1);
  MoveSync(0, 140, 0, 282, 1);
  MoveSync(140, 0, 0, 610, 1);
  MoveSync(140, 140, 0, 150, 1);
  beep(100);
  table_serv.write(154);
  delay(500);
  beep(100);
  delay(500);
  beep(100);
  delay(500);
}
