#include "body.h"
#include <iostream>
#include <cassert>

using namespace std;

void Body::createSpaceStation(int _spaceships){
  spaceships = _spaceships;
  spaceshipArray = (int*) calloc(sizeof(int), spaceships);
  assert(spaceshipArray);
  spaceshipArray = new int[spaceships];
}

void Body::setID(int _id){
  id = _id;
}

int Body::getID(){
  return id;
}

void Body::setSpaceshipOnPlanet(int _spaceshipID){
  bool success = false;
  for(int i = 0; i < spaceships;){
    if(spaceshipArray[i] != 0){
      spaceshipArray[i] = _spaceshipID;
      bool success = true;
    }
  }
  if(!success){
    cout << "Error: Spacestation FULL!" << endl;
  }
}

void Body::setSpaceshipOnPlanetVector(int _spaceshipID){
  spaceshipVector.push_back(_spaceshipID);
}

void Body::printSpaceships(){
  for(int i = 0; i < spaceshipVector.size(); i++){
    cout << spaceshipVector[i] << endl;
  }
}

vector<int> Body::getSpaceships(){
  return spaceshipVector;
}

bool Body::spaceshipOnPlanet(int _spaceshipID){
  for(int i = 0; i < spaceships;){
    if(spaceshipArray[i] == _spaceshipID){
      return true;
    }
  }
  return false;
}

void Body::sayHi(){
  if(id < 0){
    cout << "Hi i'm Hole:" << id << endl;
  } else {
    cout << "Hi i'm Planet:" << id << endl;
  }
}


Body::~Body(){
  cout << "Body destroyed" << endl;
}
