/*
ID: 68011278
Name: Ananda Stallard
Lab No: 1
Question No: 3
Date: 4/December/2025
*/

#include <iostream>
using namespace std;

int main() {
    const float PI {3.14159};
    float radius {0.0};

    while (radius >= 0){
        cout << "Please enter the radius of the circle (end with negative number) ";
        cin >> radius;
        
        if (radius < 0) {
            cout << "Goodbye";
            break;
        } else {
            float area {PI * radius * radius};
            cout << "The area of the circle with radius = " << radius << " is " << area << endl;
        }
    }
}