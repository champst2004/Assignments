#include <iostream>
#include <string.h>

using namespace std;

class Student{

		float marks;

	public:
		string name;
		int rollno,Class,division;
		string dob;
		int adhar;
		string bloodgrp;
		int phone;
		string address;
		int telno;
		static int count;

		static void no_of_students(){
			cout << "Total no of students are " << count << endl;
		}

		Student(){
			name = "Shivank";
			rollno = 20;
			Class = 2;
			division = 1;
			dob = "04/08/2004";
			adhar = 123456;
			bloodgrp = "B+";
			phone = 123456;
			address = "Pune";
			telno = 255485;
            marks = 451;
			count++;
		}

		void putdata(){
			cout << "Enter Name \n";
			cin >> name;
			cout << "Enter Roll no \n";
			cin >> rollno;
			cout << "Enter Class \n";
			cin >> Class;
			cout << "Enter Division \n";
			cin >> division;
			cout << "Enter Date of birth \n";
			cin >> dob;
			cout << "Enter Aadhar no. \n";
			cin >> adhar;
			cout << "Enter Blood Group \n";
			cin >> bloodgrp;
			cout << "Enter Phone no. \n";
			cin >> phone;
			cout << "Enter Address \n";
			cin >> address;
			cout << "Enter Telephone no. \n";
			cin >> telno;
			cout << "Enter Marks \n";
			cin >> marks;


		}

		void getdata(){
			cout << "Name: " << name << endl;
			cout << "Roll no: " << rollno << endl;
			cout << "Class: " << Class << endl;
			cout << "Division: " << division << endl;
			cout << "Date of birth: " << dob << endl;
			cout << "Aadhar no: " << adhar << endl;
			cout << "Blood Group: " << bloodgrp << endl;
			cout << "Phone no: " << phone << endl;
			cout << "Address: " << address << endl;
			cout << "Telephone no: " << telno << endl;
			cout << "Marks: " << marks << endl;
		}

        friend void percent(Student x);
};

void percent(Student x){
    cout << "percentage = " << x.marks/5 << endl;
};

int Student :: count;

int main()
{
    int n;
    cout << "Enter the no of students: ";
    cin >> n;
	Student N[n];

    for(int i = 0; i < n; i++){
        N[i].putdata();
        N[i].getdata();
    }

	Student :: no_of_students();

    for(int i = 0; i < n; i++){
        cout << "Student " << i+1 << " ";
        percent(N[i]);
    }

	return 0;
}