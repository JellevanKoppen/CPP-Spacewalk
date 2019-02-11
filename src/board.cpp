#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <vector>
#include "board.h"

using namespace std;

Board::Board(int _players) : player1(10), player2(20) {
  cout << "Generating board" << endl;
  fase1State = true;
  fase2State = false;
  turn = 1;
  players = _players;
  nOfSpaceshipsOnBoard = players * 9;
  if (players == 2){
    bodies = 18;
    bodyArray = (Body*) calloc(sizeof(Body), bodies);
    assert(bodyArray);
  }
  locationArrayP1 = (string*) calloc(sizeof(string), bodies);
  assert(locationArrayP1);
  locationArrayP1 = new string[bodies];
  locationArrayP2 = (string*) calloc(sizeof(string), bodies);
  assert(locationArrayP2);
  locationArrayP2 = new string[bodies];
  createPlayers(players);
  createBoard();
}

// create number of players thats given
void Board::createPlayers(int _players){
  cout << "Creating Players" << endl;
  if (_players == 2){
    string name1;
    //cout << "Player1 name: ";
    name1 = "Speler1";
    //cin >> name1;
    string name2;
    //cout << "Player2 name: ";
    //cin >> name2;
    name2 = "Speler2";
    player1.setName(name1);
    player2.setName(name2);
  }
}

/*
void Board::setSpaceships(){
  int spaceships = player1.getNOfSpaceships();
  for (int i = 0; i < spaceships; i++){
    int id = player1.getSpaceshipID(i);
    //player1.moveSpaceship(i, bodyArray[i].getID());
    bodyArray[i].setSpaceshipOnPlanetVector(id+1);
  }
}
*/

void Board::createBoard(){
  bodyArray = new Body[bodies];
  for (int i=0; i<bodies; i++){
    if(i % 9 == 0){
      bodyArray[i].setID(-1*i);
    } else if (i > 9) {
      bodyArray[i].setID(i-1);
    } else {
      bodyArray[i].setID(i);
    }
    bodyArray[i].createSpaceStation(nOfSpaceshipsOnBoard);
    bodyArray[i].sayHi();
  }
}

void Board::printFase1Information(int player){
  string playerName = getPlayerName(player);
  cout << "It's " << playerName << "'s turn.." << endl;
  cout << "Select a spaceship by typing it's size: L(arge),M(edium),S(mall)" << endl;
  //cout << "Next name a planet to place the spaceship on: (Numbers: 1-16)" << endl;
}

 int Board::pickPlanet(int _size){
   printBoard();  // Laat het bord zien
   cout << "Next name a planet to place the spaceship on: (Numbers: 1-16)" << endl;
   int answer = -1;
   int index;
   bool available;
   while (answer == -1){
     int input;
     cout << "Select a planet: ";
     cin >> input;
     cout << endl;
     if(!cin.good()){
       cin.clear();
       cin.ignore(INT8_MAX, '\n');
       continue;
     }

     if(input < 1 || input > 16 ){
       continue;
     }

     for(int i = 0; i < bodies; i++){
       if(bodyArray[i].getID() == input){
        index = i;
       }
     }

     if(turn == 1){
       vector<int> spaceshipIDS = bodyArray[index].getSpaceships();
       int spaceshipIDSSize = spaceshipIDS.size();
       int size;
       available = true;
       for (int i = 0; i < spaceshipIDSSize; i++){
         if(spaceshipIDS[i] < 20 && spaceshipIDS[i] != 0){
           size = player1.getSpaceshipSize(spaceshipIDS[i]);
           if (size == _size){
             available = false;
           }
         }
       }
     } else if (turn == 2){
       vector<int> spaceshipIDS = bodyArray[index].getSpaceships();
       int spaceshipIDSSize = spaceshipIDS.size();
       int size;
       available = true;
       for (int i = 0; i < spaceshipIDSSize; i++){
         if(spaceshipIDS[i] > 19){
           size = player2.getSpaceshipSize(spaceshipIDS[i]);
           if (size == _size){
             available = false;
           }
         }
       }
     }
     if (available){
       return input;
     }
   }
 }

