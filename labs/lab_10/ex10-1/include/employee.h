#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include <memory>
//Emplyee is the inverse side of the relationship, 
//so we use a weak pointer to avoid circular references and memory leaks.
class Department; // Forward declaration
class Employee : public std::enable_shared_from_this<Employee> {
public:
    Employee(const std::string& name = "", int id = 0, std::shared_ptr<Department> department = nullptr);
    virtual ~Employee() = default;
    std::string getName() const;
    int getId() const;
    void setName(const std::string& newName);
    void setId(int newId); 
    //task2: declare the setDepartment function, 
    //the parameter is a shared pointer to Department.
    void setDepartment(std::shared_ptr<Department> newDept);

    //task3: declare the getDepartment function, 
    //the return type is a shared pointer to Department.
   std::shared_ptr<Department> getDepartment();

    virtual double calculatePay() const = 0;
private:
    std::string name;
    int id;
    //Department *department;
    //task1: change the raw pointer to a weak pointer 
    //to avoid circular references and memory leaks.
    std::weak_ptr<Department> department;
};
#endif // EMPLOYEE_H