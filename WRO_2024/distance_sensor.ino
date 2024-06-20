uint16_t get_distance() {
  uint16_t a = analogRead(SHARP_PIN);
  return (a);
}

void driveToWall(int dist) { // sbros - 85 // neMost - 50
  int distance = 30000;
  while (distance > dist) {
    distance = get_distance();
    int speed = -60 - map(distance - dist, 0, dist, 0, 50);
    drive(speed*1.08, speed);
  }
  stop();

}
