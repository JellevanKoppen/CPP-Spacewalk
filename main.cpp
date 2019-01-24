#include <iostream>
#include "board.h"

using namespace std;

int main(){
  Board board(2);
  board.setSpaceships();
  board.printLocations();
}
