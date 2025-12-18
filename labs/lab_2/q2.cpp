/*
    ID: 68011278
    Name: Ananda Stallard
    Lab No: 2
    Question No: 2
    Date: Dec 18, 2025 
*/
#include <iostream>
#include <string>
using namespace std;

struct Matrix {
    //1. Complete the struct definition of this Matrix struct. 
    //  It should have three members: a pointer to a pointer of integers named data,
    //  an integer named rows, and an integer named cols.
    //  The data member will be used to store a 2D array (matrix) of integers.
    //  The rows and cols members will store the number of rows and columns of the matrix, respectively.
    int **data;
    int rows;
    int cols;
};
// Function prototypes
//2. Declare the function prototypes for the following functions:
// - getInput: takes a string prompt and returns a string input from the user.
// - getMaxInArray: takes a constant integer array and its size, returns the maximum integer
//   in that array.
// - getMaxInEachMatrixRow: takes a constant Matrix reference and returns a pointer to
//   an integer array containing the maximum element from each row of the matrix.
// - deleteMatrix: takes a Matrix and frees the allocated memory for its data.
// - printArray: takes a constant integer array and its size, prints the elements of the array.
// - printMatrix: takes a constant Matrix reference and prints the matrix.
// - fillMatrix: takes a Matrix reference and fills it with user input.
// - createMatrix: takes number of rows and columns, returns a pointer to a newly created Matrix.
string getInput(const string &prompt);
int getMaxInArray(const int array[], int array_size);
int* getMaxInEachMatrixRow(const Matrix &m);
void deleteMatrix(Matrix &m);
void printArray(const int array[], int array_size);
void printMatrix(const Matrix &m);
void fillMatrix(Matrix &m);
Matrix* createMatrix(int rows, int cols);

// Main function
// using this main function as is, to test your implementations of the above functions, and 
// the Matrix struct.
// The main function can help you to know the expected behavior of each function, 
// and the function prototypes you need to declare. 
// Do not modify the main function.
// You should consider the way the main function deallocate the memory used by the Matrix struct.
// Make sure your implementation of createMatrix and deleteMatrix functions are compatible with this main function.
int main() {
    int rows = stoi(getInput("Enter number of rows: "));
    int cols = stoi(getInput("Enter number of columns: "));
    Matrix *matrix = createMatrix(rows, cols);
    if (matrix == nullptr) {
        cout << "Memory allocation failed" << endl;
        return 1;
    }
    fillMatrix(*matrix);
    cout << "The matrix is:" << endl;
    printMatrix(*matrix);
    int *maxInRows = getMaxInEachMatrixRow(*matrix);
    cout << "The maximum elements in each row are:" << endl;
    printArray(maxInRows, rows);
    delete[] maxInRows;
    deleteMatrix(*matrix); // Free allocated memory for the matrix
    delete matrix;  // Free the matrix structure
    return 0;
}


//3. Implement the getInput function to display the prompt to the user,
//  read a line of input from the user, and return it as a string.
// Note: You can see the example of implementation of this function from twoD-array-using-pointer.cpp 
//file in our code example.
string getInput(const string &prompt){
    cout << prompt;
    string text;
    getline(cin, text);
    return text;
}

//4. Implement the createMatrix function to dynamically allocate memory for a Matrix struct,
//  including its data member which should be a 2D array of integers with the specified number of rows and columns.
//  The function should return a pointer to the newly created Matrix.
// If memory allocation fails at any point, the function should return nullptr.
// Hint: You will need to allocate memory for the Matrix struct itself,
//  then allocate memory for the array of row pointers, and finally allocate memory for each row.
//  Make sure to handle memory allocation failures properly to avoid memory leaks.
// // Note: You can see the guideline for the implementation of this function from twoD-array-using-pointer.cpp 
//file in our code example.
Matrix* createMatrix(int rows, int cols){
    Matrix *m = new Matrix;

    if (m == nullptr) { //Error handling
        return nullptr;
    }

    m->data = new int*[rows];
    m->cols = cols;
    m->rows = rows;

    for (int i = 0; i < rows; ++i){
        m->data[i] = new int[cols];
    }
    return m;
}


//5. Implement the fillMatrix function to fill the matrix with user input.
//  The function should prompt the user to enter each element of the matrix.
// Hint: You must use the getInput function to read user input.
// Note: You can see the example of implementation of this function from twoD-array-using-pointer.cpp
void fillMatrix(Matrix &m){
    for (int i = 0; i < m.rows; ++i){
        for (int j = 0; j < m.cols; ++j){
            string prompt = "Enter element [" + to_string(i) + "][" + to_string(j) + "]: ";
            string input = getInput(prompt);
            m.data[i][j] = stoi(input); //stoi is string to int
        }
    }
}

//6. Implement the printMatrix function to print the elements of the matrix in a formatted way.
//  Each row of the matrix should be printed on a new line, with elements separated
//  by spaces.
// Note: You can see the example of implementation of this function from twoD-array-using-pointer.cpp
void printMatrix(const Matrix &m) {
    if (m.data == nullptr || m.rows <= 0 || m.cols <= 0) return;
    for (int i = 0; i < m.rows; ++i) {
        for (int j = 0; j < m.cols; ++j) {
            cout << m.data[i][j];
            if (j + 1 < m.cols) cout << " ";
        }
        cout << "\n";
    }
}


//7. Implement the deleteMatrix function to free the dynamically allocated memory
//  for the matrix's data member.
// Note: You can see the example of implementation of this function from twoD-array-using-pointer.cpp
void deleteMatrix(Matrix &m){
    for (int i = 0; i < m.rows; ++i){
        delete[] m.data[i];
    }
    delete[] m.data;
    m.data = nullptr;
    m.rows = m.cols = 0;
}


//8. Implement the getMaxArray function to find and return the maximum integer
//  in the given array.
int getMaxInArray(const int array[], int array_size){
    int max = array[0];
    for (int i = 1; i < array_size; ++i){
        if (array[i] > max){
            max = array[i];
        }
    }
    return max;
}

//9. Implement the getMaxInEachMatrixRow function to find the maximum element
//  in each row of the given matrix.
//  The function should return a pointer to a newly allocated integer array
//  containing the maximum elements from each row.
// Hint: You must use the getMaxInArray function to find the maximum
int* getMaxInEachMatrixRow(const Matrix &m){
    int *row_max = new int[m.rows]; //Int array size based on amount of rows
    for (int i = 0; i < m.rows; ++i) {
        row_max[i] = getMaxInArray(m.data[i], m.cols);
    }
    return row_max;
}

//10. Implement the printArray function to print the elements of the given array.
//  The elements should be printed on a single line, separated by spaces.
void printArray(const int array[], int array_size){
    for (int i = 0; i < array_size; ++i) {
        cout << array[i];
        if (i + 1 < array_size) cout << ' ';
    }
    cout << '\n';
}
