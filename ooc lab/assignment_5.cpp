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

        void saveData(){
            ofstream output;
            output.open("assignment_5.txt", ios::app);
            if(output.is_open()){
                output << "Name: " << cust_name << endl;
                output << "ID: " << cust_id << endl;
                output << "age: " << age << endl;
                output << "Income: " << income << endl;
                output << "City: " << city << endl;
                output << "Room type: " << room_type << endl;
                output << endl;
                output.close();
            }
        }
    public:
        void accept(){
            cout << "Enter name: ";
            cin >> cust_name;
            cout << "Enter ID: ";
            cin >> cust_id;
            cout << "Enter age: ";
            cin >> age;
            cout << "Enter income: ";
            cin >> income;
            cout << "Enter city: ";
            cin >> city;
            cout << "Enter room type: ";
            cin >> room_type;

            saveData();
        }
        void display(){
            cout << "Name: " << cust_name << endl;
            cout << "ID: " << cust_id << endl;
            cout << "age: " << age << endl;
            cout << "Income: " << income << endl;
            cout << "City: " << city << endl;
            cout << "Room type: " << room_type << endl;
            cout << endl;
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
        cout << "Customer " << i + 1 << endl;
        customers[i].display();
    }
    
    delete[] customers;
    return 0;
}