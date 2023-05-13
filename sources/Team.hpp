#pragma once
#include <iostream>
#include <array>
#include "Point.hpp"
#include "Character.hpp"

using namespace ariel;
using namespace std;

const int NUM_OF_CHAR = 10;

class Team {
    array<Character*, NUM_OF_CHAR> team;
    int freeIndex;
    int leader;

    public:
        Team(Character* character);
        Team(const Team& other);
        Team& operator=(const Team& other) = default;
        Team(Team&& other) = default;
        Team& operator=(Team&& other) = default;
        ~Team();
        void add(Character* character);
        void attack(Team* enemies);
        int stillAlive();
        void print();

};