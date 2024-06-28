void wait_button(int param) {
  bool startFlag = 0;
  int frame = 0;
  bool lgbt_flag = false;
  digitalWrite(RELAY_PIN, 0);
  time2 = millis();
  while (startFlag == 0) {
    if (param == 0) {
      if (digitalRead(buttonPin) == 1)
        startFlag = 1;
    }

    if (param == 1) {
      if (digitalRead(buttonPin) == 1)
        lgbt_flag = true;
      else if (lgbt_flag) {
        frame %= 4;
        frame++;
        lgbt_flag = false;
      }
      calibration(frame);

//      Serial.print(countl); Serial.print("   "); Serial.println(countr);

      if ( millis() % 50 >= 0 and millis() % 50 < 10)
        oled.update();
    }
  }
  digitalWrite(RELAY_PIN, 1);
  delay(50);
  delay(100);
  idle_time += millis()-time2;
}
