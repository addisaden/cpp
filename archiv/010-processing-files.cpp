/*
 * https://developers.google.com/edu/c++/getting-started
 *
 * Example 9: Processing Files
 *
 * [ x ] done
 * 
 */

#include <iostream>
#include <fstream>
using namespace std;

#define filename "010-processing-files.txt.out"

void list_entries() {
  string vorname, nachname, telefonnummer;

  // list current records
  ifstream inpFile(filename, ifstream::in);
  if(inpFile.is_open()) {
    while(getline(inpFile, vorname) && getline(inpFile, nachname) && getline(inpFile, telefonnummer)) {
      cout << ":: " << nachname << ", " << vorname << " (tel " << telefonnummer << ")" << endl;
      inpFile.ignore(100, '\n');
    }
    inpFile.close();
  }
}

int main() {
  string vorname, nachname, telefonnummer, eingabe;

  cout << endl;
  cout << " ---------------" << endl;
  cout << "-- Telefonbuch --" << endl;
  cout << " ---------------" << endl << endl;

  list_entries();

  while(cout << endl << "Neuer Eintrag? (y/n) ", getline(cin, eingabe), eingabe == "y") {
    ofstream outpFile(filename, ofstream::app);
    if(outpFile.is_open()) {
      cout << endl;
      cout << "Vorname: ";
      getline(cin, vorname);
      cout << "Nachname: ";
      getline(cin, nachname);
      cout << "Telefon: ";
      getline(cin, telefonnummer);
      outpFile << vorname << endl << nachname << endl << telefonnummer << endl << endl;
      outpFile.close();
      cout << endl << "Eintrag hinzugefügt" << endl << endl;

      list_entries();
    }
  }
}
