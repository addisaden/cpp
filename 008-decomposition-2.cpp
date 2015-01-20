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
 */

#include <iostream>
using namespace std;

int GetInput(int weeklySales);
float CalcMethod1(int weeklySales, int hoursPerWeek);
float CalcMethod2(int weeklySales, int hoursPerWeek);
float CalcMethod3(int weeklySales, int hoursPerWeek);

int priceOfShoes = 225;

int main() {
  int c1, c2, c3;
  for(int hpw = 30; hpw <= 60; hpw += 5) {
    cout << "Hours per week: " << hpw << " h" << endl;
    cout << "c1: Straight salary of $600 per week" << endl;
    cout << "c2: A salary of $7.00 per hour plus a 10\% commission on sales" << endl;
    cout << "c3: No salary, but 20\% commissions and $20 for each pair of shoes sold" << endl;
    cout << "spw: Sales per week" << endl;
    for(int ws = 0; ws <= hpw * 10; ws += 5) {
      c1 = CalcMethod1(ws, hpw);
      c2 = CalcMethod2(ws, hpw);
      c3 = CalcMethod3(ws, hpw);
      cout << "spw: " << ws;
      if (c1 >= c2 && c1 >= c3)
        cout << " c1: " << c1 << " (c2 " << c2 << ", c3 " << c3 << ")";
      else if (c2 >= c1 && c2 >= c3)
        cout << " c2: " << c2 << " (c1 " << c1 << ", c3 " << c3 << ")";
      else if (c3 >= c1 && c3 >= c2)
        cout << " c3: " << c3 << " (c1 " << c1 << ", c2 " << c2 << ")";
      cout << endl;
    }
  }

  return 0;
}

float CalcMethod1(int weeklySales, int hoursPerWeek) {
  // Straight salary of $600 per week
  return 600.0;
}

float CalcMethod2(int weeklySales, int hoursPerWeek) {
  // A salary of $7.00 per hour plus a 10% commission on sales
  return 7.0 * hoursPerWeek + priceOfShoes * weeklySales * 0.1;
}

float CalcMethod3(int weeklySales, int hoursPerWeek) {
  // No salary, but 20% commissions and $20 for each pair of shoes sold
  return priceOfShoes * weeklySales * 0.2 + 20 * weeklySales;
}
