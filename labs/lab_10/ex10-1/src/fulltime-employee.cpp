#include <iostream>
#include <string>   
#include <memory>
#include "fulltime-employee.h"
//task8: implement the functions declared in the FullTimeEmployee class
FullTimeEmployee::FullTimeEmployee(const std::string& name, int id, const std::shared_ptr<Department>& department, 
        double salary, double bonus) : Employee(name, id, department), salary(salary), bonus(bonus) {};

double FullTimeEmployee::getSalary() const {
    return salary;
}

void FullTimeEmployee::setSalary(double newSalary) {
    salary = newSalary;
}

double FullTimeEmployee::getBonus() const {
    return bonus;
}

void FullTimeEmployee::setBonus(double newBonus) {
    bonus = newBonus;
}

double FullTimeEmployee::calculatePay() const {
    return salary + bonus;
}
