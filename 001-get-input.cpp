/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Example 2: Get some input
 *
 * [ x ] done
 *
 */

#include <iostream>
using namespace std;

int main() {
  int input_var = 0;
  do {
    cout << "Enter a number (-1 to quit): ";
    if(!(cin >> input_var)) {
      cout << "Please enter numbers only." << endl;
      cin.clear();
      cin.ignore(10000, '\n');
      continue;
    }
    if (input_var != -1) {
      cout << "You entered " << input_var << endl;
    }
  } while (input_var != -1);
  cout << "All done." << endl;
}
