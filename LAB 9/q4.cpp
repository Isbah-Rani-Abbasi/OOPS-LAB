#include <iostream>
#include <string>
using namespace std;


class Flight;

class Passenger {
private:
    string passengerID;
    string name;
    bool isBooked;
    int seatNumber;

public:
    Passenger(string id, string n) {
        passengerID = id;
        name = n;
        isBooked = false;
        seatNumber = -1;
    }

    string getID() const { return passengerID; }
    string getName() const { return name; }

    
    void requestBooking(Flight& f);
    void requestCancellation(Flight& f);
    void requestUpgrade(Flight& f);

    friend class Flight; 
};

class Flight {
private:
    string flightNumber;
    string departure;
    string arrival;
    int capacity;
    int bookedCount;

    Passenger** bookedPassengers;
    int* seatNumbers;

public:
    Flight(string number, string from, string to, int cap) {
        flightNumber = number;
        departure = from;
        arrival = to;
        capacity = cap;
        bookedCount = 0;

        bookedPassengers = new Passenger*[capacity];
        seatNumbers = new int[capacity];
    }

    bool bookSeat(Passenger* p) {
        if (bookedCount >= capacity) {
            cout << "Booking failed: Flight full.\n";
            return false;
        }
        if (p->isBooked) {
            cout << "Booking failed: Passenger already booked.\n";
            return false;
        }

        bookedPassengers[bookedCount] = p;
        seatNumbers[bookedCount] = bookedCount + 1;
        p->isBooked = true;
        p->seatNumber = bookedCount + 1;
        bookedCount++;

        cout << "Seat booked successfully for " << p->getName()
             << " on Flight " << flightNumber << ", Seat #" << p->seatNumber << ".\n";
        return true;
    }

    bool cancelSeat(Passenger* p) {
        if (!p->isBooked) {
            cout << "Cancellation failed: No booking found for " << p->getName() << ".\n";
            return false;
        }

        bool found = false;
        for (int i = 0; i < bookedCount; i++) {
            if (bookedPassengers[i] == p) {
      
                for (int j = i; j < bookedCount - 1; j++) {
                    bookedPassengers[j] = bookedPassengers[j + 1];
                    seatNumbers[j] = seatNumbers[j + 1];
                }
                bookedCount--;
                found = true;
                break;
            }
        }

        if (found) {
            p->isBooked = false;
            p->seatNumber = -1;
            cout << "Booking canceled for " << p->getName() << ".\n";
            return true;
        } else {
            cout << "Cancellation error: Passenger not found.\n";
            return false;
        }
    }

    bool upgradeSeat(Passenger* p) {
        if (!p->isBooked) {
            cout << "Upgrade failed: Passenger not booked.\n";
            return false;
        }
        cout << "Seat upgraded for " << p->getName()
             << " on Flight " << flightNumber << ". Enjoy premium service!\n";
        return true;
    }

    void printManifest() const {
        cout << "Flight " << flightNumber << " | " << departure << " -> " << arrival << "\n";
        cout << "Booked Passengers: " << bookedCount << "/" << capacity << "\n";
        for (int i = 0; i < bookedCount; i++) {
            cout << "- " << bookedPassengers[i]->getName()
                 << " (Seat #" << seatNumbers[i] << ")\n";
        }
        cout << endl;
    }

    ~Flight() {
        delete[] bookedPassengers;
        delete[] seatNumbers;
    }
};


void Passenger::requestBooking(Flight& f) {
    f.bookSeat(this);
}

void Passenger::requestCancellation(Flight& f) {
    f.cancelSeat(this);
}

void Passenger::requestUpgrade(Flight& f) {
    f.upgradeSeat(this);
}


int main() {
    Flight f1("AI101", "New York", "London", 3);

    Passenger p1("P001", "Alice");
    Passenger p2("P002", "Bob");
    Passenger p3("P003", "Charlie");
    Passenger p4("P004", "Diana");

    p1.requestBooking(f1);
    p2.requestBooking(f1);
    p3.requestBooking(f1);
    p4.requestBooking(f1); 

    f1.printManifest();

    p2.requestUpgrade(f1);
    p2.requestCancellation(f1);
    f1.printManifest();

    p4.requestBooking(f1); 
    f1.printManifest();

    return 0;
}
