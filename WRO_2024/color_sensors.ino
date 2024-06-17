//void get_colorr() {
//  uint16_t R, G, B;
//  R = 0;
//  G = 0;
//  B = 0;
//  for (int i = 0; i < 20; i++) {
//    r = 0;
//    g = r;
//    b = r;
//    tcs_software.getRawData(&r, &g, &b, &c);
//    //    b = b * 1.2;
//    R += r;
//    G += g;
//    B += b;
//  }
//  if (B > G) {
//    Serial.println("blue l");
//    colorr = 'b';
//  }
//
//  else if (G > B) {
//    Serial.println("green l");
//    colorr = 'g';
//  }
//
//  else  {
//    Serial.println("xz l");
//    colorr = ' ';
//  }
//}
//
//void getcolorl() {
//  uint16_t R, G, B;
//  R = 0;
//  G = 0;
//  B = 0;
//  for (int i = 0; i < 20; i++) {
//    TCS34725::RawData raw = tcs.raw();
//    r = raw.r;
//    g = raw.g;
//    b = raw.b;
//    //    b = b * 1.2;
//    R += r;
//    G += g;
//    B += b;
//  }
//  if (B > G) {
//    Serial.println("blue l");
//    colorl = 'b';
//  }
//
//  else if (G > B) {
//    Serial.println("green l");
//    colorl = 'g';
//  }
//
//  else  {
//    Serial.println("xz l");
//    colorl = ' ';
//  }
//}


void getColors() {
  int l_b = 0;
  int l_g = 0;
  int r_b = 0;
  int r_g = 0;
  int r_c = 0;
  int l_c = 0;

  time2 = millis();
  for (int i = 0; i < 30 ; i++) {
    if (  !apds.readAmbientLight(ambient_light) ||
          !apds.readRedLight(red_light) ||
          !apds.readGreenLight(green_light) ||
          !apds.readBlueLight(blue_light) ) {
      Serial.println("Error reading light values");
    } else {
      r_b += blue_light;
      r_g += green_light;
      r_c += ambient_light;
    }
    if (tcs_left.available())
    {

      TCS34725::RawData raw = tcs_left.raw();
      l_b += raw.b;
      l_g += raw.g;
      l_c += raw.c;
    }
    // Wait 25 miliseconds before next reading
    delay(25);
  }

  if ((r_g > r_b) and r_c > 9 * 0) {
    colorr = 'g' ;
  }
  else if ((r_g < r_b) and r_c > 9 * 0) {
    colorr = 'b';
  }
  else {
    colorr = 'd';
  }


  if ((l_g > l_b) and l_c > 60 * 0) {
    colorl = 'g' ;
  }
  else if ((l_g < l_b) and l_c > 60 * 0) {
    colorl = 'b';
  }
  else {
    colorl = 'd';
  }

  Serial.println(millis() - time2);
}
