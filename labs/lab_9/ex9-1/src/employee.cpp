#include <iostream>
#include "employee.h"
//task 1: Implement the Employee class methods

Employee::Employee(const std::string& name, int id, double salary) : name(name), id(id), salary(salary) {};

std::string Employee::getName() const {
    return name;
}

void Employee::setName (const std::string& newName) {
    name = newName;
}

int Employee::getId() const {
    return id;
}

void Employee::setId(int newId) {
    id = newId;
}

double Employee::getSalary() const {
    return salary;
}

void Employee::setSalary(double newSalary) {
    salary = newSalary;
}
