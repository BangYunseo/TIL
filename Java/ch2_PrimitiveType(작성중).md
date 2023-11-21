##  Chapter 2. 기본 타입

#### 0. 시작하기 전에
      - (1) 핵심 키워드 : 변수, 변수 선언, 변수 사용, 변수 사용 범위
      
      - (2) 핵심 포인트 
            - 컴퓨터 메모리(RAM)는 값을 저장할 수 있는 수많은 번지(주소)들로 구성되어 있다.     
            - 메모리의 어디에, 어떤 방식으로 저장할 지 정해놓아야 한다.     
            - 프로그래밍 언어는 이 문제를 해결하기 위해 변수라는 개념을 사용한다.
            - 변수의 역할 및 사용 방법에 대해 알아본다.
            
      - (3) 변수(Variable)
            - 값을 저장할 수 있는 메모리의 특정 번지에 붙여진 이름
            - 변수를 통해 해당 메모리 번지에 하나의 값을 저장하고 읽음
            - 변수는 정수, 실수 등 다양한 타입의 값을 저장
            
![variable](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/variable.PNG)
 
#### 1. 변수 선언  
- 변수 사용을 위해서 변수 선언이 필요
  
      - 변수에 어떤 타입의 데이터를 저장할 것인지, 변수의 이름이 무엇인지 결정
            
![variable1](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/variable1.PNG)

      - 같은 타입의 변수는 콤마를 이용해 한꺼번에 선언

![variable2](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/variable2.PNG)

- 변수 이름

      - 자바 언어에서 정한 명명 규칙에 따라 작성

![variablename](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/variablename.PNG)

- 예약어

      - 자바 언어에서 의미를 가지고 사용되는 단어
      - 변수 이름으로 사용할 경우 컴파일 에러

![variablename1](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/variablename1.PNG)

#### 2. 값 저장

- 값을 저장할 경우 대입 연산자 (=) 사용

      - 변수를 선언
      - 대입 연산자를 사용해서 오른쪽의 값을 왼쪽 변수에 저장

![variablesave](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/variablesave.PNG)

- 변수 초기화     

      - 변수에 최초로 값이 저장될 때 메모리에 변수가 생성됨
      - 생성되는 변수는 초기화
      - 생성되는 변수의 값은 초기값

![variablereset](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/variablereset.PNG)

      - 초기화를 하지 않은 변수는 메모리에서 값을 읽을 수 없음

![variableresetno](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/variableresetno.PNG)

```Java
// VariableInitializationExample 실습
package sec01.exam01;

public class VariableInitializationExample {
	public static void main(String[] args) {
		//변수 value 선언
		int value = 20;    
		
		//변수 value 값을 읽고 10을 더하는 산술 연산을 수행
		//연산의 결과값을 변수 result의 초기값으로 저장
		int result = value + 10;
		
		//변수 result 값을 읽고 콘솔에 출력
		System.out.println(result);
	}
}
```
#### 3. 변수 사용 
- 변수 사용 : 변수의 값을 이용해서 출력문이나 연산식을 수행

![usevariable](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/usevariable.PNG)

```Java
// VariableUseExample 실습
package sec01.exam02;

public class VariableUseExample {
	public static void main(String[] args) {
		int hour = 3;
		int minute = 5;
		System.out.println(hour + "½Ã°£ " + minute + "ºÐ");

		int totalMinute = (hour*60) + minute;
		System.out.println("ÃÑ" + totalMinute + "ºÐ");
	}
}
```
- 변수 값 복사 : 변수의 값을 다른 변수에 저장

![copyvariable](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/copyvariable.PNG)

```Java
// VariableExchangeExample 실습
package sec01.exam03;

public class VariableExchangeExample {
	public static void main(String[] args) {
		int x = 3;
		int y = 5;
		System.out.println("x:" + x + ", y:" + y);
		
		int temp = x;
		x = y;
		y = temp;
		System.out.println("x:" + x + ", y:" + y);
	}
}
```
#### 4. 변수 사용 범위
- 지역 변수(Local Variable)     

      - 메소드 블록 내에서 선언된 변수는 지역 변수
      - 지역 변수는 메소드 블록 내에서만 사용되고 실행이 끝나면 자동으로 삭제
  
![localvariable](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/localvariable.PNG)

      - 지역 변수는 해당 중괄호 블록 내에서만 사용 가능

![localvariable1](https://github.com/BangYunseo/TIL/blob/main/Java/Image/ch1/localvariable1.PNG)

      - 지역 변수를 선언할 때 변수가 어떤 범위에서 사용될 것인지 고려하여 선언 위치를 결정
      - 메소드 블록 전체에서 사용하려는 경우 메소드 블록 첫머리에 선언
      - 특정 블록 내부에서만 사용하려는 경우 해당 블록 내에 선언

```Java
// VariableScopeExample 실습
package sec01.exam04;

public class VariableScopeExample {
	public static void main(String[] args) {
		int v1 = 15;
		if(v1>10) {
			int v2;
			v2 = v1 - 10;
		}
		//int v3 = v1 + v2 + 5;  //v2 변수를 사용할 수 없기 때문에 컴파일 에러가 생김
	}
}
```
      
#### Special. 키워드로 정리하기

- 변수 : 값을 저장할 수 있는 메모리 번지에 붙인 이름으로 변수를 통해 프로그램은 메모리 번지에 값을 저장하고 읽음
- 변수 선언 : 변수에 어떤 타입의 데이터를 저장할지 그리고 변수 이름이 무엇인지를 결정하는 것
- 변수 사용 : 변수의 값을 읽거나 변경하는 것으로 변수는 출력문이나 연산식 내부에서 사용되어 변수에 저장된 값을 출력하거나 연산에 사용
- 변수 사용 범위 : 변수는 자신이 선언된 위치에서 자신이 속한 블록 내부 까지만 사용이 가능하고 밖에서는 사용 불가
