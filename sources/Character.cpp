#include <string>
#include "Character.hpp"

using namespace ariel;
using namespace std;


/*--------------- Character Class ---------------*/ 
Character::Character(string name, Point position, int points, int type): name(name), position(position), points(points), type(type) {}

bool Character::isAlive() {
    return (this->points > 0) ? true : false;
}

double Character::distance(const Character* other) {
    return this->position.distance(other->position);
}

void Character::hit(int points) {
    if(points < 0) {
        throw invalid_argument("The points to hit can't be zero");
    }
    this->points = this->points - points;
    if(this->points < 0) {
        this->points = 0;
    }
}

string Character::getName() {
    return this->name;
}

Point Character::getLocation() {
    return this->position;
}

string Character::print() {
    string str = "";
    if(!this->isAlive()) {
        if(this->type == 0) { // Cowboy
            str += "C (" + this->name + ") points: " + to_string(this->points); 
        } else if(this->type == 1) { // Ninja
            str += "N (" + this->name + ") points: " + to_string(this->points); 
        }
    } else {
        if(this->type == 0) { // Cowboy
            str += "C (" + this->name + ") points: " + to_string(this->points) + "position: " + this->position.print(); 
        } else if(this->type == 1) { // Ninja
            str += "N (" + this->name + ") points: " + to_string(this->points) + "position: " + this->position.print(); 
        }
    }
    return str;
}
/*----------------------------------------------------*/



/*--------------- Cowboy Class ---------------*/
Cowboy::Cowboy(string name, Point position): Character(name, position, 110, 0), bullets(6) {}

void Cowboy::shoot(Character* enemy) {
    if(this->isAlive() && this->hasboolets()) {
        enemy->hit(10);
        this->bullets = this->bullets - 1;
    }
}

bool Cowboy::hasboolets() {
    return (this->bullets > 0) ? true : false;
}

void Cowboy::reload() {
    this->bullets = this->bullets + 6;
}
/*---------------------------------------------*/



/*--------------- Ninja Class ---------------*/
Ninja::Ninja(string name, Point position, int points, int speed): Character(name, position, points, 1), speed(speed) {}

void Ninja::move(const Character* enemy) {
    cout << "Move" << endl;
}

void Ninja::slash(Character* enemy) {
    double dist = this->distance(enemy);
    if(dist < 1.0 && this->isAlive()) {
        enemy->hit(40);
    }
}
/*-------------------------------------------*/



/*--------------- YoungNinja Class ---------------*/
YoungNinja::YoungNinja(string name, Point position): Ninja(name, position, 100, 14) {}
/*------------------------------------------------*/


/*--------------- TrainedNinja Class ---------------*/
TrainedNinja::TrainedNinja(string name, Point position): Ninja(name, position, 120, 12) {}
/*--------------------------------------------------*/



/*--------------- OldNinja Class ---------------*/
OldNinja::OldNinja(string name, Point position): Ninja(name, position, 150, 8) {}
/*----------------------------------------------*/