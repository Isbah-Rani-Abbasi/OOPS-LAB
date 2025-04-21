#include <iostream>
#include <string>
using namespace std;

// Base class Person
class Person {
protected:
    string name;
    int id;

public:
    virtual void getdata() {
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cin.ignore(); // to handle getline after cin
    }

    virtual void displaydata() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }

    virtual void bonus() {
        cout << "Bonus not defined for base Person.\n";
    }

    virtual ~Person() {}
};

// Derived class Admin
class Admin : virtual public Person {
protected:
    float salary;

public:
    void getdata() override {
        Person::getdata();
        cout << "Enter Admin Salary: ";
        cin >> salary;
        cin.ignore();
    }

    void displaydata() override {
        Person::displaydata();
        cout << "Admin Salary: $" << salary << endl;
    }

    void bonus() override {
        cout << "Admin Bonus: $" << salary * 0.1 << endl;
    }
};

// Derived class Account
class Account : virtual public Person {
protected:
    float accountBalance;

public:
    void getdata() override {
        Person::getdata();
        cout << "Enter Account Balance: ";
        cin >> accountBalance;
        cin.ignore();
    }

    void displaydata() override {
        Person::displaydata();
        cout << "Account Balance: $" << accountBalance << endl;
    }

    void bonus() override {
        cout << "Account Bonus: $" << accountBalance * 0.05 << endl;
    }
};

// Master class derived from Admin and Account
class Master : public Admin, public Account {
public:
    void getdata() override {
        Person::getdata(); // Only get Person data once
        cout << "Enter Admin Salary: ";
        cin >> salary;
        cout << "Enter Account Balance: ";
        cin >> accountBalance;
        cin.ignore();
    }

    void displaydata() override {
        Person::displaydata();
        cout << "Admin Salary: $" << salary << endl;
        cout << "Account Balance: $" << accountBalance << endl;
    }

    void bonus() override {
        float totalBonus = (salary * 0.1f) + (accountBalance * 0.05f);
        cout << "Total Bonus (Admin + Account): $" << totalBonus << endl;
    }
};

// Main function to demonstrate usage
int main() {
    Person* ptr;  // base class pointer

    Master m1;
    cout << "--- Enter Master Employee Data ---" << endl;
    ptr = &m1;
    ptr->getdata();

    cout << "\n--- Displaying Master Employee Data ---" << endl;
    ptr->displaydata();

    cout << "\n--- Calculating Bonus ---" << endl;
    ptr->bonus();

    return 0;
}
