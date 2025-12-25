/*
    Name: Ananda Stallard
    Lab No: 3
    Question No: 1
    Date: Dec 25, 2025 
*/
#include <iostream>
#include "employee.hpp"
using namespace std;
void displayEmployeeInfo(const Employee& emp);
int main() {
    Employee emp[3] = {
        Employee("John Doe", 101, 55000.0),
        Employee("Jane Smith", 102, 62000.0),
        Employee("Alice Johnson", 103, 58000.0)
    };
    //task5
    //display all employee information using displayEmployeeInfo function
    //you may use a loop here
    for (int i = 0; i < 3; i++){
        displayEmployeeInfo(emp[i]);
        cout << '\n';
    }
    
    //task 6
    //update and display the salary of the first employee
    cout << "Update salary of employee 1:\n";
    emp[0].setSalary(60000);
    displayEmployeeInfo(emp[0]);
    return 0;
}

void displayEmployeeInfo(const Employee& emp) {
    //task7
    //display employee information in the format:
    //Employee Name: <name>
    //Employee ID: <id>
    //Employee Salary: <salary>
    cout << "Employee Name: " << emp.getName() << '\n';
    cout << "Employee ID: " << emp.getID() << '\n';
    cout << "Employee Salary: " << emp.getSalary() << '\n';
}