int Board::pickSpaceship(){
  string size;
  int answer = -1;
  while (answer == -1){
    cout << "Select a spaceship: ";
    cin >> size;
    cout << endl;

    if(size == "l" || size == "L" || size == "Large" || size == "large" || size == "3" || size == "LARGE"){
      if(turn == 1){
        answer = player1.getAvailableSpaceship(3);
      } else if (turn == 2){
        answer = player2.getAvailableSpaceship(3);
      } else {
        cout << "Error it's no-ones turn!" << endl;
      }
    }
    if(size == "m" || size == "M" || size == "Medium" || size == "medium" || size == "2" || size == "MEDIUM"){
      if(turn == 1){
        answer = player1.getAvailableSpaceship(2);
      } else if (turn == 2){
        answer = player2.getAvailableSpaceship(2);
      } else {
        cout << "Error it's no-ones turn!" << endl;
      }
    }
    if(size == "s" || size == "S" || size == "Small" || size == "small" || size == "1" || size == "SMALL"){
      if(turn == 1){
        answer = player1.getAvailableSpaceship(1);
      } else if (turn == 2){
        answer = player2.getAvailableSpaceship(1);
      } else {
        cout << "Error it's no-ones turn!" << endl;
      }
    }
    if(answer == -1){
      cout << "You dont have that size spaceship left!" << endl;
    }
  }
  return answer;
}

void Board::setSpaceship(int spaceshipID){
  int size = 0;
  if(turn == 1){
    player1.setSpaceshipStatus(true, spaceshipID);
    size = player1.getSpaceshipSize(spaceshipID);
  } else if (turn == 2){
    player2.setSpaceshipStatus(true, spaceshipID);
    size = player2.getSpaceshipSize(spaceshipID);
  }
  // Check op elke planeet of spaceship id binnen player range en van die size op planeet staat
  int planetID = pickPlanet(size);

  // zet spaceship spaceshipID op planeet planetID
  for (int i = 0; i < bodies; i++){
    if (bodyArray[i].getID() == planetID){
      bodyArray[i].setSpaceshipOnPlanetVector(spaceshipID);
    }
  }
}

// DEBUGGING
int Board::pickPlanetDebug(int _size){
  int answer = -1;
  int index;
  bool available;
  int input = 1;
  while (answer == -1){
    for(int i = 0; i < bodies; i++){
      if(bodyArray[i].getID() == input){
       index = i;
      }
    }

    if(turn == 1){
      vector<int> spaceshipIDS = bodyArray[index].getSpaceships();
      int spaceshipIDSSize = spaceshipIDS.size();
      int size;
      available = true;
      for (int i = 0; i < spaceshipIDSSize; i++){
        if(spaceshipIDS[i] < 20 && spaceshipIDS[i] != 0){
          size = player1.getSpaceshipSize(spaceshipIDS[i]);
          if (size == _size){
            available = false;
          }
        }
      }
    } else if (turn == 2){
      vector<int> spaceshipIDS = bodyArray[index].getSpaceships();
      int spaceshipIDSSize = spaceshipIDS.size();
      int size;
      available = true;
      for (int i = 0; i < spaceshipIDSSize; i++){
        if(spaceshipIDS[i] > 19){
          size = player2.getSpaceshipSize(spaceshipIDS[i]);
          if (size == _size){
            available = false;
          }
        }
      }
    }
    if (available){
      return input;
    } else {
      input++;
    }
  }
}

// DEBUGGING
void Board::setSpaceshipDebug(int spaceshipID){
  int size = 0;
  if(turn == 1){
    player1.setSpaceshipStatus(true, spaceshipID);
    size = player1.getSpaceshipSize(spaceshipID);
  } else if (turn == 2){
    player2.setSpaceshipStatus(true, spaceshipID);
    size = player2.getSpaceshipSize(spaceshipID);
  }
  // Check op elke planeet of spaceship id binnen player range en van die size op planeet staat
  int planetID = pickPlanetDebug(size);

  // zet spaceship spaceshipID op planeet planetID
  for (int i = 0; i < bodies; i++){
    if (bodyArray[i].getID() == planetID){
      bodyArray[i].setSpaceshipOnPlanetVector(spaceshipID);
    }
  }
}

