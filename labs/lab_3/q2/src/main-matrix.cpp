/*
    Name: 
    Lab No: 3
    Question No: 2
    Date: Dec 25, 2025 
*/
#include <iostream>
#include <string>
#include "matrix.hpp"
using namespace std;
string getInput(string prompt);
//task9: 
//Declare the function prototypes for the following functions:
//1. fillMatrix: This function takes a Matrix object as input and fills it with user-provided values.
//2. printMatrix: This function takes a Matrix object as input and prints its contents to the console.
//3. printArray: This function takes an array of integers and its size as input and prints the array elements to the console.

int main() {
    int rows = stoi(getInput("Enter number of rows: "));
    int cols = stoi(getInput("Enter number of columns: "));
    //task10: 
    // Create a Matrix object with the specified number of rows and columns
    
    //taks11: 
    // Use the fillMatrix function to fill the matrix with user-provided values
    
    cout << "The matrix is:" << endl;
    //task12: 
    // Use the printMatrix function to display the matrix
    
    //task13: 
    // Use the getMaxInEachMatrixRow function to get an array of maximum values in each row 
    

    cout << "Maximum in each row:" << endl;
    //task14: 
    // Use the printArray function to display the array of maximum values
    
    //task15: 
    // Deallocate the memory used for the array of maximum values
    
    return 0;
}
void fillMatrix(Matrix &matrix) {
    //task16: 
    // Fill the given matrix with user-provided values
    // Use the getInput function to get user input for each element
    // Hint: You can use nested loops to iterate through each element of the matrix
    // and set its value using the set method of the Matrix class.
    
}
string getInput(string prompt) {
    cout << prompt;
    string input;
    getline(cin, input);
    return input;
}
void printMatrix(const Matrix &matrix) {
    //task17: 
    // Print the contents of the given matrix to the console
    // Use the get method of the Matrix class to access each element
    // Hint: You can use nested loops to iterate through each element of the matrix.
    
}
void printArray(const int arr[], int size) {
    //task18:
    // Print the elements of the given array to the console
    // Hint: Use a loop to iterate through the array and print each element.
    //you can consult the code in lab2 question 2 (function printArray) for reference.
    
}