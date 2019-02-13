#ifndef PLAYER_H
#define PLAYER_H

#include <string>
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
    void setNOfSpaceships(int nr);
    int getNrOfUnplacedSpaceships(int size);
    void createSpaceships();
    void setFiches(int _fiches);
    int getFiches();
    int getSpaceshipID(int index);
    void setName(std::string _name);
    std::string getName();
    int getScore();
    void setScore(int _score);
    void printName();
    Player(std::string _name);
    Player(int _startID);
    Spaceship *spaceshipArray;

  private:
    std::string name;
    int score;
    int startID;
    int fiches;
    int nOfSpaceships;
};
#endif
