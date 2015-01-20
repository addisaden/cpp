/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Example 7: Next steps with decomposition - Your first day on the job
 *
 * [ x ] done
 * 
 * You should choose this:
 * No salary, but 20% commissions and $20 for each pair of shoes sold
 *
 * make it a little bit smarter
 *
 */

#include <iostream>
using namespace std;

int GetInput(int weeklySales);
float CalcMethod1(int weeklySales);
float CalcMethod2(int weeklySales);
float CalcMethod3(int weeklySales);

#define priceOfShoes 225
#define hoursPerWeek 40

int main() {
  int c1, c2, c3;
  cout << endl << "Hours per week: " << hoursPerWeek << " h" << endl;
  cout << "c1: Straight salary of $600 per week" << endl;
  cout << "c2: A salary of $7.00 per hour plus a 10\% commission on sales" << endl;
  cout << "c3: No salary, but 20\% commissions and $20 for each pair of shoes sold" << endl << endl;

  int last_method = 0;
  bool last_method_presence = false;
  float last_method_price = 0.0;
  int last_method_value = 0;

  for(int ws = 0; ws <= hoursPerWeek * 20; ws++) {
    c1 = CalcMethod1(ws);
    c2 = CalcMethod2(ws);
    c3 = CalcMethod3(ws);

    if(c1 >= c2 && c1 >= c3 && last_method != 1) {
      if(last_method_presence) {
        cout << " Up to " << last_method_value << " sales with " << last_method_price << "$ made." << endl;
      }
      cout << "From " << ws << " sales per week you should choose method c1 stat with " << c1 << "$ per week.";
      last_method = 1;
    } else if(c2 >= c1 && c2 >= c3 && last_method != 2) {
      if(last_method_presence) {
        cout << " Up to " << last_method_value << " sales with " << last_method_price << "$ made." << endl;
      }
      cout << "From " << ws << " sales per week you should choose method c2 stat with " << c2 << "$ per week.";
      last_method = 2;
    } else if(c3 >= c1 && c3 >= c2 && last_method != 3) {
      if(last_method_presence) {
        cout << " Up to " << last_method_value << " sales with " << last_method_price << "$ made." << endl;
      }
      cout << "From " << ws << " sales per week you should choose method c3 stat with " << c3 << "$ per week.";
      last_method = 3;
    }
    switch(last_method) {
      case 1: last_method_price = c1; last_method_value = ws; last_method_presence = true; break;
      case 2: last_method_price = c2; last_method_value = ws; last_method_presence = true; break;
      case 3: last_method_price = c3; last_method_value = ws; last_method_presence = true; break;
      default: last_method_presence = false;
    }
  }

  return 0;
}

float CalcMethod1(int weeklySales) {
  // Straight salary of $600 per week
  return 600.0;
}

float CalcMethod2(int weeklySales) {
  // A salary of $7.00 per hour plus a 10% commission on sales
  return 7.0 * hoursPerWeek + priceOfShoes * weeklySales * 0.1;
}

float CalcMethod3(int weeklySales) {
  // No salary, but 20% commissions and $20 for each pair of shoes sold
  return priceOfShoes * weeklySales * 0.2 + 20 * weeklySales;
}
