#ifndef FULLTIME_EMPLOYEE_H
#define FULLTIME_EMPLOYEE_H
#include "employee.h"
//task 3
// Define FullTimeEmployee class inheriting from Employee
// with salary and bonus attributes
// and override calculatePay function
class FullTimeEmployee : public Employee {
public:
    FullTimeEmployee(const std::string& name, int id, Department *dept, double salary, double bonus);
    double calculatePay() override;
    ~FullTimeEmployee() = default;

private:
    double salary;
    double bonus;
};

#endif // FULLTIME_EMPLOYEE_H