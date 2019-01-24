#include <iostream>
#include <cassert>
#include <stdlib.h>
#include "board.h"

using namespace std;

Board::Board(int _players) : player1(), player2() {
  cout << "Generating board" << endl;
  players = _players;
  if (players == 2){
    bodies = 18;
    bodyArray = (Body*) calloc(sizeof(Body), bodies);
    assert(bodyArray);
  } else if (players > 2){
    cout << "TODO..." << endl;
  }
  createPlayers(players);
  createBoard();
}

// create number of players thats given
void Board::createPlayers(int _players){
  cout << "Creating Players" << endl;
  if (_players == 2){
    string name1;
    cout << "Player1 name: ";
    cin >> name1;
    string name2;
    cout << "Player2 name: ";
    cin >> name2;
    player1.setName(name1.c_str());
    player2.setName(name2.c_str());
  }
}

void Board::setSpaceships(){
  int spaceships = player1.getNOfSpaceships();
  for (int i = 0; i < spaceships; i++){
    player1.moveSpaceship(i, bodyArray[i].getID());
  }
}

void Board::createBoard(){
  bodyArray = new Body[bodies];
  for (int i=0; i<bodies; i++){
    if(i % 9 == 0){
      bodyArray[i].setID(-1*(i+1));
      bodyArray[i].sayHi();
    } else {
      bodyArray[i].setID(i+1);
      bodyArray[i].sayHi();
    }
  }
}

void Board::printLocations(){
  int spaceships = player1.getNOfSpaceships();
  for (int i = 0; i < spaceships; i++){
    cout << "Spaceship: " << i << " is on planet: " << player1.getSpaceshipLocation(i) << endl;
  }
}

int Board::spaceshipsOnBoard(){
  return nOfSpaceshipsOnBoard;
}

void Board::setBodies(int _bodies){
  bodies = _bodies;
}

Board::~Board(){
  delete[] bodyArray;
  cout << "Board destroyed" << endl;
}

void Board::print(){
  cout << string(50, '\n');
  cout << "Player1:  1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S" << endl;
  cout << "Player2:  1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S" << endl;
  cout << "          |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|" << endl;
  cout << "          |--01--|    |--02--|    |--03--|    |--04--|    |--05--|    |--06--|    |--07--|    |--08--|" << endl;
  cout << "          |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|" << endl;
  cout << "{~~~~~}                                                                                                  {~~~~~}" << endl;
  cout << "{#@1&$}                                                                                                  {#@2&$}" << endl;
  cout << "{~~~~~}                                                                                                  {~~~~~}" << endl;
  cout << "          |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|" << endl;
  cout << "          |--16--|    |--15--|    |--14--|    |--13--|    |--12--|    |--11--|    |--10--|    |--09--|" << endl;
  cout << "          |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|" << endl;
  cout << "Player1:  1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S    1L|3M|4S" << endl;
  cout << "Player2:  1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S    1L|9M|8S" << endl;
}
