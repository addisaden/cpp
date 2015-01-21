#include <iostream>
#include "hw.h"
using namespace std;

int main() {
  Auto a;
  cout << a.to_string() << endl;
  a.beschleunige(50);
  cout << a.to_string() << endl;
  a.bremse();
  cout << a.to_string() << endl;
  a.bremse();
  cout << a.to_string() << endl;

  return 0;
}
