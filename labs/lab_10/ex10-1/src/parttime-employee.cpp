#include "parttime-employee.h"
#include <string>
#include <iostream>
#include <memory>
//task 9: implement the functions declared in the PartTimeEmployee class
PartTimeEmployee::PartTimeEmployee(const std::string& name, int id, 
        const std::shared_ptr<Department>& department, double hourlyWage, 
        double hoursWorked) : Employee(name, id, department), hourlyWage(hourlyWage), hoursWorked(hoursWorked) {};

double PartTimeEmployee::getHourlyWage() const {
    return hourlyWage;
}

void PartTimeEmployee::setHourlyWage(double newHourlyWage) {
    hourlyWage = newHourlyWage;
}

double PartTimeEmployee::getHoursWorked() const {
    return hoursWorked;
}

void PartTimeEmployee::setHoursWorked(double newHoursWorked) {
    hoursWorked = newHoursWorked;
}

double PartTimeEmployee::calculatePay() const {
    return hourlyWage * hoursWorked;
}
