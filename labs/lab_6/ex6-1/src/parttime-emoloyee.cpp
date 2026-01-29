#include "parttime-employee.h"
#include <string>
#include <iostream>
//task 6
// Implement PartTimeEmployee class methods
PartTimeEmployee::PartTimeEmployee(const std::string& name, int id, Department* dept, double hourlyWage, double hoursWorked) 
    : Employee(name, id, dept), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {}

double PartTimeEmployee::calculatePay() {
    return hourlyWage * hoursWorked;
}