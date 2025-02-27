#include <iostream>
#include <algorithm>
#include <cmath>

class Polynomial {
private:
    double* coefficients;
    int degree;

public:
    // Default constructor
    Polynomial() : degree(0) {
        coefficients = new double[1];
        coefficients[0] = 0.0;
    }

    // Parameterized constructor
    Polynomial(int degree, const double* coeffs) : degree(degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = coeffs[i];
        }
    }

    // Copy constructor
    Polynomial(const Polynomial& other) : degree(other.degree) {
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; ++i) {
            coefficients[i] = other.coefficients[i];
        }
    }

    // Move constructor
    Polynomial(Polynomial&& other) noexcept : degree(other.degree), coefficients(other.coefficients) {
        other.coefficients = nullptr;
        other.degree = 0;
    }

    // Destructor
    ~Polynomial() {
        delete[] coefficients;
    }

    // Assignment Operator
    Polynomial& operator=(const Polynomial& other) {
        if (this != &other) {
            delete[] coefficients;
            degree = other.degree;
            coefficients = new double[degree + 1];
            for (int i = 0; i <= degree; ++i) {
                coefficients[i] = other.coefficients[i];
            }
        }
        return *this;
    }

    
    Polynomial& operator=(Polynomial&& other) noexcept {
        if(this != &other){
            delete[] coefficients;
            coefficients = other.coefficients;
            degree = other.degree;
            other.coefficients = nullptr;
            other.degree = 0;
        }
        return *this;
    }


    int getDegree() const {
        return degree;
    }
    
    double evaluate(double x) const {
        double result = 0.0;
        for (int i = 0; i <= degree; ++i) {
            result += coefficients[i] * std::pow(x, i);
        }
        return result;
    }

    Polynomial add(const Polynomial& other) const {
        int newDegree = std::max(degree, other.degree);
        double* newCoeffs = new double[newDegree + 1];

        for (int i = 0; i <= newDegree; ++i) {
            double coeff1 = (i <= degree) ? coefficients[i] : 0.0;
            double coeff2 = (i <= other.degree) ? other.coefficients[i] : 0.0;
            newCoeffs[i] = coeff1 + coeff2;
        }

        return Polynomial(newDegree, newCoeffs);
    }

    Polynomial multiply(const Polynomial& other) const {
        int newDegree = degree + other.degree;
        double* newCoeffs = new double[newDegree + 1];
        std::fill(newCoeffs, newCoeffs + newDegree + 1, 0.0);

        for (int i = 0; i <= degree; ++i) {
            for (int j = 0; j <= other.degree; ++j) {
                newCoeffs[i + j] += coefficients[i] * other.coefficients[j];
            }
        }

        return Polynomial(newDegree, newCoeffs);
    }

    void print() const {
        for(int i = 0; i <= degree; ++i) {
            std::cout << coefficients[i] << (i < degree ? "x^" + std::to_string(i) + " + " : "x^" + std::to_string(i));
        }
        std::cout << std::endl;
    }
};

int main() {
    double coeffs1[] = {1.0, 2.0, 3.0}; 
    Polynomial poly1(2, coeffs1);

    double coeffs2[] = {4.0, 5.0}; 
    Polynomial poly2(1, coeffs2);

    std::cout << "Polynomial 1: ";
    poly1.print();

    std::cout << "Polynomial 2: ";
    poly2.print();

    Polynomial sum = poly1.add(poly2);
    std::cout << "Sum: ";
    sum.print();

    Polynomial product = poly1.multiply(poly2);
    std::cout << "Product: ";
    product.print();

    std::cout << "Evaluate poly1 at 2: " << poly1.evaluate(2.0) << std::endl;

    Polynomial poly3 = poly1; 
    std::cout << "Copy of poly1: ";
    poly3.print();

    Polynomial poly4 = std::move(poly2); // Move constructor
    std::cout << "Moved poly2: ";
    poly4.print();
    //std::cout << "Original poly2: "; poly2.print(); //Will cause error.

    return 0;
}
