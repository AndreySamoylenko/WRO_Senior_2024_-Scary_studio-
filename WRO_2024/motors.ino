void drive(int sp1, int sp2) {
  sp1 = constrain(sp1, -255, 255);
  sp2 = constrain(sp2, -255, 255);

  if (sp1 > 0) {
    analogWrite(ma1, sp1);
    analogWrite(ma2, 0);
  }
  else {
    analogWrite(ma1, 0);
    analogWrite(ma2, abs(sp1));
  }

  if (sp2 > 0) {
    analogWrite(mb1, sp2);
    analogWrite(mb2, 0);
  }
  else {
    analogWrite(mb1, 0);
    analogWrite(mb2, abs(sp2));
  }
  if (sp1 == sp2 and sp1 == 0)
    stop();
}

void stop() {
  digitalWrite(ma1, 1);
  digitalWrite(mb1, 1);
  digitalWrite(ma2, 1);
  digitalWrite(mb2, 1);
}


void MoveSync (float sped1, float sped2,  int r, uint32_t dist, int stop) {
  dist = (dist / 28.5) * 100;
  drive(0, 0);
  float k = 1;
  if ( r == 1)
    delay(50);
  float e = 0;
  float eold = 0;
  float sped11 = sped1;
  float sped22 = sped2;
  countr = 0;
  countl = 0;
  int timer = millis();
  float deg = 0;
  while (deg < dist ) {

    if (sped1 != 0 and sped2 != 0) {
      if (abs(sped1) > abs(sped2)) {
        deg = countl;
        e = countl - countr * abs(sped1) / abs(sped2);
      }
      else {
        deg = countr;
        e = countl * abs(sped2) / abs(sped1) - countr;
      }

      if (r == 1 and k < 1 and (dist > 50 and deg < 300 and deg < 0.7 * dist) and (millis() - timer) < 200) {
        sped1 = MIN_SPEED + ((millis() - timer) / 200) * (sped1 - MIN_SPEED);
        sped2 = MIN_SPEED + ((millis() - timer) / 200) * (sped2 - MIN_SPEED);
      }
      else if(dist > 150 and (sped1>=150 and sped2 >=150) and dist-deg<50){
        sped1 = sped11*0.6;
        sped2 = sped22*0.6;
      }
      else {
        sped1 = sped11;
        sped2 = sped22;
      }

      float u = e * 4 + (e - eold) * 8;
      float mot1 = sped1 - u * sped1 / abs(sped1);
      float mot2 = sped2 + u * sped2 / abs(sped2);
      if (sped1 > 0)
        mot1 = constrain(mot1, 0, 255);
      else
        mot1 = constrain(mot1, -255, 0);

      if (sped2 > 0)
        mot2 = constrain(mot2, 0, 255);
      else
        mot2 = constrain(mot2, -255, 0);

      drive(mot1, mot2);
      e_old = e;
    }
    else {
      drive(sped1, sped2);
      if (sped1 != 0 ) deg = countl;
      if (sped2 != 0 ) deg = countr;

    }
  }
  if (stop > 10) { //резко тормоз
    drive (-255 * sped1 / abs(sped1), -255 * sped2 / abs(sped2));
    delay(((abs(sped1) + abs (sped2)) / 2) / 255 * stop);
    drive (0, 0);
    delay(200);
  }
  else if (stop > 1 and stop < 10){
    drive (-255 * sped1 / abs(sped1), -255 * sped2 / abs(sped2));
    delay(((abs(sped1) + abs (sped2)) / 2) / 255 * round(autoBreak(((abs(sped1)+abs(sped2)))/2)));
    drive (0, 0);
    delay(200);
  }
}


void turn(float sped, int side, int angle) {
  delay(100);
  MoveSync(side * sped, -side * sped, 0, angle * 1.76, 120*(abs(sped)/255));
}
