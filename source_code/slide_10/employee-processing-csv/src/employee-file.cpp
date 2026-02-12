#include "employee-file.h"
#include <fstream>
#include <sstream>
bool EmployeeFile::saveEmployeeToFile(const std::vector<Employee>& emp, const std::string& filename) {
    //std::ofstream outFile(filename, std::ios::app);
    std::ofstream outFile(filename, std::ios::out | std::ios::trunc);
    if (!outFile) {
        return false; // Failed to open file
    }
    for (const Employee& e : emp) {
        outFile << e.getEmployeeId() << ","
                << e.getFirstName() << ","
                << e.getLastName() << "\n";
    }
    outFile.close();
    return true;
}
bool EmployeeFile::readEmployeeFromFile(std::vector<Employee>& emp, const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        return false; // Failed to open file
    }
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string idStr, firstName, lastName;
        if (std::getline(ss, idStr, ',') &&
            std::getline(ss, firstName, ',') &&
            std::getline(ss, lastName)) {
            int id = std::stoi(idStr);
            emp.push_back(Employee(id, firstName, lastName));
        }
    }
    /*std::string line;
    while (std::getline(inFile, line)) {
        size_t pos1 = line.find(',');
        size_t pos2 = line.find(',', pos1 + 1);
        if (pos1 == std::string::npos || pos2 == std::string::npos) {
            continue; // Malformed line
        }
        int id = std::stoi(line.substr(0, pos1));
        std::string firstName = line.substr(pos1 + 1, pos2 - pos1 - 1);
        std::string lastName = line.substr(pos2 + 1);
        emp.push_back(Employee(id, firstName, lastName));
    }*/
    inFile.close();
    return true;
}