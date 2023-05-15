#include "Team.hpp"

/*----------- Team Class ------------*/
Team::Team(Character* character): freeIndex(1), leader(0) {
    this->team[0] = character;
}

Team::Team(const Team& other) {
    cout << "Copy constructor" << endl;
}

Team::~Team() {
    cout << "Destructor" << endl;
}

void Team::add(Character* character) {
    cout << "Add" << endl;
}

void Team::attack(Team* enemies) {
    cout << "Attack" << endl;
}

int Team::stillAlive() {
    cout << "Still alive" << endl;
    return 0;
}

void Team::print() {
    cout << "Print" << endl;
}
/*------------------------------------*/


/*----------- SmartTeam Class ------------*/
SmartTeam::SmartTeam(Character* character): Team(character) {}

void SmartTeam::attack(Team* enemies) {
    cout << "Attack" << endl;
}
/*------------------------------------*/


/*----------- Team2 Class ------------*/
Team2::Team2(Character* character): Team(character) {}

void Team2::add(Character* character) {
    cout << "Add" << endl;
}

void Team2::attack(Team* enemies) {
    cout << "Attack" << endl;
}

void Team2::print() {
    cout << "Print" << endl;
}
/*------------------------------------*/
