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
    void clear();
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
    void winner();
    int useCoin();
    void printSpaceshipLocations();
    void getLocations();
    void calculateScore();
    int getScore(int player);
    Board(int _players);
    ~Board();
    void printBoard();
    void printStats();
    void destroySpaceship(int player);
  private:
    Player player1;
    Player player2;
    bool finished;
    bool coinUsed;
    bool player1UsedCoin;
    bool player2UsedCoin;
    int nOfSpaceshipsOnBoard;
    bool fase1State;
    bool fase2State;
    int bodies;
    int turn;
    int previousturn;
    int players;
    std::string *locationArrayP1;
    std::string *locationArrayP2;
    Body *bodyArray;
};
#endif
