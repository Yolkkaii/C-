#include <iostream>
#include <vector>
using namespace std;
template<typename T>
class Matrix {
    private:
        int rows; // number of rows
        int cols; // number of columns
        //task 1 
        //use a single vector to store matrix data
        vector<T> data;
        
        int getIndex(int row, int col) const;
    public:
        Matrix(int numRows, int numCols); 
        T get(int row, int col) const;
        void set(int row, int col, T value);
        int getRows() const;
        int getCols() const; 
        vector<T> getMaxInEachMatrixRow() const;
};
#include "matrix.tpp"