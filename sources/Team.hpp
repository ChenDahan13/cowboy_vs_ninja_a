#pragma once
#include "Point.hpp"
#include "Character.hpp"

using namespace ariel;
using namespace std;

#define NUM_OF_CHAR 10

class Team {

    Character* team[NUM_OF_CHAR];
    int freeIndex;
    int leader;

    public:
        Team(Character* character);
        ~Team();
        void add(Character* character);
        void attack(Team* enemies);
        int stillAlive();
        void print();

};