void timer() {
  uint32_t all_time = millis() - time;
  all_time -= idle_time;
  int mins = all_time / 60000;
  int secs10 = all_time / 10000 % 10;
  int secs1 = all_time / 1000 % 10;
  int decisecs = all_time % 100;
  byte secs = round(all_time / 1000);
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
  broItsCRINGE(secs);
  oled.clear();
  oled.home();
  oled.setScale(1);
  oled.textMode(BUF_ADD);
  oled.print(secs);
  oled.print('.');
  oled.print(decisecs);
  oled.update();
  delay(10000);
}


int autoBreak(float speed) {
  return round(log10(speed + 5) / log10(1.0114381)) - 270;
}

void broItsCRINGE(byte bite) {
  for (int i = 0; i < 8; i++)
    if (bit_is_set(bite, i))
      indicate1(random_colors[i], i * 2);
    else
      indicate1(' ', i * 2);
  lent.show();
}
