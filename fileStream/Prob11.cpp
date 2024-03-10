#include <iostream>

// Function to dynamically allocate memory for a matrix
int** createMatrix(int rows, int cols) {
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }
    return matrix;
}

// Function to perform matrix addition
int** addMatrices(int** matrix1, int** matrix2, int rows, int cols) {
    int** result = createMatrix(rows, cols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }

    return result;
}

// Function to display a matrix
void displayMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to deallocate memory for a matrix
void deleteMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int main() {
    int rows, cols;

    // Get dimensions of matrices from the user
    std::cout << "Enter the number of rows: ";
    std::cin >> rows;

    std::cout << "Enter the number of columns: ";
    std::cin >> cols;

    // Dynamically allocate memory for two matrices
    int** matrix1 = createMatrix(rows, cols);
    int** matrix2 = createMatrix(rows, cols);

    // Get values for the first matrix from the user
    std::cout << "Enter values for the first matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element (" << i + 1 << "," << j + 1 << "): ";
            std::cin >> matrix1[i][j];
        }
    }

    // Get values for the second matrix from the user
    std::cout << "Enter values for the second matrix:" << std::endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element (" << i + 1 << "," << j + 1 << "): ";
            std::cin >> matrix2[i][j];
        }
    }

    // Perform matrix addition
    int** resultMatrix = addMatrices(matrix1, matrix2, rows, cols);

    // Display the matrices and the result
    std::cout << "Matrix 1:" << std::endl;
    displayMatrix(matrix1, rows, cols);

    std::cout << "Matrix 2:" << std::endl;
    displayMatrix(matrix2, rows, cols);

    std::cout << "Resultant Matrix:" << std::endl;
    displayMatrix(resultMatrix, rows, cols);

    // Deallocate dynamically allocated memory
    deleteMatrix(matrix1, rows);
    deleteMatrix(matrix2, rows);
    deleteMatrix(resultMatrix, rows);

    return 0;
}
