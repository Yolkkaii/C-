#ifndef PARTTIME_EMPLOYEE_H
#define PARTTIME_EMPLOYEE_H
#include "employee.h"
//task 5
// Define PartTimeEmployee class inheriting from Employee
class PartTimeEmployee : public Employee {
public:
    PartTimeEmployee(const std::string& name, int id, Department *dept, double hourlyWage, double hoursWorked);
    double calculatePay() override;
    ~PartTimeEmployee() = default;

private:
    double hourlyWage;
    double hoursWorked;
};

#endif // PARTTIME_EMPLOYEE_H