/*
ID: 68011278
Name: Ananda Stallard
Lab No: 10
Question No: 1
Date: 26 Feb 2026
*/
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "department.h"
#include "employee.h"
#include "fulltime-employee.h"
#include "parttime-employee.h"
using namespace std;

void createEmployeesAndDepartments(vector<shared_ptr<Employee>>& employees, vector<shared_ptr<Department>>& departments) {
    //Example data
    //task10: create 3 employees, two full-time and one part-time, with example data.
    shared_ptr<Employee> emp1 = make_shared<FullTimeEmployee>("Alice Smith", 1001, nullptr, 60000, 5000);
    shared_ptr<Employee> emp2 = make_shared<PartTimeEmployee>("John Doe", 1002, nullptr, 300, 8);
    shared_ptr<Employee> emp3 = make_shared<FullTimeEmployee>("Jane Johnson", 1003, nullptr, 65000, 4500);

    employees.push_back(emp1);
    employees.push_back(emp2);
    employees.push_back(emp3);

    //task11: create 2 departments with example names.
    shared_ptr<Department> dept1 = make_shared<Department>("Human Resources");
    shared_ptr<Department> dept2 = make_shared<Department>("Engineering");

    departments.push_back(dept1);
    departments.push_back(dept2);
}
void assignEmployeeToDepartment(vector<shared_ptr<Department>>& departments, vector<shared_ptr<Employee>>& employees) {
    // Example assignments
    //task12: assign the first two employees to the first department, the third to the second department.
    departments[0]->addEmployee(employees[0]);
    departments[0]->addEmployee(employees[1]);
    departments[1]->addEmployee(employees[2]);
}
void displayEmployeeInfo(const vector<shared_ptr<Employee>>& employees) {
    // task13: Display information for each employee
    //Consult the lab manual for the expected output format
    for (const auto& emp : employees) {
        cout << "Employee Name: " << emp->getName() << ", ID: " << emp->getId() << ", Pay: " << emp->calculatePay();
        auto dept = emp->getDepartment();
        cout << ", Department: " << (dept ? dept->getDeptName() : "None") << endl;
    }
    cout << endl;
}
void displayDepartmentInfo(const vector<shared_ptr<Department>>& departments) {
    // task14: Display information for each department
    //Consult the lab manual for the expected output format
    for (const auto& dept : departments) {
        cout << "Department: " << dept->getDeptName() << endl << "Employees:" << endl;
        for (const auto& emp : dept->getEmployees()) {
            cout << "- " << emp->getName() << ", ID: " << emp->getId() << ", Pay: " << emp->calculatePay() << endl;
        }
        cout << "\n";
    }
    cout << endl;
}
int main() {
    //task15: Declare vectors to hold shared pointers to Employee and Department objects.
    std::vector<shared_ptr<Employee>> employees;
    std::vector<shared_ptr<Department>> departments;

    //task16: Call the functions to create employees and departments, 
    //assign employees to departments, and display the information.
    //call the functions in the correct order to demonstrate the functionality of the system.
    createEmployeesAndDepartments(employees, departments);
    
    shared_ptr<Department> dept1 = departments[0];
    shared_ptr<Department> dept2 = departments[1];

    assignEmployeeToDepartment(departments, employees);
    displayEmployeeInfo(employees);
    displayDepartmentInfo(departments);

    //task17: Demonstrate the transfer of an employee from one department to another,
    //and display the updated information for the employee and both departments.
    dept1->transferEmployee((dept1->getEmployees())[1], dept2);
    cout << "After transfering:\n";
    displayEmployeeInfo(employees);
    displayDepartmentInfo(departments);

    //task 18: Demonstrate the removal of an employee from a department,
    //and display the updated information for the employee and the department.
    dept2->removeEmployee((dept2->getEmployees())[1]);
    cout << "After removing:\n";
    displayEmployeeInfo(employees);
    displayDepartmentInfo(departments);

    employees.clear();  
    departments.clear();

    return 0;
}
