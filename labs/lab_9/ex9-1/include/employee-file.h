#ifndef EMPLOYEE_FILE_H
#define EMPLOYEE_FILE_H
#include <string>
#include "employee.h"
#include <vector>
class EmployeeFile {
public:
   static bool saveEmployeeToFile(const std::vector<Employee>& employees, 
            const std::string& filename);
    static bool readEmployeeFromFile(std::vector<Employee>& employees, 
        const std::string& filename);
};
#endif // EMPLOYEE_FILE_H