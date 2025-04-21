#include <iostream>
#include <string>
using namespace std;

class Wallet {
private:
    double balance;
    double dailyDepositLimit;
    double dailyWithdrawLimit;
    double dailyDeposited;
    double dailyWithdrawn;

public:
    Wallet(double depositLimit = 5000.0, double withdrawLimit = 2000.0) {
        balance = 0.0;
        dailyDepositLimit = depositLimit;
        dailyWithdrawLimit = withdrawLimit;
        dailyDeposited = 0.0;
        dailyWithdrawn = 0.0;
    }

    bool deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount.\n";
            return false;
        }
        if ((dailyDeposited + amount) > dailyDepositLimit) {
            cout << "Deposit limit exceeded.\n";
            return false;
        }
        balance += amount;
        dailyDeposited += amount;
        cout << "Deposited: " << amount << ". New balance: " << balance << "\n";
        return true;
    }

    bool withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount.\n";
            return false;
        }
        if ((dailyWithdrawn + amount) > dailyWithdrawLimit) {
            cout << "Withdrawal limit exceeded.\n";
            return false;
        }
        if (amount > balance) {
            cout << "Insufficient funds.\n";
            return false;
        }
        balance -= amount;
        dailyWithdrawn += amount;
        cout << "Withdrawn: " << amount << ". New balance: " << balance << "\n";
        return true;
    }

    double checkBalance() const {
        return balance;
    }

    void resetDailyLimits() {
        dailyDeposited = 0.0;
        dailyWithdrawn = 0.0;
    }
};

class User {
private:
    int userID;
    string name;
    Wallet* wallet;

public:
    User(int id, string n) {
        userID = id;
        name = n;
        wallet = new Wallet();
    }

    ~User() {
        delete wallet;
    }

    void deposit(double amount) {
        wallet->deposit(amount);
    }

    void withdraw(double amount) {
        wallet->withdraw(amount);
    }

    void checkBalance() const {
        cout << "Balance for " << name << ": " << wallet->checkBalance() << "\n";
    }

    void resetLimits() {
        wallet->resetDailyLimits();
    }
};

int main() {
    User u1(101, "Isbah");
    User u2(102, "Faris");

    u1.deposit(3000);
    u1.deposit(2500); 
    u1.withdraw(1000);
    u1.withdraw(1200); 
    u1.withdraw(500); 
    u1.checkBalance();

    u2.deposit(2000);
    u2.withdraw(500);
    u2.checkBalance();

    
    u1.resetLimits();
    u1.deposit(2000);
    u1.checkBalance();

    return 0;
} 
