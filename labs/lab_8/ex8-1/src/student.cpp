#include "student.h"
//task 1 
// Implement the member functions of the Student class here.

Student::Student(const std::string& aName, int anId, double aGpa) : name{aName}, id{anId}, gpa{aGpa} {};

std::string Student::getName() const{
    return name;
};

void Student::setName(const std::string& aName) {
    name = aName;
};

int Student::getId() const {
    return id;
};

void Student::setId(int anId) {
    id = anId;
};

double Student::getGpa() const {
    return gpa;
};

void Student::setGpa(double aGpa){
    gpa = aGpa;
};
