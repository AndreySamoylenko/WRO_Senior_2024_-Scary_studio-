void beep(int del) {
  digitalWrite(buzz, 1);
  delay(del / 2);
  digitalWrite(buzz, 0);
  delay(del / 2);
}
