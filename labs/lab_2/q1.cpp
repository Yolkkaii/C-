/*
ID: 68011278
Name: Ananda Stallard
Lab No: 2
Question No: 1
Date: 18 Dec 2025
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//define function prototypes for to_uppercase and replace_first
//1. to_uppercase: converts a string to uppercase, 
// returns the uppercase string, the orginal string remains unchanged

string to_uppercase(string s);

//2. replace_first: replaces only the FIRST occurrence of a substring with another substring,
// returns the modified string, the original string remains unchanged

string replace_first(string s, string sub_1, string sub_2);

int main() {
    string text = "I love learning Python with Python tutorials using Google Colab.";

    // Step 1: Convert to uppercase
    // 3. Call the to_uppercase function, 
    //store the result in a new string variable named upper_string
    // Print the uppercase strings, including appropriate messages.

    string upper_string = to_uppercase(text);
    cout << upper_string << "\n";

    // Step 2: Replace the first occurrence of 'PYTHON' with 'PROGRAMMING'
    // 4. Call the replace_first function,
    // store the result in a new string variable named replaced_string
    // Print the modified string with an appropriate message

    string replaced_string = replace_first(upper_string, "PYTHON", "PROGRAMMING");
    cout << replaced_string << "\n";
    
    // Step 3: Check whether "Google" is in the string
    //5 . Use an if statement to check if "Google" (case-sensitive)
    // is present in replaced_string
    
    cout << "Is \"Google\" in the above string?\n";
    auto pos = replaced_string.find(to_uppercase("Google"));

    if (pos == string::npos) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}

// Function to convert a string to uppercase
//6. Define the to_uppercase function
string to_uppercase(string s){
    string upper;
    // for (char c : s){ // Method using ASCII code
    //     if ((c - 32) >= 65 && (c - 32) <= 90){
    //         upper += c - 'a' + 'A';
    //     }else{
    //         upper += c;
    //     }
    // }
    // return upper;

    transform(s.begin(), s.end(), s.begin(), ::toupper);
    return s;
}

// Function to replace only the FIRST occurrence
//7. Define the replace_first function
string replace_first(string s, string sub_1, string sub_2){
    auto p = s.find(sub_1);
    if (p != string::npos) s.replace(p, sub_1.length(), sub_2);
    return s;
}