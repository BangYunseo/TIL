## Problem 2. 
- 아이디와 패스워드를 확인하여 로그인 하는 프로그램을 작성합니다. 아이디나 패스워드가 총 3회 틀리는 경우 오류가 발생하여 로그인을 중단시킵니다. 아이디는 Kim, 비번은 12345 라고 가정합니다.

		(1) 출력 예 1:
		로그인 아이디 >> Kim
		로그인 비밀번호>> 12345
		로그인 성공입니다.

		(2) 출력 예 2:
		로그인 아이디 >> Lee
		아이디가 틀렸습니다. 
		로그인 아이디>> Kim
		로그인 비밀번호>> 123
		비밀번호가 틀렸습니다. 
		로그인 비밀번호>> 1234
		비밀번호가 틀렸습니다. 
		로그인을 중단합니다.
  
```JAVA 
package StudyJava1_2;

import java.util.Scanner;
// scanner 사용을 위해 import한다.

public class StudyJava1_2 {
        public static void main(String[] args) {
            Scanner scanner = new Scanner(System.in);
	    // scanner를 통해 입력받는다.

            String IDcode = "Kim";
            String PWcode = "12345";
	    // 정확한 IDcode와 PWcode를 설정한다.

            int count = 0;
	    // ID와 PW를 입력받을 횟수를 0으로 초기화한다.
	    // 0으로 초기화해야 1씩 더할 때 총 3번의 기회를 줄 수 있다.

            String ID ="";
	    // ID를 초기화하지 않으면 오류가 발생한다.
	    // String ID = scanner.nextLine(); 가 아니라 ID = scanner.nextLine(); 를 사용하기 위해서 초기화가 필요하다.

            boolean left = true;
	    // while문 반복을 위한 값이다.

            while (left) {
                	if (count == 0 || !ID.equals(IDcode)) {
			// 처음 아이디를 입력하거나, 전에 입력한 ID가 IDcode("Kim")과 일치하지 않을 경우 아이디를 입력받는다.

                    		System.out.print("로그인 아이디>> ");
                    		ID = scanner.nextLine();

                    		if (!ID.equals(IDcode)) {
				// 입력받은 아이디가 틀렸을 경우 아이디가 틀렸다고 출력한 후 count에 1을 더한다.
				// 입력할 수 있는 횟수 1회 감소

                        		System.out.println("아이디가 틀렸습니다.");
                        		count++;
				}
			else {
			// 입력받은 아이디가 일치했을 경우, 비밀번호만을 입력받는다.
			// 아이디는 재입력받지 않는다.
				while (count < 3) {
				// 비밀번호 입력 횟수를 3으로 제한한다.
				// 만약 while문이 없을 경우, 비밀번호를 무한대로 입력받는 오류가 발생한다.
				// Why? 비밀번호가 지속적으로 일치하지 않을 경우, if (count == 3)까지 작동하지 못하기 때문이다.

					System.out.print("로그인 비밀번호 >> "); 
					String PW = scanner.nextLine();
                            		if (PW.equals(PWcode)) {
					// PW도 일치할 경우, while문을 탈출하며 로그인에 성공한다.
                                		System.out.println("로그인 성공입니다."); 
                                		left = false;
                                		break;
                            		} else {
					// PW가 일치하지 않을 경우 count를 1 더하고 3이 되면 아래의 if문이 실행된다.
                                		System.out.println("비밀번호가 틀렸습니다."); 
                                		count++;
                              		}
                        	}
                  	}
            		} if (count == 3) {
			// 만약 count가 3이 되면 로그인을 중단한다.
			// 아이디만 3번 틀리더라도 로그인이 중단된다. 같은 if문으로 작성되었기 때문이다.

                  		System.out.println("로그인을 중단합니다.");
                  		left = false;
				// while문을 계속 반복하는 left를 false로 바꿈으로써 탈출한다.
              			}
			}
        	scanner.close();
		// scanner.close();를 while문이 끝나기 전에 쓰지 않도록 주의한다.
        	}
    	}
```
