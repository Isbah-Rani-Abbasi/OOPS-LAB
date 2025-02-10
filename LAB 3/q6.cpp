#include <iostream>
#include <vector>

class Matrix {
private:
    int rows;
    int cols;
    std::vector<std::vector<int>> data;

public:
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        data.resize(rows, std::vector<int>(cols, 0));
    }

    int getRows() const {
        return rows;
    }

    int getCols() const {
        return cols;
    }

    void setElement(int i, int j, int value) {
        if (i >= 0 && i < rows && j >= 0 && j < cols) {
            data[i][j] = value;
        } else {
            std::cerr << "Invalid matrix indices." << std::endl;
        }
    }

    Matrix add(const Matrix& other) const {
        if (rows != other.rows || cols != other.cols) {
            std::cerr << "Matrices cannot be added." << std::endl;
            return Matrix(0, 0); // Return an empty matrix
        }

        Matrix result(rows, cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return result;
    }

    Matrix multiply(const Matrix& other) const {
        if (cols != other.rows) {
            std::cerr << "Matrices cannot be multiplied." << std::endl;
            return Matrix(0, 0); // Return an empty matrix
        }

        Matrix result(rows, other.cols);
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < other.cols; j++) {
                for (int k = 0; k < cols; k++) {
                    result.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return result;
    }

    void printMatrix() const {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }

    void inputMatrix() {
        std::cout << "Enter the elements of the matrix:" << std::endl;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                std::cout << "Element at (" << i << ", " << j << "): ";
                std::cin >> data[i][j];
            }
        }
    }
};

int main() {
    int rows1, cols1, rows2, cols2;

    std::cout << "Enter dimensions for matrix 1:" << std::endl;
    std::cout << "Rows: ";
    std::cin >> rows1;
    std::cout << "Columns: ";
    std::cin >> cols1;

    Matrix m1(rows1, cols1);
    m1.inputMatrix();

    std::cout << "\nEnter dimensions for matrix 2:" << std::endl;
    std::cout << "Rows: ";
    std::cin >> rows2;
    std::cout << "Columns: ";
    std::cin >> cols2;

    Matrix m2(rows2, cols2);
    m2.inputMatrix();

    std::cout << "\nMatrix 1:" << std::endl;
    m1.printMatrix();
    std::cout << "\nMatrix 2:" << std::endl;
    m2.printMatrix();

    Matrix sum = m1.add(m2);
    if (sum.getRows() > 0) {
        std::cout << "\nSum of matrices:" << std::endl;
        sum.printMatrix();
    }

    Matrix product = m1.multiply(m2);
    if (product.getRows() > 0) {
        std::cout << "\nProduct of matrices:" << std::endl;
        product.printMatrix();
    }

    return 0;
}
