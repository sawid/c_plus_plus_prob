#include <iostream>

class Matrix {
private:
    int rows;
    int cols;
    int **data;

public:
    // Constructor
    Matrix(int r, int c) : rows(r), cols(c) {
        // Allocate memory for the matrix
        data = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            data[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        // Deallocate memory
        for (int i = 0; i < rows; ++i) {
            delete[] data[i];
        }
        delete[] data;
    }

    // Setter function to set matrix elements
    void setElement(int row, int col, int value) {
        data[row][col] = value;
    }

    // Getter function to get matrix elements
    int getElement(int row, int col) const {
        return data[row][col];
    }

    // Function to display the matrix
    void display() const {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    // Overloading + operator for matrix addition
    Matrix operator+(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    // Overloading - operator for matrix subtraction
    Matrix operator-(const Matrix& other) const {
        Matrix result(rows, cols);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                result.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return result;
    }
};

int main() {
    // Create two matrices
    Matrix A(2, 2);
    Matrix B(2, 2);

    // Set elements for matrix A
    A.setElement(0, 0, 1);
    A.setElement(0, 1, 2);
    A.setElement(1, 0, 3);
    A.setElement(1, 1, 4);

    // Set elements for matrix B
    B.setElement(0, 0, 5);
    B.setElement(0, 1, 6);
    B.setElement(1, 0, 7);
    B.setElement(1, 1, 8);

    // Display matrix A
    std::cout << "Matrix A:" << std::endl;
    A.display();
    std::cout << std::endl;

    // Display matrix B
    std::cout << "Matrix B:" << std::endl;
    B.display();
    std::cout << std::endl;

    // Perform matrix addition and display the result
    std::cout << "Matrix A + B:" << std::endl;
    (A + B).display();
    std::cout << std::endl;

    // Perform matrix subtraction and display the result
    std::cout << "Matrix A - B:" << std::endl;
    (A - B).display();

    return 0;
}
