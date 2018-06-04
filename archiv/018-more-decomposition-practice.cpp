/*
 * https://developers.google.com/edu/c++/next-steps
 *
 * Example #1: More Decomposition Practice
 *
 * [ x ] done
 *
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
using namespace std;



// this is 200 ft/s or 60.96 m/s
#define Kvelocity 60.96

// this is 32.2 ft/s or 9.81456 m/s
#define Kgravity 9.81456

// angle can be 0 - 360
float angle_sin(float angle) { return sin(angle * M_PI / 180.0); }
float angle_cos(float angle) { return cos(angle * M_PI / 180.0); }

// funciton predecleration
void introduction();
void outro(int enemies_down);
int give_a_shot();
int distance_from_angle(float angle);
int make_a_shot();



int main() {
  srand(time(NULL));
  introduction();

  int enemies_down = 0;
  string input;

  do {
    enemies_down += give_a_shot();
    cout << endl << "You've killed " << enemies_down << (enemies_down == 1 ? " enemy." : " enemies.") << endl << endl;
    cout << "Try again? (y/n) ";
  } while((cin >> input), input == "y");

  outro(enemies_down);

  return 0;
}



void introduction() {
  cout
    << endl
    << " ------------------------" << endl
    << "-- Welcome to Artillery --" << endl
    << " ------------------------" << endl
    << endl
    << "You are in the middle of a war and being charged by thousands of enemies. " << endl
    << "You have one cannon, which you can shoot at any angle (0 - 90). " << endl
    << endl;
}

void outro(int enemies_down) {
  cout
    << endl
    << " ----------------------------" << endl
    << "-- You killed " << setw(5) << enemies_down << (enemies_down == 1 ? " enemy   --" : " enemies --") << endl
    << " ----------------------------" << endl;
}



// shoot-the-enemy game
int give_a_shot() {
  int cannon_balls = 10;
  float angle_input;

  int max_distance = distance_from_angle(45);
  int enemy_distance = rand() % max_distance + 1;
  int shoot_distance;

  cout << "Enemy in front of us!" << endl;

  do {
    shoot_distance = make_a_shot();
    
    cout << endl;

    if(shoot_distance == enemy_distance) {
      cout << "You shot the enemy!" << endl << endl;
      return 1;
    } else if (shoot_distance > enemy_distance) {
      cout << "Your shot goes " << shoot_distance - enemy_distance << " meter after the enemy." << endl << endl;
    } else {
      cout << "Your shot goes " << enemy_distance - shoot_distance << " meter before the enemy." << endl << endl;
    }

    cannon_balls--;

    if(cannon_balls > 0)
      cout << "You have " << cannon_balls << " cannonballs left." << endl;
    else
      cout << "You missed the enemy. He escaped." << endl;
  } while(cannon_balls > 0);

  return 0;
}



int distance_from_angle(float angle) {
  float time_in_air, distance;

  time_in_air = (2.0 * Kvelocity * angle_sin(angle)) / Kgravity;
  distance = (int) round((Kvelocity * angle_cos(angle)) * time_in_air);

  return distance;
}



int make_a_shot() {
  float angle;

  while(true) {
    cout << "Make your shot (angle up to 90): ";
    if(cin >> angle) {
      break;
    } else {
      cout << "Please give a valid angle." << endl << endl;
      cin.clear();
      cin.ignore(1000, '\n');
    }
  }

  return distance_from_angle(angle);
}
