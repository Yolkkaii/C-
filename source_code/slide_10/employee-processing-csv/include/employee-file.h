#ifndef EMPLOYEE_FILE_H
#define EMPLOYEE_FILE_H
#include "employee.h"
#include <fstream>
#include <vector>
class EmployeeFile {
    public:
        static bool saveEmployeeToFile(const std::vector<Employee>& emp, 
            const std::string& filename);
        static bool readEmployeeFromFile(std::vector<Employee>& emp, 
            const std::string& filename);
};
#endif // EMPLOYEE_FILE_H