float sensors(int dat) {
  float data = 0;
  switch (dat) {
    case 1:
      data = float(sensors_value(1) - datflmin) / (datflmax - datflmin);
      break;
    case 2:
      data = float(sensors_value(2) - datfrmin) / (datfrmax - datfrmin);
      break;
    case 3:
      data = float(sensors_value(3) - datblmin) / (datblmax - datblmin);
      break;
    case 4:
      data = float(sensors_value(4) - datbrmin) / (datbrmax - datbrmin);
      break;
    case 5:
      data = float(sensors_value(5) - datprmin) / (datprmax - datprmin);
      break;
    case 6:
      data = float(sensors_value(6) - datplmin) / (datplmax - datplmin);
      break;
  }
  return constrain(data * 256, 0, 256);
}

int sensors_value(int pin) {
  switch (pin) {
    case 3:
      return analogRead(A10);
      break;
    case 4:
      return analogRead(A8);
      break;
    case 1:
      return analogRead(A2);
      break;
    case 2:
      return analogRead(A0);
      break;
    case 5:
      return analogRead(A1);
      break;
    case 6:
      return analogRead(A5);
      break;
  }
}
