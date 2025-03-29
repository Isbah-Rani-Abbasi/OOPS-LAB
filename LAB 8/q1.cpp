#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denominator;

    // Function to compute GCD using the Euclidean Algorithm
    int computeGCD(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void reduce() {
        int g = computeGCD(abs(numerator), abs(denominator)); 
        numerator /= g;
        denominator /= g;

        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    Fraction(int num = 0, int den = 1) {
        if (den == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            den = 1;
        }
        numerator = num;
        denominator = den;
        reduce();
    }

    Fraction operator+(const Fraction& other) const {
        return Fraction(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator-(const Fraction& other) const {
        return Fraction(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    Fraction operator*(const Fraction& other) const {
        return Fraction(numerator * other.numerator, denominator * other.denominator);
    }

    Fraction operator/(const Fraction& other) const {
        return Fraction(numerator * other.denominator, denominator * other.numerator);
    }

    bool operator==(const Fraction& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const Fraction& other) const {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const {
        return numerator * other.denominator < other.numerator * denominator;
    }

    bool operator>(const Fraction& other) const {
        return numerator * other.denominator > other.numerator * denominator;
    }

    bool operator<=(const Fraction& other) const {
        return !(*this > other);
    }

    bool operator>=(const Fraction& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const Fraction& f) {
        os << f.numerator << "/" << f.denominator;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& f) {
        is >> f.numerator >> f.denominator;
        if (f.denominator == 0) {
            cout << "Error: Denominator cannot be zero. Setting to 1." << endl;
            f.denominator = 1;
        }
        f.reduce();
        return is;
    }
};

int main() {
    Fraction f1(2, 4), f2(3, 6);
    cout << f1 + f2 << endl;  
    return 0;
}
