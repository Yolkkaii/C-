#include "student.h"
#include <string>
//part A
//task1-A
//Implement the member functions of the Student class here
//Refer to the declarations in student.h for function signatures
//There are 4 member functions and 1 constructor to implement for part A
//Your code here
Student::Student(const std::string& aName, int anId) 
    : name(aName), id(anId){}

std::string Student::getName() const{
    return name;
}

void Student::setName(const std::string& aName){
    name = aName;
}

int Student::getId() const {
    return id;
}

void Student::setId(int anId){
    id = anId;
}

//part C
//task3-C
//Implement the member functions related to courses here
//Refer to the declarations in student.h for function signatures
//There are 2 member functions to implement for part C
//Make sure to update the courses list correctly
//Your code here
std::vector<Course*> Student::getCourses() const{
    return courses;
}

void Student::addCourse(Course* course) {
    courses.push_back(course);
}
