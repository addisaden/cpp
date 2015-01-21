#include "base.hpp"
#include <iomanip>
#include <cstdlib>
#include <ctime>

/*         |  B | BOpt | Range | Hit  S, Cn,  Cz | Hit J,  Cn,  Cz | Hit T, Cn, Cz
 * Soldier | 80 |  160 |     1 |20:  75,  4,  30 | 4: 18,  18, 162 |10: 40, 10, 80
 * Jeep    | 10 |   20 |     4 |35:  50,  7,  20 |16: 24,   6,  18 | 2:  8,  6, 48
 * Tank    |  2 |    4 |    10 |25: 125,  8,  80 |20: 60,   3,  18 | 8: 16,  2,  8
 *
 * SoldierCountBalance (SCB) = (40 +  80/2) *  1 = 80 * 4
 * JeepCountBalance    (JCB) = ( 5 +  10/2) *  4 = 40 * 4
 * TankCountBalance    (TCB) = ( 1 +   2/2) * 10 = 20 * 4
 *
 * SoldierHit = 80 = SP + JP + TP = 20 + 35 + 25 ) / 10
 * JeepHit    = 40 = SP + JP + TP =  4 + 16 + 20 ) / 10
 * TankHit    = 20 = SP + JP + TP = 10 +  2 +  8 ) / 10
 *
 */

#define kSoldierBuild 80
#define kSoldierBuildOptional 160
#define kJeepBuild 10
#define kJeepBuildOptional 20
#define kTankBuild 2
#define kTankBuildOptional 4

#define kSoldierRadius 1
#define kJeepRadius 4
#define kTankRadius 10

#define kSoldierHitSoldier 75
#define kSoldierHitSoldierChanceN 4
#define kSoldierHitSoldierChanceZ 150

#define kSoldierHitJeep 18
#define kSoldierHitJeepChanceN 18
#define kSoldierHitJeepChanceZ 810

#define kSoldierHitTank 40
#define kSoldierHitTankChanceN 10
#define kSoldierHitTankChanceZ 400

#define kJeepHitSoldier 50
#define kJeepHitSoldierChanceN 7
#define kJeepHitSoldierChanceZ 100

#define kJeepHitJeep 24
#define kJeepHitJeepChanceN 6
#define kJeepHitJeepChanceZ 90

#define kJeepHitTank 8
#define kJeepHitTankChanceN 6
#define kJeepHitTankChanceZ 240

#define kTankHitSoldier 125
#define kTankHitSoldierChanceN 8
#define kTankHitSoldierChanceZ 400

#define kTankHitJeep 60
#define kTankHitJeepChanceN 3
#define kTankHitJeepChanceZ 90

#define kTankHitTank 16
#define kTankHitTankChanceN 2
#define kTankHitTankChanceZ 40

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
  int builds = rand() % (kSoldierBuildOptional + 1) + kSoldierBuild;
  soldiers += builds;
  cout << builds << (builds == 1 ? " Soldat" : " Soldaten") << " ausgebildet." << endl;
}

void GameOfWar::Base::buildJeeps() {
  int builds = rand() % (kJeepBuildOptional + 1) + kJeepBuild;
  jeeps += builds;
  cout << builds << (builds == 1 ? " Jeep" : " Jeeps") << " hergestellt." << endl;
}

void GameOfWar::Base::buildTanks() {
  int builds = rand() % (kTankBuildOptional + 1) + kTankBuild;
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
