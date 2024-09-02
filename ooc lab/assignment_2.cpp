#include <iostream>
using namespace std;

class student
{
private:
    string name;
    int roll;
    char Class;
    string division;
    string dob;
    unsigned long long aadhar;
    string blood;
    string address;
    unsigned long long tel;

public:
    student()
    {
        name = "Shivank Tripahi";
        roll = 20;
        Class = '2';
        division = "J";
        dob = "04/08/2004";
        aadhar = 55085767;
        blood = "B+";
        address = "Pune";
        tel = 94226;
    }

    student(string Name, int Roll, char Class_, string Division, string Dob,
            unsigned long long Aadhar, string Blood, string Address, unsigned long long Tel)
    {
        name = Name;
        roll = Roll;
        Class = Class_;
        division = Division;
        dob = Dob;
        aadhar = Aadhar;
        blood = Blood;
        address = Address;
        tel = Tel;
    }

    student(student &p)
    {
        name = p.name;
        roll = p.roll;
        Class = p.Class;
        division = p.division;
        dob = p.dob;
        aadhar = p.aadhar;
        blood = p.blood;
        address = p.address;
        tel = p.tel;
    }

    void print()
    {
        cout << "Name : " << name << endl;
        cout << "Roll No : " << roll << endl;
        cout << "Class : " << Class << endl;
        cout << "Division : " << division << endl;
        cout << "Date of birth : " << dob << endl;
        cout << "Aadhar No. : " << aadhar << endl;
        cout << "Bloog Group : " << blood << endl;
        cout << "Address : " << address << endl;
        cout << "Telephone No.: " << tel << endl;
    }

    ~student()
    {
        cout << "Object destroyed" << endl;
    }
};

int main()
{
    student s1;
    cout << "Default Constructor:\n";
    s1.print();

    cout << "Parameterized Constructor:\n";
    string Name;
    int Roll;
    char Class_;
    string Division;
    string Dob;
    unsigned long long Aadhar;
    string Blood;
    string Address;
    unsigned long long Tel;
    cout << "Enter your name : " << endl;
    getline(cin >> ws, Name);
    cout << "Enter roll no : " << endl;
    cin >> Roll;
    cout << "Enter class : " << endl;
    cin >> Class_;
    cout << "Enter division : " << endl;
    getline(cin >> ws, Division);
    cout << "Enter dob : " << endl;
    getline(cin >> ws, Dob);
    cout << "Enter aadhar no. : " << endl;
    cin >> Aadhar;
    cout << "Enter blood group : " << endl;
    getline(cin >> ws, Blood);
    cout << "Enter address : " << endl;
    getline(cin >> ws, Address);
    cout << "Enter telephone no. : " << endl;
    cin >> Tel;
    cout << endl;
    student s2(Name, Roll, Class_, Division, Dob, Aadhar, Blood, Address, Tel);
    s2.print();
    cout << "Copy Constructor:\n";
    student s3 = s2;
    s3.print();
}