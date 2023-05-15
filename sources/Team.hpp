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
        Team() = default;
        Team& operator=(const Team& other) = default;
        Team(Team&& other) = default;
        Team& operator=(Team&& other) = default;
        virtual ~Team();

        virtual void add(Character* character);
        virtual void attack(Team* enemies);
        int stillAlive();
        virtual void print();

};

class Team2: public Team{
        
    public:
        Team2(Character* character);
        void add(Character* character) override; 
        void attack(Team* enemies) override;   
        void print() override;     

        Team2() = default;
        Team2(const Team2& other) = default;
        Team2 &operator=(const Team2& other) = default;
        Team2(Team2&& other) noexcept = default;
        Team2 &operator=(Team2&& other) noexcept = default;
        
};

class SmartTeam: public Team{
    
    public:
        SmartTeam(Character* character);
        void attack(Team* enemies) override;   

        SmartTeam() = default;
        SmartTeam(const SmartTeam& other) = default;
        SmartTeam &operator=(const SmartTeam& other) = default;
        SmartTeam(SmartTeam&& other) noexcept = default;
        SmartTeam &operator=(SmartTeam&& other) noexcept = default;
        
};
