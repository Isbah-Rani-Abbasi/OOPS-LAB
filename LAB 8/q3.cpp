#include <iostream>
#include <string>
using namespace std;

class BigInteger {
private:
    string number;
    bool isNegative;

    static string addStrings(const string& num1, const string& num2) {
        string result = "";
        int carry = 0, sum;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0 || j >= 0 || carry) {
            sum = carry;
            if (i >= 0) sum += num1[i--] - '0';
            if (j >= 0) sum += num2[j--] - '0';
            carry = sum / 10;
            result = char(sum % 10 + '0') + result;
        }
        return result;
    }

    static string subtractStrings(const string& num1, const string& num2) {
        string result = "";
        int borrow = 0, diff;
        int i = num1.size() - 1, j = num2.size() - 1;
        while (i >= 0) {
            diff = (num1[i] - '0') - (j >= 0 ? num2[j--] - '0' : 0) - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else borrow = 0;
            result = char(diff + '0') + result;
            i--;
        }
        while (result.size() > 1 && result[0] == '0') result.erase(0, 1);
        return result;
    }

public:
    BigInteger(string num = "0") {
        if (num[0] == '-') {
            isNegative = true;
            num = num.substr(1);
        } else isNegative = false;
        number = num;
    }

    BigInteger operator+(const BigInteger& other) const {
        if (isNegative == other.isNegative) {
            return BigInteger((isNegative ? "-" : "") + addStrings(number, other.number));
        } else {
            if (number >= other.number)
                return BigInteger((isNegative ? "-" : "") + subtractStrings(number, other.number));
            else
                return BigInteger((other.isNegative ? "-" : "") + subtractStrings(other.number, number));
        }
    }

    BigInteger operator-(const BigInteger& other) const {
        BigInteger negOther = other;
        negOther.isNegative = !other.isNegative;
        return *this + negOther;
    }

    bool operator==(const BigInteger& other) const {
        return isNegative == other.isNegative && number == other.number;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    bool operator<(const BigInteger& other) const {
        if (isNegative != other.isNegative) return isNegative;
        if (number.size() != other.number.size())
            return (number.size() < other.number.size()) ^ isNegative;
        return (number < other.number) ^ isNegative;
    }

    bool operator>(const BigInteger& other) const {
        return other < *this;
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    friend ostream& operator<<(ostream& os, const BigInteger& bi) {
        if (bi.isNegative) os << "-";
        os << bi.number;
        return os;
    }

    friend istream& operator>>(istream& is, BigInteger& bi) {
        is >> bi.number;
        if (bi.number[0] == '-') {
            bi.isNegative = true;
            bi.number = bi.number.substr(1);
        } else bi.isNegative = false;
        return is;
    }
};

int main() {
    BigInteger num1, num2;
    cin >> num1 >> num2;
    cout << "Sum: " << (num1 + num2) << endl;
    cout << "Difference: " << (num1 - num2) << endl;
    return 0;
}
