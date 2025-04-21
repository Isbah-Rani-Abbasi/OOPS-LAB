#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Student {
protected:
    string name;
    int id;

public:
    virtual void setDetails(const string& n, int i) {
        name = n;
        id = i;
    }

    virtual void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "ID: " << id << endl;
    }

    // Pure virtual function
    virtual float getTuition(const string& status, int creditHours) = 0;

    virtual ~Student() {}
};

// Derived class
class GraduateStudent : public Student {
private:
    string researchTopic;

public:
    void setResearchTopic(const string& topic) {
        researchTopic = topic;
    }

    string getResearchTopic() const {
        return researchTopic;
    }

    float getTuition(const string& status, int creditHours) override {
        if (status == "undergraduate") {
            return creditHours * 200.0f;
        } else if (status == "graduate") {
            return creditHours * 300.0f;
        } else if (status == "doctoral") {
            return creditHours * 400.0f;
        } else {
            cout << "Invalid status!" << endl;
            return 0.0f;
        }
    }

    void displayDetails() override {
        Student::displayDetails();
        cout << "Research Topic: " << researchTopic << endl;
    }
};

// Main function for demonstration
int main() {
    GraduateStudent gs;

    gs.setDetails("Alice Smith", 101);
    gs.setResearchTopic("AI in Healthcare");

    string status = "graduate";
    int credits = 9;

    cout << "\n--- Graduate Student Info ---\n";
    gs.displayDetails();

    float tuition = gs.getTuition(status, credits);
    cout << "Status: " << status << "\nCredit Hours: " << credits << "\nTuition: $" << tuition << endl;

    return 0;
}
