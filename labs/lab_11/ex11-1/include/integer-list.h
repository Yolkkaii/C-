#ifndef INTEGERLIST_H
#define INTEGERLIST_H
#include <iostream>
#include <vector>
#include <algorithm>

class IntegerList {
public:
    IntegerList(int maxSize = 1, std::vector<int> list = {});
    int getNumbers(int count);
    bool validateNumber(std::string input);
    bool checkRange(std::string input);
    void addToList(int number);
    void sortList();
    void displayList();
private:
    int maxSize;
    std::vector<int> list;
};

#endif