#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Tower{
  int height;
public:
  Tower(){ height = 1; }
  Tower(int a){ height = a; }
  int getHeight(){ return height; }
};

int main(){
  Tower myTower;
  Tower seoulTower(100);
  cout << "높이는" << myTower.getHeight() << "미터" << endl;
  cout << "높이는" << seoulTower.getHeight() << "미터" << endl;
}
