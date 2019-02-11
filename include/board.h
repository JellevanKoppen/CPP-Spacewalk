#ifndef BOARD_H
#define BOARD_H

#include "body.h"
#include "player.h"
#include <string>

class Board{
  public:
    void setBodies();
    void createBoard();
    void fase1();
    void fase2();
    void setSpaceship(int spaceshipID);
    int pickSpaceship();
    int pickPlanet(int _size);
    int selectPlanet();
    int makeDecisionForPlayer();
    void moveSpaceships(int planetID);
    void moveSpaceship(int planetID, int spaceshipID);
    std::string getPlayerName(int player);
    void printFase1Information(int player);
    void printFase2Information(int player);
    int generateSpaceshipSpot();  // DEBUGGING
    void setSpaceshipDebug(int spaceshipID); // DEBUGGING
    int pickPlanetDebug(int _size); // DEBUGGING
    void createPlayers(int _players);
    void setBodies(int _bodies);
    void printLocations();
    void printSpaceshipLocations();
    void getLocations();
    Board(int _players);
    ~Board();
    void printBoard();
    void printStats();
  private:
    Player player1;
    Player player2;
    int nOfSpaceshipsOnBoard;
    bool fase1State;
    bool fase2State;
    int bodies;
    int turn;
    int players;
    std::string *locationArrayP1;
    std::string *locationArrayP2;
    Body *bodyArray;
};
#endif
