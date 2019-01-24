#include "body.h"
#include "player.h"

class Board{
  public:
    void setBodies();
    void createBoard();
    void createPlayers(int _players);
    void setBodies(int _bodies);
    void setSpaceships();
    int spaceshipsOnBoard();
    void printLocations();
    Board(int _players);
    virtual ~Board();
    void print();
  private:
    Player player1;
    Player player2;
    int nOfSpaceshipsOnBoard;
    int bodies;
    int players;
    Body *bodyArray;
};
