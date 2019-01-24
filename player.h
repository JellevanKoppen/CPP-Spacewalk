#include "spaceship.h"

class Player {
  public:
    virtual ~Player();
    Player();
    void moveSpaceship(int spaceshipID, int location);
    int getSpaceshipLocation(int spaceshipID);
    int getNOfSpaceships();
    void createSpaceships();
    void setFiches(int _fiches);
    int getFiches();
    void setName(char const* _name);
    char const* getName();
    void printName();
    Player(char const* _name);
    Spaceship *spaceshipArray;
  private:
    char const* name;
    int fiches;
    int nOfSpaceships;
};
