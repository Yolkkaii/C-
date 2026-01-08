#include <iostream>
#include "matrix.hpp"
using namespace std;
Matrix::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
    //task1: complete the constructor
    // Allocate memory for the 2D array
    //you can consult the code in lab2 question 2 (function createMatrix) for reference.
    //if memory allocation fails, print "Memory allocation failed" and exit the program.
    data = new(nothrow) int*[rows]; //nothrow handles memory allocation fails
    
    if (!data){
        cout << "Memory allocation failed." << endl;
        exit(EXIT_FAILURE);
    }

    for (int i=0; i < rows; ++i){
        data[i] = new(nothrow) int[cols];
        if (!data[i]) {
            for (int j = 0; j< i; ++j){
                delete[] data[j]; //delete j first then delete data (since !data[i] we skip to data)
                delete[] data;
            }
        }

        for (int j = 0; j < cols; ++j) {
            data[i][j] = 0;
        }
    }
}
Matrix::~Matrix() {
    //task2: complete the destructor
    // Deallocate the memory for the 2D array
    //you can consult the code in lab2 question 2 (function deleteMatrix) for reference.
    if (data){
        for (int i =0; i < rows; ++i){
            delete[] data[i];
        }
        delete[] data;
        data = nullptr;
    }
    rows = cols = 0;
}
int Matrix::get(int row, int col) const {
    //task3: complete the get function
    // Return the value at the specified row and column
    return data[row][col];
}
void Matrix::set(int row, int col, int value) {
    //task4: complete the set function
    // Set the value at the specified row and column
    data[row][col] = value;
}
int Matrix::getRows() const {
    //task5: complete the getRows function
    // Return the number of rows in the matrix
    return rows;
}
int Matrix::getCols() const {
    //task6: complete the getCols function
    // Return the number of columns in the matrix
    return cols;
}
int Matrix::getMaxArray(const int arr[], int size) {
    //task7: complete the getMaxArray function
    // Return the maximum value in the given array
    //the methosd is private and will be used in the next function.
    //you can consult the code in lab2 question 2 (function getMaxArray) for reference.
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
int *Matrix::getMaxInEachMatrixRow(const Matrix &matrix) {
    //task8: complete the getMaxInEachMatrixRow function
    // Return an array containing the maximum value in each row of the given matrix
    //you can consult the code in lab2 question 2 (function getMaxInEachMatrixRow) for reference.
    //if memory allocation fails, print "Memory allocation failed" and exit the program.
    // Note: The returned array should be deleted by the caller to avoid memory leaks.
    // Hint: You can use the getMaxArray function defined above.
    int row = matrix.getRows();
    int col = matrix.getCols();
    int *result = new(nothrow) int[row];

    for (int i = 0; i < row; ++i) {
        result[i] = getMaxArray(matrix.data[i], col);
    }
    return result;
}