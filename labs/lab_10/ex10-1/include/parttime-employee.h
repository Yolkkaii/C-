#ifndef PARTTIME_EMPLOYEE_H
#define PARTTIME_EMPLOYEE_H
#include "employee.h"
#include <memory>
class PartTimeEmployee : public Employee {
public:
    PartTimeEmployee(const std::string& name = "", int id = 0, 
        const std::shared_ptr<Department>& department = nullptr, double hourlyWage = 0.0, 
        double hoursWorked = 0.0);
    double getHourlyWage() const;
    void setHourlyWage(double newHourlyWage);
    double getHoursWorked() const;
    void setHoursWorked(double newHoursWorked);
    double calculatePay() const override;
    
private:
    double hourlyWage;
    double hoursWorked;
};
#endif // PARTTIME_EMPLOYEE_H