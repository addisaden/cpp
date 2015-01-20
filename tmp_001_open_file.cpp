#include <iostream>
#include <fstream>
using namespace std;

int main() {
  fstream source_file;
  source_file.open("tmp_001_open_file.cpp", fstream::in);
  
  string current_line;

  // while(source_file >> current_line) {
  while(getline(source_file, current_line)) {
    cout << ": " << current_line << endl;
  }

  source_file.close();

  return 0;
}
