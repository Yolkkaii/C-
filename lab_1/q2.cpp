/*
ID: 68011278
Name: Ananda Stallard
Lab No: 1
Question No: 2
Date: 4/December/2025
*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    int score {100};

    while (score != 0){
        cout << "Enter score end with 0: ";
        cin >> score;

        string grade;

        if (score >= 80){
            grade = "A";
        } else if (score >= 75){
            grade = "B+";
        } else if (score >= 70){
            grade = "B";
        } else if (score >= 65){
            grade = "C+";
        } else if (score >= 60){
            grade = "C";
        } else if (score >= 55){
            grade = "D+";
        } else if (score >= 50){
            grade = "D";
        } else {
            grade = "F";
        }

        if (score == 0) {
            cout << "Goodbye";
            break;
        } else {
            cout << "score = " << score << " grade = " << grade << endl;
        }
    }
}
