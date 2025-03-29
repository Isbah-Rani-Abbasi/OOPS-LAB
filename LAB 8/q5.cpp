#include <iostream>
using namespace std;

class Shape {
private:
    float length, width;
public:
    Shape(float l = 0, float w = 0) : length(l), width(w) {}

    float Area() const {
        return length * width;
    }

    Shape operator+(const Shape& other) const {
        return Shape(Area() + other.Area(), 1); 
    }

    void display() const {
        cout << "Area: " << Area() << endl;
    }
};

int main() {
    Shape shape1(5, 4); 
    Shape shape2(6, 3);  

    cout << "Shape 1 ";
    shape1.display();

    cout << "Shape 2 ";
    shape2.display();

    Shape totalArea = shape1 + shape2;
    
    cout << "Total Area ";
    totalArea.display();

    return 0;
}
