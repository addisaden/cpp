#include <iostream>
using namespace std;

namespace GameOfWar {
  class Base {
    int soldiers;
    int jeeps;
    int tanks;
    int last_status[3];
    Base *enemy;

    public:
    Base();
    void setEnemy(Base*);

    void status();
    bool dead();

    int getSoldiers();
    int getJeeps();
    int getTanks();
    void deadSoldier();
    void deadJeep();
    void deadTank();

    // private .. later
    void attack();
    void buildSoldiers();
    void buildJeeps();
    void buildTanks();

    private:
    void reset_last_status();
  };
};
