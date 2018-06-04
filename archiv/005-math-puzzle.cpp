/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Example 5: Math Puzzles
 *
 * [ x ] done
 *
 */

#include <iostream>
using namespace std;

int main() {
  int horse_price = 10;
  int pigs_price = 3;
  float rabbit_price = 0.5;

  int max_pay = 100;

  int horses_buyed = 0;
  int pigs_buyed = 0;
  int rabbit_buyed = 0;

  for(int i = 0;; i++) {
    if(i * horse_price + i * pigs_price + i * rabbit_price <= max_pay) {
      horses_buyed = i;
    } else if(horses_buyed * horse_price + i * pigs_price + i * rabbit_price <= max_pay) {
      pigs_buyed = i;
    } else if(horses_buyed * horse_price + pigs_buyed * pigs_price + i * rabbit_price <= max_pay) {
      rabbit_buyed = i;
    } else {
      break;
    }
  }

  cout << "The farmer had " << max_pay << "$ and buyed " << horses_buyed << " horses, ";
  cout << pigs_buyed << " pigs and " << rabbit_buyed << " rabbits. He just payed ";
  cout << horses_buyed * horse_price + rabbit_buyed * rabbit_price + pigs_buyed * pigs_price << "$ for all." << endl;

  // oh i diddnt understand it correct ... 100 animals for 100$. So this is googles answer:

  for (int h = 0; h < 100; h++)
    for (int p = 0; p < 100; p++)
      for (int r = 0; r < 100; r++)
        if ((h + p + r) == 100)
          if (((10 * h) + (3 * p) + (0.5 * r)) == 100)
            cout << "Found one! " << h << " horses " << p << " pigs " << r << " rabbits "  << endl;

  return 0;
}
