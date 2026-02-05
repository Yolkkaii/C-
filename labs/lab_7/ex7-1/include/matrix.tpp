#include <iostream>
#include <algorithm>
#include <vector>
template<typename T>
Matrix<T>::Matrix(int numRows, int numCols) : rows{numRows}, cols{numCols} {
    static_assert(std::is_arithmetic<T>::value, "This template only supports numeric types!");
    data = new T[rows * cols];
    if (data == nullptr) {
        std::cout << "Memory allocation failed" << std::endl;
        exit(1);
    }
}
template<typename T> //Copy constructor
Matrix<T>::Matrix(const Matrix& other) : rows(other.rows), cols(other.cols) {
    data = new T[rows * cols];
    for (int i = 0; i < rows * cols; ++i) {
        data[i] = other.data[i];
    }
}
template<typename T>
Matrix<T>::~Matrix() {
    // Free allocated memory
    delete[] data;
}
template<typename T>
T Matrix<T>::get(int row, int col) const {
   
    int index = getIndex(row, col);
    return data[index];
}
template<typename T>
void Matrix<T>::set(int row, int col, T value) {
    
    int index = getIndex(row, col);
    data[index] = value;
}
template<typename T>
int Matrix<T>::getRows() const {
    
    return rows;
}
template<typename T>
int Matrix<T>::getCols() const {
    
    return cols;
}
template<typename T>
T Matrix<T>::getMaxArray(const T arr[], int size) const {
    
    T maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}
template<typename T>
T* Matrix<T>::getMaxInEachMatrixRow() const {
    T* maxInRows = new T[rows];
    if (maxInRows == nullptr) {
        std::cout << "Memory allocation failed" << std::endl;
        exit(1);
    }
    T* rowsData;
    for (int i = 0; i < rows; ++i) {
        rowsData = data + i * cols;
        maxInRows[i] = getMaxArray(rowsData, cols);
        
    }
    return maxInRows;
}
template<typename T>
int Matrix<T>::getIndex(int row, int col) const {
    return row * cols + col;
}

