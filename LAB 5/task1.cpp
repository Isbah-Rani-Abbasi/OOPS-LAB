# include <iostream>
# include<string>
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
    Engine e; 

public:
    void startCar() {
        e.start();
    }
    
    void stopCar() {
        e.stop();
    }
};

int main() {
    Car car;
    car.startCar();
    car.stopCar();
    return 0;
}

