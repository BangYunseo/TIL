##  Chapter 2. 수식과 연산자       

#### 1. 수식(expression)
      
      1. 상수, 변수, 연산자의 조합
      2. 연산자와 피연산자로 나누어진다. 
      
#### 2. 기능에 따른 연산자의 분류 

|연산자의 분류|연산자|의미|
|:---:|:---:|:---:|
|대입|=|오른쪽을 왼쪽에 대입|
|산술|+ - * / %|사칙연산과 나머지 연산|
|부호|+ -|상수 및 변수 앞의 부호|
|증감|++ --|증가, 감소 연산|
|관계|< > == != >= <=|오른쪽과 왼쪽을 비교|
|논리|&&  ll  !|논리적인 AND, OR, NOT|
|조건|?|조건에 따라 선택|
|콤마|,|피연산자들을 순차적으로 실행|
|비트 단위 연산자|& l ^ ~ >> <<|비트별 AND, OR, XOR, 반전, 이동|
|sizeof 연산자|sizeof|자료형이나 변수의 크기를 바이트 단위로 반환|
|형변환|(type)|변수나 상수의 자료형을 변환|
|포인터 연산자|* & []|주소 계산, 포인터가 가리키는 곳의 내용 추출|
|구조체 연산자|. ->|구조체의 멤버 참조

#### 3. 피연산자 수에 따른 연산자 분류

      * 단항 연산자 : 피연산자의 수가 1개
            ++x;
            --y;   
            
      * 이항 연산자 : 피연산자의 수가 2개
            x + y;
            x - y;   
            
      * 삼항 연산자 : 연산자의 수가 3개
            x ? y : z;   
            
      (참고) 거듭 제곱 연산자는?
            - C언어에는 거듭 제곱을 나타내는 연산자가 없다.
              x * x와 같이 단순히 변수를 두 번 곱한다.
     

#### 4. 나눗셈 연산자

      - 정수형끼리의 나눗셈에서는 결과가 정수형으로 생성되고 
        부동소수점형끼리는 부동소수점 값을 생성한다.  
      - 정수형끼리의 나눗셈에서 소수점 이하는 버려진다.
      
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

![overflow](https://user-images.githubusercontent.com/104207412/226173524-a9e30b78-cf72-4b71-8fd4-8365cb85ecc1.PNG)


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
