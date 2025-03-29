#include <iostream>
using namespace std;

class Polynomial;

class PolynomialUtils {
public:
    static int evaluate(const Polynomial &p, int x);
    static Polynomial derivative(const Polynomial &p);
};

class Polynomial {
private:
    int coefficients[100];
    int degree;

    void trim() {
        while (degree > 0 && coefficients[degree] == 0) {
            degree--;
        }
    }

public:
    Polynomial() : degree(0) {
        for (int i = 0; i < 100; i++) coefficients[i] = 0;
    }

    Polynomial(int arr[], int size) : degree(size - 1) {
        for (int i = 0; i < 100; i++) coefficients[i] = (i < size ? arr[i] : 0);
        trim();
    }

    Polynomial operator+(const Polynomial &other) const {
        int maxDegree = max(degree, other.degree);
        int result[100];
        for (int i = 0; i <= maxDegree; i++)
            result[i] = coefficients[i] + other.coefficients[i];
        return Polynomial(result, maxDegree + 1);
    }

    Polynomial operator-(const Polynomial &other) const {
        int maxDegree = max(degree, other.degree);
        int result[100];
        for (int i = 0; i <= maxDegree; i++)
            result[i] = coefficients[i] - other.coefficients[i];
        return Polynomial(result, maxDegree + 1);
    }

    Polynomial operator*(const Polynomial &other) const {
        int result[100] = {0};
        for (int i = 0; i <= degree; i++) {
            for (int j = 0; j <= other.degree; j++) {
                result[i + j] += coefficients[i] * other.coefficients[j];
            }
        }
        return Polynomial(result, degree + other.degree + 1);
    }

    friend ostream &operator<<(ostream &os, const Polynomial &p) {
        bool first = true;
        for (int i = p.degree; i >= 0; i--) {
            if (p.coefficients[i] != 0) {
                if (!first) os << (p.coefficients[i] > 0 ? " + " : " - ");
                else if (p.coefficients[i] < 0) os << "-";
                first = false;
                os << (p.coefficients[i] < 0 ? -p.coefficients[i] : p.coefficients[i]);
                if (i > 0) os << "x^" << i;
            }
        }
        if (first) os << "0";
        return os;
    }

    friend class PolynomialUtils;
};

int PolynomialUtils::evaluate(const Polynomial &p, int x) {
    int result = 0, power = 1;
    for (int i = 0; i <= p.degree; i++) {
        result += p.coefficients[i] * power;
        power *= x;
    }
    return result;
}

Polynomial PolynomialUtils::derivative(const Polynomial &p) {
    if (p.degree == 0) return Polynomial();
    int result[100];
    for (int i = 1; i <= p.degree; i++)
        result[i - 1] = p.coefficients[i] * i;
    return Polynomial(result, p.degree);
}

int main() {
    int a[] = {1, 2, 3};
    int b[] = {0, 1, -1};
    Polynomial p1(a, 3), p2(b, 3);
    cout << "P1: " << p1 << "\nP2: " << p2 << endl;
    cout << "P1 + P2: " << (p1 + p2) << endl;
    cout << "P1 - P2: " << (p1 - p2) << endl;
    cout << "P1 * P2: " << (p1 * p2) << endl;
    cout << "P1 evaluated at x=2: " << PolynomialUtils::evaluate(p1, 2) << endl;
    cout << "Derivative of P1: " << PolynomialUtils::derivative(p1) << endl;
    return 0;
}
