class Payment {
	public
	int transID;
	double amount;
	String custCate;
	double disc = 0;
	Payment(int transID, double amount, String custCate) {
		this.transID = transID;
		this.amount = amount;
		this.custCate = custCate;
	}
	
	void calcDisc(double value) {
		if(value > 2000) {
			this.disc = 5;
			System.out.println("5% discount applied based on purchase value");
		}
		else System.out.println("Discount based on purchase value cannot be applied.");
	}
	
	void calcDisc(String category) {
		if(category == "VIP") {
			this.disc = 10;
			System.out.println("10% discount applied based on customer category");
		}
		else System.out.println("Discount based on customer category cannot be applied.");
	}
	
	void payMethodDisc() {
		System.out.println("Standard payment procedure.");
	}
	
	void display() {
		System.out.println("TransactionID: " + this.transID);
		System.out.println("Amount: " + this.amount);
		System.out.println("Customer Category: " + this.custCate);
		System.out.println("Discount: " + this.disc);
		if(disc != 0) System.out.println("Final Amount: " + (amount - ((disc*amount)/100)));
		else System.out.println("Final Amount: " + this.amount);
	}
}

class UPIPayment extends Payment {
	UPIPayment(int id, double amt, String cat){
		super(id, amt, cat); 
	}
	@Override
	public void payMethodDisc() {
		disc = 15;
		System.out.println("15% discount applied based on UPI Payment");
	}
}
public class assgn3 {
	public static void main(String[] args) {
		Payment obj1 = new Payment(123, 2000, "VIP");
		obj1.calcDisc(2000);
		obj1.calcDisc("VIP");
		obj1.payMethodDisc();
		obj1.display();	
		UPIPayment obj2 = new UPIPayment(456, 3000, "Standard");
		obj2.payMethodDisc();
		obj2.display();
	}
}