// DEBUGGING
int Board::generateSpaceshipSpot(){
  string size;
  int answer = -1;
  while (answer == -1){
    size = "l";
    if(size == "l" || size == "L" || size == "Large" || size == "large" || size == "3" || size == "LARGE"){
      if(turn == 1){
        answer = player1.getAvailableSpaceship(3);
      } else if (turn == 2){
        answer = player2.getAvailableSpaceship(3);
      } else {
        cout << "Error it's no-ones turn!" << endl;
      }
    }
    if(answer == -1){
      size = "m";
    }
    if(size == "m" || size == "M" || size == "Medium" || size == "medium" || size == "2" || size == "MEDIUM"){
      if(turn == 1){
        answer = player1.getAvailableSpaceship(2);
      } else if (turn == 2){
        answer = player2.getAvailableSpaceship(2);
      } else {
        cout << "Error it's no-ones turn!" << endl;
      }
    }
    if(answer == -1){
      size = "s";
    }
    if(size == "s" || size == "S" || size == "Small" || size == "small" || size == "1" || size == "SMALL"){
      if(turn == 1){
        answer = player1.getAvailableSpaceship(1);
      } else if (turn == 2){
        answer = player2.getAvailableSpaceship(1);
      } else {
        cout << "Error it's no-ones turn!" << endl;
      }
    }
    if(answer == -1){
      cout << "You dont have that size spaceship left!" << endl;
    }
  }
  return answer;
}

// Fase 1: Players place spacehips on board turn for turn.
void Board::fase1(){
  while (fase1State){
    int s = 0, m = 0, l = 0;
    if(turn == 1){
      s = player1.getNrOfUnplacedSpaceships(1);
      m = player1.getNrOfUnplacedSpaceships(2);
      l = player1.getNrOfUnplacedSpaceships(3);
      if(s == 0 && m == 0 && l == 0){
        fase1State = false;
        break;
      }
    } else if (turn == 2){
      s = player2.getNrOfUnplacedSpaceships(1);
      m = player2.getNrOfUnplacedSpaceships(2);
      l = player2.getNrOfUnplacedSpaceships(3);
    } else {
     cout << "Error: player" << turn << " not found!" << endl;
    }
    printFase1Information(turn);
    cout << "You have left: " << l << " large, " << m << " medium, and " << s << " small ships" << endl;
    // Laat speler kiezen uit een ruimteschip die nog niet op t board staat

    /*DEBUGGING:
    int spaceshipID = pickSpaceship();
    */

    //DEBUGGING:
    int spaceshipID = generateSpaceshipSpot();
    setSpaceshipDebug(spaceshipID);
    /* DEBUGGING:
    // Laat speler daarna kiezen op welke planeet dit ruimteschip komt
    setSpaceship(spaceshipID);
    */
    if(turn == 1){
      turn = 2;
    } else if(turn == 2){
      turn = 1;
    }
  }
}

int Board::makeDecisionForPlayer(){
  string player;
  int answer = -1;
  while (answer == -1){
    cout << "Type P1 for player1 and P2 for player2 | (P)1 or (P)2" << endl;
    cout << "Choose a player: ";
    cin >> player;
    cout << endl;

    if(player == "P1" || player == "p1" || player == "1"){
      answer = 1;
    }
    if(player == "P2" || player == "p2" || player == "2"){
      answer = 2;
    }
    if(answer == -1){
      cout << "That player does not exist!" << endl;
    }
  }
  return answer;
}

void Board::moveSpaceship(int planetID, int spaceshipID){
  for (int i = 0; i < bodies; i++){
    if (bodyArray[i].getID() == planetID){
      cout << "Setting spaceship " << spaceshipID << " on planet: " << bodyArray[i].getID() << endl;
      bodyArray[i].setSpaceshipOnPlanetVector(spaceshipID);
    }
  }
}

