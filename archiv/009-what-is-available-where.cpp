/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Example 8: What is available where?
 *
 * [ x ] done
 * 
 */

#include <iostream>
using namespace std;

// global vars
int a = 18;
int b = 6;

int function1(int a, int b) {
  // use parameters
  return a - b;
}

int function2() {
  int c;
  // use global a and b
  c = a + b;
  return c;
}

int main() {
  int b = 12;
  int c = 0;
  // set global a with local b and global a
  // result global a = -6
  a = function1(b, a);
  // local c = global a -6 + global b 6 = 0;
  c = function2();

  // output: a -6, b 12, c 0
  cout << "a: " << a << " b: " << b << " c: " << c << endl;
}
