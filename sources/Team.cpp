#include "Team.hpp"

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

