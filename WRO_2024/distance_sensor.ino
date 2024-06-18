uint16_t get_distance() {
  uint16_t a = analogRead(SHARP_PIN);

  return (a);
}

void driveToWall(int dist){ // sbros - 85 // neMost - 50
  int distance = 0;
  while (distance<dist) {
    distance = get_distance();
    drive(-60+distance/4,-60+distance/4);
  }
  stop();

}
