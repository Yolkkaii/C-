#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include "department.h"
#include <string>
class Employee {
public:
    Employee(const std::string& name = "", int id = 0, Department* department = nullptr);
    std::string getName() const;
    int getId() const;
    void setName(const std::string& newName);
    void setId(int newId); 
    void setDepartment(Department *newDepartment);
    Department *getDepartment() const;
    //task 1 
    // Declare a pure default destructor
    virtual ~Employee();

    //task 2
    // Declare a pure virtual function calculatePay
    virtual double calculatePay() = 0;

    
private:
    std::string name;
    int id;
    Department *department;
};
#endif // EMPLOYEE_H