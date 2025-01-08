#include <iostream>
using namespace std;
 
class user{
	long phoneNo;
	string name;
	float billAmount;
	public:
		user(){
			phoneNo = 0;
			name = "default";
			billAmount = 0;
		}
		friend class record;
};

class record{
	int n;
	user u[10];
	public:
	    record(int n1){n = n1;}
		void accept(){
			for(int i = 0; i < n; i++){
				cout << "Enter Name: ";
				cin >> u[i].name;
				cout << "Enter Phone No.: ";
				cin >> u[i].phoneNo;
				cout << "Enter bill amount: ";
				cin >> u[i].billAmount;
			}	
		}
		void display(){
			for(int i = 0; i < n; i++){
				cout << "\nDetails of user " << i + 1 << endl;
				cout << "Name: " << u[i].name << endl;
				cout << "Phone No.: " << u[i].phoneNo << endl;
				cout << "Bill Amount: " << u[i].billAmount << endl;
			}
		}
		int linearSearch(){
			long no;
			cout << "Enter the no. to search: ";
			cin >> no;
			for(int i = 0; i < n; i++){
				if(u[i].phoneNo == no) return i;
			}
			return -1;
		}
		void adjust(int n, int i){
			while(2*i+1 <= n){
				int j = 2*i+1;
				if((j+1 <= n) and (u[j+1].billAmount > u[j].billAmount)) j++;
				if(u[i].billAmount >= u[j].billAmount) break;
				else swap(u[i],u[j]);
			}
		}
		void heapSort(){
			int m = n;
			for(int i = (m/2)-1; i > -1; i--){
				adjust(m-1,i);
			}
			while(m > 0){
				swap(u[0], u[m-1]);
				m--;
				adjust(m-1,0);
			}
		}
		int binarySearch(){
			long no;
			cout << "Enter the no. to search: ";
			cin >> no;
			int l = 0;
			int r = n - 1;
			while(l <= r){
				int mid = (l+r)/2;
				if(u[mid].phoneNo == no) return mid;
				else if(u[mid].phoneNo < no) l = mid + 1;
				else r = mid - 1;
			}
            return -1;
		}
		void printUser(int i){
			if(i == -1) cout << "User not found\n";
			else{
				cout << "Name: " << u[i].name << endl;
				cout << "Phone No.: " << u[i].phoneNo << endl;
				cout << "Bill Amount: " << u[i].billAmount << endl;
			}
		}
};

int main(){
	int n, choice;
	cout << "Enter no. of users: ";
	cin >> n;
	record jio(n);
    while(1){
        cout << "1. Accept records\n2. Display records\n3. Sort using HeapSort\n";
        cout << "4. Sort using Quick Sort\n5. Search using Linear Search\n6. Search using Binary search\n7. Exit\n";
        cout << "Enter Choice: ";
        cin >> choice;
        switch(choice){
            case 1:
            jio.accept();
                break;
            case 2:
            jio.display();
                break;
            case 3:
                jio.heapSort();
                break;
            case 4:
                break;
            case 5:
				jio.printUser(jio.linearSearch());
                break;
            case 6:
				jio.printUser(jio.binarySearch());
                break;
            case 7:
                cout << "Thank You";
                return 0;
        }
    }
}
