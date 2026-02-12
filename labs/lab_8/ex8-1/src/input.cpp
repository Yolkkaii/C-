#include "input.h"
#include <limits>
#include <stdexcept>
#include <iostream>
#include "invalid-input-excep.h"
// Implement the member functions of the Input class here.
void Input::clearInputStream() {
    //task 2: Implement this function to clear the input stream
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}
std::string Input::getString(const std::string& prompt) {
    //task 3: Implement this function to get a string input from the user
    // and return it. Use the prompt parameter to display a message to the user.
    std::string value;
    std::cout << prompt;
    std::cin >> value;

    clearInputStream();
    return value;
}
int Input::getInt(const std::string& prompt) {
    //task 4: Implement this function to get an integer input from the user
    // and return it. Use the prompt parameter to display a message to the user.
    // If the input is invalid, throw an InvalidInputException.
    // Hint: Use std::cin.fail() to check for invalid input.
    // Also, remember to clear the input stream after reading.
    int value;
    std::cout << prompt;
    std::cin >> value;
   
    if (std::cin.fail()) {
        clearInputStream();
        throw InvalidInputException("Invalid integer input");
    }

    clearInputStream();
    return value;
}
double Input::getDouble(const std::string& prompt) {
    //task 5: Implement this function to get a double input from the user
    // and return it. Use the prompt parameter to display a message to the user.
    // If the input is invalid, throw an InvalidInputException.
    // Hint: Use std::cin.fail() to check for invalid input.
    // Also, remember to clear the input stream after reading.
    double value;
    std::cout << prompt;
    std::cin >> value;
   
    if (std::cin.fail()) {
        clearInputStream();
        throw InvalidInputException("Invalid double input");
    }

    clearInputStream();
    return value;
}