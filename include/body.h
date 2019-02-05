#ifndef BODY_H
#define BODY_H
#include <vector>
#include <algorithm>

class Body{
  public:
    void sayHi();
    void setID(int _id);
    int getID();
    void setSpaceshipOnPlanet(int _spaceshipID);
    void setSpaceshipOnPlanetVector(int _spaceshipID);
    void removeSpaceshipOffPlanetVector(int _spaceshipID);
    bool spaceshipOnPlanet(int _spaceshipID);
    void createSpaceStation(int _spaceships);
    void printSpaceships();
    std::vector<int> getSpaceships();
    ~Body();
    void print();
  private:
    int id;
    int spaceships;
    int *spaceshipArray;
    std::vector<int> spaceshipVector;
};
#endif
