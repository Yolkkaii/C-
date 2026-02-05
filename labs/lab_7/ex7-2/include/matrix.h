#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
#include <vector>
template<typename T>
class Matrix {
    private:
        int rows; // number of rows
        int cols; // number of columns
        T *data; // pointer to the first element of the matrix
        int getIndex(int row, int col) const;
        T getMaxArray(const T arr[], int size) const;
    public:
        Matrix(int numRows, int numCols); 
        ~Matrix();
        T get(int row, int col) const;
        T& get(int row, int col);
        void set(int row, int col, T value);
        int getRows() const;
        int getCols() const; 
        T* getMaxInEachMatrixRow() const;
        //task 1 declaration of = operator
        Matrix<T>& operator=(const Matrix& other);

        //task 2 declaration of + operator
        Matrix<T> operator+(const Matrix& other) const;

        //task 3 declaration of * operator
        Matrix<T> operator*(const Matrix& other) const;

        // task 4 declaration of () operator to get matrix element using the syntaxmatrix(row, col)
        T operator()(int row, int col) const;

        // task 5 declaration of () operator to set matrix element using the syntax matrix(row, col) = value
        T& operator()(int row, int col);
        // task 6 declaration of << operator to print the matrix
        template<typename U>
        friend std::ostream& operator<<(std::ostream& os, const Matrix<U>& matrix);
        // task 7 declaration of >> operator to read the matrix
        template<typename U>
        friend std::istream& operator>>(std::istream& is, const Matrix<U>& matrix);
};
#include "matrix.tpp"
#endif // MATRIX_H
