#include "course.h"
#include <string>
//part B
//task1-B
//Implement the member functions of the Course class here
//Refer to the declarations in course.h for function signatures
//There are 4 member functions and 1 constructor to implement for part B
//Your code here
Course::Course(const std::string& courseName, int courseCode) 
    : courseName(courseName), courseCode(courseCode){}

std::string Course::getCourseName() const{
    return courseName;
}

void Course::setCourseName(const std::string& courseName){
    this->courseName = courseName;
}

int Course::getCourseCode() const{
    return courseCode;
}

void Course::setCourseCode(int courseCode) {
    this->courseCode = courseCode;
}

//part C
//You comeback to this part after finish implmenting the part B
//task6-C
//Implement the member functions related to students here
//Refer to the declarations in course.h for function signatures
//There are 2 member functions to implement for part C
//Make sure to update the enrollment list correctly
//Your code here
std::vector<Student*> Course::getEnrolledStudents() const{
    return enrolledStudents;
}

void Course::addStudent(Student* student){
    enrolledStudents.emplace_back(student);
}
