/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Exercises and Projects
 *
 * [   ] Exercise 1 / 7
 * 
 * The common field cricket chirps in direct proportion
 * to the current temperature. Adding 40 to the number
 * of time a cricket chirps in a minute, then dividing
 * that value by 4 gives us the temperature. Write a
 * program that takes as input the number of chirps in
 * a minute and prints the current temperature. For
 * example,
 *
 * > Number of chirps: 120
 * > The temperature is: 40.0 degrees.
 *
 * ... you should first devide by 4 and add 40 after that.
 * source: http://www.almanac.com/cricket-chirps-temperature-thermometer
 *
 */

#include <iostream>
using namespace std;

float fahrenheit_to_celsius(float temperature) {
  return (temperature - 32) * 5.0 / 9.0;
}

int main() {
  cout << endl;
  cout << "  ---------------" << endl;
  cout << " -- Temperature --" << endl;
  cout << "-- calculated by --" << endl;
  cout << " ---- chirps -----" << endl;
  cout << "  ---------------" << endl << endl;

  cout << "Please count the cricket chirps you hear in a minute." << endl << endl;

  int input_value;
  float result;

  cout << "Number of chirps: ";
  if(cin >> input_value) {
    result = input_value / 4 + 40;
    cout << endl << "Temperature: " << result << " °F / " << fahrenheit_to_celsius(result) << " °C" << endl << endl;
  } else {
    cout << "You should give a number as input." << endl << endl;
  }

  return 0;
}
