/*
ID: 68011278
Name: Ananda Stallard
Lab No: 7
Question No: 2
Date: 5 Feb 2026
*/
// Do not modify this file except to add necessary #include directives, and your name and ID above.
#include <iostream>
#include <type_traits>
#include <string>
#include "matrix.h"
using namespace std;
template<typename T>
void fillMatrix(Matrix<T> &matrix); //this function is not used in main, kept for reference
template<typename T>
void printMatrix(const Matrix<T> matrix); //this function is not used in main, kept for reference
template<typename T>
void printArray(const T* arr, int size);
int main() {
    int rows, cols; 
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    Matrix<double> matrix(rows, cols);
    cin >> matrix; // Using overloaded >> operator to fill the matrix  
    cout << "The matrix is:" << endl;
    cout << matrix; // Using overloaded << operator to print the matrix
    
    double* maxInRows = matrix.getMaxInEachMatrixRow();
    cout << "Maximum in each row:" << endl;
    
    printArray(maxInRows, matrix.getRows());
    delete[] maxInRows;
    
    Matrix<double> matrixB(rows, cols);
    cin >> matrixB; // Using overloaded >> operator to fill the second matrix
    cout << "The second matrix is:" << endl;
    cout << matrixB; // Using overloaded << operator to print the second matrix
    Matrix<double> sumMatrix = matrix + matrixB; // Using overloaded + operator
    cout << "Sum of the two matrices:" << endl;
    cout << sumMatrix; // Using overloaded << operator to print the sum matrix

    Matrix<double> matrixC(cols, rows); // Note the swapped dimensions for multiplication
    cin >> matrixC; // Using overloaded >> operator to fill the third matrix
    cout << "The third matrix is:" << endl;
    cout << matrixC; // Using overloaded << operator to print the third matrix
    Matrix<double> productMatrix = matrix * matrixC; // Using overloaded * operator
    cout << "Product of the first and third matrices:" << endl;
    cout << productMatrix; // Using overloaded << operator to print the product matrix

    // Demonstrating the use of overloaded () operator
    productMatrix(0,0) = 555.55; // Using overloaded () operator to set an element
    cout << "Modified product matrix (after setting element [0][0] to 555.55):" << endl;
    cout << productMatrix(0,0) << endl; // Using overloaded () operator to get an element
    return 0;
}
template<typename T>
void fillMatrix(Matrix<T> &matrix) {
    // Function to fill the matrix with user input
    // you can copy this code to overload >> operator in matrix.tpp
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
void printMatrix(const Matrix<T> matrix) {
    // Function to print the matrix
    // you can copy this code to overload << operator in matrix.tpp
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            cout << matrix.get(i, j) << " ";
        }
        cout << endl;
    }
}
template<typename T>

void printArray(const T* arr, int size) {
    
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}