# include <iostream>

using namespace std;

class Engine {
private:
    bool isRunning;

public:
    Engine() : isRunning(false) {}
    
    void start() {
        if (!isRunning) {
            isRunning = true;
            cout << "Engine started" << endl;
        } else {
            cout << "Engine is already running" << endl;
        }
    }
    
    void stop() {
        if (isRunning) {
            isRunning = false;
            cout << "Engine stopped" << endl;
        } else {
            cout << "Engine is already stopped" << endl;
        }
    }
};

class Car {
private:
    Engine engine; 
    string name;
    int id;

public:
    Car(string carName, int carId) : name(carName), id(carId) {}

    ~Car() {
        cout << "Car " << name << " (ID: " << id << ") destroyed" << endl;
    }

    void startCar() {
        engine.start();
    }
    
    void stopCar() {
        engine.stop();
    }

    string getName() const {
        return name;
    }

    int getId() const {
        return id;
    }
};

class Garage {
private:
    Car* cars[10]; 
    int carCount;

public:
    Garage() : carCount(0) {}

    void parkCar(Car* car) {
        if (carCount < 10) {
            cars[carCount++] = car;
        } else {
            cout << "Garage is full!" << endl;
        }
    }

    void listCars() const {
        cout << "Cars in garage:" << endl;
        for (int i = 0; i < carCount; ++i) {
            if (cars[i]) { 
                cout << "ID: " << cars[i]->getId() << ", Name: " << cars[i]->getName() << endl;
            } else {
                cout << "Warning: Dangling pointer detected!" << endl;
            }
        }
    }
};

void testGarage() {
    Garage tempGarage;
    {
        Car tempCar("Nissan", 4);
        tempGarage.parkCar(&tempCar);
        tempGarage.listCars(); 
    } 

    cout << "After tempCar is destroyed:" << endl;
    tempGarage.listCars(); 
}

int main() {
    Car car1("Toyota", 1);
    Car car2("Honda", 2);
    Car car3("Ford", 3);

    Garage myGarage;
    myGarage.parkCar(&car1);
    myGarage.parkCar(&car2);
    myGarage.parkCar(&car3);

    myGarage.listCars();

    
    testGarage();

    return 0;
}

