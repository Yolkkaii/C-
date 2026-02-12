#ifndef STUDENT_FILE_H
#define STUDENT_FILE_H
#include <string>
#include "student.h"
#include <vector>
class StudentFile {
public:
   static bool saveStudentToFile(const std::vector<Student>& students, 
            const std::string& filename);
    static bool readStudentFromFile(std::vector<Student>& students, 
        const std::string& filename);
};
#endif // STUDENT_FILE_H