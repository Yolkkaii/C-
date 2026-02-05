#include <iostream>
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
T& Matrix<T>::get(int row, int col) {
   
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
template<typename T>
//task 8 implementation of = operator
// Note: Do not forget to handle deep copy of the data array.
Matrix<T>& Matrix<T>::operator=(const Matrix& other){
    if (this == &other){
        return *this;
    }
    if (rows != other.rows || cols != other.cols) {
        delete[] data;
        rows = other.rows;
        cols = other.cols;
        data = new T[rows * cols];
    }

    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j){
            set(i, j, other.get(i,j));
        }
    }
    
    return *this;
}

template<typename T>
//task 9 implementation of + operator
Matrix<T> Matrix<T>::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw std::invalid_argument("Matrix dimentions invalid");
    }

    Matrix<T> result(rows, cols);
    for (int i = 0; i < rows * cols; ++i){
        result.data[i] = data[i] + other.data[i];
    }
    return result;
}

template<typename T>
//task 10 implementation of * operator
Matrix<T> Matrix<T>::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw std::invalid_argument("Matrix dimentions invalid"); 
    }

    Matrix<T> result(rows, other.cols);
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < other.cols; ++j){
            T sum = 0;
            for (int k = 0; k < cols; ++k) {
                sum += this->get(i,k) * other.get(k, j);
            }
            result.set(i, j, sum);
        }
    }
    return result;
}

template<typename T>
//task 11 implementation of () operator to get matrix element using the syntax matrix(row, col)
T Matrix<T>::operator()(int row, int col) const{
    return get(row, col);
}

template<typename T>
//task 12 implementation of () operator to set matrix element using the syntax matrix(row, col) = value
T& Matrix<T>::operator()(int row, int col){
    return get(row, col);
}
template<typename T>
// task 13 implementation of << operator to print the matrix
// you can reference the code in the function printMatrix() in main-matrix.cpp 
std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix){
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            os << matrix.get(i, j) << " ";
        }
        os << std::endl;
    }
    return os;
}

template<typename T>
// task 14 implementation of >> operator to read the matrix
// you can reference the code in the function fillMatrix() in main-matrix.cpp
std::istream& operator>>(std::istream& is, Matrix<T>& matrix){
    T value;
    for (int i = 0; i < matrix.getRows(); ++i) {
        for (int j = 0; j < matrix.getCols(); ++j) {
            std::string prompt = "Enter element [" + std::to_string(i) + "][" + std::to_string(j) + "]: ";
            std::cout << prompt;
            is >> value;
            matrix.set(i, j, value);
        }
    }
    return is;
}
