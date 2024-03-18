#include<iostream>
using namespace std;

class Employee {
public:
    int empid;
    string name;
    int deptid;
    double basicSalary;

    Employee() {
        empid = 101;
        name = "Shivanjali";
        deptid = 10;
        basicSalary = 30000;
    }

    Employee(int empid, string name, int deptid, double basicSalary) {
        this->empid = empid;
        this->name = name;
        this->deptid = deptid;
        this->basicSalary = basicSalary;
    }

    double NetSalary() { 
        return basicSalary; 
    }

    void display() {
        cout << "Employee ID : " << empid << endl;
        cout << "Employee Name : " << name << endl;
        cout << "Department ID : " << deptid << endl;
        cout << "Basic Salary : " << basicSalary << endl;
    }
};

class Manager : public Employee {
public:
    double perfBonus;
    Manager() {
        perfBonus = 5000;
    }
    Manager(int empid, string name, int deptid, double basicSalary, double perfBonus) : Employee(empid, name, deptid, basicSalary) {
        this->perfBonus = perfBonus;
    }
    double NetSalary() {
        return basicSalary + perfBonus;
    }
    void display() {
        Employee::display();
        cout << "Performance bonus : " << perfBonus << endl;
        cout << "Net Salary : " << NetSalary() << endl;
    }
};

class Worker : public Employee {
public:
    int hoursWorked;
    int hourlyRate;

    Worker() {
        hoursWorked = 10;
        hourlyRate = 600;
    }
    Worker(int empid, string name, int deptid, double basicSalary, int hoursWorked, int hourlyRate) : Employee(empid, name, deptid, basicSalary) {
        this->hoursWorked = hoursWorked;
        this->hourlyRate = hourlyRate;
    }
    double NetSalary() {
        return basicSalary + (hoursWorked * hourlyRate);
    }
    int getHrlyRate() {
        return hoursWorked * hourlyRate;
    }
    void display() {
        Employee::display();
        cout << "Hours Worked : " << hoursWorked << endl;
        cout << "Hourly Rate : " << hourlyRate << endl;
        cout << "Net Salary : " << NetSalary() << endl;
    }
};

int main() {
    Employee emp;
    Manager mg;
    Worker wr;
    int choice;
    do {
        cout << "------ Enter choice as per menu -------" << endl;
        cout << "1.Hire Manager\n2.Hire Worker\n3.Display Net Salary information\n4.Exit" << endl;
        cin >> choice;

        switch (choice) {
        case 1:
            mg.display();
            break;
        case 2:
            wr.display();
            break;
        case 3:
            double empNetSalary = emp.NetSalary();
            double mgNetsalary = mg.NetSalary();
            double wrNetSalary = wr.NetSalary();
            cout<<"Employee Netsalary : "<<empNetSalary<<endl;
            cout<<"Manager Netsalary : "<<mgNetsalary<<endl;
            cout<<"Worker Netsalary : "<<wrNetSalary<<endl;
            break;
        }
    } while (choice != 4);
    return 0;
}
