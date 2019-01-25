#include "player.h"
#include <iostream>

using namespace std;

Player::Player(char const* _name){
  name = _name;
  nOfSpaceships = 9;
  cout << "Hey " << name << endl;
  cout << "Creating spaceships for " << name << endl;
  spaceshipArray = (Spaceship*) calloc(sizeof(Spaceship), 9);
  createSpaceships();
}

Player::Player(int _startID){
  startID = _startID;
  nOfSpaceships = 9;
  name = "Undefined";
  cout << "Hey " << name << endl;
  cout << "Creating spaceships for " << name << endl;
  spaceshipArray = (Spaceship*) calloc(sizeof(Spaceship), 9);
  spaceshipArray= new Spaceship[9];
  createSpaceships();
}

void Player::printName(){
  cout << name << endl;
}

int Player::getSpaceshipID(int index){
  return spaceshipArray[index].getID();
}

int Player::getNOfSpaceships(){
  return nOfSpaceships;
}

int Player::getSpaceshipLocation(int spaceshipID){
  return spaceshipArray[spaceshipID].getLocation();
}

int Player::getSpaceshipSize(int spaceshipID){
  for (int i = 0; i < 9; i++){
    if(spaceshipArray[i].getID() == spaceshipID){
      return spaceshipArray[i].getSize();
    }
  }
  return -1;
}

void Player::moveSpaceship(int spaceshipID, int location){
  spaceshipArray[spaceshipID].setLocation(location);
}


void Player::setFiches(int _fiches){
  fiches = _fiches;
}

int Player::getFiches(){
  return fiches;
}

void Player::createSpaceships(){
  //Create 3x3 sizes of spaceships
  for (int i=0; i<3; i++){
    spaceshipArray[i].setID(i+startID);
    spaceshipArray[i].setSize(1);
    spaceshipArray[i].sayHi();
  }
  for (int i=3; i<6; i++){
    spaceshipArray[i].setID(i+startID);
    spaceshipArray[i].setSize(2);
    spaceshipArray[i].sayHi();
  }
  for (int i=6; i<9; i++){
    spaceshipArray[i].setID(i+startID);
    spaceshipArray[i].setSize(3);
    spaceshipArray[i].sayHi();
  }
}

void Player::setName(char const* _name){
  name = _name;
}

char const* Player::getName(){
  return name;
}

Player::~Player(){
  delete[] spaceshipArray;
  cout << "Player destroyed" << endl;
}
