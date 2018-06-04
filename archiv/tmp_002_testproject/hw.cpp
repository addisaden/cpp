#include "hw.h"
#include <sstream>

Auto::Auto() {
  speed = 0.0;
}

float Auto::beschleunige(float additional_speed) {
  int is_pos = additional_speed >= 0 ? 1 : -1;
  speed += is_pos * additional_speed;
  return speed;
}

float Auto::bremse() {
  speed -= 30;
  speed = speed < 0 ? 0 : speed;
  return speed;
}

string Auto::to_string() {
  stringbuf result;
  ostream out (&result);
  out << "Das Auto fährt " << speed << " km/h schnell.";
  return result.str();
}
