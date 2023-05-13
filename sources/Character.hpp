#pragma once
#include <iostream>
#include <string>
#include "Point.hpp"
using namespace std;
using namespace ariel;

const int DEFAULT_POINTS = 50;
const int DEFAULT_SPEED = 20;

class Character {
    
    Point position;
    int points;
    string name;
    int type; // 0 for cowboys, 1 for ninjas
    
    public:
        Character(string name = "Chen", Point position = Point(0,0), int points = DEFAULT_POINTS, int type = 0);
        ~Character() = default;
        Character(const Character& other) = default;
        Character& operator=(const Character& other) = default;
        Character(Character&& other) = default;
        Character& operator=(Character&& other) = default;

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
        Cowboy(string name = "Chen", Point position = Point(0,0));
        ~Cowboy() = default;
        Cowboy(const Cowboy& other) = default;
        Cowboy& operator=(const Cowboy& other) = default;
        Cowboy(Cowboy&& other) noexcept = default;
        Cowboy& operator=(Cowboy&& other) noexcept = default;

        void shoot(Character* enemy);
        bool hasboolets();
        void reload();

};


class Ninja: public Character {
    
    int speed;

    public:
        Ninja(string name = "Chen", Point position = Point(0,0), int points = DEFAULT_POINTS, int speed = DEFAULT_SPEED);
        ~Ninja() = default;
        Ninja(const Ninja& other) = default;
        Ninja& operator=(const Ninja& other) = default;
        Ninja(Ninja&& other) noexcept = default;
        Ninja& operator=(Ninja&& other) noexcept = default;

        void move(const Character* enemy);
        void slash(Character* enemy);

};


class YoungNinja: public Ninja {

    public:
        YoungNinja(string name = "Chen", Point position = Point(0,0));
        ~YoungNinja() = default;
        YoungNinja(const YoungNinja& other) = default;
        YoungNinja& operator=(const YoungNinja& other) = default;
        YoungNinja(YoungNinja&& other) noexcept = default;
        YoungNinja& operator=(YoungNinja&& other) noexcept = default;

};


class TrainedNinja: public Ninja {

    public:
        TrainedNinja(string name = "Chen", Point position = Point(0,0));
        ~TrainedNinja() = default;
        TrainedNinja(const TrainedNinja& other) = default;
        TrainedNinja& operator=(const TrainedNinja& other) = default;
        TrainedNinja(TrainedNinja&& other) noexcept = default;
        TrainedNinja& operator=(TrainedNinja&& other) noexcept = default;
        
};


class OldNinja: public Ninja {

    public:
        OldNinja(string name = "Chen", Point position = Point(0,0));
        ~OldNinja() = default;
        OldNinja(const OldNinja& other) = default;
        OldNinja& operator=(const OldNinja& other) = default;
        OldNinja(OldNinja&& other) noexcept = default;
        OldNinja& operator=(OldNinja&& other) noexcept = default;
        
};