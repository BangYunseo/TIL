package MoneyManager;

import java.util.Scanner;

public class MoneyBook {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String[] nameList = new String[10];
		int[] valueList = new int[10];
		int left = 100000;
		
		boolean run = true;
		while(run) {
			System.out.print("가계부 | 1 = 수입 | 2 = 지출 | 3 = 삭제 | 4 = 출력 | 5 = 종료 >> ");
			int ans = scanner.nextInt();
			String item;
			int amount;
			if (ans == 1 | ans == 2) {
				System.out.print("내역 >> ");
				item = scanner.next();
				System.out.print("금액 >> ");
				amount = scanner.nextInt();
				if (ans == 2)
					amount = -amount;
				addBook(nameList, valueList, item, amount);
				left += amount;
			}
		//	else if (ans == 2) {
		//		System.out.print("내역 >> ");
		//		item = scanner.next();
		//		System.out.print("금액 >> ");
		//		amount = scanner.nextInt();
		//		addBook(nameList, valueList, item, -amount);
		//		left -= amount;
		//	}
			else if (ans == 3) {
				System.out.print("내역 >> ");
				item = scanner.next();
				left -= removeBook(nameList, valueList, item);
			}
			else if (ans == 4) {
				showBook(nameList, valueList, left);
			}
			else if (ans == 5) {
				System.out.println("프로그램을 종료합니다.");
				run = false;
				break;
			}
			else {
				System.out.println("잘못된 명령입니다.");
			}
		}
		scanner.close();
	}
	public static void addBook(String[] nameList, int[] valueList, String item, int amount) {
		for (int i = 0; i < nameList.length; i++) {
			if (nameList[i] == null) {
				nameList[i] = item;
				valueList[i] = amount;
				break;
			}
		}
	}
	public static int removeBook(String[] nameList, int[] valueList, String item) {
		int value = 0;
		for(int i = 0; i < nameList.length; i++) {
			if (nameList[i].equals(item)) {
				nameList[i] = null;
				value = valueList[i];
				valueList[i] = 0;
				System.out.println(item + " 삭제됨");
				break;
			}
		}
		return value;
	}
	public static void showBook(String[] nameList, int[] valueList, int left) {
		for (int i = 0; i < nameList.length; i++) {
			if (nameList[i] != null)
				System.out.printf("%s : %d원\n", nameList[i], valueList[i]);
		}
		System.out.println("잔액 : " + left + "원");
	}
}
