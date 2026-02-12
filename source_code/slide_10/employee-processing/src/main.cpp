#include "employee-file.h"
#include "employee.h"
#include "invalid-input-excep.h"
#include <iostream>
#include <vector>
#include <limits>
#include <stdexcept>
using namespace std;
int getInt(const string& prompt) throw (InvalidInputException);
void inputEmployeeData(vector<Employee>& employees);
void printEmployees(const vector<Employee>& employees);
void clearInputStream();

int main() {
    vector<Employee> employees;
    employees.push_back(Employee(1, "John", "Doe"));
    employees.push_back(Employee(2, "Jane", "Smith"));  
    employees.push_back(Employee(3, "Alice", "Johnson"));

    //inputEmployeeData(employees);

    string filename = "employees.txt";
    if (EmployeeFile::saveEmployeeToFile(employees, filename)) {
        cout << "Employees saved to " << filename << endl;
    } else {
        cout << "Failed to save employees to file." << endl;
    }
    /*try {
        EmployeeFile::saveEmployeeToFile(employees, filename);
        cout << "Employees saved to " << filename << endl;
    } catch (const std::runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }*/
    employees.clear();
    
    if (EmployeeFile::readEmployeeFromFile(employees, filename)) {
        cout << "Employees read from " << filename << ":\n";
        printEmployees(employees);
    } else {
        cout << "Failed to read employees from file." << endl;
    }
    /*try {
        EmployeeFile::readEmployeeFromFile(employees, filename);
        cout << "Employees read from " << filename << ":\n";
        printEmployees(employees);
    } catch (const std::runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }*/
    employees.clear();
    return 0;
}
void clearInputStream() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void printEmployees(const vector<Employee>& employees) {
    for (const Employee& emp : employees) {
        cout << "Employee ID: " << emp.getEmployeeId() << ", Name: " 
             << emp.getFullName() << endl;
    }   
}
void inputEmployeeData(vector<Employee>& employees) {
    int id;
    string firstName, lastName;
    string prompt = "Enter employee data (ID FirstName LastName), or -1 to stop: ";
    while (true) {
        try {
            id = getInt(prompt);           
        } catch (const InvalidInputException& e) {
            cout << e.what() << endl;
            continue;   
        }
        if (id == -1) {
            break;
        }
        cout << "Enter First Name and Last Name: ";
        cin >> firstName >> lastName;
        employees.push_back(Employee(id, firstName, lastName));
    }
}
int getInt(const string& prompt) throw (InvalidInputException) {
    int value;
    cout << prompt;
    cin >> value;
    if (cin.fail()) {
        clearInputStream();
        throw InvalidInputException("Invalid integer input");
    }
    clearInputStream();
    return value;
}