#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
template<typename T>
class Matrix {
    private:
        int rows; // number of rows
        int cols; // number of columns
        T* data; // pointer to the first element of the matrix
        int getIndex(int row, int col) const;
        T getMaxArray(const T arr[], int size) const;
    public:
        Matrix(int numRows, int numCols); 
        Matrix(const Matrix& other); //Copy constructor
        ~Matrix();
        T get(int row, int col) const;
        void set(int row, int col, T value);
        int getRows() const;
        int getCols() const; 
        T* getMaxInEachMatrixRow() const;
};
#include "matrix.tpp"
#endif // MATRIX_H
