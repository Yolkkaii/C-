#ifndef FULLTIME_EMPLOYEE_H
#define FULLTIME_EMPLOYEE_H
#include "employee.h"
#include <memory>
class FullTimeEmployee : public Employee {
public:
    FullTimeEmployee(const std::string& name = "", int id = 0, const std::shared_ptr<Department>& department = nullptr, 
        double salary = 0.0, double bonus = 0.0);
    double getSalary() const;
    void setSalary(double newSalary);
    double getBonus() const;
    void setBonus(double newBonus);
    double calculatePay() const override;
    
private:
    double salary;
    double bonus;
};
#endif // FULLTIME_EMPLOYEE_H