#include <iostream>

using namespace std;

int main(){
  string hey;
  int s,m,l;
  s = 1;
  m = 2;
  l = 3;
  hey = "  " + to_string(l) + "L|" + to_string(m) + "Mrm |" + to_string(s) + "S  ";
  cout << hey << endl;
}
