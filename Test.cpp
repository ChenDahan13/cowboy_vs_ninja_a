#include "doctest.h"
#include <iostream>
#include <string>
#include "sources/Character.hpp"
#include "sources/Point.hpp"
#include "sources/Team.hpp"

using namespace ariel;
using namespace std;

TEST_CASE("Point class tests") {
    Point p1(1.0,2.0), p2(9.0,8.0);
    
    CHECK(p1.getX() == 1.0);
    CHECK(p1.getY() == 2.0);
    CHECK(p2.getX() == 9.0);
    CHECK(p2.getY() == 8.0);

    CHECK(p1.distance(p2) == 10.0);
    CHECK(p1.print().compare("(1.0,2.0)") == 0);

    Point p3(0.0, 0.0), p4(3.0, 4.0);

    Point p5 = p3.moveTowards(p4, 2.0);
    CHECK(p5.getX() == 1.2);
    CHECK(p5.getY() == 1.6);

    Point p6 = p3.moveTowards(p4, 5.0);
    CHECK(p6.getX() == 3.0);
    CHECK(p6.getY() == 4.0);

}

TEST_CASE("Cowboy class tests") {
    Point p1(0.0,0.0), p2(3.0,4.0);
    Cowboy *Chen = new Cowboy("Chen", p1);
    Cowboy *Nadav = new Cowboy("Chen", p2);
    double dest = Chen->distance(Nadav);
    CHECK(dest == 5.0);
    CHECK(Chen->isAlive() == true);
    CHECK(Chen->hasboolets() == true);
    CHECK(Nadav->isAlive() == true);
    CHECK(Nadav->hasboolets() == true);

    for(int i=0; i < 6; i++)
        Chen->shoot(Nadav);
    
    CHECK(Chen->hasboolets() == false);
    CHECK(Nadav->isAlive() == true);

    Chen->reload();

    CHECK(Chen->hasboolets() == true);

}

TEST_CASE("Ninjas class tests") {
    Point p1(0.0,0.0), p2(3.0,4.0);
    OldNinja* Chen = new OldNinja("Chen", p2);
    YoungNinja* Nadav = new YoungNinja("Nadav", p1);

    Nadav->move(Chen);
    Point p3 = Nadav->getLocation();
    CHECK(p3.getX() == 8.4);
    CHECK(p3.getY() == 11.2);

    delete Chen;
    delete Nadav;

    Point p4(0.0,0.0), p5(0.5,0.5);
    Chen = new OldNinja("Chen", p4);
    Nadav = new YoungNinja("Nadav", p5);

    for(int i = 0; i < 3; i++) {
        Chen->slash(Nadav);
    }  

    CHECK(Nadav->isAlive() == false);  

}

TEST_CASE("Team class tests") {
    Point p1(0.0,0.0), p2(3.0,4.0), p3(5.0,6.0), p4(8.0,9.0);
    Cowboy *Chen = new Cowboy("Chen", p1);
    Cowboy *Nadav = new Cowboy("Nadav", p2);

    TrainedNinja *Sesko = new TrainedNinja("Sesko", p3);
    YoungNinja *Reem = new YoungNinja("Reem", p4);

    Team teamA(Chen);
    teamA.add(Nadav);
    Team teamB(Sesko);
    teamB.add(Reem);

    CHECK(teamA.stillAlive() == 2);
    CHECK(teamB.stillAlive() == 2);

    for(int i = 0; i < 11; i++) {
        teamA.attack(&teamB);
    }

    CHECK(teamB.stillAlive() == 0);
}


