#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
class Employee {
private: 
    std::string name;
    int id;
    double salary;
public:
    Employee(const std::string& name="", int id=0, double salary=0.0);
    std::string getName() const;
    void setName(const std::string& newName);
    int getId() const;
    void setId(int newId);

    double getSalary() const;
    void setSalary(double newSalary);

};
#endif // EMPLOYEE_H