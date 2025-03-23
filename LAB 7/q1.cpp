#include<iostream>
#include<string>
using namespace std;

class Account {
protected:
    const int acc_no;
    double balance;
    const string acc_hd_name;
    string acc_type;

public:
    Account(int a, double b, string n, string t) : acc_no(a), balance(b), acc_hd_name(n), acc_type(t) {}
    virtual ~Account() {}

    double getBalance() {
        return balance;
    }

    void setBalance(double b) {
        balance = b;
    }

    void deposit(double a) {
        if (a <= 0) {
            cout << "Invalid deposit amount!" << endl;
        } else {
            balance += a;
            cout << "Deposited: " << a << ". New balance: " << balance << endl;
        }
    }

    virtual void withdraw(double a) {
        if (a <= 0 || a > balance) {
            cout << "Insufficient funds or invalid amount!" << endl;
        } else {
            balance -= a;
            cout << "Withdrew: " << a << ". New balance: " << balance << endl;
        }
    }

    virtual void calculateInterest() {
        cout << "No specific interest calculation for base Account." << endl;
    }

    virtual void printStatement() {
        cout << "------- Account Statement -------" << endl;
        getInfo();
    }

    void getInfo() {
        cout << "User Name     : " << acc_hd_name << endl;
        cout << "Account Type  : " << acc_type << endl;
        cout << "Account No.   : " << acc_no << endl;
        cout << "Current Balance: " << balance << endl;
    }
};

class SavingAccount : public Account {
private:
    double interestRate;
    double minimumBalance;

public:
    SavingAccount(int no, double b, string n, string t, double i, double m)
        : Account(no, b, n, t), interestRate(i), minimumBalance(m) {}

    void withdraw(double a) override {
        if (balance - a < minimumBalance || a <= 0) {
            cout << "Withdrawal denied! Must maintain minimum balance of " << minimumBalance << "." << endl;
        } else {
            balance -= a;
            cout << "Withdrawn: " << a << ". Remaining balance: " << balance << endl;
        }
    }

    void calculateInterest() override {
        double interest = balance * (interestRate / 100);
        balance += interest;
        cout << "Interest of " << interest << " applied. New balance: " << balance << endl;
    }

    void printStatement() override {
        cout << "------- Saving Account Statement -------" << endl;
        getInfo();
        cout << "Interest Rate  : " << interestRate << "%" << endl;
        cout << "Minimum Balance: " << minimumBalance << endl;
    }
};

class FixedDepositAccount : public Account {
private:
    double fixedInterestRate;
    string maturityDate;
    bool matured;

public:
    FixedDepositAccount(int no, double b, string n, string t, double i, string mDate)
        : Account(no, b, n, t), fixedInterestRate(i), maturityDate(mDate), matured(false) {}

    void withdraw(double a) override {
        if (!matured) {
            cout << "Cannot withdraw! Account has not reached maturity (" << maturityDate << ")." << endl;
        } else if (a <= 0 || a > balance) {
            cout << "Invalid withdrawal!" << endl;
        } else {
            balance -= a;
            cout << "Withdrawn: " << a << ". Remaining balance: " << balance << endl;
        }
    }

    void calculateInterest() override {
        if (!matured) {
            double interest = balance * (fixedInterestRate / 100);
            balance += interest;
            matured = true;
            cout << "Fixed deposit matured! Interest of " << interest << " applied. New balance: " << balance << endl;
        } else {
            cout << "Interest already applied. Current balance: " << balance << endl;
        }
    }

    void printStatement() override {
        cout << "------- Fixed Deposit Account Statement -------" << endl;
        getInfo();
        cout << "Fixed Interest Rate: " << fixedInterestRate << "%" << endl;
        cout << "Maturity Date      : " << maturityDate << endl;
    }
};

int main() {
    SavingAccount sa(1001, 5000.0, "Ali Khan", "Saving", 5.0, 1000.0);
    sa.deposit(2000);
    sa.withdraw(4000);
    sa.calculateInterest();
    sa.printStatement();

    FixedDepositAccount fda(2001, 10000.0, "Sara Ahmed", "Fixed Deposit", 8.0, "31-Dec-2025");
    fda.calculateInterest();
    fda.withdraw(5000);
    fda.printStatement();

    return 0;
}
