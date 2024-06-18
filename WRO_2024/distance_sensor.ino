uint32_t get_distance() {
  uint32_t a = 0;
  for (int i = 0; i < 100; i++)
    a += analogRead(SHARP_PIN);
  a/=100;
  return (a);
}

void driveToWall(int dist) { // sbros - 85 // neMost - 50
  int distance = 0;
  while (distance < dist) {
    distance = get_distance();
    drive(-60 + distance / 4, -60 + distance / 4);
  }
  stop();

}
