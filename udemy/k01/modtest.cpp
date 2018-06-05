#include <iostream>
#include "modtest.h"

using std::cout;
using std::endl;

void mod2liste(int it, int jt)
{
  for(int i = 0; i < it; i++)
  {
    for(int j = 0; j < jt; j++)
    {
      cout << "Die Summe aus " << i << " und " << j;
      (i + j) % 2 == 0 ? cout << " ist gerade" : cout << " ist ungerade";
      cout << endl;
    }
  }
}
