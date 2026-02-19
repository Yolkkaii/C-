#include "employee-file.h"
#include "invalid-file-exception.h"
#include <fstream>
#include <sstream>
bool EmployeeFile::saveEmployeeToFile(const std::vector<Employee>& employees, 
        const std::string& filename) {
    //task 2 : Implement this function to save the list of employees to a file.
    // Each employee's data should be written in a new line in the format:
    // id,name, salary   
    // If the file cannot be opened, throw an InvalidFileException.
    // Return true if the operation is successful.
    // you may not use this function in this lab, but you can implement it for future use.
    // consult the previous labs for how to write to a file in C++ and how to throw exceptions.
    // You may use it to write the file to test your readEmployeeFromFile function 
    // by first writing a file with some employee data and then reading it back.
    std::ofstream outFile(filename, std::ios::out | std::ios::trunc);
    if (!outFile) {
        throw InvalidFileException("Can't read CSV file.");
    }

    for (const Employee& e: employees) {
        outFile << e.getId() << ","
                << e.getName() << ","
                << e.getSalary() << "\n";
    }

    outFile.close();
    return true;
}

bool EmployeeFile::readEmployeeFromFile(std::vector<Employee>& employees, 
    const std::string& filename) {
    //task 3: Implement this function to read the list of employees from a file.
    // Each employee's data is expected to be in a new line in the format:
    // id,name,salary   
    // If the file cannot be opened, throw an InvalidFileException.
    // If the file is read successfully, populate the employees vector with 
    // the data and return true.
    // Return true if the operation is successful.
    // consult the previous labs for how to read from a file in C++ and how to throw exceptions.
    std::ifstream inFile(filename);
    if (!inFile) {
        throw InvalidFileException("Can't read CSV file.");
    }

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream ss(line);
        std::string nameStr, idStr, salaryStr;
        if (std::getline(ss, idStr, ',') &&
            std::getline(ss, nameStr, ',') &&
            std::getline(ss, salaryStr)) {
            int id = std::stoi(idStr);
            double salary = std::stod(salaryStr);
            employees.push_back(Employee(nameStr, id, salary));
        }
    }

    inFile.close();
    return true;
}