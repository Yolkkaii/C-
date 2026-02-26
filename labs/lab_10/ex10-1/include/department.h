#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <string>
#include <vector>
#include <memory>
//Department is the owning side of the relationship,
//so we use shared pointers to manage the lifetime of Employee objects.
class Employee;  // Forward declaration
class Department : public std::enable_shared_from_this<Department> {
public:
    Department(const std::string& deptName="");
    std::string getDeptName() const;
    void setDeptName(const std::string& newDeptName);
    //task5: declare the addEmployee, removeEmployee, transferEmployee, 
    //and getEmployees functions to manage the employees in the department.
    //addEmployee function takes a shared pointer to Employee as a parameter 
    //and adds it to the department's employee list.
    //removeEmployee function takes a shared pointer to Employee as a parameter 
    //and removes it from the department's employee list.
    //transferEmployee function takes a shared pointer to Employee 
    //and a shared pointer to the new Department
    //as parameters, removes the employee from the current department 
    //and adds it to the new department.
    //getEmployees function returns a vector of shared pointers to Employee representing the employees in the department.
    void addEmployee(std::shared_ptr<Employee> emp);
    void removeEmployee(std::shared_ptr<Employee> emp);
    void transferEmployee(std::shared_ptr<Employee> emp, std::shared_ptr<Department> dept);
    std::vector<std::shared_ptr<Employee>> getEmployees();

private:
    std::string deptName;
    //task4: declare a vector of shared pointers to Employee 
    //to store the employees in the department.
    std::vector<std::shared_ptr<Employee>> employees;
    
};
#endif // DEPARTMENT_H