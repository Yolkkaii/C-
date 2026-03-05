#include "integer-list.h"
#include <iostream>
#include <vector>
#include <algorithm>

IntegerList::IntegerList(int maxSize, std::vector<int> list) : maxSize(maxSize), list(list) {};

int IntegerList::getNumbers(int count) {
    std::string input;
    std::cout << "Enter " << maxSize << " valid integers in the range [-100, 100] " << std::endl;
    while (list.size() < maxSize) {
        std::cout << "Enter integer " << count << ": ";
        std::getline(std::cin, input);
        if (validateNumber(input) == false || checkRange(input) == false) {
            continue;
        } else {
            addToList(std::stoi(input));
            count++;
        }
    }
}

bool IntegerList::validateNumber(std::string input) {
    // Validate input
    if (input.empty()) {
        std::cout << "Empty input. Please enter a valid integer." << std::endl;
        return false;
    }
    if ((input[0] == '-' || input[0] == '+') && input.size() > 1) {
        if (input.find_first_not_of("0123456789", 1) != std::string::npos) {
            std::cout << "Invalid input. Please enter a valid integer." << std::endl;
            return false;
        }
    }
    else if (input.find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "Invalid input. Please enter a valid integer." << std::endl;
        return false;
    }
    return true;
}

bool IntegerList::checkRange(std::string input) {
    // Convert input to integer and validate range
    int number = std::stoi(input);
    if (number < -100 || number > 100) {
        std::cout << "Invalid input. Please enter an integer in the range [-100, 100]." << std::endl;
        return false;
    }
    return true;
}

void IntegerList::addToList(int number) {
    list.push_back(number);
}

void IntegerList::sortList() {
    std::sort(list.begin(), list.end());
}

void IntegerList::displayList() {
    std::cout << "List: ";
    for (int num : list) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}