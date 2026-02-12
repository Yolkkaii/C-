#include "student-file.h"
#include "invalid-file-excep.h"
#include <fstream>
#include <sstream>
bool StudentFile::saveStudentToFile(const std::vector<Student>& students, 
        const std::string& filename) {
    //task 6 : Implement this function to save the list of students to a file.
    // Each student's data should be written in a new line in the format:
    // name,id,gpa
    // If the file cannot be opened, throw an InvalidFileException.
    // Return true if the operation is successful.
    std::ofstream outFile(filename, std::ios::out | std::ios::trunc);
    if (!outFile) {
        throw InvalidFileException("Can't read CSV file");
    }

    for (const Student& s : students) {
        outFile << s.getName() << ","
                << s.getId() << ","
                << s.getGpa() << "\n";
    }

    outFile.close();
    return true;
}
bool StudentFile::readStudentFromFile(std::vector<Student>& students, 
    const std::string& filename) {
    //task 7: Implement this function to read the list of students from a file.
    // Each student's data is expected to be in a new line in the format:
    // name,id,gpa
    // If the file cannot be opened, throw an InvalidFileException.
    // Return true if the operation is successful.
    std::ifstream inFile(filename);
    if (!inFile) {
        throw InvalidFileException("Can't read CSV file");
    }

    std::string line;
    while (std::getline(inFile, line)) { //While there are more lines to read (?)
        std::istringstream ss(line);
        std::string nameStr, idStr, gpaStr;
        if (std::getline(ss, nameStr, ',') &&
            std::getline(ss, idStr, ',') &&
            std::getline(ss, gpaStr)) {
            int id = std::stoi(idStr);
            double gpa = std::stod(gpaStr);
            students.push_back(Student(nameStr, id, gpa));
        }
    }
    inFile.close();
    return true;
}