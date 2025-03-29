#include <iostream>
using namespace std;

class Number {
private:
    int value;
public:
    Number(int v) : value(v) {}

    // Prefix decrement: Multiply by 4
    Number& operator--() {
        value *= 4;
        return *this;
    }

    // Postfix decrement: Divide by 4
    Number operator--(int) {
        Number temp = *this; // Store current value
        value /= 4;
        return temp; // Return old value
    }

    void display() const {
        cout << "Value: " << value << endl;
    }
};

int main() {
    Number num(8);

    cout << "Original: ";
    num.display();

    cout << "After Postfix (num--): ";
    num--;  // Divide by 4
    num.display();


    cout << "After Prefix (--num): ";
    --num;  // Multiply by 4
    num.display();

  
    return 0;
}
