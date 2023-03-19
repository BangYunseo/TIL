## * 개념 및 예제 확인하기     

#### 1. 변수는 어디에 만들어지는가?
      
      1. 변수는 메인 메모리에 만들어진다.
      2. 변수 이름을 사용해서 메모리 공간을 사용한다.     
      
#### 2. 변수는 왜 필요한가?   

      1. 변수는 사용자에게 받는 데이터를 저장하는 장소이다.
      2. 변수가 없다면 사용자로부터 받은 데이터를 저장할 수 없다.

#### 3. 변수와 상수

      * 변수(Variable) : 저장된 값의 변경이 가능한 공간   
      * 상수(Constant) : 저장된 값의 변경이 불가능한 공간    
      * ex) 3.14, 100, 'A', "Hello, World!" 
      
```C
      // 원의 면적을 계산하는 예제
      #include <stdio.h>
      #define PI 3.141592     // PI를 3.141592로 정의한다.
      
      int main(void)
      {
        double radius;   // 원의 반지름을 저장할 변수를 선언한다.
        double area;    // 원의 면적을 저장할 변수를 선언한다.
        
        printf("원의 반지름을 입력해라 :");    // 원의 반지름을 입력하라고 출력한다.
        scanf("%lf", &radius);      // 원의 반지름을 변수 radius에 저장한다. 
        
        area = PI * radius * radius;      // 원의 면적 area를 계산한다.
        printf("원의 면적 : %lf\n", area);    // 원의 면적을 출력한다.
        
        return 0;
      }      
```
#### 4. 자료형

      - 자료형은 크게 3가지로 나누어진다.     
      
      1. 정수형 : short, int, long, long long     
      2. 부동 소수점형(실수형) : float, double, long double     
      3. 문자형 : char        
```C
      // 자료형의 크기
      #include <stdio.h>
      
      int main(void)
      {
        int x;    // 정수형 변수 x를 선언한다.
        
        printf("변수 x의 크기 : %d\n", sizeof(x));   // 변수 x의 크기 : 4
        printf("char형의 크기 : %d\n", sizeof(char));     // char형의 크기 : 1
        printf("int형의 크기 : %d\n", sizeof(int));     // int형의 크기 : 4
        printf("short형의 크기 : %d\n", sizeof(short));     // short형의 크기 : 2
        printf("long형의 크기 : %d\n", sizeof(long));     // long형의 크기 : 4
        printf("float형의 크기 : %d\n", sizeof(float));     // float형의 크기 : 4
        printf("double형의 크기 : %d\n", sizeof(double));     // double형의 크기 : 8
        
        
        return 0;
      }      
```
      
#### 4-1. 정수형
      
      - 정수형은 short, int, long, long long이 있다.
|자료형|비트|범위|
|:---|:---:|:---|
|short|16비트|-32768 ~ 32767|
|int|32비트|-2147483648 ~ 2147483647|
|long|32비트|-2147483648 ~ 2147483647|
|long long|64비트|-9,223,372,036,854,775,808 ~ 9,223,372,036,854,775,807|

```C
      // 변수 선언하기 예제  
      #include <stdio.h>
      
      int main(void)
      {
        int Number1;          // 'Number1'이라는 정수형 int 변수 선언하기
        short Number2;        // 'Number2' 라는 정수형 short 변수 선언하기
        long Number3;         // 'Number3' 라는 정수형 long 변수 선언하기
        double Number4;       // 'Number4' 라는 실수형 double 변수 선언하기
        char Character1;      // 'Character1' 이라는 문자형 char 변수 선언하기

        return 0;
      }      
```
      
#### 5. signed와 unsigned

      - unsigned
            1. 음수가 아닌 값만을 나타낸다.
            2. unsigned int
      - signed
            1. 부호를 가지는 값을 나타낸다.
            2. 흔히 생략한다.
      ex) (signed) int는 -2147483648 ~ 2147483647의 범위를 가지지만 unsigned int는 0 ~ 4294967295의 범위를 가진다.

#### 5-1. unsigned 수식자
      
```C
      // unsigned 수식자 예제  
      #include <stdio.h>
      
      int main(void)
      {
        unsigned int speed;         // 부호 없는 int형
        unsigned distance;          // unsigned int distance와 같다.
        unsigned short players;     // 부호 없는 short형
        unsigned long seconds;      // 부호 없는 long형
        
        unsigned int sales = 2800000000 // 약 28억
        printf("%u\n", sales);          // %d를 사용하면 음수로 출력되니 주의하기
        
        return 0;
      }      
```

#### 6. 오버플로우
      
      - 오버플로우(overflow)는 변수가 나타낼 수 있는 범위를 넘는 숫자를 저장하려고 할 때 발생한다.
      - 오버플로우는 규칙성이 있다. 
     ![overflow](https://user-images.githubusercontent.com/104207412/226170933-c40924d9-2f39-4ddd-9e7f-fd7a851c033e.PNG)


