#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Position {
    float x;
    float y;
};

class Shape {
protected:
    Position position;
    string color;
    float borderThickness;

public:
    Shape(Position p, string c, float t) : position(p), color(c), borderThickness(t) {}

    virtual void draw(){} 
    virtual void calculateArea(){} 
    virtual void calculatePerimeter(){} 
   
};

class Circle : public Shape {
    float radius;

public:
    Circle(float r, Position p, string c, float t) : radius(r), Shape(p, c, t) {}

    void draw() override {
        cout << "A circle of " << color << " color with border thickness "
             << borderThickness << "cm has been drawn at center position ("
             << position.x << ", " << position.y << ")." << endl;
    }

    void calculateArea() override {
        cout << "The area of the circle is " << 3.14 * radius * radius << " sq. units." << endl;
    }

    void calculatePerimeter() override {
        cout << "The perimeter (circumference) of the circle is " << 2 * 3.14 * radius << " units." << endl;
    }
};

class Rectangle : public Shape {
    float height;
    float width;

public:
    Rectangle(float h, float w, Position p, string c, float t) : height(h), width(w), Shape(p, c, t) {}

    void draw() override {
        cout << "A rectangle of " << color << " color with border thickness "
             << borderThickness << "cm has been drawn at top-left corner position ("
             << position.x << ", " << position.y << ")." << endl;
    }

    void calculateArea() override {
        cout << "The area of the rectangle is " << height * width << " sq. units." << endl;
    }

    void calculatePerimeter() override {
        cout << "The perimeter of the rectangle is " << 2 * (height + width) << " units." << endl;
    }
};

class Triangle : public Shape {
    float a;
    float b;
    float c;

public:
    Triangle(float sideA, float sideB, float sideC, Position p, string color, float t)
        : a(sideA), b(sideB), c(sideC), Shape(p, color, t) {}

    void draw() override {
        cout << "A triangle of " << color << " color with border thickness "
             << borderThickness << "cm has been drawn at position ("
             << position.x << ", " << position.y << ")." << endl;
    }

    void calculateArea() override {
        float s = (a + b + c) / 2;
        float area = sqrt(s * (s - a) * (s - b) * (s - c));
        cout << "The area of the triangle is " << area << " sq. units." << endl;
    }

    void calculatePerimeter() override {
        cout << "The perimeter of the triangle is " << (a + b + c) << " units." << endl;
    }
};

class Polygon : public Shape {
    int numSides;
    float sideLength;

public:
    Polygon(int n, float s, Position p, string color, float t)
        : numSides(n), sideLength(s), Shape(p, color, t) {}

    void draw() override {
        cout << "A polygon with " << numSides << " sides of " << color << " color and border thickness "
             << borderThickness << "cm has been drawn at position ("
             << position.x << ", " << position.y << ")." << endl;
    }

    void calculateArea() override {
        float area = (numSides * sideLength * sideLength) / (4 * tan(M_PI / numSides));
        cout << "The area of the polygon is " << area << " sq. units." << endl;
    }

    void calculatePerimeter() override {
        float perimeter = numSides * sideLength;
        cout << "The perimeter of the polygon is " << perimeter << " units." << endl;
    }
};

int main() {
    Position center = {0, 0};
    Position topLeft = {5, 10};
    Position topRight = {10, 10};
    Position bottomRight = {15, 0};

    Circle c(3, center, "red", 2.5);
    Rectangle r(4, 6, topLeft, "green", 1.5);
    Triangle t(3, 4, 5, topRight, "blue", 1.0);
    Polygon p(5, 7, bottomRight, "yellow", 2.0);

    Shape* s;

    s = &c;
    s->draw();
    s->calculateArea();
    s->calculatePerimeter();
    cout << endl;

    s = &r;
    s->draw();
    s->calculateArea();
    s->calculatePerimeter();
    cout << endl;

    s = &t;
    s->draw();
    s->calculateArea();
    s->calculatePerimeter();
    cout << endl;

    s = &p;
    s->draw();
    s->calculateArea();
    s->calculatePerimeter();
    cout << endl;

    return 0;
}
