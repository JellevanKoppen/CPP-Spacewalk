#include "location.h"
#include <cassert>
#include <iostream>

using namespace std;

// Constructor
Location::Location(){
  cout << "Warning: Unset boardsize!" << endl;
}

Location::Location(int _boardSize){
  cout << "Creating Location Interface" << endl;
  boardSize = _boardSize;
  locationArray = (int*) calloc(sizeof(int), boardSize);
  assert(locationArray);
  locationArray = new int[boardSize];
}

/*
void Location::setSpaceshipLocation(int id, int location){
  // Zet het ruimteschip op de locatie van de planeet(id)
  // Gewenste planeet id opzoeken
  for(int i = 0; i < boardSize; i++){
    if(locationArray[i] == location){
      // Zet ruimteschip op planeet;

    }
  }
}
*/

void Location::initiate(int _boardSize){
  cout << "Creating Location Interface" << endl;
  boardSize = _boardSize;
  locationArray = (int*) calloc(sizeof(int), boardSize);
  assert(locationArray);
  locationArray = new int[boardSize];
}

// Set the location of every body
void Location::setBodyLocation(int i, int bodyID){
  locationArray[i] = bodyID;
}

// Print all the locations of every body
void Location::printLocations(){
  for (int i = 0; i < boardSize; i++){
    cout << "Hey I'm Body: " << i << " And I'm on position: " << locationArray[i] << endl;
  }
}

// Destructor
Location::~Location(){
  delete[] locationArray;
  cout << "Location instance destroyed" << endl;
}
