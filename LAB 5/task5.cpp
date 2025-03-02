#include <iostream>
#include <string>
using namespace std;

class Car {
public:
    mutable int horse_pw;
    mutable int seat_cap;
    mutable int no_of_sp;

    Car() : horse_pw(0), seat_cap(0), no_of_sp(0) {}

    void sethorse_pw(int h) const { horse_pw = h; }
    void setcap(int c) const { seat_cap = c; }
    void setsp(int hn) const { no_of_sp = hn; }

    int getpw() const { return horse_pw; }
    int getcap() const { return seat_cap; }
    int getsp() const { return no_of_sp; }
};

int main() {
    const Car c;
    c.sethorse_pw(10);
    c.setcap(20);
    c.setsp(30);
    cout << "Horse power of car is:" << c.getpw() << endl
         << "Seat capacity of car is:" << c.getcap() << endl
         << "No of seats of car is:" << c.getsp() << endl;

    return 0;
}