void Board::moveSpaceships(int planetID){
  int steps = 1;
  int index = 0;
  int player = 0;
  int size = 0;
  for(int i = 0; i < bodies; i++){
    if(bodyArray[i].getID() == planetID){
     index = i;
    }
  }
  // Array with spaceships
  vector<int> spaceshipIDS = bodyArray[index].getSpaceships();
  int spaceshipIDSSize = spaceshipIDS.size();
  // Move every spaceship to a new planet;
  int smallSizeP1 = 0, mediumSizeP1 = 0, largeSizeP1 = 0;
  int smallSizeP2 = 0, mediumSizeP2 = 0, largeSizeP2 = 0;
  for (int i = 0; i < spaceshipIDSSize; i++){
    int spaceshipID = spaceshipIDS[i];
    if(spaceshipIDS[i] < 20 && spaceshipIDS[i] != 0){
      //Haal de grootes van alle planeten op;
      size = player1.getSpaceshipSize(spaceshipID);
      player = 1;
    } else if (spaceshipIDS[i] > 19){
      size = player2.getSpaceshipSize(spaceshipID);
      player = 2;
    }
    if (player == 1){
      switch (size) {
        case 0:
          continue;
        case 1:
          smallSizeP1++;
          break;
        case 2:
          mediumSizeP1++;
          break;
        case 3:
          largeSizeP1++;
          break;
        default:
          cout << "Error: Spaceshipsize not found" << endl;
      }
    } else if (player == 2){
      switch (size) {
        case 0:
          continue;
        case 1:
          smallSizeP2++;
          break;
        case 2:
          mediumSizeP2++;
          break;
        case 3:
          largeSizeP2++;
          break;
        default:
          cout << "Error: Spaceshipsize not found" << endl;
      }
    }
  }
  if(largeSizeP1 > 0 && largeSizeP2 > 0){
    while(largeSizeP1 > 0 && largeSizeP2 > 0){
      // Kies welke grote spaceship als eerste 1 plek mag verschuiven
      cout << "Whose large spaceship do you want to move first?" << endl;
      int decision = makeDecisionForPlayer();
      int toMove;
      if(decision == 1){
        // Move one of player 1's large Spaceships
        for (int i = 0; i < spaceshipIDSSize; i++){
          //Check elke planeet voor een spaceship
          if(spaceshipIDS[i] < 20 && spaceshipIDS[i] != 0){
            if(player1.getSpaceshipSize(spaceshipIDS[i]) == 3){
              toMove = spaceshipIDS[i];
              //cout << "To Move: " << toMove << endl;
              break;
            }
          }
        }
        bodyArray[index].removeSpaceshipOffPlanetVector(toMove);
        moveSpaceship(bodyArray[index+steps].getID(), toMove);
        steps++;
        largeSizeP1--;
      }
      if(decision == 2){
        // Move one of player 2's large spaceships
        for (int i = 0; i < spaceshipIDSSize; i++){
          //Check elke planeet voor een spaceship
          if(spaceshipIDS[i] > 19){
            if(player2.getSpaceshipSize(spaceshipIDS[i]) == 3){
              toMove = spaceshipIDS[i];
              break;
            }
          }
        }
        cout << "PlanetID: " << bodyArray[index+steps].getID() << endl;
        cout << "To Move: " << toMove << endl;
        bodyArray[index].removeSpaceshipOffPlanetVector(toMove);
        cout << "Got here!" << endl;
        moveSpaceship(bodyArray[index+steps].getID(), toMove);
        cout << "Got here! too" << endl;
        steps++;
        largeSizeP2--;
      }
    }
  }
}

int Board::selectPlanet(){
  printBoard();  // Laat het bord zien
  int answer = -1;
  int index;
  bool available;
  while (answer == -1){
    int input;
    cout << "Select a planet: ";
    cin >> input;
    cout << endl;
    if(!cin.good()){
      cin.clear();
      continue;
    }

    if(input < 1 || input > 16 ){
      continue;
    }

    for(int i = 0; i < bodies; i++){
      if(bodyArray[i].getID() == input){
       index = i;
      }
    }

    if(turn == 1){
      vector<int> spaceshipIDS = bodyArray[index].getSpaceships();
      int spaceshipIDSSize = spaceshipIDS.size();
      available = false;
      for (int i = 0; i < spaceshipIDSSize; i++){
        if(spaceshipIDS[i] < 20 && spaceshipIDS[i] != 0){
          available = true;
        }
      }
    } else if (turn == 2){
      vector<int> spaceshipIDS = bodyArray[index].getSpaceships();
      int spaceshipIDSSize = spaceshipIDS.size();
      available = false;
      for (int i = 0; i < spaceshipIDSSize; i++){
        if(spaceshipIDS[i] > 19){
          available = true;
        }
      }
    }
    if (available){
      return input;
    } else {
      cout << "You don't have any spaceships on that planet!" << endl;
    }
  }
}

void Board::printFase2Information(int player){
  string playerName = getPlayerName(player);
  cout << "It's " << playerName << "'s turn.." << endl;
  cout << "Select a planet by typing its ID: (Numbers: 1-16)" << endl;
}

