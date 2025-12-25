#include <iostream>
#include "matrix.hpp"
using namespace std;
Matrix::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
    //task1: complete the constructor
    // Allocate memory for the 2D array
    //you can consult the code in lab2 question 2 (function createMatrix) for reference.
    //if memory allocation fails, print "Memory allocation failed" and exit the program.
    if (data == nullptr){
        return;
    }

    m->data = new int*[rows];
    m->cols = cols;
    m->rows = rows;

    for (int i=0; i < rows; ++i){
        m->data[i] = new int[cols];
    }

    return m;
}
Matrix::~Matrix() {
    //task2: complete the destructor
    // Deallocate the memory for the 2D array
    //you can consult the code in lab2 question 2 (function deleteMatrix) for reference.
    for (int i=0; i < rows; ++i){
        delete[] data[i];
    }
    delete[] data;
    data = nullptr;
}
int Matrix::get(int row, int col) const {
    //task3: complete the get function
    // Return the value at the specified row and column
    
}
void Matrix::set(int row, int col, int value) {
    //task4: complete the set function
    // Set the value at the specified row and column
    
}
int Matrix::getRows() const {
    //task5: complete the getRows function
    // Return the number of rows in the matrix
    
}
int Matrix::getCols() const {
    //task6: complete the getCols function
    // Return the number of columns in the matrix
    
}
int Matrix::getMaxArray(const int arr[], int size) {
    //task7: complete the getMaxArray function
    // Return the maximum value in the given array
    //the methosd is private and will be used in the next function.
    //you can consult the code in lab2 question 2 (function getMaxArray) for reference.
    
}
int *Matrix::getMaxInEachMatrixRow(const Matrix &matrix) {
    //task8: complete the getMaxInEachMatrixRow function
    // Return an array containing the maximum value in each row of the given matrix
    //you can consult the code in lab2 question 2 (function getMaxInEachMatrixRow) for reference.
    //if memory allocation fails, print "Memory allocation failed" and exit the program.
    // Note: The returned array should be deleted by the caller to avoid memory leaks.
    // Hint: You can use the getMaxArray function defined above.
    
}