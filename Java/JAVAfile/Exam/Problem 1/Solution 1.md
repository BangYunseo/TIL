## Problem 1. 
- for 문을 이용해서 다음과 같이 출력이 되는 코드를 작성합니다. 문자 배열을 아래와 같이 선언합니다.
- 문제 의도 :

```JAVA 
(1) char[] myCh = {'+', '-', '*', '/'}
(2) 출력 :  
++
----
******
////////
```
```JAVA
package StudyJava1;
	public class StudyJava1_1 {
		public static void main(String[] args) {
			char[] myCh = {'+', '-', '*', '/'};
                        // myCh라는 배열을 생성하고 배열을 {'+', '-', '*', '/'} 으로 초기화한다.
			for (int i = 0; i < myCh.length; i++) {
                        // 배열의 길이만큼 for문을 반복한다.
                        // 여기서 배열의 길이는 숫자가 아니라 myCh.length로 유동적으로 확인한다.
				for (int j = 1; j <= (i * 2) + 2; j++){
					System.out.print(myCh[i]);
                                         // 1번째 줄은 2, 2번째 줄은 4, 3번째 줄은 6, 4번째 줄은 8의 순으로 출력된다.
                                         // 따라서 (i * 2) + 2까지 출력을 반복한다.
                                         // println으로 쓰지 않도록 주의한다.
				}
				System.out.println();
                                // for문이 끝날 때마다 한 줄씩 넘긴다.
			}
		}
}
```
