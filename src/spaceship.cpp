#include "spaceship.h"
#include <iostream>

using namespace std;

Spaceship::Spaceship(int _size, int _id){
  size = _size;
  id = _id;
}

Spaceship::Spaceship(){
  size = -1;
  id = -1;
}

void Spaceship::setStatus(bool _onBoard){
  onBoard = _onBoard;
}

bool Spaceship::getStatus(){
  return onBoard;
}

void Spaceship::setLocation(int _location){
  location = _location;
}

int Spaceship::getLocation(){
  return location;
}


void Spaceship::setID(int _id){
  id = _id;
}

int Spaceship::getID(){
  return id;
}

void Spaceship::setSize(int _size){
  size = _size;
}

int Spaceship::getSize(){
  return size;
}

void Spaceship::sayHi(){
  if (size == 1){
    sizeText = "small";
  } else if (size == 2){
    sizeText = "medium";
  } else if (size == 3){
    sizeText = "large";
  } else {
    sizeText = "Not Assigned Yet!";
  }
  cout << "Hi i'm spaceship nr: " << id << endl;
  cout << "I'm of a " << sizeText << " size" << endl;
}

Spaceship::~Spaceship(){
  cout << "Spaceship destroyed" << endl;
}
