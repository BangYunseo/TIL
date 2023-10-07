package StudyJava1;
	public class StudyJava1_1 {
		public static void main(String[] args) {
			char[] myCh = {'+', '-', '*', '/'};
			for (int i = 0; i < myCh.length; i++) {
				for(int j = 1; j <= (i * 2) + 2; j++) {
					System.out.print(myCh[i]);
				}
				System.out.println();
			}
		}
}