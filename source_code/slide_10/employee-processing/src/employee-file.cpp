#include "employee-file.h"
#include <fstream>
#include <iostream>
#include <limits>
#include <stdexcept>
bool EmployeeFile::saveEmployeeToFile(const std::vector<Employee>& emp, const std::string& filename) {
    //std::ofstream outFile(filename, std::ios::app);
    std::ofstream outFile(filename, std::ios::out | std::ios::trunc);
    if (!outFile) {
        return false; // Failed to open file
        //throw std::runtime_error("Could not open file for writing");
    }
    for (const Employee& e : emp) {
        outFile << e.getEmployeeId() << " "
                << e.getFirstName() << " "
                << e.getLastName() << "\n";
    }
    outFile.close();
    return true;
}
bool EmployeeFile::readEmployeeFromFile(std::vector<Employee>& emp, const std::string& filename) {
    std::ifstream inFile(filename);
    int id;
    std::string firstName, lastName;
    if (!inFile) {
        return false; // Failed to open file
        //throw std::runtime_error("Could not open file for reading");
    }
    
    while(inFile >> id >> firstName >> lastName) {
        emp.push_back(Employee(id, firstName, lastName));

    }
    
    inFile.close();
    return true;
}