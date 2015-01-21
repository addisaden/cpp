#include <iostream>
using namespace std;

class Auto {
  public:
    Auto();
    float beschleunige(float additional_speed);
    float bremse();
    string to_string();
  private:
    float speed;
};
