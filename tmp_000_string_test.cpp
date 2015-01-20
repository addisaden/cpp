#include <iostream>
#include <string>
using namespace std;

int main() {
  string vorname, nachname;

  cout << "Bitte geben Sie ihren Vornamen ein: ";
  cin >> vorname;
  cout << "Bitte geben Sie ihren Nachnamen ein: ";
  cin >> nachname;

  cout << "Ihr Name: " << nachname << ", " << vorname << endl;
  cout << "Capacity: " << nachname.capacity() << endl;
  cout << "Length: " << nachname.length() << endl;

  return 0;
}
