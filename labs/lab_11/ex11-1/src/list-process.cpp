#include <iostream>
#include <vector>
#include <algorithm>
#include "integer-list.h"

using namespace std;
const int MAX_SIZE = 5;
int main() {
    vector<int> list;
    IntegerList intList(MAX_SIZE, list);
    int count = 1;
    //Get input from user
    intList.getNumbers(count);
    intList.sortList();
    intList.displayList();
}
// int main() {
//     vector<int> list;
//     string input;
//     int count = 1;
//     //enter data to list
//     std::cout << "Enter " << MAX_SIZE << " valid integers in the range [-100, 100] " << std::endl;
//      while (list.size() < MAX_SIZE) {
//         std::cout << "Enter integer " << count << ": ";
//         std::getline(std::cin, input);
//         // Validate input
//         if (input.empty()) {
//             std::cout << "Empty input. Please enter a valid integer." << std::endl;
//             continue;
//         }
//         if ((input[0] == '-' || input[0] == '+') && input.size() > 1) {
//             if (input.find_first_not_of("0123456789", 1) != std::string::npos) {
//                 std::cout << "Invalid input. Please enter a valid integer." << std::endl;
//                 continue;
//             }
//         }
//         else if (input.find_first_not_of("0123456789") != std::string::npos) {
//             std::cout << "Invalid input. Please enter a valid integer." << std::endl;
//             continue;
//         }
//         // Convert input to integer and validate range
//         int number = std::stoi(input);
//         if (number < -100 || number > 100) {
//             std::cout << "Invalid input. Please enter an integer in the range [-100, 100]." << std::endl;
//             continue;
//         }
//         list.push_back(number);
//         count++;
//     }
//     // Sort the list
//     std::sort(list.begin(), list.end());
//     // Display the sorted list
//     std::cout << "List: ";
//     for (int num : list) {
//         std::cout << num << " ";
//     }
//     std::cout << std::endl;
// }