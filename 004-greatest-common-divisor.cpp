/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Example 4: Decomposing makes everything easier...
 *
 * [ x ] greatest common divisor
 *
 * The greatest common divisor of two integers is
 * the largest number that divides them both evenly.
 * For example, gcd(12, 18) = 6, gcd(−4, 14) = 2.
 * The most efficient way to compute gcd is with
 * the Euclidean algorithm. Write a program with
 * a function to compute gcd for two integers.
 * Try doing the function without recursion
 * first - it will help you understand how the
 * algorithm works. Explicitly define your sub-tasks,
 * for example, find the code for the Euclidean
 * algorithm; create a non-recursive function for
 * the algorithm; etc. Here is our solution.
 *
 * https://developers.google.com/edu/c++/solutions/1-7
 *
 */

#include <iostream>
using namespace std;

int my_solution(int a, int b);
int google_solution(int a, int b);

int main() {
  int a, b;

  cout << "g r e a t e s t" << endl;
  cout << " c o m m o n" << endl;
  cout << "d i v i s o r !" << endl << endl;

  cout << "Please type in two numbers: ";
  if(!(cin >> a >> b)) {
    cout << "You really should try numbers..." << endl;
    return 0;
  }

  cout << "The greatest common divisor of " << a << " and " << b << " is " << my_solution(a, b) << "!" << endl;
  cout << "And the result of googles solution is " << google_solution(a, b) << "!";

  return 0;
}

int my_solution(int a, int b) {
  int smallest = a > 0 ? a : -1 * a;
  int b_temp = b > 0 ? b : -1 * b;
  if (b_temp < smallest)
    smallest = b_temp;

  for(int i = smallest; i > 0; i--) {
    if(a % i == 0 && b % i == 0) {
      return i;
    }
  }
}

int google_solution(int a, int b) {
  int temp;
  while(b != 0) {
    temp = a % b;
    a = b;
    b = temp;
  }
  return a;
}
