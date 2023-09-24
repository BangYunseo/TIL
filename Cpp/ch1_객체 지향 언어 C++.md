##  Chapter 1. 객체 지향 언어 C++       

#### 1. 객체(Object)
      - 데이터의 분산을 막기 위해 데이터와 기능을 하나로 묶은 그룹
 
#### 2. 객체 지향 언어(Object-oriented Language)  

      - 컴퓨터 프로그래밍의 한 가지 기법으로 객체를 만들고 객체를 사용하는 프로그래밍 언어
      - 프로그램을 데이터와 처리 방법으로 나누는 것이 아님
      - 프로그램을 다수의 "객체"로 만들고, 이들을 상호작용해서 만들어지는 방식
      
#### 3. 객체 지향 특성 - 캡슐화

##### (1) 캡슐화(Encapsulation)     
      - 데이터를 캡슐로 싸서 외부의 접근으로부터 보호     
      - C++에서 클래스(class 키워드)로 캡슐을 표현      

![class](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch1/class.PNG)

##### (2) 클래스와 객체     
      - 클래스 : 객체를 만드는 틀     
      - 객체 : 클래스라는 틀에서 생겨난 실체      
      - 객체(object), 실체(instance)는 같은 뜻     
      
![instance](https://github.com/BangYunseo/TIL/blob/main/Cpp/Image/ch1/instance.PNG)

```C++
// 원을 추상화한 클래스 Circle
class Circle{
private :
      int radius;      // 반지름 값
public :
      Circle(int r){ radius = r; }
      double getArea(){ return 3.14 * radius * radius }
};    
```

#### 4. 객체 지향 특성 - 상속성

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

![overflow](https://github.com/BangYunseo/TIL/blob/main/C/Image/ch1/overflow.PNG)


#### 7. 기호 상수

      - 기호 상수(Symbolic Constant): 기호를 이용하여 상수를 표현한 것이다.
      
            1. 가독성이 높아진다.
            2. 값을 쉽게 변경할 수 있다.
            
      ex) area = 3.141592 * radius * radius;
          -> area = PI * radius * radius;
      ex) income = salary - 0.15 * salary;
          -> income = salary - TAX_RATE * salary;

      - 기호 상수 사용하는 법
            1. #define 이용하기
            2. const 이용하기
            
```C
      // 기호 상수 예제 - 연봉과 세금 계산하기         
      #include <stdio.h>
      #defube TAX_RATE 0.2    // 기호 상수를 이용해서 TAX_RATE를 0.2로 선언한다.
      
      int main(void)
      {
        const int MONTHS = 12;      // 기호 상수를 이용해서 MONTHS를 12로 선언한다.
        int m_salary, y_salary;     // m_salary와 y_salary를 변수로 선언한다.
        
        printf("월급을 입력하세요 :");      
        scanf("%d",&m_salary);            // 입력받은 월급을 m_salary에 저장한다. 
        y_salary = MONTHS * m_salary;     // y_salary에 월급과 달 수를 곱한 값을 저장한다.
        printf("연봉은 %d 입니다.", y_salary);  // 연봉을 출력한다.
        printf("세금은 %lf 입니다.", y_salary * TAX_RATE);  // 세금을 출력한다.

        return 0;
      }      
```

[참고자료](https://radait.tistory.com/4)
