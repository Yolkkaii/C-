#include "department.h"
#include "employee.h"
#include <string>
using namespace std;
// Implementation file for Department class
Department::Department(const string& deptName):deptName{deptName} {}
string Department:: getDeptName() const {
    return deptName;
}
void Department:: setDeptName(const string& newDeptName) {
    deptName = newDeptName;
}   
void Department::addEmployee(Employee* emp) {
    if (emp == nullptr) {
        return;
    }
    for (const auto& e : employees) {
        if (e == emp) {
            return; // Employee already exists
        }
    }   
    employees.push_back(emp);
    // Ensure bidirectional association
    if (emp->getDepartment() != this) { //if not called from Employee::setDepartment    
        emp->setDepartment(this);
    }
}
const vector<Employee*> Department::getEmployees() const {
    return employees;
}