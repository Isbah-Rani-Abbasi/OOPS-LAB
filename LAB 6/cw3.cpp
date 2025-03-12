#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int id;
    string name;
public:
    Employee(int i, string n) : id(i), name(n) {}
    virtual void show() {
        cout << "ID: " << id << ", Name: " << name << endl;
    }
    virtual ~Employee() {}
};

class IOrderTaker {
public:
    virtual void takeOrder(string order) = 0;
    virtual ~IOrderTaker() {}
};

class IOrderPreparer {
public:
    virtual void prepareOrder(string order) = 0;
    virtual ~IOrderPreparer() {}
};

class IBiller {
public:
    virtual void generateBill(double amount) = 0;
    virtual ~IBiller() {}
};

class Waiter : public Employee, public IOrderTaker {
public:
    Waiter(int i, string n) : Employee(i, n) {}
    void takeOrder(string order) override {
        show();
        cout << "Taking order: " << order << endl;
    }
};

class Chef : public Employee, public IOrderPreparer {
public:
    Chef(int i, string n) : Employee(i, n) {}
    void prepareOrder(string order) override {
        show();
        cout << "Preparing order: " << order << endl;
    }
};

class Cashier : public Employee, public IBiller {
public:
    Cashier(int i, string n) : Employee(i, n) {}
    void generateBill(double amount) override {
        show();
        cout << "Generating bill: $" << amount << endl;
    }
};

class Manager : public Employee, public IOrderTaker, public IBiller {
public:
    Manager(int i, string n) : Employee(i, n) {}
    void takeOrder(string order) override {
        show();
        cout << "Manager taking order: " << order << endl;
    }
    void generateBill(double amount) override {
        show();
        cout << "Manager generating bill: $" << amount << endl;
    }
};

class Menu {
protected:
    string name;
public:
    Menu(string n) : name(n) {}
    virtual double calculateTotal(double basePrice) = 0;
    virtual ~Menu() {}
};

class FoodMenu : public Menu {
public:
    FoodMenu() : Menu("Food Menu") {}
    double calculateTotal(double basePrice) override {
        return basePrice;
    }
};

class BeverageMenu : public Menu {
public:
    BeverageMenu() : Menu("Beverage Menu") {}
    double calculateTotal(double basePrice) override {
        return basePrice * 1.1;
    }
};

int main() {
    const int empCount = 4;
    Employee** employees = new Employee*[empCount];
    employees[0] = new Waiter(1, "Alice");
    employees[1] = new Chef(2, "Bob");
    employees[2] = new Cashier(3, "Charlie");
    employees[3] = new Manager(4, "Diana");

    for (int i = 0; i < empCount; ++i) {
        employees[i]->show();
    }

    const int takerCount = 2;
    IOrderTaker** takers = new IOrderTaker*[takerCount];
    takers[0] = dynamic_cast<IOrderTaker*>(employees[0]);
    takers[1] = dynamic_cast<IOrderTaker*>(employees[3]);

    for (int i = 0; i < takerCount; ++i) {
        if (takers[i]) takers[i]->takeOrder("Pasta");
    }

    const int preparerCount = 1;
    IOrderPreparer** preparers = new IOrderPreparer*[preparerCount];
    preparers[0] = dynamic_cast<IOrderPreparer*>(employees[1]);

    for (int i = 0; i < preparerCount; ++i) {
        if (preparers[i]) preparers[i]->prepareOrder("Pasta");
    }

    const int billerCount = 2;
    IBiller** billers = new IBiller*[billerCount];
    billers[0] = dynamic_cast<IBiller*>(employees[2]);
    billers[1] = dynamic_cast<IBiller*>(employees[3]);

    for (int i = 0; i < billerCount; ++i) {
        if (billers[i]) billers[i]->generateBill(25.0);
    }

    const int menuCount = 2;
    Menu** menus = new Menu*[menuCount];
    menus[0] = new FoodMenu();
    menus[1] = new BeverageMenu();

    double prices[2] = {20.0, 5.0};
    for (int i = 0; i < menuCount; ++i) {
        double total = menus[i]->calculateTotal(prices[i]);
        cout << "Menu " << i+1 << " total: $" << total << endl;
    }

    for (int i = 0; i < empCount; ++i) delete employees[i];
    delete[] employees;

    for (int i = 0; i < menuCount; ++i) delete menus[i];
    delete[] menus;

    delete[] takers;
    delete[] preparers;
    delete[] billers;

    return 0;
}


