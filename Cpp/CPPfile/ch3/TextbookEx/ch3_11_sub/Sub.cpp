#include "Sub.h"

Sub::Sub(int a, int b){
  op1 = a; op2 = b;
}
int Sub::process(){
  return op1 - op2;
}
