/*
ID: 68011278
Name: Ananda Stallard
Lab No: 4
Question No: 1 
Date: 8 January 2025
*/
#include <iostream>
#include <string>
#include "matrix.h"
using namespace std;
// Function prototypes
template<typename T>
void fillMatrix(Matrix<T> &matrix);
template<typename T>
void printMatrix(const Matrix<T> &matrix);
template<typename T>
void printVector(const vector<T> &vec);
int main() {
    int rows, cols; 
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    //task8
    // Create a Matrix object of type int with the specified rows and columns
    Matrix<int> matrix(rows, cols);

    //task9
    // Fill the matrix with user input, calling fillMatrix function
    fillMatrix(matrix);
    cout << "The matrix is:" << endl;
    //task10
    // Print the matrix, calling printMatrix function
    printMatrix(matrix);

    //task11
    // Get the maximum element from each row, calling getMaxInEachMatrixRow function
    vector<int> maxInEachRow = matrix.getMaxInEachMatrixRow();

    cout << "Maximum in each row:" << endl;
    
    //task12
    // Print the vector of maximum elements, calling printVector function
    printVector(maxInEachRow);

    return 0;
}
template<typename T>
void fillMatrix(Matrix<T> &matrix) {
    //task13    
    // Fill the matrix with user input
    // Prompt the user to enter each element of the matrix
    // and set it using the set method of the Matrix class
    // make sure that the user can input elements of type T
    // Your implementation here
    string prompt;
    T value;
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            prompt = "Enter element [" + to_string(i) + "][" + to_string(j) + "]: ";
            cout << prompt;
            cin >> value;
            matrix.set(i, j, value);
        }
    }
}

template<typename T>
void printMatrix(const Matrix<T> &matrix) {
    //task14
    // Print the matrix elements in a formatted way
    // Iterate through each element of the matrix
    // and print it using the get method of the Matrix class
    // Your implementation here
    for (int i = 0; i < matrix.getRows(); ++i){
        for (int j = 0; j < matrix.getCols(); ++j){
            cout << matrix.get(i, j) << " ";
        }
        cout << endl;
    }
}
template<typename T>
void printVector(const vector<T> &vec) {
    //task15
    // Print the elements of the vector in a single line separated by spaces
    // Your implementation here
    for (const auto& element : vec){
        cout << element << " ";
    }
    cout << endl;
}