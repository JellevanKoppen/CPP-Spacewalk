#ifndef PLAYER_H
#define PLAYER_H

#include "spaceship.h"

class Player {
  public:
    ~Player();
    Player();
    void moveSpaceship(int spaceshipID, int location);
    int getSpaceshipLocation(int spaceshipID);
    int getSpaceshipSize(int spaceshipID);
    bool getSpaceshipStatus(int spaceshipID);
    int getAvailableSpaceship(int size);
    void setSpaceshipStatus(bool state, int spaceshipID);
    int getNOfSpaceships();
    int getNrOfUnplacedSpaceships(int size);
    void createSpaceships();
    void setFiches(int _fiches);
    int getFiches();
    int getSpaceshipID(int index);
    void setName(char const* _name);
    char const* getName();
    void printName();
    Player(char const* _name);
    Player(int _startID);
    Spaceship *spaceshipArray;

  private:
    char const* name;
    int startID;
    int fiches;
    int nOfSpaceships;
};
#endif
