#include "base.hpp"
#include <iomanip>
#include <cstdlib>
#include <ctime>

#define kSoldierBuild 40
#define kJeepBuild 10
#define kTankBuild 1

#define kSoldierRadius 1
#define kJeepRadius 3
#define kTankRadius 10

#define kSoldierHitSoldier 7
#define kSoldierHitSoldierChanceN 1
#define kSoldierHitSoldierChanceZ 20

#define kSoldierHitJeep 2
#define kSoldierHitJeepChanceN 5
#define kSoldierHitJeepChanceZ 120

#define kSoldierHitTank 1
#define kSoldierHitTankChanceN 1
#define kSoldierHitTankChanceZ 50

#define kJeepHitSoldier 8
#define kJeepHitSoldierChanceN 2
#define kJeepHitSoldierChanceZ 30

#define kJeepHitJeep 2
#define kJeepHitJeepChanceN 3
#define kJeepHitJeepChanceZ 50

#define kJeepHitTank 0
#define kJeepHitTankChanceN 0
#define kJeepHitTankChanceZ 10

#define kTankHitSoldier 5
#define kTankHitSoldierChanceN 9
#define kTankHitSoldierChanceZ 100

#define kTankHitJeep 2
#define kTankHitJeepChanceN 1
#define kTankHitJeepChanceZ 80

#define kTankHitTank 2
#define kTankHitTankChanceN 3
#define kTankHitTankChanceZ 50

GameOfWar::Base::Base() {
  srand(time(NULL));
  soldiers = 10;
  jeeps = 2;
  tanks = 1;
}

void GameOfWar::Base::setEnemy(Base* enemy_base) {
  enemy = enemy_base;
}

void GameOfWar::Base::status() {
  cout << "Soldaten " << setw(15) << soldiers << endl;
  cout << "Jeeps    " << setw(15) << jeeps << endl;
  cout << "Panzer   " << setw(15) << tanks << endl;
  cout << "Gegner: ";
  cout << (*enemy).getSoldiers() << " Soldaten, ";
  cout << (*enemy).getJeeps() << " Jeeps, ";
  cout << (*enemy).getTanks() << " Panzer." << endl;
}

bool GameOfWar::Base::dead() {
  return (soldiers <= 0 && jeeps <= 0 && tanks <= 0);
}

void GameOfWar::Base::buildSoldiers() {
  int builds = rand() % (kSoldierBuild + 1);
  soldiers += builds;
  cout << builds << (builds == 1 ? " Soldat" : " Soldaten") << " ausgebildet." << endl;
}

void GameOfWar::Base::buildJeeps() {
  int builds = rand() % (kJeepBuild + 1);
  jeeps += builds;
  cout << builds << (builds == 1 ? " Jeep" : " Jeeps") << " hergestellt." << endl;
}

void GameOfWar::Base::buildTanks() {
  int builds = rand() % (kTankBuild + 1);
  tanks += builds;
  cout << builds << (builds == 1 ? " Panzer" : " Panzer") << " hergestellt." << endl;
}

int GameOfWar::Base::getSoldiers() { return soldiers; }
int GameOfWar::Base::getJeeps() { return jeeps; }
int GameOfWar::Base::getTanks() { return tanks; }

void GameOfWar::Base::deadSoldier() { soldiers -= soldiers > 0 ? 1 : 0; }
void GameOfWar::Base::deadJeep() { jeeps -= jeeps > 0 ? 1 : 0; }
void GameOfWar::Base::deadTank() { tanks -= tanks > 0 ? 1 : 0; }

void GameOfWar::Base::attack() {
  int killed_soldiers = 0;
  int killed_jeeps = 0;
  int killed_tanks = 0;

  // soldiers turn
  for(int i = 0; i < soldiers; i++) {
    for(int j = 0; j < kSoldierRadius; j++) {
      int target = rand() % (kSoldierHitSoldier + kSoldierHitJeep + kSoldierHitTank);
      if(target < kSoldierHitSoldier) {
        if((rand() % kSoldierHitSoldierChanceZ) < kSoldierHitSoldierChanceN && (*enemy).getSoldiers() > 0) {
          (*enemy).deadSoldier();
          killed_soldiers++;
        }
      } else if((target - kSoldierHitSoldier) < kSoldierHitJeep) {
        if((rand() % kSoldierHitJeepChanceZ) < kSoldierHitJeepChanceN && (*enemy).getJeeps() > 0) {
          (*enemy).deadJeep();
          killed_jeeps++;
        }
      } else {
        if((rand() % kSoldierHitTankChanceZ) < kSoldierHitTankChanceN && (*enemy).getTanks() > 0) {
          (*enemy).deadTank();
          killed_tanks++;
        }
      }
    }
  }

  // jeeps turn
  for(int i = 0; i < jeeps; i++) {
    for(int j = 0; j < kJeepRadius; j++) {
      int target = rand() % (kJeepHitSoldier + kJeepHitJeep + kJeepHitTank);
      if(target < kJeepHitSoldier) {
        if((rand() % kJeepHitSoldierChanceZ) < kJeepHitSoldierChanceN && (*enemy).getSoldiers() > 0) {
          (*enemy).deadSoldier();
          killed_soldiers++;
        }
      } else if((target - kJeepHitSoldier) < kJeepHitJeep) {
        if((rand() % kJeepHitJeepChanceZ) < kJeepHitJeepChanceN && (*enemy).getJeeps() > 0) {
          (*enemy).deadJeep();
          killed_jeeps++;
        }
      } else {
        if((rand() % kJeepHitTankChanceZ) < kJeepHitTankChanceN && (*enemy).getTanks() > 0) {
          (*enemy).deadTank();
          killed_tanks++;
        }
      }
    }
  }

  // tanks turn
  for(int i = 0; i < tanks; i++) {
    for(int j = 0; j < kTankRadius; j++) {
      int target = rand() % (kTankHitSoldier + kTankHitJeep + kTankHitTank);
      if(target < kTankHitSoldier) {
        if((rand() % kTankHitSoldierChanceZ) < kTankHitSoldierChanceN && (*enemy).getSoldiers() > 0) {
          (*enemy).deadSoldier();
          killed_soldiers++;
        }
      } else if((target - kTankHitSoldier) < kTankHitJeep) {
        if((rand() % kTankHitJeepChanceZ) < kTankHitJeepChanceN && (*enemy).getJeeps() > 0) {
          (*enemy).deadJeep();
          killed_jeeps++;
        }
      } else {
        if((rand() % kTankHitTankChanceZ) < kTankHitTankChanceN && (*enemy).getTanks() > 0) {
          (*enemy).deadTank();
          killed_tanks++;
        }
      }
    }
  }

  cout << "Besiegt: " << killed_soldiers << " Soldaten, " << killed_jeeps << " Jeeps und " << killed_tanks << " Panzer." << endl;
}
