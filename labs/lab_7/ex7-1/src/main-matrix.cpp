/*
ID: 68011278
Name: Ananda Stallard
Lab No: 7
Question No: 1 
Date: 5 Feb 2026
*/
#include <iostream>
#include <type_traits>
#include <string>
#include "matrix.h"
using namespace std;
template<typename T>
void fillMatrix(Matrix<T> &matrix);
template<typename T>
void printMatrix(const Matrix<T> matrix);
template<typename T>
void printArray(const T* arr, int size);
int main() {
    int rows, cols; 
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;
    Matrix<double> matrix(rows, cols);
    fillMatrix(matrix);
    cout << "The matrix is:" << endl;
    printMatrix(matrix);
    
    double* maxInRows = matrix.getMaxInEachMatrixRow();
    cout << "Maximum in each row:" << endl;
    
    printArray(maxInRows, matrix.getRows());
    delete[] maxInRows;
    
    return 0;
}
template<typename T>
void fillMatrix(Matrix<T> &matrix) {
    
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