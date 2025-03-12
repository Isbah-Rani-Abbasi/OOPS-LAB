#include <iostream>
#include <string>
using namespace std;

class BankAccount {
protected:
    string accountNumber;
    double balance;
    bool frozen = false;

public:
    BankAccount(string accNum, double bal = 0) : accountNumber(accNum), balance(bal) {}
    virtual ~BankAccount() {}

    virtual void deposit(double amount) {
        if (frozen) return notify("Frozen! Deposit blocked.");
        balance += amount;
        notify("Deposited $" + to_string(amount));
    }

    virtual void withdraw(double amount) {
        if (frozen) return notify("Frozen! Withdraw blocked.");
        if (balance >= amount) {
            balance -= amount;
            notify("Withdrew $" + to_string(amount));
        } else notify("Insufficient funds!");
    }

    virtual void display() const {
        cout << accountNumber << " | Balance: $" << balance << (frozen ? " [Frozen]" : "") << endl;
    }

    void freeze()   { frozen = true;  notify("Account frozen!"); }
    void unfreeze() { frozen = false; notify("Account unfrozen!"); }
    string getAccNum() const { return accountNumber; }

protected:
    void notify(string msg) const { cout << "[" << accountNumber << "] " << msg << endl; }
};

class SavingsAccount : public BankAccount {
    double interestRate = 0.02;
public:
    SavingsAccount(string accNum, double bal = 0) : BankAccount(accNum, bal) {}
    void applyInterest() {
        if (frozen) return notify("Frozen! Interest skipped.");
        double interest = balance * interestRate;
        balance += interest;
        notify("Interest $" + to_string(interest) + " applied.");
    }
    void display() const override {
        cout << "[Savings] "; BankAccount::display();
    }
};

class CheckingAccount : public BankAccount {
    double overdraftLimit = 500;
public:
    CheckingAccount(string accNum, double bal = 0) : BankAccount(accNum, bal) {}
    void withdraw(double amount) override {
        if (frozen) return notify("Frozen! Withdraw blocked.");
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            notify("Withdrew $" + to_string(amount));
            if (balance < 0) notify("Overdraft alert!");
        } else notify("Overdraft limit exceeded!");
    }
    void display() const override {
        cout << "[Checking] "; BankAccount::display();
    }
};

class BusinessAccount : public BankAccount {
    double taxRate = 0.05;
public:
    BusinessAccount(string accNum, double bal = 0) : BankAccount(accNum, bal) {}
    void deposit(double amount) override {
        if (frozen) return notify("Frozen! Deposit blocked.");
        double tax = amount * taxRate;
        balance += (amount - tax);
        notify("Deposited $" + to_string(amount - tax) + " after tax $" + to_string(tax));
    }
    void display() const override {
        cout << "[Business] "; BankAccount::display();
    }
};

class User {
protected:
    string name;
public:
    User(string uname) : name(uname) {}
    virtual ~User() {}
    virtual void deposit(BankAccount& acc, double amt) { acc.deposit(amt); }
    virtual void withdraw(BankAccount& acc, double amt) { acc.withdraw(amt); }
    virtual string role() const = 0;
};

class Customer : public User {
public:
    Customer(string uname) : User(uname) {}
    string role() const override { return "Customer"; }
};

class Employee : public User {
public:
    Employee(string uname) : User(uname) {}
    void freezeAccount(BankAccount& acc) { acc.freeze(); }
    void unfreezeAccount(BankAccount& acc) { acc.unfreeze(); }
};

class Teller : public Employee {
public:
    Teller(string uname) : Employee(uname) {}
    string role() const override { return "Teller"; }
};

class Manager : public Employee {
public:
    Manager(string uname) : Employee(uname) {}
    string role() const override { return "Manager"; }
    void overrideLimit(BankAccount& acc) {
        cout << "[Manager] Overriding limits on account " << acc.getAccNum() << endl;
    }
};

int main() {
    const int numAcc = 3, numUsers = 3;

    BankAccount** accounts = new BankAccount*[numAcc];
    accounts[0] = new SavingsAccount("SAV123", 1000);
    accounts[1] = new CheckingAccount("CHK456", 500);
    accounts[2] = new BusinessAccount("BUS789", 2000);

    User** users = new User*[numUsers];
    users[0] = new Customer("Alice");
    users[1] = new Teller("Bob");
    users[2] = new Manager("Charlie");

    for (int i = 0; i < numUsers; ++i) {
        cout << users[i]->role() << " " << i+1 << " actions:\n";
        for (int j = 0; j < numAcc; ++j) users[i]->deposit(*accounts[j], 100);
        for (int j = 0; j < numAcc; ++j) users[i]->withdraw(*accounts[j], 50);
        cout << endl;
    }

    Teller* teller = dynamic_cast<Teller*>(users[1]);
    if (teller) teller->freezeAccount(*accounts[0]);

    Manager* manager = dynamic_cast<Manager*>(users[2]);
    if (manager) manager->overrideLimit(*accounts[1]);

    cout << "\n=== Account Status ===\n";
    for (int i = 0; i < numAcc; ++i) accounts[i]->display();

    SavingsAccount* sav = dynamic_cast<SavingsAccount*>(accounts[0]);
    if (sav) sav->applyInterest();

    cout << "\n=== Final Account Status ===\n";
    for (int i = 0; i < numAcc; ++i) accounts[i]->display();

    for (int i = 0; i < numAcc; ++i) delete accounts[i];
    delete[] accounts;

    for (int i = 0; i < numUsers; ++i) delete users[i];
    delete[] users;

    return 0;
}

