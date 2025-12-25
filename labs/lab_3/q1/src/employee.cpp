#include <iostream>
#include "employee.hpp"
using namespace std;
 
//complete the function definitions here
//task3 
//complete the constructor
Employee::Employee(const string& name, int id, double salary) : name(name), id(id), salary(salary) {}

//task4
//complete the getter and setter functions
const string& Employee::getName() const{
    return name;
}
int Employee::getID() const {
    return id;
}
double Employee::getSalary() const {
    return salary;
}

void Employee::setName(const string& name_in){
    name = name_in;
}
void Employee::setID(int id_in){
    id = id_in;
}
void Employee::setSalary(double salary_in){
    salary = salary_in;
}
