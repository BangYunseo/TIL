## Problem 1. 
- 코드를 헤더 파일과 cpp 파일로 분리합니다.

- 문제의도 : 이 문제는 비어있는 코드를 완성시키고 각각을 하나의 cpp 파일이 아닌 여러 개로 나누어진 파일(2개의 cpp 파일, 1개의 헤더 파일)로 분리하는 목적을 가집니다. 코드 자체는 메모리 값을 반환하는 목적을 가지고 있으며 이로 인해 배열을 사용합니다.
- 이 문제에서 주의해야 할 점은 char mem[100 * 1024]인데, 이 코드로 인해 배열의 메모리 누수가 생깁니다. 컴파일 에러나 다른 오류가 발생하는 것은 아니지만, 효율적인 코드가 아니라는 것은 인지해야 합니다.

  
```C++
// Ram.h = Ram 헤더 파일
// Ram.h는 헤더파일로, cpp 파일을 위한 기반으로 사용됩니다.
#pragma once
#ifndef RAM_H
// 이 지시문은 "if not defined"의 약어로, 주어진 심볼이 정의되어 있지 않은 경우에 코드 블록을 컴파일하는 데 사용됩니다.
#define RAM_H

class Ram {
// Ram 이라는 class를 생성합니다.
	char mem[100 * 1024];
	// 문자형 배열 mem을 [100 * 1024] 의 메모리를 갖도록 선언합니다.
	int size;
	// 배열의 크기를 지정하는 정수형 변수입니다.
public:
	Ram();
	// 기본 생성자입니다.
	~Ram();
	// 기본 소멸자입니다.
	char read(int address);
	// 배열의 메모리를 읽는 함수입니다.
	void write(int address, char value);
	// 배열의 메모리 값을 새로 쓰는 함수입니다.
};
#endif
```
```C++
// Ram.cpp = Ram cpp 파일
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include "Ram.h"
// 헤더 파일을 포함하는 cpp파일입니다.
// 위의 헤더 파일에서 함수들을 public으로 설정했으므로 자유롭게 사용할 수 있습니다.
// 또한 헤더 파일의 함수들을 이 cpp 파일에서 선언합니다.

Ram::Ram() {
// 기본 생성자에서 배열을 모두 0으로 초기화합니다.
	size = 100 * 1024;
	for (int i = 0; i < size; i++) 
		mem[i] = 0;
	
}
Ram::~Ram() {	// 소멸자입니다. 소멸자는 코드의 작동이 끝나면 자동으로 실행됩니다.
	cout << "메모리 제거됨" << endl;
}
char Ram::read(int address) {
// 배열의 값을 읽는 함수로, 배열 그대로의 값을 반환합니다.
	return mem[address];
}
void Ram::write(int address, char value) {
// 배열의 값을 새로 쓰는 함수로, 배열의 위치에 값을 저장합니다. (새로 쓰는 함수 O / 값을 더하는 함수 X)
	mem[address] = value;
}
```
```C++
// main.cpp = main cpp 파일
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include "Ram.h"
// Ram.h를 포함해야 함수를 자유롭게 사용할 수 있습니다.

int main() {
	Ram ram;
	// Ram 클래스를 ram으로 선언해서 사용합니다.
	ram.write(100, 20);
	// 위치 100의 배열 원소 값을 20으로 새로 씁니다.
	ram.write(101, 30);
	// 위치 101의 배열 원소 값을 30으로 새로 씁니다.
	char res = ram.read(100) + ram.read(101);
	// 배열의 위치 100과 101을 읽은 값을 각각 더한 후 변수 res에 저장합니다.
	ram.write(102, res);
	// 위치 102에 앞서 더한 값 res를 저장합니다.
	cout << "102 번지의 값 = " << (int)ram.read(102) << endl;
	// 102번지의 값을 출력합니다.
}
// 실행 결과
// 102 번지의 값 = 50
// 메모리 제거됨
```

