/*
ID: 68011278
Name: Ananda Stallard
Lab No: 9
Question No: 1
Date: 19 Feb 2026
*/
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdexcept>
#include "employee.h"
#include "number-fields-exception.h"
#include "invalid-file-exception.h"
#include "invalid-input-exception.h"
#include "employee-file.h"
using namespace std;
bool isInteger(const string& str);
bool isDouble(const string& str);
void CleanData(const string& inputfile, const string& outputfile,
        const string& errorLogFile);
void readAndDisplayEmployees(const string& filename);
void readErrorLog(const string& errorLogFile);
int main() {
    string inputfile = "rawemployee.csv";
    string outputfile = "cleanedemployee.csv";
    string errorLogFile = "errorlog.txt";
    CleanData(inputfile, outputfile, errorLogFile);
    readAndDisplayEmployees(outputfile);
    readErrorLog(errorLogFile);
    return 0;
}
bool isInteger(const string& str) {
    if (str.empty()) return false;
    if (str[0] == '-' && str.size() > 1) {
        return str.find_first_not_of("0123456789", 1) == std::string::npos;
    }
    return str.find_first_not_of("0123456789") == std::string::npos;
    
}
bool isDouble(const string& str) {
    if (str.empty()) return false;
    if (str[0] == '-' && str.size() > 1) {
        return str.find_first_not_of("0123456789.", 1) == std::string::npos;
    }
    return str.find_first_not_of("0123456789.") == std::string::npos;
    
}

void CleanData(const string& inputfile, const string& outputfile, 
        const string& errorLogFile) {
    // Implement this function to clean the employee data from the input file and write the cleaned data to the output file.
    // Each line in the input file is expected to be in the format: id,name,salary
    // The function should read each line from the input file, validate the data, 
    //and write the valid lines to the output file in the same format.
    // If a line has an incorrect number of fields, invalid data types, or any other issues, 
    //it should be skipped and an appropriate error message should be written to the error log file.
    // The error message should include the line number and a description of the error.
    // At the end of the function, print a summary of how many lines were processed, 
    // how many were cleaned successfully, and how many had errors.
    // Consult the lab instructions for the expected format of the error messages and summary output.
    
    //task 7
    // open the input file, output file, and error log file. If any of the files cannot be opened, 
    //throw an InvalidFileException with an appropriate message        
    std::ifstream inFile(inputfile);
    if (!inFile) {
        throw InvalidFileException("Can't access from input file.");
    }
    
    std::ofstream outFile(outputfile);
    if (!outFile) {
        throw InvalidFileException("Can't access from output file.");
    }

    std::ofstream logFile(errorLogFile);
    if (!logFile) {
        throw InvalidFileException("Can't access from error log file.");
    }

    //task 8
    // read each line from the input file, validate the data, 
    //and write the valid lines to the output file in the same format.
    // If a line has an incorrect number of fields, invalid data types, or any other issues, 
    //it should be skipped and an appropriate error message should be written to the error log file.
    //---------------------------------------------------------------------------------
    //start with the loop to read each line from the input file and process it. 
    //Use a line counter to keep track of the line numbers for error reporting.
    // skip if the line is empty and continue to the next iteration of the loop.
    // For each line, split the line into fields using a stringstream 
    // put the fields into a vector and check the number of fields. 
    // throw a NumberOfFieldsException if the number of fields is not 3 and 
    // catch it to log the error message with the line number and the issue
    // validate each field  according to the following rules:
    // The id field must be an integer. 
    // use the isInteger function to validate the id field
    // throw an InvalidInputException if the id field is not an integer 
    // and catch it to log the error message with the line number and the issue 
    // The salary field must be a double. 
    // use the isDouble function to validate the salary field
    // throw an InvalidInputException if the salary field is not a double
    // and catch it to log the error message with the line number and the issue
    // If all fields are valid, write the line to the output file in the same format (id,name,salary).
    // Keep track of the number of lines processed, cleaned successfully, and with errors for the summary output.
    // At the end of the function, print a summary of how many lines were processed, 
    // how many were cleaned successfully, and how many had errors.
    // Consult the lab instructions for the expected format of the error messages and summary output.
    int lineNum {0}, cleanedLines {0}, errors {0};
    std::string line;
    std::vector<std::string> fields;

    while (std::getline(inFile, line)) {
        if (line.empty() || line == "\r") continue;
        fields.clear();
        lineNum++;
        try {
            std::istringstream ss(line);
            std::string field;
            
            while (std::getline(ss, field, ',')) {
                if (!field.empty() && field.back() == '\r') field.pop_back();
                fields.push_back(field);
            }

            if (fields.size() != 3){
                throw NumberOfFieldsException("Incorrect number of fields");
            }
            
            if (!isInteger(fields[0])){
                throw InvalidInputException("ID is not an integer");
            }

            if (!isDouble(fields[2])){
                throw InvalidInputException("Salary is not a double");
            }

            outFile << line << endl;
            cleanedLines++;
        }
        catch (const std::exception& e) {
            errors++;
            logFile << "Line " << std::to_string(lineNum) << ": " << e.what() << " - " << line << "\n";
            // continue;
        }
    }  

    cout << std::to_string(cleanedLines) << " out of " << std::to_string(lineNum) << " from " << inputfile << " were written to " << outputfile << ", see " << errorLogFile << " for details.\n";

    //task 9 close all the files
    inFile.close();
    outFile.close();
    logFile.close();
}
void readAndDisplayEmployees(const string& filename) {
    //task 10: Implement this function to read the list of employees from a cleaned file and display their details.
    // Use the EmployeeFile::readEmployeeFromFile function to read the employees from the file.
    // If the file cannot be opened, catch the InvalidFileException and display an error message.
    // If the file is read successfully, display the details of each employee in the following format:
    // Employee Name: <name>
    // Employee ID: <id>
    // Employee Salary: <salary>
    // -----------------------------
    // Replace <name>, <id>, and <salary> with the actual values from the Employee object.
    std::vector<Employee> employees;
    try {
        EmployeeFile::readEmployeeFromFile(employees, filename);
    } catch (const InvalidFileException) {
        throw;
    }

    for (auto e: employees) {
        cout << "\nEmployee Name: " << e.getName() << "\nEmployee ID: " << e.getId() << "\nEmployee Salary: " << e.getSalary() << "\n";
        cout << "\n-------------------------\n";
    }
    cout << endl;
}
void readErrorLog(const string& errorLogFile) {
    //task 11: Implement this function to read and display the contents of the error log file.
    // Open the error log file and read its contents. 
    //If the file cannot be opened, display an error message.
    std::ifstream errorFile(errorLogFile);
    if (!errorFile) {
        throw InvalidFileException("Can't read from error log file.");
    }

    std::string line;

    while (std::getline(errorFile, line)) {
        std::istringstream ss(line);
        cout << line << "\n";
    }
}
