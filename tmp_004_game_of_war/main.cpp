#include <iostream>
#include "base.hpp"
using namespace std;

void introduction();

int main() {
  introduction();

  GameOfWar::Base player, ki;

  player.setEnemy(&ki);
  ki.setEnemy(&player);

  int runde = 0;
  int eingabe;

  while(true) {
    if(player.dead() || ki.dead()) break;

    cout << endl << endl << "********* Runde " << ++runde << " *********";
    cout << endl << endl << ">>> Zug des Spielers <<<" << endl;
    player.status();
    do {
    cout << endl << "1 Soldaten ausbilden" << endl
      << "2 Jeeps bauen" << endl
      << "3 Panzer bauen" << endl
      << "4 Angriff!" << endl
      << "1337 Beenden" << endl << endl
      << "Auswahl: ";
    } while(!(cin >> eingabe) || !(eingabe == 1 || eingabe == 2 || eingabe == 3 || eingabe == 4 || eingabe == 1337));

    switch(eingabe) {
      case 1: player.buildSoldiers(); break;
      case 2: player.buildJeeps(); break;
      case 3: player.buildTanks(); break;
      case 4: player.attack();
    }


    if(player.dead() || ki.dead()) break;

    cout << endl << endl << ">>> Zug des Computers <<<" << endl;
    switch(rand() % 6) {
      case 0: ki.buildSoldiers(); break;
      case 1: ki.buildJeeps(); break;
      case 2: ki.buildTanks(); break;
      default: ki.attack();
    }
  }

  cout << endl << endl << endl;
  cout << "... AND THE WINNER IS ..." << endl << endl;
  if(player.dead()) {
    cout << " ------------" << endl;
    cout << "-- COMPUTER --" << endl;
    cout << " ------------" << endl;
  } else if(ki.dead()) {
    cout << " -----------" << endl;
    cout << "-- SPIELER --" << endl;
    cout << " -----------" << endl;
  }
  cout << endl << endl << endl;

  return 0;
}

void introduction() {
  cout << endl << "Welcome to the" << endl << endl;
  cout << " -----------" << endl;
  cout << "-- Game of --" << endl;
  cout << " --- War ---" << endl;
  cout << "   -------" << endl << endl;
}
