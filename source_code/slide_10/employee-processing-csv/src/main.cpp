#include "employee-file.h"
#include "employee.h"
#include <iostream>
#include <vector>
using namespace std;
int main() {
    vector<Employee> employees;
    employees.push_back(Employee(1, "John", "Doe"));
    employees.push_back(Employee(2, "Jane", "Smith"));
    employees.push_back(Employee(3, "Alice", "Johnson"));

    string filename = "employees.csv";
    if (EmployeeFile::saveEmployeeToFile(employees, filename)) {
        cout << "Employees saved to " << filename << endl;
    } else {
        cout << "Failed to save employees to file." << endl;
    }

    employees.clear();
    if (EmployeeFile::readEmployeeFromFile(employees, filename)) {
        cout << "Employees read from " << filename << ":\n";
        for (const Employee& emp : employees) {
            cout << emp.getEmployeeId() << ": " << emp.getFullName() << endl;
        }
    } else {
        cout << "Failed to read employees from file." << endl;
    }
    
    employees.clear();
    return 0;
}