// Fase 1: Players take turn to move spaceships
void Board::fase2(){
  fase2State = true;
  cout << "Well Done!" << endl;
  cout << "Lets begin phase2" << endl;
  cout << "Select a planet to move all the spaceships" << endl;
  cout << endl;
  while (fase2State){
    //system("clear");
    printFase2Information(turn);

    //Speler die aan de beurt is mag een planeet kiezen
    int planetID = selectPlanet();
    moveSpaceships(planetID);

    if(turn == 1){
      turn = 2;
    } else if(turn == 2){
      turn = 1;
    }
  }
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
    int player = 0;
    int size = 0;
    int smallSizeP1 = 0, mediumSizeP1 = 0, largeSizeP1 = 0;
    int smallSizeP2 = 0, mediumSizeP2 = 0, largeSizeP2 = 0;
    vector<int> spaceshipIDS = bodyArray[i].getSpaceships();
    int spaceshipIDSSize = spaceshipIDS.size();
    for (int i = 0; i < spaceshipIDSSize; i++){
      if(spaceshipIDS[i] < 20 && spaceshipIDS[i] != 0){
        player = 1;
        size = player1.getSpaceshipSize(spaceshipIDS[i]);
      } else if (spaceshipIDS[i] > 19){
        player = 2;
        size = player2.getSpaceshipSize(spaceshipIDS[i]);
      } else {
        size = 0;
      }
      if (size == 1 && player == 1){
        smallSizeP1++;
      } else if(size == 2 && player == 1){
        mediumSizeP1++;
      } else if(size == 3 && player == 1){
        largeSizeP1++;
      } else if (size == 1 && player == 2){
        smallSizeP2++;
      } else if(size == 2 && player == 2){
        mediumSizeP2++;
      } else if(size == 3 && player == 2){
        largeSizeP2++;
      } else if (size == 0){
        continue;
      } else {
        cout << "Error: Spaceshipsize not found" << endl;
      }
    }
    locationArrayP1[i] = "  " + to_string(largeSizeP1) + "L|" + to_string(mediumSizeP1) + "M|" + to_string(smallSizeP1) + "S  ";
    locationArrayP2[i] = "  " + to_string(largeSizeP2) + "L|" + to_string(mediumSizeP2) + "M|" + to_string(smallSizeP2) + "S  ";
  }
}

void Board::setBodies(int _bodies){
  bodies = _bodies;
}

string Board::getPlayerName(int player){
  if (player == 1){
    string name =  player1.getName();
    return name;
  } else if(player == 2){
    string name =  player2.getName();
    return name;
  } else {
    cout << "getPlayerName Error: Player not found!" << endl;
  }
}

Board::~Board(){
  delete[] bodyArray;
  cout << "Board destroyed" << endl;
}

void Board::printBoard(){
  getLocations();
  cout << "Player1:"<< locationArrayP1[1] << locationArrayP1[2] << locationArrayP1[3] << locationArrayP1[4] << locationArrayP1[5] << locationArrayP1[6] << locationArrayP1[7] << locationArrayP1[8] << endl;
  cout << "Player2:"<< locationArrayP2[1] << locationArrayP2[2] << locationArrayP2[3] << locationArrayP2[4] << locationArrayP2[5] << locationArrayP2[6] << locationArrayP2[7] << locationArrayP2[8] << endl;
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
  cout << "Player1:"<< locationArrayP1[17] << locationArrayP1[16] << locationArrayP1[15] << locationArrayP1[14] << locationArrayP1[13] << locationArrayP1[12] << locationArrayP1[11] << locationArrayP1[10] << endl;
  cout << "Player2:"<< locationArrayP2[17] << locationArrayP2[16] << locationArrayP2[15] << locationArrayP2[14] << locationArrayP2[13] << locationArrayP2[12] << locationArrayP2[11] << locationArrayP2[10] << endl;
  cout << "" << endl;
}

void Board::printStats(){
  cout << "Player 1" << endl;
    cout << "Fleet: " << player1.getNOfSpaceships() << endl;
    cout << "Space Coins: " << player1.getFiches() << endl;
    cout << "" << endl;
    cout << "Player 2" << endl;
    cout << "Fleet: " << player2.getNOfSpaceships() << endl;
    cout << "Space Coins: " << player2.getFiches() << endl;
    cout << "" << endl;
}
