/*
ID: 68011278
Name: Ananda Stallard
Lab No: 6
Question No: 1
Date: 29 Jan 2026
*/
#include <iostream>
#include <string>
#include <vector>
#include "department.h"
#include "employee.h"
#include "fulltime-employee.h"
#include "parttime-employee.h"
using namespace std;

void createEmployeesAndDepartments(vector<Employee*>& employees, vector<Department>& departments) {
    //task 7
    //Example data
    // Creating 3 employees, two full-time and one part-time
    employees.push_back(new FullTimeEmployee("Alice Smith", 1001, nullptr, 65000.0, 1000.0)); //Use new because employees
    employees.push_back(new PartTimeEmployee("John Doe", 1002, nullptr, 2400.0, 1.0)); //store pointers
    employees.push_back(new FullTimeEmployee("Jane Johnson", 1003, nullptr, 69500.0, 500.0));

    // Creating 2 departments
    departments.push_back(Department("Human Resources"));
    departments.push_back(Department("Engineering"));

}
void assignEmployeeToDepartment(vector<Department>& departments, vector<Employee*>& employees) {
    //task 8
    // Example assignments
    //The first two employees to the first department, the third to the second department
    departments[0].addEmployee(employees[0]);
    departments[0].addEmployee(employees[1]);

    departments[1].addEmployee(employees[2]);
}
void displayEmployeeInfo(const vector<Employee*>& employees) {
    //task 9
    // Display information for each employee
    //Consult the lab manual for the expected output format
    for (const auto emp: employees) {
        cout << "Employee Name: " << emp->getName() << ", ID: " << emp->getId() << ", Pay: " << emp->calculatePay() << ", Department: " << (emp->getDepartment())->getDeptName() << "\n";
    }
    cout << endl;
}
void displayDepartmentInfo(const vector<Department>& departments) {
    //task 10
    // Display information for each department
    //Consult the lab manual for the expected output format
    for (const auto& dept: departments){
        cout << "Department: " << dept.getDeptName() << "\nEmployees:\n";
        for (Employee* emp: dept.getEmployees()) {
            cout << "- " << emp->getName() << ", ID: " << emp->getId() << ", Pay: " << emp->calculatePay() << "\n";
        }
        cout << endl;
    }
}

int main() {
    //task 11
    // Create vectors to hold employees, the variable name must be employees 
    vector<Employee*> employees;

    //task 12
    // Create vectors to hold departments, the variable name must be departments
    vector<Department> departments;

    //task 13
    // Reserve space to optimize memory allocations for 3 employees
    employees.reserve(3);

    //task 14
    // Reserve space to optimize memory allocations for 2 departments
    departments.reserve(2);

    //task 15
    //call functions to create data, assign relationships, and display info 
    createEmployeesAndDepartments(employees, departments);
    assignEmployeeToDepartment(departments, employees);

    displayEmployeeInfo(employees);
    displayDepartmentInfo(departments);

    //task 16
    // Clean up dynamically allocated memory
    // this is important to avoid memory leaks
    for (Employee* emp: employees) {
        delete emp;
    }

    //The department is not a pointer, so no delete for it

    employees.clear();  
    departments.clear();

    return 0;
}
