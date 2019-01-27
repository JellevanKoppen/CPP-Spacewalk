#ifndef BOARD_H
#define BOARD_H

#include "body.h"
#include "player.h"

class Board{
  public:
    void setBodies();
    void createBoard();
    void fase1();
    void setSpaceship(int spaceshipID);
    int pickSpaceship();
    void createPlayers(int _players);
    void setBodies(int _bodies);
    void printLocations();
    void printSpaceshipLocations();
    void getLocations();
    Board(int _players);
    ~Board();
    void print();
  private:
    Player player1;
    Player player2;
    int nOfSpaceshipsOnBoard;
    bool fase1State;
    int bodies;
    int turn;
    int players;
    std::string *locationArrayP1;
    std::string *locationArrayP2;
    Body *bodyArray;
};
#endif
