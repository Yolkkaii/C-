/*
ID:
Name:
Lab No: 5
Question No: 1
Date: 15 Jan 2026
*/
#include <iostream>
#include "student.h"
#include "course.h"
#include <string>
#include <vector>
using namespace std;
//Function prototypes
//part A
//uncomment the following 2 function prototypes for part A
void sampleStudents (vector<Student> &students);
void printStudents(const vector<Student>& students);

//part B
//uncomment the following 2 function prototypes for part B
//void sampleCourses(vector<Course> &courses);
//void printCourses(const vector<Course>& courses);

//part C
//uncomment the following function prototypes for part C
//bool duplicateEnrollment(const Student& student, const Course& course);
//int courseMenu(const vector<Course>& courses);
//void enrollStudentInCourse(vector<Student>& students, vector<Course>& courses);
//void printEnrolledCourses(const vector<Student>& students);
//void printEnrolledStudents(const vector<Course>& courses);

void sampleStudents (vector<Student> &students) {
    //part A
    //task2-A
    //Fill in a vector of at least 4 sample Student objects
    //your code here
    students.reserve(4);
    students.emplace_back("John", 101);
    students.emplace_back("Jane", 102);
    students.emplace_back("Mark", 103);
    students.emplace_back("Lincoln", 104);
}
void printStudents(const vector<Student>& students) {
    //part A
    //task3-A
    //Print the details of each student in the provided vector
    //your code here   
    for (const auto& student : students){
        cout << "Name: " << student.getName() << ", ID: " << student.getId() << endl;
    }
    cout << endl;
}
void sampleCourses(vector<Course> &courses) {
    //part B
    //task2-B
    //Fill in a vector of at least 4 sample Course objects
    //your code here
    courses.reserve(4);
    courses.emplace_back("Discrete Mathematics", 10101);
    courses.emplace_back("Differential Equations", 10102);
    courses.emplace_back("Digital System Fundamentals", 10103);
    courses.emplace_back("Object Oriented Programming", 10104);
    
}
void printCourses(const vector<Course>& courses) {
    //part B
    //task3-B
    //Print the details of each course in the provided vector
    //your code here
    for (const auto& course: courses) {
        cout << "Course name: " << course.getCourseName() << ", Course ID: " << course.getCourseCode() << endl;
    }
    cout << endl;
}
bool duplicateEnrollment(const Student& student, const Course& course) {
    //part C
    //task7-C
    //Check if the student is already enrolled in the given course
    //Return true if the student is already enrolled, false otherwise
    //Hint: use the getCourses() member function of the Student class
    // and compare course codes to determine if the course is already in the student's list
    //use the getCourseCode() member function of the Course class
    //use a loop to iterate through the student's courses
    //or use std::find algorithm from <algorithm> header
    
    //your code here
    std::vector<Course*> courses = student.getCourses();

    for (auto c : courses){
        if (c->getCourseCode() == course.getCourseCode()){
            return true;
        }
    }
    return false;
}
int courseMenu(const vector<Course>& courses) {
    //part C
    //task8-C
    //Display the list of available courses and prompt the user to select one
    //Return the index of the selected course (1-based index)
    //Return 0 if the user wants to finish enrollment
    //Hint: iterate through the courses vector to display course names and codes
      
    //your code here
    int index {0};
    cout << "Available Courses : \n";

    for (auto course : courses){
        cout << index + 1 << ". " << "Course name : " << course.getCourseName() << " Course code: " << course.getCourseCode() << endl;
        index++;
    }
    
    cout << "Enter 0 to stop enrolling" << endl;

    int choice;

    cout << "Course to enroll in : ";
    cin >> choice;

    cout << endl;

    return choice;
}
void enrollStudentInCourse(vector<Student>& students, vector<Course>& courses) {
    //part C
    //task9-C
    //For each student, allow them to enroll in multiple courses
    //iterate through the students vector
    //For each student, repeatedly display the course menu using courseMenu function
    //Check for duplicate enrollments using the duplicateEnrollment function
    //Update both the student's and the course's enrollment lists upon successful enrollment
    //Provide appropriate prompts and messages to the user
    //Note: you need to check if the students and courses vectors are not empty before proceeding
    //Refer to the sample interaction provided in the lab document for guidance
    
    //your code here
    for (int i = 0; i < students.size(); i++) {
        Student& student = students[i];
        cout << "Name: " << student.getName() << ", ID: " << student.getId() << endl;
        
        int choice {1};
        do {
            choice = courseMenu(courses);
            
            if (choice == 0) break;
            
            
            int courseIndex = choice - 1;
            
            if (duplicateEnrollment(student, courses[courseIndex])) {
                cout << "You are already enrolled in this course" << endl;
            } else {
                Course* course = &courses[courseIndex];
                student.addCourse(course);
                course->addStudent(&student);
                cout << "Enrollment successful!" << endl;
            }
            cout << endl;
            
        } while (choice != 0);
    }
    cout << endl;
}

void printEnrolledCourses(const vector<Student>& students) {
    //part C
    //task10-C
    //Print the list of courses each student is enrolled in
    //iterate through the students vector
    //Hint: use the getCourses() member function of the Student class
    //and the getCourseName() and getCourseCode() member functions of the Course class
    //your code here
    for (const auto student : students){
        cout << "Name: " << student.getName() << ", ID: " << student.getId() << endl;
        auto courses = student.getCourses();
        for (const auto course : courses){
            cout << "Course name : " << course->getCourseName() << ", Course code : " << course->getCourseCode() << endl;
        }
        cout << endl;
    }
    cout << endl;
}
void printEnrolledStudents(const vector<Course>& courses) {
    //part C
    //task11-C
    //Print the list of students enrolled in each course
    //iterate through the courses vector
    //Hint: use the getEnrolledStudents() member function of the Course class
    //and the getName() and getId() member functions of the Student class
    //your code here   
    for (const auto course : courses){
        cout << "Course name : " << course.getCourseName() << ", Course code : " << course.getCourseCode() << endl;
        auto students = course.getEnrolledStudents();
        for (const auto student : students){
            cout << "Name: " << student->getName() << ", ID: " << student->getId() << endl;
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    //part A
    //task4-A
    //Create sample students and courses
    //using the sampleStudents() function
    //then print them using printStudents() function
    //this is to verify that your Student class implementation is correct
    //your code here
    vector<Student> students;
    sampleStudents(students);
    printStudents(students);
    
    //part B
    //task4-B
    //Create sample courses and students
    //using the sampleCourses() function
    //then print them using printCourses() function
    //this is to verify that your Course class implementation is correct
    //your code here
    vector<Course> courses;
    sampleCourses(courses);
    printCourses(courses);

    //part C
    //task12-C
    //Enroll students in courses and print the enrollment details
    //First, enroll students in courses using enrollStudentInCourse() function
    //Then, print the enrolled courses for each student using printEnrolledCourses() function
    //Finally, print the enrolled students for each course using printEnrolledStudents() function
    //your code here
    enrollStudentInCourse(students, courses);
    printEnrolledCourses(students);
    printEnrolledStudents(courses);
    
    return 0;
}