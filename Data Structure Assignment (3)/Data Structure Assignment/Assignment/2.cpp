#include <iostream>
using namespace std;

// Function to input a matrix
void inputMatrix(int** matrix, int rows, int cols) {
    cout << "Enter elements of the matrix (" << rows << "x" << cols << "):\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int cols) {
    cout << "Matrix:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to add two matrices
void addMatrices(int** mat1, int** mat2, int** result, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}

// Function to calculate the transpose of a matrix
void transposeMatrix(int** matrix, int** transpose, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            transpose[j][i] = matrix[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int** mat1, int** mat2, int** result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0; // Initialize result cell to zero
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}

// Function to dynamically allocate a 2D array
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Function to free dynamically allocated 2D array
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows1, cols1, rows2, cols2;

    cout << "Enter rows and columns for the first matrix: ";
    cin >> rows1 >> cols1;
    int** mat1 = createMatrix(rows1, cols1);
    inputMatrix(mat1, rows1, cols1);

    cout << "Enter rows and columns for the second matrix: ";
    cin >> rows2 >> cols2;
    int** mat2 = createMatrix(rows2, cols2);
    inputMatrix(mat2, rows2, cols2);

    // Matrix Addition
    if (rows1 == rows2 && cols1 == cols2) {
        int** addition = createMatrix(rows1, cols1);
        addMatrices(mat1, mat2, addition, rows1, cols1);
        cout << "Addition of matrices:\n";
        displayMatrix(addition, rows1, cols1);
        deleteMatrix(addition, rows1);
    } else {
        cout << "Matrix addition not possible (dimensions mismatch).\n";
    }

    // Transpose of the first matrix
    int** transpose = createMatrix(cols1, rows1);
    transposeMatrix(mat1, transpose, rows1, cols1);
    cout << "Transpose of the first matrix:\n";
    displayMatrix(transpose, cols1, rows1);
    deleteMatrix(transpose, cols1);

    // Matrix Multiplication
    if (cols1 == rows2) {
        int** multiplication = createMatrix(rows1, cols2);
        multiplyMatrices(mat1, mat2, multiplication, rows1, cols1, cols2);
        cout << "Multiplication of matrices:\n";
        displayMatrix(multiplication, rows1, cols2);
        deleteMatrix(multiplication, rows1);
    } else {
        cout << "Matrix multiplication not possible (dimensions mismatch).\n";
    }

    // Free allocated memory
    deleteMatrix(mat1, rows1);
    deleteMatrix(mat2, rows2);

    return 0;
}
