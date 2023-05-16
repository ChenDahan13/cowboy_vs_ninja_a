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

    Point p5 = Point::moveTowards(p3 ,p4, 2.0);
    CHECK(p5.getX() == 1.2);
    CHECK(p5.getY() == 1.6);

    Point p6 = Point::moveTowards(p3, p4, 5.0);
    CHECK(p6.getX() == 3.0);
    CHECK(p6.getY() == 4.0);

}

TEST_CASE("Cowboy class tests") {
    Point p1(0.0,0.0), p2(3.0,4.0);
    Cowboy *Chen = new Cowboy("Chen", p1);
    Cowboy *Nadav = new Cowboy("Nadav", p2);
    
    CHECK_EQ(Chen->getName(), "Chen");
    CHECK_EQ(Nadav->getName(), "Nadav");
    
    double dest = Chen->distance(Nadav);
    CHECK(dest == 5.0);
    CHECK(Chen->isAlive() == true);
    CHECK(Chen->hasboolets() == true);
    CHECK(Nadav->isAlive() == true);
    CHECK(Nadav->hasboolets() == true);

    for(int i = 0; i < 6; i++)
        Chen->shoot(Nadav);
    
    CHECK(Chen->hasboolets() == false);
    CHECK(Nadav->isAlive() == true);

    Chen->reload();

    CHECK(Chen->hasboolets() == true);

    for(int i = 0; i < 5; i++)
        Chen->shoot(Nadav);

    CHECK(Chen->hasboolets() == true);
    CHECK(Nadav->isAlive() == false);

    CHECK_THROWS(Chen->shoot(Nadav)); // Character is already dead
    CHECK_THROWS(Chen->shoot(Chen)); // Imposible situation
    CHECK_THROWS(Chen->shoot(NULL)); // Imposible situation

}

TEST_CASE("Ninjas class tests") {
    Point p1(0.0,0.0), p2(3.0,4.0), p3(-1.0,-5.0);
    OldNinja* Chen = new OldNinja("Chen", p2);
    YoungNinja* Nadav = new YoungNinja("Nadav", p1);
    TrainedNinja* Sesko = new TrainedNinja("Sesko", p3);

    CHECK_EQ(Chen->getName(), "Chen");
    CHECK_EQ(Nadav->getName(), "Nadav");
    CHECK_EQ(Sesko->getName(), "Sesko");
    
    CHECK(Chen->getLocation().getX() == 0.0);
    CHECK(Chen->getLocation().getY() == 0.0);
    CHECK(Nadav->getLocation().getX() == 3.0);
    CHECK(Nadav->getLocation().getY() == 4.0);
    CHECK(Sesko->getLocation().getX() == -1.0);
    CHECK(Sesko->getLocation().getY() == -5.0);
    
    Nadav->move(Chen);
    Point p4 = Nadav->getLocation();
    CHECK(p4.getX() == 8.4);
    CHECK(p4.getY() == 11.2);

    delete Chen;
    delete Nadav;

    Point p5(0.0,0.0), p6(0.5,0.5);
    Chen = new OldNinja("Chen", p5);
    Nadav = new YoungNinja("Nadav", p6);

    for(int i = 0; i < 3; i++) {
        Chen->slash(Nadav);
    }  

    CHECK(Nadav->isAlive() == false);

    CHECK_THROWS(Chen->slash(Nadav)); // Character is already dead
    CHECK_THROWS(Chen->slash(Chen)); // Imposible situation
    
    CHECK_THROWS(Chen->move(Nadav)); // Character is already dead
    CHECK_THROWS(Chen->move(Chen)); // Imposible situation

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

    Cowboy *example1 = new Cowboy("example1", Point(0, 0));
    Cowboy *example2 = new Cowboy("example2", Point(0, 0));
    Cowboy *example3 = new Cowboy("example3", Point(0, 0));
    Cowboy *example4 = new Cowboy("example4", Point(0, 0));
    Cowboy *example5 = new Cowboy("example5", Point(0, 0));
    Cowboy *example6 = new Cowboy("example6", Point(0, 0));
    Cowboy *example7 = new Cowboy("example7", Point(0, 0));
    Cowboy *example8 = new Cowboy("example8", Point(0, 0));
    Cowboy *example9 = new Cowboy("example9", Point(0, 0));

    teamA.add(example1);
    teamA.add(example2);
    teamA.add(example3);
    teamA.add(example4);
    teamA.add(example5);
    teamA.add(example6);
    teamA.add(example7);
    teamA.add(example8);

    CHECK_THROWS(teamA.add(example9)); // The team is full
}


