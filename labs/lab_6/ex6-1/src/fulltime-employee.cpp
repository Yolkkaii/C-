#include <iostream>
#include <string>   
#include "fulltime-employee.h"
//task 4
// Implement FullTimeEmployee class methods
FullTimeEmployee::FullTimeEmployee(const std::string& name, int id, Department *dept, double salary, double bonus) 
    : Employee(name, id, dept), salary(salary), bonus(bonus) {}

double FullTimeEmployee::calculatePay() {
    return salary + bonus;
}