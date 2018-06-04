/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Example 4: Decomposing makes everything easier...
 *
 * [ x ] Step 1
 * [ x ] Step 2
 * [ x ] Step 3
 *
 */

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  // give random a seed with time
  srand(time(NULL));

  cout << " ------------" << endl;
  cout << "-- Guessing --" << endl;
  cout << "-     a      -" << endl;
  cout << "--  number  --" << endl;
  cout << " ------------" << endl;
  cout << endl;

  int secret_number = rand() % 100;
  int guessing = -1;
  int counted = 0;

  do {
    cout << "Please guess the number between 0 and 100: ";
    if(!(cin >> guessing)) {
      cout << "Sorry, only numbers allowed." << endl;
      cin.clear();
      cin.ignore(10000, '\n');
      continue;
    }
    if (guessing < 0 || guessing > 100) {
      cout << "Sorry, only numbers between 0 and 100 allowed." << endl;
      continue;
    }
    if (guessing < secret_number) {
      cout << "You guessed too low." << endl;
    } else if (guessing > secret_number) {
      cout << "You guessed too high." << endl;
    }
    counted++;
  } while(guessing != secret_number);

  cout << endl << "### WINNER ### You guessed right. It's the ";
  cout << secret_number << "!" << endl;
  cout << "You tried just " << counted << " times!" << endl << endl;

  return 0;
}
