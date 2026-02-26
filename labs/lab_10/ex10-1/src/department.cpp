#include "department.h"
#include "employee.h"
#include <string>
#include <memory>
#include <iostream>
using namespace std;
//task6: implement the functions declared in the Department class
Department::Department(const std::string& deptName) : deptName(deptName) {};

std::string Department::getDeptName() const {
    return deptName;
}

void Department::setDeptName(const std::string& newDeptName) {
    deptName = newDeptName;
}

void Department::addEmployee(std::shared_ptr<Employee> emp) {
    if (std::find(employees.begin(), employees.end(), emp) == employees.end()){
        employees.push_back(emp);
        emp->setDepartment(shared_from_this());
    } else {
        return;
    }
}

void Department::removeEmployee(std::shared_ptr<Employee> emp) {
    auto e = std::find(employees.begin(), employees.end(), emp);
    if (e == employees.end()){
        return;
    } else {
        employees.erase(e);
        emp->setDepartment(nullptr);
    }
}

void Department::transferEmployee(std::shared_ptr<Employee> emp, std::shared_ptr<Department> dept) {
    removeEmployee(emp);
    dept->addEmployee(emp);
}

std::vector<std::shared_ptr<Employee>> Department::getEmployees() {
    return employees;
}
