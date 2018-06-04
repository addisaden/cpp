/*
* https://developers.google.com/edu/c++/next-steps
*
* Example #2: Practice with Pointers
*
* [ x ] done
*
*/

#include <iostream>
using namespace std;

void DuplicateCpp(int& a, int& b, int& c) {
  a *= 2;
  b *= 2;
  c *= 2;
}

void DuplicateC(int* a, int* b, int* c) {
  *a *= 2;
  *b *= 2;
  *c *= 2;
}

void DoIt(int &foo, int goo) {
  foo = goo + 3;
  goo = foo + 4;
  foo = goo + 3;
  goo = foo;
}

int main() {
  int a, b, c;
  a = 2;
  b = 3;
  c = 4;

  cout << "a: " << a << " b: " << b << " c: " << c << endl;
  DuplicateCpp(a, b, c);
  cout << "a: " << a << " b: " << b << " c: " << c << endl;
  DuplicateC(&a, &b, &c);
  cout << "a: " << a << " b: " << b << " c: " << c << endl;
  cout << endl;

  int *foo, *goo;
  foo = new int;
  *foo = 1;
  goo = new int;
  *goo = 3;
  *foo = *goo + 3;
  delete foo;
  foo = goo;
  *goo = 5;
  *foo = *goo + *foo;
  DoIt(*foo, *goo);
  // should print 20!
  cout << (*foo) << endl;
  delete goo;

  return 0;
}
