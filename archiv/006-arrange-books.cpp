/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Example 5: Arrange books
 *
 * [ x ] How many ways can you arrange 6 different books, left to right, on a shelf? 720
 *
 */

#include <iostream>
using namespace std;

int main() {
  int sorted = 0;

  for(int a = 0; a < 6; a++) {
    for(int b = 0; b < 6; b++) {
      if(b == a) continue;
      for(int c = 0; c < 6; c++) {
        if(c == a || c == b) continue;
        for(int d = 0; d < 6; d++) {
          if(d == a || d == b || d == c) continue;
          for(int e = 0; e < 6; e++) {
            if(e == a || e == b || e == c || e == d) continue;
            for(int f = 0; f < 6; f++) {
              if(f == a || f == b || f == c || f == d || f == e) continue;
              sorted++;
            }
          }
        }
      }
    }
  }

  cout << "There are " << sorted << " ways to arrange 6 diffrent books." << endl;

  return 0;
}
