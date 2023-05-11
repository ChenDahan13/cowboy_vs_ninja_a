#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
using namespace std;
using namespace ariel;


class Character {
    
    Point position;
    int points;
    string name;
    int type; // 0 for cowboys, 1 for ninjas
    
    public:
        Character(string name = "Chen", Point poin = Point(0,0), int points = 50, int type = 0);
        bool isAlive();
        double distance(const Character* other);
        void hit(int points);
        string getName();
        Point getLocation();
        string print();

};


class Cowboy: public Character {

    int bullets;

    public:
        Cowboy(string name = "Chen", Point poin = Point(0,0));
        void shoot(Character* enemy);
        bool hasboolets();
        void reload();

};


class Ninja: public Character {
    
    int speed;

    public:
        Ninja(string name = "Chen", Point poin = Point(0,0), int points = 50, int speed = 20);
        void move(const Character* enemy);
        void slash(Character* enemy);

};


class YoungNinja: public Ninja {

    public:
        YoungNinja(string name = "Chen", Point poin = Point(0,0));

};


class TrainedNinja: public Ninja {

    public:
        TrainedNinja(string name = "Chen", Point poin = Point(0,0));
        
};


class OldNinja: public Ninja {

    public:
        OldNinja(string name = "Chen", Point poin = Point(0,0));
        
};