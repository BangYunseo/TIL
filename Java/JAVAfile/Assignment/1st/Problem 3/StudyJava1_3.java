package StudyJava1_3;
import java.util.Scanner;
import java.util.Random;
public class StudyJava1_3 {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
Random random = new Random();
String[] strGame = {"가위", "바위", "보"};
System.out.println("가위 바위 보 게임을 시작합니다.");
while(true) {
System.out.print("가위 바위 보! >> ");
String rspGame = scanner.nextLine();
int rspGameCom = random.nextInt(3);
// rspGameCom( ) 3 ( ) 컴퓨터의 가위바위보 입력 에 가지의 숫자 랜덤으로 넣기 배열의 인덱스
// rspGameCom은 계속 배열의 인덱스로 사용됨
if(rspGame.equals("종료")) {
System.out.println("게임을 종료합니다.");
break;
}
System.out.print("사용자 = " + rspGame + ", 컴퓨터 = " + strGame[rspGameCom]+".");
if (rspGame.equals(strGame[rspGameCom])) {
System.out.println("비겼습니다."); 
} else if((rspGame.equals("가위") && strGame[rspGameCom].equals("보"))
	|| (rspGame.equals("바위") && strGame[rspGameCom].equals("가위")) 
	|| (rspGame.equals("보") && strGame[rspGameCom].equals("바위")) )
	{
System.out.println("사용자가 이겼습니다."); 
} else {
System.out.println("컴퓨터가 이겼습니다.");
}
}
scanner.close();
}
}