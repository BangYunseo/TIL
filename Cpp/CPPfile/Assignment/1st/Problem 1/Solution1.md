## Problem 1. 
- 코드를 헤더 파일과 cpp 파일로 분리합니다.
  
```C++
// Ram.h = Ram 헤더 파일
#pragma once
#ifndef RAM_H
#define RAM_H

class Ram {
	char mem[100 * 1024];
	int size;
public:
	Ram();
	~Ram();
	char read(int address);
	void write(int address, char value);
};
#endif
```
```C++
// Ram.cpp = Ram cpp 파일
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include "Ram.h"

Ram::Ram() {
	size = 100 * 1024;
	for (int i = 0; i < size; i++) 
		mem[i] = 0;
}
Ram::~Ram() {
	cout << "메모리 제거됨" << endl;
}
char Ram::read(int address) {
	return mem[address];
}
void Ram::write(int address, char value) {
	mem[address] = value;
}
```
```C++
// main.cpp = main cpp 파일
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include "Ram.h"

int main() {
	Ram ram;
	ram.write(100, 20);
	ram.write(101, 30);
	char res = ram.read(100) + ram.read(101);
	ram.write(102, res);
	cout << "102 번지의 값 = " << (int)ram.read(102) << endl;
}
// 실행 결과
// 102 번지의 값 = 50
// 메모리 제거됨
```

