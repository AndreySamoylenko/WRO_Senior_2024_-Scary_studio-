void calibration(int frame) {
  oled.clear();
  oled.home();
  oled.setScale(1);
  oled.textMode(BUF_ADD);
  oled.print("     CALIBRATION");
//  Serial.print(sensors(1)); Serial.print( " "); Serial.print( sensors(2)); Serial.print( " "); Serial.print( sensors(3)); Serial.print(" "); Serial.print( sensors(4)); Serial.print("    ");
//  Serial.print(sensors_value(1)); Serial.print( " "); Serial.print( sensors_value(2)); Serial.print( " "); Serial.print( sensors_value(3)); Serial.print(" "); Serial.println( sensors_value(4));

  switch (frame) {
    case 0:
      oled.setCursor(0, 2);
      oled.setScale(2);
      oled.print("OLEG IS ON");
      if (millis() % 1200 < 601) {
        oled.setCursor(8, 7);
        oled.setScale(1);
        oled.print("press the button..");
      }
      break;
    case 1:

      oled.setCursor(12, 1);
      oled.print("dat1     dat2     dat5");
      oled.setCursor(12, 2);
      oled.print(sensors(1));
      oled.setCursor(50, 2);
      oled.print(sensors(2));
      oled.setCursor(99, 2);
      oled.print(sensors(5));

      oled.setCursor(20, 4);
      oled.print("dat3       dat4");
      oled.setCursor(20, 5);
      oled.print(sensors(3));
      oled.setCursor(84, 5);
      oled.print(sensors(4));

      oled.setCursor(20, 5);
      oled.print("dat5       dat6");
      oled.setCursor(20, 6);
      oled.print(sensors(5));
      oled.setCursor(84, 5);
      oled.print(sensors(6));

      oled.setCursor(0, 7);
      oled.print("*mapped");
      Serial.print("dat1 : "); Serial.print(sensors(1)); Serial.print("   dat2 : "); Serial.print(sensors(2));
      Serial.print("  dat3 : "); Serial.print(sensors(3)); Serial.print("   dat4 : "); Serial.print(sensors(4));
      Serial.print("  dat5 : "); Serial.print(sensors(5)); Serial.print("   dat6 : "); Serial.println(sensors(6));
      Serial.print("mapped");

      break;
    case 2:

      oled.setCursor(20, 1);
      oled.print("dat1       dat2");
      oled.setCursor(20, 2);
      oled.print(sensors_value(1));
      oled.setCursor(84, 2);
      oled.print(sensors_value(2));

      oled.setCursor(20, 4);
      oled.print("dat3       dat4");
      oled.setCursor(20, 5);
      oled.print(sensors_value(3));
      oled.setCursor(84, 5);
      oled.print(sensors_value(4));

      oled.setCursor(0, 7);
      oled.print("*not mapped");
      Serial.print("dat1 : "); Serial.print(sensors_value(1)); Serial.print("   dat2 : "); Serial.print(sensors_value(2));
      Serial.print("  dat3 : "); Serial.print(sensors_value(3)); Serial.print("   dat4 : "); Serial.print(sensors_value(4));
      Serial.print("  dat5 : "); Serial.print(sensors_value(5)); Serial.print("   dat6 : "); Serial.println(sensors_value(6));
      Serial.print("not mapped");
      break;


    case 3:

      oled.setCursor(20, 1);
      oled.print("encl       encr");
      oled.setCursor(20, 2);
      oled.print(countl);
      oled.setCursor(84, 2);
      oled.print(countr);


      oled.setCursor(0, 7);
      oled.print("*motori");

      break;
    case 4:
      oled.home();
      oled.setCursor(1, 1);

      //      get_color();
      oled.setCursorXY(64, 9);
      //      oled.print(color);
      //      oled.setCursorXY(64, 17);
      //      oled.print(r);
      //      oled.setCursorXY(64, 25);
      //      oled.print(g);
      //      oled.setCursorXY(64, 33);
      //      oled.print(b);
      //      oled.setCursorXY(64, 41);
      //      oled.print(c);
      break;

  }

}
