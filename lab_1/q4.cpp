/*
ID: 68011278
Name: Ananda Stallard
Lab No: 1
Question No: 4
Date: 4/December/2025
*/

#include <iostream>
using namespace std;

int main() {
    const float PI {3.14159};
    int choice {1};

    do {
        cout << "1.Circle\n2.Rectangle\n3.Triangle\n0.Exit\n";
        cin >> choice;

        float area {0.0};

        float radius {0.0};

        float length {0.0};
        float width {0.0};

        float base {0.0};
        float height {0.0};

        switch (choice){
            case 1:
                cout << "Enter the radius of the circle: ";
                cin >> radius;

                area = PI * radius * radius;
                cout << "The area of the circle with radius = " << radius << " is " << area << endl;
                break;
            case 2:
                cout << "Enter the length of the rectangle: ";
                cin >> length;

                cout << "Enter the width of the rectangle: ";
                cin >> width;

                area = length * width;
                cout << "The area of the rectangle with length " << length << " and width " << width << " is " << area << endl;
                break;
            case 3:
                cout << "Enter the base of the triangle: ";
                cin >> base;

                cout << "Enter the height of the triangle: ";
                cin >> height;

                area = 0.5 * base * height;

                cout << "The area of the triangle with base " << base << " and height " << height << " is " << area << endl;
                break;
            case 0:
                cout << "Exiting the program";
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 0);
}