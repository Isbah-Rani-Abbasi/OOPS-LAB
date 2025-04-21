#include <iostream>
#include <string>
using namespace std;

// Abstract base class Car
class Car {
protected:
    string model;
    float price;

public:
    // Constructor
    Car(string m = "", float p = 0.0f) {
        model = m;
        price = p;
    }

    // Getter methods
    string getModel() {
        return model;
    }

    float getPrice() {
        return price;
    }

    // Setter for model
    void setModel(string m) {
        model = m;
    }

    // Pure virtual method (abstract)
    virtual void setPrice(float p) = 0;

    // Virtual destructor
    virtual ~Car() {}
};

// Derived class Color
class Color : public Car {
private:
    string color;

public:
    Color(string m, string c) {
        model = m;
        color = c;
    }

    void setColor(string c) {
        color = c;
    }

    string getColor() {
        return color;
    }

    void setPrice(float p) {
        // Add a small price adjustment based on color
        if (color == "Red" || color == "Black")
            price = p + 2000;
        else
            price = p;
    }
};

// Derived class Company
class Company : public Car {
private:
    string company;

public:
    Company(string m, string comp) {
        model = m;
        company = comp;
    }

    void setCompany(string comp) {
        company = comp;
    }

    string getCompany() {
        return company;
    }

    void setPrice(float p) {
        // Price depends on the company
        if (company == "BMW" || company == "Mercedes")
            price = p + 10000;
        else
            price = p;
    }
};

// Main function demonstrating the use
int main() {
    Color myCar1("Model X", "Red");
    myCar1.setPrice(50000);
    cout << "Car 1 (Color-Based):\n";
    cout << "Model: " << myCar1.getModel() << endl;
    cout << "Color: " << myCar1.getColor() << endl;
    cout << "Price: $" << myCar1.getPrice() << endl << endl;

    Company myCar2("Model S", "BMW");
    myCar2.setPrice(60000);
    cout << "Car 2 (Company-Based):\n";
    cout << "Model: " << myCar2.getModel() << endl;
    cout << "Company: " << myCar2.getCompany() << endl;
    cout << "Price: $" << myCar2.getPrice() << endl;

    return 0;
}

