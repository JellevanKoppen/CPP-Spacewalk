#include "body.h"
#include <iostream>

using namespace std;

void Body::setID(int _id){
  id = _id;
}

int Body::getID(){
  return id;
}

void Body::sayHi(){
  if(id < 0){
    cout << "Hi i'm Hole:" << id << endl;
  } else {
    cout << "Hi i'm Planet:" << id << endl;
  }
}

void Body::print(){
  cout << "|Planet|" << endl;
  cout << "|--" << id << "--|" << endl;
  cout << "|Planet|" << endl;
  cout << "" << endl;
}


Body::~Body(){
  cout << "Body destroyed" << endl;
}
