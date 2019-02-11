#include <iostream>
#include <vector>

using namespace std;

int main(){
  vector<int> vec;
  for(int i = 0; i < 10; i++){
    vec.push_back(i);
  }
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << endl;
  }
  for(int i = 0; i < vec.size(); i++){
    if (vec[i] == 8){
      vector<int>::iterator itr = vec.begin() + vec[i];
      vec.erase(itr);
    }
  }
  for(int i = 0; i < vec.size(); i++){
    cout << vec[i] << endl;
  }
}
