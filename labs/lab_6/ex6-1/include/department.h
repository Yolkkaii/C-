#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
#include <vector>
class Employee;  // Forward declaration
class Department {
public:
    Department(const std::string& deptName="");
    std::string getDeptName() const;
    void setDeptName(const std::string& newDeptName);
    void addEmployee(Employee* emp);
    const std::vector<Employee*> getEmployees() const;
private:
    std::string deptName;
    std::vector<Employee*> employees;
};
#endif // DEPARTMENT_H