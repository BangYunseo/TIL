#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

class Oval{
  int width, height;
public:
  Oval(){ width = height = 1; }
  Oval(int w, int h);
  ~Oval();
  int getWidth();
  int getHeight();
  void set(int w, int h);
  void show();
  double getArea();
};
Oval::Oval(int w, int h){
  width = w;
  height = h;
}
Oval::~Oval(){
  cout << "Oval 소멸 : ";
  show();
}
int Oval::getWidth(){
  return width;
}
int Oval::getHeight(){
  return height;
}
void Oval::set(int w, int h){
  width = w;
  height = h;
}
void Oval::show(){
  cout << "width = " << width << ", height = " << height << endl;
}
double Oval::getArea(){
  return (width / 2) * (height / 2) * 3.14;
}
int main(){
  Oval a, b(3, 4);
  a.set(10, 20);
  a.show();
  cout << b.getWidth() << "," << b.getHeight() << endl;
  cout << "면적은 " << a.getArea() << endl;
}
