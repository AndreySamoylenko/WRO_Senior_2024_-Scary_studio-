
void getColors() {
  int l_b = 0;
  int l_g = 0;
  int r_b = 0;
  int r_g = 0;
  int r_c = 0;
  int l_c = 0;

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

  if ((r_g > r_b) ) {
    colorr = 'g' ;
  }
  else if ((r_g < r_b) ) {
    colorr = 'b';
  }


  if (l_g > l_b) {
    colorl = 'g' ;
  }
  else if (l_g < l_b) {
    colorl = 'b';
  }


}


void get_color_man() {
  delay(200);
  if ( get_distance() > 130 and get_distance() < 170)
    colorl = 'g';
  else if  ( get_distance() > 625 and get_distance() < 700)
    colorl = 'b';
}
