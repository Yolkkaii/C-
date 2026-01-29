#include "employee.h"
#include <string>
#include <iostream>
using namespace std;
// Implementation file for Employee class
Employee::Employee(const string& aName, int anId, Department* aDepartment):name{aName}, 
    id{anId}, department{aDepartment} {}
string Employee:: getName() const {
    return name;
}
int Employee:: getId() const {
    return id;
}
void Employee::setName(const string& newName) {
    name = newName;
}
void Employee::setId(int newId) {
    id = newId;
}
void Employee::setDepartment(Department *newDepartment) {
    if (department == newDepartment) { // No change, or not called from Department::addEmployee
        return;
    }
    department = newDepartment;
    if (newDepartment) {
        newDepartment->addEmployee(this);
    }
}
Department *Employee::getDepartment() const {
    return department;
}
Employee::~Employee() = default;