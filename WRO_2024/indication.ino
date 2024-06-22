void listmovel() {
  if (colorsl[0] != ' ') {
    char templst[4] = {colorsl[0], colorsl[1], colorsl[2], colorsl[3]};
    int i = 0;
    i = 0;
    while (templst[i] != ' ' and (i < 4)) {
      colorsl[i + 1] = templst[i];
      i += 1;
    }
    colorsl[0] = colorl;
  }
  else {
    colorsl[0] = colorl;
  }
  ultra_lgbt_flag = 1;
  lenta_color(colorsl);
}

void listmover() {
  if (colorsr[0] != ' ' ) {
    char templst[4] = {colorsr[0], colorsr[1], colorsr[2], colorsr[3]};
    int i = 0;
    i = 0;
    while (templst[i] != ' ' and (i < 4)) {
      colorsr[i + 1] = templst[i];
      i += 1;
    }
    colorsr[0] = colorr;
  }
  else {
    colorsr[0] = colorr;
  }
  ultra_lgbt_flag = 0;
  lenta_color(colorsr);
}





void lenta_color(char col[4]) {
  if (USE_LED == 1) {
    for (int i = 0; i < 4; i ++) {
      if (col[i] == 'b')
        for (int j = i * 2 ; j <= i * 2 + 1; j++)
          lent.setPixelColor(ultra_lgbt_flag == 1 ? 15 - j : j, lent.Color(0, 10, 255));
      if (col[i] == 'g')
        for (int j = i * 2 ; j <= i * 2 + 1; j++)
          lent.setPixelColor(ultra_lgbt_flag == 1 ? 15 - j : j, lent.Color(0, 255, 10));
      if (col[i] == 'y')
        for (int j = i * 2 ; j <= i * 2 + 1; j++)
          lent.setPixelColor(ultra_lgbt_flag == 1 ? 15 - j : j, lent.Color(255, 80, 10));
      if (col[i] == 'r')
        for (int j = i * 2; j <= i * 2 + 1; j++)
          lent.setPixelColor(ultra_lgbt_flag == 1 ? 15 - j : j, lent.Color(255, 0, 0));
      if (col[i] == ' ')
        for (int j = i * 2 ; j <= i * 2 + 1; j++)
          lent.setPixelColor(ultra_lgbt_flag == 1 ? 15 - j : j, lent.Color(0, 0, 0));
      if (col[i] == 'd')
        for (int j = i * 2 ; j <= i * 2 + 1; j++)
          lent.setPixelColor(ultra_lgbt_flag == 1 ? 15 - j : j, lent.Color(100, 0, 100));

    }
    lent.show();

  }
}

void indicate8(char cols[8]) {
  for (int i = 0; i < 16; i+=2) {
    indicate1(cols[i/2], i);
  }
  lent.show();
}
void indicate1(char col, int pos) {
  if (USE_LED == 1) {
    if (col == 'b')
      for (int j = 0 ; j <= 1; j++)
        lent.setPixelColor(pos + j, lent.Color(0, 10, 255));
    if (col == 'g')
      for (int j = 0 ; j <= 1; j++)
        lent.setPixelColor(pos + j, lent.Color(0, 255, 10));
    if (col == 'y')
      for (int j = 0 ; j <= 1; j++)
        lent.setPixelColor(pos + j, lent.Color(255, 80, 10));
    if (col == 'r')
      for (int j = 0; j <= 1; j++)
        lent.setPixelColor(pos + j, lent.Color(255, 0, 0));
    if (col == ' ')
      for (int j = 0; j <= 1; j++)
        lent.setPixelColor(pos + j, lent.Color(0, 0, 0));
    if (col == 'd')
      for (int j = 0; j <= 1; j++)
        lent.setPixelColor(pos + j, lent.Color(100, 0, 100));
  }
}
