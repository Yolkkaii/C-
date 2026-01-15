#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <vector>
#include "course.h"
class Student {
public:
    //part A
    //The following are the declarations you need to implement for part A in the file student.cpp
    
    Student(const std::string& aName="", int anId=0);
    std::string getName() const;
    void setName(const std::string& aName); 
    int getId() const;
    void setId(int anId);

    //part C
    //You comeback to this part after finish implmenting the part B
    //task2-C
    //declare the member functions related to courses here
    //Refer to course.h for the Course class declaration
    //There are 2 member functions to declare for part E
    //The first function is to get the list of courses the student is enrolled in
    //The second function is to add a course to the student's list of courses
    //The first function should return a vector of pointers to Course objects
    //The second function should take a pointer to a Course object as parameter
    //The first function's name is getCourses
    //The second function's name is addCourse
    //Your code here 
    std::vector<Course*> getCourses() const;
    void addCourse(Course* course);
    
private:
    //part A
    std::string name;
    int id;

    //part C
    //You comeback to this part after finish implmenting the part D
    //task1-C
    //Add the data member to store the courses the student is enrolled in
    //the data member should be a vector of pointers to Course objects
    //Refer to course.h for the Course class declaration
    //The data member's name is courses
    //Your code here
    std::vector<Course*> courses;
    
};
#endif // STUDENT_H