/*
    ID: 68011278
    Name: Ananda Stallard
    Lab No: 8
    Question No: 1
    Date: Feb 13, 2026
*/
#include <iostream>
#include "input.h"
#include "student.h"
#include "student-file.h"
#include "invalid-input-excep.h"
#include "invalid-file-excep.h"
#include <string>
#include <vector>
using namespace std;

void inputStudentInfo(vector<Student> &students);
void printStudentInfo(const vector<Student> &students);
void writeStudentFile(const vector<Student> &students, string fileName);
void readStudentFile(vector<Student> &students, string fileName);

int main() {
    std::string filename = "students.csv";
    vector<Student> students;
    inputStudentInfo(students);
    printStudentInfo(students);

    cout << "Writing to student.csv" << endl;
    //task 10: Use try-catch blocks to handle InvalidFileException
    //when calling writeStudentFile
    try {
        writeStudentFile(students, filename);
        // cout << "Students read from " << filename << ":\n";
        // printStudentInfo
    } catch (const InvalidFileException& e) {
        cout << "Error: " << e.what() << endl;
    }

    students.clear();
    cout << "Reading from student.csv" << endl;
    // task 11: Use try-catch blocks to handle InvalidFileException
    // when calling readStudentFile
    try {
        readStudentFile(students, filename);
        // cout << "Students read from " << filename << ":\n";
        // printStudentInfo
    } catch (const InvalidFileException& e) {
        cout << "Error: " << e.what() << endl;
    }

    printStudentInfo(students);
    students.clear();

    return 0;
}
void inputStudentInfo(vector<Student> &students) {
    //task 12: Implement this function to input student information
    // from the user until a student with a non-positive id is entered.
    // Use the Input class to get inputs and handle InvalidInputException
    // for invalid inputs.
    // Store the valid Student objects in the students vector.
    // Hint: Use a loop to repeatedly get student details.
    // Break the loop when a non-positive id is entered.
    // For each student, get the name, id, and gpa.
    // Use try-catch blocks to handle invalid inputs for id and gpa.
    // If an input is invalid, display an error message and prompt again.
    // Example:
    // Enter student Id end with 0 or negative: abc
    // Invalid input for Id. Please enter an integer.
    // Enter student Id end with 0 or negative: 101
    // Enter student name: John Doe
    // Enter student GPA: xyz
    // Invalid input for GPA. Please enter a number.
    // Enter student GPA: 3.5
    // (repeat until non-positive id is entered)
    std::string name;
    int id;
    double gpa;

    std::string idPrompt = "Enter student Id end with 0 or negative:";
    std::string namePrompt = "Enter student's name: ";
    std::string gpaPrompt = "Enter student's GPA: ";

    while (true) {
        try {
            id = Input::getInt(idPrompt);
        } catch (const InvalidInputException& e) {
            cout << e.what() << endl;
            continue;
        }
        if (id <= 0) {
            break;
        }

        cout << namePrompt;
        std::getline(cin >> std::ws, name);

        try {
            gpa = Input::getDouble(gpaPrompt);
        } catch (const InvalidInputException& e) {
            cout << e.what() << endl;
            continue;
        }
        
        students.push_back(Student(name, id, gpa));
    }
}
void printStudentInfo(const vector<Student> &students) {
    cout << "Student Information:" << endl;
    for (const auto& student : students) {
        cout << "ID: " << student.getId()
             << ", Name: " << student.getName()
             << ", GPA: " << student.getGpa() << endl;
    }
}
void writeStudentFile(const vector<Student> &students, string fileName) {
    //task 13: Implement this function to write student information
    // to a file using the StudentFile class.
    // Handle InvalidFileException when calling the saveStudentToFile method.
    // rethrow the exception to be handled in main.
    try {
        StudentFile::saveStudentToFile(students, fileName);
    } catch (const InvalidFileException& e) {
        throw;
    }
}   
void readStudentFile(vector<Student> &students, string fileName) {
    //task 14: Implement this function to read student information
    // from a file using the StudentFile class.
    // Handle InvalidFileException when calling the readStudentFromFile method.
    // Rethrow the exception to be handled in main.
    try {
        StudentFile::readStudentFromFile(students, fileName);
    } catch (const InvalidFileException& e) {
        throw;
    }
}