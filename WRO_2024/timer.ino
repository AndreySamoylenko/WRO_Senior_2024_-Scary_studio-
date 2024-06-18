void timer() {
  int mins = (millis() - time) / 60000;
  int secs10 = (millis() - time) / 10000 %10;
  int secs1 = (millis() - time) / 1000 %10;
  int decisecs = (millis() - time) % 100;
//  for (int i = 0; i < mins; i++) {
//    beep(400);
//  }
//  delay(1000);
//
//  for (int i = 0; i < secs10; i++) {
//    beep(200);
//  }
//  delay(1000);
//  for (int i = 0; i < secs1; i++) {
//    beep(100);
//    delay(100);
//  }
//  delay(1000);

oled.clear();
  oled.home();
  oled.setScale(1);
  oled.textMode(BUF_ADD);
  oled.print((millis()-time)/1000);
  oled.update();
  delay(10000);
}


int autoBreak(float speed){
  return round(log10(speed+5)/log10(1.0114381)) - 270;
}
