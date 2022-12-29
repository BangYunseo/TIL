Python ch1. 파이썬 기본 개념
============================


## 1. Python 타입

    다음은 파이썬의 기본 데이터 타입을 분류한 표이다.   
    가변성은 타입에 따라 상자에 포함된 데이터 값을 변경할 수 있거나 (가변) 일정하게 유지할 수 있는가 (불변)를 판단하는 기준이다.
    
|이름|타입|가변성|예제|
|----|----|-----|----|
|불리언|bool|아니오|True, False|
|정수|int|아니오|47, 25000, 25_000|
|부동소수점|float|아니오|3.14, 2.7e5|
|복소수|complex|아니오|3j, 5 + 9j|
|텍스트 문자열|str|아니오|'안녕하세요', "black"|
|리스트|list|예|['Hello', "happy", 'love']|
|튜플|tuple|아니오|(2,4,8)|
|바이트|bytes|아니오|b'ab\xff'|
|바이트 배열|bytearray|예|bytearray(...)|
|셋|set|예|set([3, 5, 7])|
|프로즌 셋|frozenset|아니오|frozenset(['Elsa', 'Otto'])|
|딕셔너리|dict|예|{'game' : 'bingo', 'dog' : 'dingo', 'drummer' : 'Ringo'}|



## 2. Python 변수

+ 파이썬 변수 이름에는 몇 가지 규칙이 있다.
+ 다음 문자만 사용할 수 있다.

    - 소문자(a~z)
    - 대문자(A~Z)
    - 숫자(0~9)
    - 언더바(_)

+ 대소 문자를 구분한다. ex) thing, Thing, THING은 서로 다른 이름이다.
+ 숫자가 아닌 문자나 언더바로 시작한다. ex) 1first, 2second와 같은 변수는 사용할 수 없다.
+ 언더바로 시작하는 이름은 특별하게 취급한다.
+ 파이썬 예약어(키워드)는 사용할 수 없다. ex) print, in, is, break, None, False와 같은 것들이 예약어이다.
+ 파이썬 프로그램에서 에약어를 찾을 수 있다.

```python
help("Keywords")

import keyword
keyword.kwlist
```

+ 사용할 수 있는 변수 이름의 예와 사용할 수 없는 변수 이름의 예이다.

|사용할 수 있는 변수|사용할 수 없는 변수|
|----|----|
|a|1|
|a1|1a|
|a_b_b___95|1_|
|_abc|name!|
|_1a|another-name|
