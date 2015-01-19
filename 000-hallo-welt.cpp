/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Example 1: Get your compiler working!
 *
 * [ x ] done
 *
 */

#include <iostream>
#include <iomanip>
using namespace std;

int main() {
  for(int j = 0; j < 6; j++) {
    for(int i = 0; i < 4; i++) {
      // cout.width(17);
      // cout << left << "Hallo Welt";
      cout << setw(17) << left << "Hallo welt";
    }
    cout << endl;
  }
  cout << "This is the end";
  cout << "!" << endl;
  return 0;
}
