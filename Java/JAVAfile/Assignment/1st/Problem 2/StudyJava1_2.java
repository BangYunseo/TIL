package StudyJava1_2;
import java.util.Scanner;
public class StudyJava1_2 {
public static void main(String[] args) {
Scanner scanner = new Scanner(System.in);
String IDcode = "Kim";
String PWcode = "12345";
int count = 0;
String ID ="";
boolean left = true;
while (left) {
if (count == 0 || !ID.equals(IDcode)) {
System.out.print("로그인 아이디>> ");
ID = scanner.nextLine();
if (!ID.equals(IDcode)) {
System.out.println("아이디가 틀렸습니다.");
count++;
} else {
while (count < 3) {
System.out.print("로그인 비밀번호 >> "); 
String PW = scanner.nextLine();
if (PW.equals(PWcode)) {
System.out.println("로그인 성공입니다."); 
left = false;
break;
} else {
System.out.println("비밀번호가 틀렸습니다."); 
count++;
}
}
}
} if (count == 3) {
System.out.println("로그인을 중단합니다.");
left = false;
}
}
scanner.close();
}
}