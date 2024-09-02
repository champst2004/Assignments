#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string Ename;
    int EmpID;

public:
    void accept() {
        cout << "Enter Employee Name: ";
        cin >> Ename;
        cout << "Enter Employee ID: ";
        cin >> EmpID;
    }

    void display() {
        cout << "Employee Name: " << Ename << endl;
        cout << "Employee ID: " << EmpID << endl;
    }
};

class SalariedEmployee : public Employee {
private:
    double weeklySalary;

public:
    void accept() {
        Employee::accept();  
        cout << "Enter Weekly Salary: ";
        cin >> weeklySalary;
    }

    void display() {
        Employee::display();
        cout << "Weekly Salary: Rs." << weeklySalary << endl;
    }

    void weekly_earnings() {
        cout << "Weekly Earnings: Rs." << weeklySalary << endl;
    }
};

class HourlyEmployee : public Employee {
private:
    double wage;
    double hours;
    double hourlySalary;

public:
    void accept() {
        Employee::accept();
        cout << "Enter Wage per Hour: ";
        cin >> wage;
        cout << "Enter Hours Worked: ";
        cin >> hours;
        if (hours < 40) {
            hourlySalary = hours * wage;
        } else {
            hourlySalary = 40 * wage + ((hours - 40) * wage) * 1.5;
        }
    }

    void display() {
        Employee::display(); 
        cout << "Hourly Wage: Rs." << wage << endl;
        cout << "Hours Worked: " << hours << endl;
        cout << "Hourly Salary: Rs." << hourlySalary << endl;
    }

    void hourly_earnings() {
        cout << "Hourly Earnings: Rs." << hourlySalary << endl;
    }
};

class CommissionEmployee : public Employee {
private:
    double grossSales;
    double commissionRate;
    double commissionSalary;

public:
    void accept() {
        Employee::accept(); 
        cout << "Gross Sales: ";
        cin >> grossSales;
        cout << "Commission Rate: ";
        cin >> commissionRate;
        calculate_commission_salary();
    }

    void display() {
        Employee::display(); 
        cout << "Gross Sales: Rs." << grossSales << endl;
        cout << "Commission Rate: " << commissionRate * 100 << "%" << endl;
        cout << "Commission Salary: Rs." << commissionSalary << endl;
    }

    void calculate_commission_salary() {
        commissionSalary = grossSales * commissionRate;
    }

    void commission_earnings() {
        cout << "Commission Earnings: Rs." << commissionSalary << endl;
    }
};

int main() {
    SalariedEmployee sEmployee;
    HourlyEmployee hEmployee;
    CommissionEmployee cEmployee;

    cout << "Salaried Employee Data:" << endl;
    sEmployee.accept();
    sEmployee.display();
    sEmployee.weekly_earnings();
    cout << endl;

    cout << "Hourly Employee Data:" << endl;
    hEmployee.accept();
    hEmployee.display();
    hEmployee.hourly_earnings();
    cout << endl;

    cout << "Commission Employee Data:" << endl;
    cEmployee.accept();
    cEmployee.display();
    cEmployee.commission_earnings();
    cout << endl;
    return 0;
}