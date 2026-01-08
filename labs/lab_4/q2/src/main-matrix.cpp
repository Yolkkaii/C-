/*
ID: 68011278
Name: Ananda Stallard
Lab No: 4
Question No: 2 
Date: 8 January 2025
*/
#include <iostream>
#include <type_traits>
#include <string>
#include "matrix.h"
using namespace std;
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
    //task9
    // create a Matrix<double> object named matrix with the specified rows and cols
    Matrix<double> matrix(rows, cols);
    
    //task10
    //fill the matrix with user input, by calling fillMatrix
    fillMatrix(matrix);
    
    cout << "The matrix is:" << endl;
    //task11
    //print the matrix by calling printMatrix
    printMatrix(matrix);

    //task12
    //get the maximum in each row by calling getMaxInEachMatrixRow
    vector<double> maxInEachRow = matrix.getMaxInEachMatrixRow();

    cout << "Maximum in each row:" << endl;
    //task13
    //print the maximums by calling printVector
    printVector(maxInEachRow);

    return 0;
}
template<typename T>
void fillMatrix(Matrix<T> &matrix) {
    //task14
    // fill the matrix with user input
    // use nested loops to iterate through each element
    // for each element, prompt the user for input and set the value in the matrix using set method
    // hint: you can use getRows() and getCols() to get the dimensions of the matrix
    // example prompt: "Enter element [i][j]: "
    // where i and j are the current row and column indices
    // read the value from standard input and use matrix.set(i, j, value) to set it
    // remember to declare a variable of type T to hold the input value
    // your implementation goes here
    string prompt;
    T value;
    for (int i = 0; i < matrix.getRows(); ++i){
        for (int j = 0; j < matrix.getCols(); ++j){
            prompt = "Enter element [" + to_string(i) + "][" + to_string(j) + "]: ";
            cout << prompt;
            cin >> value;
            matrix.set(i, j, value);
        }
    }
}

template<typename T>
void printMatrix(const Matrix<T> &matrix) {
    //task15
    // print the matrix to standard output
    // use nested loops to iterate through each element
    // for each element, retrieve the value using get method and print it
    // format the output so that each row is on a new line
    // and elements in a row are separated by spaces
    // your implementation goes here
    for (int i = 0; i < matrix.getRows(); ++i){
        for (int j = 0; j < matrix.getCols(); ++j){
            cout << matrix.get(i, j) << " ";
        }
        cout << endl;
    }
}

template<typename T>
void printVector(const vector<T> &vec) {
    //task16
    // print the elements of the vector to standard output
    // iterate through the vector and print each element followed by a space
    // after printing all elements, print a newline
    // your implementation goes here
    for (const auto& element : vec){
        cout << element << " ";
    }
    cout << endl;
}