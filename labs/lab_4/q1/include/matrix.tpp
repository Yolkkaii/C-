#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template<typename T>
Matrix<T>::Matrix(int numRows, int numCols) : rows(numRows), cols(numCols) {
    //task2
    //use static_assert to ensure the type of T is numeric
    // Initialize the 2D vector with given rows and columns
    static_assert(is_arithmetic<T>::value, "Matrix elements must be numeric");
    data.resize(rows, vector<T>(cols));
}
template<typename T>
T Matrix<T>::get(int row, int col) const {
    //task3
    // Return the element at the specified row and column
    return data[row][col];
}
template<typename T>
void Matrix<T>::set(int row, int col, T value) {
    //task4
    // Set the element at the specified row and column to the given value
    data[row][col] = value;
}
template<typename T>
int Matrix<T>::getRows() const {
    //task5
    // Return the number of rows
    return rows;
}
template<typename T>
int Matrix<T>::getCols() const {
    //task6
    // Return the number of columns
    return cols;
}
template<typename T>

vector<T> Matrix<T>::getMaxInEachMatrixRow() const {
    //task7
    // Return a vector containing the maximum element from each row of the matrix
    // Use the standard library algorithm to find the maximum element in each row
    // and store it in the result vector
    // Hint: You can use std::max_element from <algorithm>
    // to find the maximum element in a range
    // Example: T maxVal = *max_element(data[i].begin(), data[i].end());
    // where data[i] is the i-th row of the matrix
    // Iterate through each row, find the maximum element, and add it to the result vector
    // Return the result vector containing maximum elements from each row
    // Your implementation here
    vector<T> maxInrows;

    for (const auto& row : data){
        T maxVal = *max_element(row.begin(), row.end());
        maxInrows.push_back(maxVal); //adds maxVal to the vector
    }

    return maxInrows;
}