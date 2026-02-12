#include <iostream>
#include <fstream>
#include <string>

int main() {
    //std::ifstream inFile("example.txt");
    std::ifstream inFile("example.txt", std::ios::in);
    std::string line;

    if (inFile.is_open()) {
        // Read until end of file (EOF)
        while (std::getline(inFile, line)) {
            std::cout << "Read from file: " << line << std::endl;
        }
        inFile.close();
    } else {
        std::cerr << "Unable to open file for reading." << std::endl;
    }
    return 0;
}