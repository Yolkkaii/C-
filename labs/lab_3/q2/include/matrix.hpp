#include <iostream>
using namespace std;
class Matrix {
    private:
        int rows;
        int cols;
        int **data;
        int getMaxArray(const int arr[], int size);
    public:
        Matrix(int numRows, int numCols); 
        ~Matrix(); 
        int get(int row, int col) const;
        void set(int row, int col, int value);
        int getRows() const;
        int getCols() const; 
        int *getMaxInEachMatrixRow(const Matrix &matrix);
};