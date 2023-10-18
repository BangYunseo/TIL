#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include "Calculator.h"
#include "Adder.h"
#include "Sub.h"

void Calculator::run(){
  cout << "두 개의 수를 입력하시오 >> ";
  
  int a, b;
  cin >> a >> b;
  
  Adder adder(a, b);
  Sub sub(a, b);
  
  cout << adder.process() << endl;
  cout << sub.process() << endl;
}
