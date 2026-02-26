#include "employee.h"
#include <string>
#include <memory>
#include <iostream>
using namespace std;
//task 7: implement the functions declared in the Employee class
Employee::Employee(const std::string& name, int id, std::shared_ptr<Department> department) : name(name), id(id), department(department){};

std::string Employee::getName() const {
    return name;
}

int Employee::getId() const {
    return id;
}

void Employee::setName(const std::string& newName) {
    name = newName;
}

void Employee::setId(int newId) {
    id = newId;
}

void Employee::setDepartment(std::shared_ptr<Department> newDept) {
    department = newDept;
}

std::shared_ptr<Department> Employee::getDepartment() {
    return department.lock(); //Important
}

double Employee::calculatePay() const {
    return 0;
}
