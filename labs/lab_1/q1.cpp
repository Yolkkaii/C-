/*
ID: 68011278
Name: Ananda Stallard
Lab No: 1
Question No: 1
Date: 4/December/2025
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string fullName;
    int age {0};
    int weight {0};

    cout << "Enter first name and last name, separated by space ";
    getline(cin, fullName);
    
    cout << "Enter age and weight, separated by spaces ";
    cin >> age >> weight;

    cout << "Name: " << fullName << endl;
    cout << "Age: " << age << endl;
    cout << "Weight: " << weight << endl;
}