#include <iostream>
using namespace std;

class Person {
protected:
    int employeeID;
public:
    void getData() {
        cout << "Enter Employee ID: ";
        cin >> employeeID;
    }

    void displayData() const {
        cout << "Employee ID: " << employeeID << endl;
    }
};

class Admin : public Person {
protected:
    string name;
    float monthlyIncome;
public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    float bonus() const {
        return (monthlyIncome * 12) * 0.05;
    }

    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }
};

class Accounts : public Person {
protected:
    string name;
    float monthlyIncome;
public:
    void getData() {
        Person::getData();
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter Monthly Income: ";
        cin >> monthlyIncome;
    }

    float bonus() const {
        return (monthlyIncome * 12) * 0.05;
    }

    void displayData() const {
        Person::displayData();
        cout << "Name: " << name << endl;
        cout << "Monthly Income: $" << monthlyIncome << endl;
        cout << "Annual Bonus: $" << bonus() << endl;
    }
};

int main() {
    Admin adminEmp;
    Accounts accountsEmp;

    cout << "Enter Admin Employee Details:\n";
    adminEmp.getData();

    cout << "\nEnter Accounts Employee Details:\n";
    accountsEmp.getData();

    cout << "\n--- Employee Details ---\n";
    adminEmp.displayData();
    cout << endl;
    accountsEmp.displayData();

    return 0;
}
