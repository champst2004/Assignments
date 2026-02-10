import java.util.Scanner;

public class assgn1 {
	public static void main(String[] args) {
		Cloud c1 = new Cloud("ST.apk", 101);
		c1.getData();
		System.out.println();
		System.out.println("After accessing file: ");
		c1.accessFile("10AM");
		c1.getData();
	}
}

class Cloud{
	Scanner sc = new Scanner(System.in);
	String name;
	int fileID;
	int accessCount;
	String lastAccessTime;
	
	Cloud(String n, int id){
		name = n;
		fileID = id;
		accessCount = 0;
		lastAccessTime = "Not accessed";
	}
//	void setData() {
//		System.out.print("Enter name of user: ");
//		String userName = sc.nextLine();
//		System.out.print("Enter id of user: ");
//		int id = sc.nextInt();
//		System.out.print("Enter access count: ");
//		int access = sc.nextInt();
//		System.out.print("Enter last access time: ");
//		int accessTime = sc.nextInt();
//		
//	}
	void getData() {
		System.out.println("Name of file: " + name);
		System.out.println("ID: " + fileID);
		System.out.println("Access count: " + accessCount);
		System.out.println("Last access time: " + lastAccessTime);
	}
	void accessFile(String time) {
		accessCount++;
		lastAccessTime = time;
	}
}