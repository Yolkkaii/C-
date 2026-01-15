#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
//uncomment the following line when you start implementing part C
class Student; // Forward declaration
class Course {
public:
    //part B
    //The following are the declarations you need to implement for part B in the file course.cpp
    Course(const std::string& courseName="", int courseCode=0);
    std::string getCourseName() const;
    void setCourseName(const std::string& courseName); 
    int getCourseCode() const;
    void setCourseCode(int courseCode);

    //part C
    //You comeback to this part after finish implmenting the part B
    //task5-C
    //declare the member functions related to students here
    //Refer to student.h for the Student class declaration
    //There are 2 member functions to declare for part C
    //The first function is to get the list of students enrolled in the course
    //The second function is to add a student to the course's list of enrolled students
    //The first function should return a vector of pointers to Student objects
    //The second function should take a pointer to a Student object as parameter
    //The first function's name is getEnrolledStudents
    //The second function's name is addStudent
    //Your code here
    std::vector<Student*> getEnrolledStudents() const;
    void addStudent(Student* student);
    
private:
    //part B
    std::string courseName;
    int courseCode;
    //part C
    //You comeback to this part after finish implmenting the part D
    //task4-C
    //Add the data member to store the students enrolled in the course
    //the data member should be a vector of pointers to Student objects
    //Refer to student.h for the Student class declaration
    //The data member's name is enrolledStudents
    //Your code here
    std::vector<Student*> enrolledStudents;
    
};
#endif // COURSE_H