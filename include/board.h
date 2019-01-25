#ifndef BOARD_H
#define BOARD_H

#include "body.h"
#include "player.h"

class Board{
  public:
    void setBodies();
    void createBoard();
    void fase1();
    void setSpaceships();
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
    int bodies;
    int players;
    std::string *locationArray;
    Body *bodyArray;
};
#endif
