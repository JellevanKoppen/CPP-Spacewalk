#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <vector>
#include "board.h"

using namespace std;

Board::Board(int _players) : player1(10), player2(20) {
  cout << "Generating board" << endl;
  players = _players;
  nOfSpaceshipsOnBoard = players * 9;
  if (players == 2){
    bodies = 18;
    bodyArray = (Body*) calloc(sizeof(Body), bodies);
    assert(bodyArray);
  } else if (players > 2){
    cout << "TODO..." << endl;
  }
  locationArray = (string*) calloc(sizeof(string), bodies);
  assert(locationArray);
  locationArray = new string[bodies];
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
    int id = player1.getSpaceshipID(i);
    //player1.moveSpaceship(i, bodyArray[i].getID());
    bodyArray[i].setSpaceshipOnPlanetVector(id);
  }
}

void Board::createBoard(){
  bodyArray = new Body[bodies];
  for (int i=0; i<bodies; i++){
    if(i % 9 == 0){
      bodyArray[i].setID(-1*(i+1));
    } else {
      bodyArray[i].setID(i+1);
    }
    bodyArray[i].createSpaceStation(nOfSpaceshipsOnBoard);
    bodyArray[i].sayHi();
  }
}

// Fase 1: Players place spacehips on board turn for turn.
void Board::fase1(){
  bool player1 = true;
  bool player2 = false;
}

void Board::printLocations(){
  int spaceships = player1.getNOfSpaceships();
  for (int i = 0; i < spaceships; i++){
    cout << "Spaceship: " << i << " is on planet: " << player1.getSpaceshipLocation(i) << endl;
  }
}

void Board::printSpaceshipLocations(){
    for (int i = 0; i < bodies; i++){
      cout << "Planet: " << i << endl;
      bodyArray[i].printSpaceships();
    }
}

void Board::getLocations(){
  for (int i = 0; i < bodies; i++){
    int size = 0;
    int smallSize = 0, mediumSize = 0, largeSize = 0;
    vector<int> spaceshipIDS = bodyArray[i].getSpaceships();
    int spaceshipIDSSize = spaceshipIDS.size();
    cout << spaceshipIDSSize << endl;
    for (int i = 0; i < spaceshipIDSSize; i++){
      cout << "Spaceship ID: " << spaceshipIDS[i] << endl;
      if(spaceshipIDS[i] < 20 && spaceshipIDS[i] != 0){
        size = player1.getSpaceshipSize(spaceshipIDS[i]);
      } else if (i > 19){
        size = player2.getSpaceshipSize(spaceshipIDS[i]);
      } else {
        size = 0;
      }
      if (size == 1){
        cout << "Small" << endl;
        smallSize++;
      } else if(size == 2){
        cout << "Medium" << endl;
        mediumSize++;
      } else if(size == 3){
        cout << "Large" << endl;
        largeSize++;
      } else if (size == 0){
        continue;
      } else {
        cout << "Error: Spaceshipsize not found" << endl;
      }
    }
    locationArray[i] = "  " + to_string(largeSize) + "L|" + to_string(mediumSize) + "M|" + to_string(smallSize) + "S  ";
    cout << "Planeet: " << i << " " << locationArray[i] << endl;
  }
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
  cout << "Player1:"<< locationArray[1] << locationArray[2] << locationArray[3] << locationArray[4] << locationArray[5] << locationArray[6] << locationArray[7] << locationArray[8] << endl;
  cout << "" << endl;
  cout << "          |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|" << endl;
  cout << "          |--01--|    |--02--|    |--03--|    |--04--|    |--05--|    |--06--|    |--07--|    |--08--|" << endl;
  cout << "          |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|" << endl;
  cout << "{~~~~~}                                                                                                  {~~~~~}" << endl;
  cout << "{#@1&$}                                                                                                  {#@2&$}" << endl;
  cout << "{~~~~~}                                                                                                  {~~~~~}" << endl;
  cout << "          |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|" << endl;
  cout << "          |--16--|    |--15--|    |--14--|    |--13--|    |--12--|    |--11--|    |--10--|    |--09--|" << endl;
  cout << "          |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|    |Planet|" << endl;
  cout << "" << endl;
  cout << "Player1:"<< locationArray[10] << locationArray[11] << locationArray[12] << locationArray[13] << locationArray[14] << locationArray[15] << locationArray[16] << locationArray[17] << endl;
  cout << "" << endl;
  }
