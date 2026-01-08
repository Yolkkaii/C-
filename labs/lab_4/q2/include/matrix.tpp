#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
template<typename T>
Matrix<T>::Matrix(int numRows, int numCols) : rows{numRows}, cols{numCols} {
    //task2
    // use static assert to ensure T is a numeric type
    // then allocate memory for the data vector by resizing it to rows * cols
    static_assert(is_arithmetic<T>::value, "Matrix elements must be numeric");
    data.resize(rows * cols);
}
template<typename T>
T Matrix<T>::get(int row, int col) const {
    //task3
    // calculate the index using getIndex and return the corresponding value from data vector
    int index = getIndex(row, col);
    return data[index];
}
template<typename T>
void Matrix<T>::set(int row, int col, T value) {
    //task4
    // calculate the index using getIndex and set the corresponding value in data vector
    int index = getIndex(row, col);
    data[index] = value;
}
template<typename T>
int Matrix<T>::getRows() const {
    //task5
    //return number of rows
    return rows;
}
template<typename T>
int Matrix<T>::getCols() const {
    //task6
    // return number of columns
    return cols;
}
template<typename T>
vector<T> Matrix<T>::getMaxInEachMatrixRow() const {
    //task7
    // return a vector containing the maximum element from each row of the matrix
    // hint: iterate through each row, extract the row data, and use std::max_element to find the maximum
    // store the maximums in a result vector and return it
    // you may find it helpful to create a temporary vector to hold row data during extraction
    // example: vector<T> rowData(cols);
    // then use rowData.assign(...) to copy data from the matrix to rowData
    // the formulas to assign each row's data to rowData is:
    // data.begin() + (i * cols) to data.begin() + (i * cols) + cols
    // where i is the current row index
    //for example if matrix has 2 rows and 3 columns:
    // row 0 data is from index 0 to 2 (3 elements)
    //data.begin() + (0 * 3)  to data.begin() + (0 * 3) + 3 that is 
    // data.begin() + 0 to data.begin() + 3
    // the last argument is exclusive, so it extracts elements at index 0, 1, and 2 
    // row 1 data is from index 3 to 5 (3 elements)
    //data.begin() + (1 * 3) to data.begin() + (1 * 3) + 3 that is
    // data.begin() + 3 to data.begin() + 6
    // the last argument is exclusive, so it extracts elements at index 3, 4, and 5
    // after extracting each row's data into rowData,
    //finally use max_element on rowData to find the maximum value in that row
    // repeat for all rows
    // return the result vector containing maximums
    // hint: std::max_element is defined in <algorithm>
    // example usage: T maxVal = *max_element(rowData.begin(), rowData.end());
    // your implementation goes here

    vector<T> result;
    result.reserve(rows); //reserve to pre allocate memory

    for (int i = 0; i < rows; ++i){
        auto rowStart = data.begin() + i * cols; //since we are doing this all in one vector we need to move to the "row" first by multiplying "col" to move to the next "row" (adding i is like moving in "col")
        auto rowEnd   = rowStart + cols; //the row's end is equal to the start + amount of cols

        T maxVal = *max_element(rowStart, rowEnd);
        result.push_back(maxVal);
    }

    return result;
}

template<typename T>
int Matrix<T>::getIndex(int row, int col) const {
    //task8
    // calculate and return the index in the data vector for the given row and column
    // formula: index = row * number_of_columns + col
    // your implementation goes here
    
    return row * getCols() + col;
    
}