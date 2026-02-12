#include <iostream>
#include <fstream>

int main() {
    // 1. Create and Open
    //std::ofstream outFile("example.txt");
    //std::ofstream outFile("example.txt", std::ios::out);
    std::ofstream outFile("example.txt", std::ios::app);
    // 2. Check for success
    if (outFile.is_open()) {
        outFile << "Line 1: Hello C++ File Processing!\n";
        outFile << "Line 2: Teaching data science students.\n";
        
        // 3. Close
        outFile.close();
        std::cout << "File written successfully." << std::endl;
    } else {
        std::cerr << "Error: Could not open file for writing." << std::endl;
    }
    return 0;
}