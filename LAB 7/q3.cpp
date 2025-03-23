#include <iostream>
#include <string>
using namespace std;

class Currency {
protected:
    double amount;
    string currencyCode;
    string currencySymbol;
    double exchangeRate;

public:
    Currency(double amt, string code, string symbol, double rate)
        : amount(amt), currencyCode(code), currencySymbol(symbol), exchangeRate(rate) {}

    virtual double convertToBase() {
        return amount * exchangeRate;
    }

    virtual double convertTo(Currency& targetCurrency) {
        double baseAmount = convertToBase();
        return baseAmount / targetCurrency.getExchangeRate();
    }

    virtual void displayCurrency() {
        cout << "Currency: " << currencyCode << " Amount: " << currencySymbol << amount << endl;
    }

    double getExchangeRate() {
        return exchangeRate;
    }

    double getAmount() {
        return amount;
    }

    void setAmount(double amt) {
        amount = amt;
    }
};

class Dollar : public Currency {
public:
    Dollar(double amt)
        : Currency(amt, "USD", "$", 1.0) {}

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout << "USD: $" << amount << endl;
    }
};

class Euro : public Currency {
public:
    Euro(double amt)
        : Currency(amt, "EUR", "€", 1.1) {}

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout << "EUR: €" << amount << endl;
    }
};

class Rupee : public Currency {
public:
    Rupee(double amt)
        : Currency(amt, "PKR", "Rs", 0.0036) {}

    double convertToBase() override {
        return amount * exchangeRate;
    }

    void displayCurrency() override {
        cout << "PKR: Rs" << amount << endl;
    }
};

int main() {
    Dollar d(100);
    Euro e(100);
    Rupee r(10000);

    d.displayCurrency();
    e.displayCurrency();
    r.displayCurrency();

    double dollarToEuro = d.convertTo(e);
    double euroToRupee = e.convertTo(r);
    double rupeeToDollar = r.convertTo(d);

    cout << "100 USD in EUR: " << dollarToEuro << " EUR" << endl;
    cout << "100 EUR in PKR: " << euroToRupee << " PKR" << endl;
    cout << "10000 PKR in USD: " << rupeeToDollar << " USD" << endl;

    return 0;
}
