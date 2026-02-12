#include "employee.h"
Employee::Employee(int id, const std::string& first, const std::string& last)
    : employeeId(id), firstName(first), lastName(last) {}
void Employee::setFirstName(const std::string& first) {
    firstName = first;
}
void Employee::setLastName(const std::string& last) {
    lastName = last;
}
std::string Employee::getFullName() const {
    return firstName + " " + lastName;
}
int Employee::getEmployeeId() const {
    return employeeId;
}
void Employee::setEmployeeId(int id) {
    employeeId = id;
}
std::string Employee::getLastName() const {
    return lastName;
}
std::string Employee::getFirstName() const {
    return firstName;
}
