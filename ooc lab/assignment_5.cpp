#include <iostream>
#include <fstream>
using namespace std;

class Hotel{
    private:
        string cust_name;
        int cust_id;
        int age;
        int income;
        string city;
        string room_type;
        bool error = false;

        void saveData(){
            if(!error){
                ofstream output;
                output.open("assignment_5.txt", ios::app);
                if(output.is_open()){
                    output << "Name: " << cust_name << endl;
                    output << "ID: " << cust_id << endl;
                    output << "Age: " << age << endl;
                    output << "Income: " << income << endl;
                    output << "City: " << city << endl;
                    output << "Room type: " << room_type << endl;
                    output << endl;
                    output.close();
                }
            }
        }

    public:
        Hotel(){
            cust_name = "Random";
            cust_id = 911420;
            city = "Random";
            room_type = "Default";

        }
        void accept(){
            cout << "Enter name: ";
            getline(cin >> ws, cust_name);
            cout << "Enter ID: ";
            cin >> cust_id;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter income: ";
            cin >> income;
            cout << "Enter city: ";
            cin >> city;
            cout << "Enter room type: ";
            getline(cin >> ws, room_type);  

            checkExecption();    
            saveData();
        }

        void checkExecption(){
            try{
                if(getAge() < 18 || getAge() > 55){
                    throw 404;
                }
            }
            catch(int err){            //err = 404 as thrown above
		        cout << "Age must me between 18 and 55" << endl;
                error = true;
            }
            
            try{
            	if(getIncome() < 50000 || getIncome() > 100000){
            		throw 404;
            	}
            }
            catch(int err){
            	cout << "Income must be between 50000 and 100000" << endl;
                error = true;
            }
            
            try{
            	if(getCity() != "Pune" && getCity() != "Mumbai"){
            		throw 404;
            	}
            }
            catch(int err){
            	cout << "City must be Pune or Mumbai" << endl;
                error = true;
            }
            
            try{
            	if(getRoomType() != "Deluxe" && getRoomType() != "Super deluxe"){
            		throw 404;
            	}
            }
            catch(int err){
            	cout << "Room type cmust be Deluxe or Super deluxe" << endl;
                error = true;
            }   
        }

        void display(){
            if(!error){
                cout << "Name: " << cust_name << endl;
                cout << "ID: " << cust_id << endl;
                cout << "Age: " << age << endl;
                cout << "Income: " << income << endl;
                cout << "City: " << city << endl;
                cout << "Room type: " << room_type << endl;
                cout << endl;
            }
        }
        int getAge(){
            return age;
        }
        int getIncome(){
            return income;
        }
        string getCity(){
            return city;
        }
        string getRoomType(){
            return room_type;
        }
};

int main(){
    int n;
    cout << "Enter no. of customers: ";
    cin >> n;
    Hotel *customers = new Hotel[n];

    for(int i = 0; i < n; i++){
        cout << "Enter details for customer " << i + 1 << endl;
        customers[i].accept();
        cout << endl;
    }

    for(int i = 0; i < n; i++){
        customers[i].display();
    }

    delete[] customers;
    return 0;
}
