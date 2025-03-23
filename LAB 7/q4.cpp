#include <iostream>
#include <string>
using namespace std;

class Person {
protected:
    string name;
    string id;
    string address;
    string phoneNumber;
    string email;

public:
    Person(string n, string i, string addr, string phone, string mail)
        : name(n), id(i), address(addr), phoneNumber(phone), email(mail) {}

    virtual void displayInfo() {
        cout << "Name       : " << name << endl;
        cout << "ID         : " << id << endl;
        cout << "Address    : " << address << endl;
        cout << "Phone No.  : " << phoneNumber << endl;
        cout << "Email      : " << email << endl;
    }

    virtual void updateInfo(string addr, string phone, string mail) {
        address = addr;
        phoneNumber = phone;
        email = mail;
    }

    string getID() const {
        return id;
    }

    virtual ~Person() {}
};

class Student : public Person {
private:
    string coursesEnrolled[5];
    int totalCourses;
    float gpa;
    int enrollmentYear;

public:
    Student(string n, string i, string addr, string phone, string mail, float g, int year)
        : Person(n, i, addr, phone, mail), gpa(g), enrollmentYear(year), totalCourses(0) {}

    void enrollCourse(string courseID) {
        if (totalCourses < 5) {
            coursesEnrolled[totalCourses] = courseID;
            totalCourses++;
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Enrollment Year : " << enrollmentYear << endl;
        cout << "GPA             : " << gpa << endl;
        cout << "Courses Enrolled: ";
        if (totalCourses == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < totalCourses; i++)
                cout << coursesEnrolled[i] << " ";
        }
        cout << endl;
    }
};

class Professor : public Person {
private:
    string department;
    string coursesTaught[5];
    int totalCourses;
    double salary;

public:
    Professor(string n, string i, string addr, string phone, string mail, string dept, double sal)
        : Person(n, i, addr, phone, mail), department(dept), salary(sal), totalCourses(0) {}

    void assignCourse(string courseID) {
        if (totalCourses < 5) {
            coursesTaught[totalCourses] = courseID;
            totalCourses++;
        }
    }

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department      : " << department << endl;
        cout << "Salary          : $" << salary << endl;
        cout << "Courses Taught  : ";
        if (totalCourses == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < totalCourses; i++)
                cout << coursesTaught[i] << " ";
        }
        cout << endl;
    }
};

class Staff : public Person {
private:
    string department;
    string position;
    double salary;

public:
    Staff(string n, string i, string addr, string phone, string mail, string dept, string pos, double sal)
        : Person(n, i, addr, phone, mail), department(dept), position(pos), salary(sal) {}

    void displayInfo() override {
        Person::displayInfo();
        cout << "Department : " << department << endl;
        cout << "Position   : " << position << endl;
        cout << "Salary     : $" << salary << endl;
    }
};

class Course {
private:
    string courseId;
    string courseName;
    int credits;
    string instructor;
    string schedule;
    Student* enrolledStudents[10];
    int totalEnrolled;

public:
    Course(string id, string name, int cred, string inst, string sched)
        : courseId(id), courseName(name), credits(cred), instructor(inst), schedule(sched), totalEnrolled(0) {}

    void registerStudent(Student* student) {
        if (totalEnrolled < 10) {
            enrolledStudents[totalEnrolled] = student;
            totalEnrolled++;
            student->enrollCourse(courseId);
            cout << "Student " << student->getID() << " enrolled in " << courseName << endl;
        }
    }

    void displayCourse() {
        cout << "Course ID   : " << courseId << endl;
        cout << "Course Name : " << courseName << endl;
        cout << "Credits     : " << credits << endl;
        cout << "Instructor  : " << instructor << endl;
        cout << "Schedule    : " << schedule << endl;
        cout << "Enrolled Students: ";
        if (totalEnrolled == 0) {
            cout << "None";
        } else {
            for (int i = 0; i < totalEnrolled; i++)
                cout << enrolledStudents[i]->getID() << " ";
        }
        cout << endl;
    }

    void calculateGrades() {
        cout << "Grades calculated for course: " << courseName << endl;
    }
};

int main() {
    Student s1("Alice", "S1001", "123 Main St", "555-0101", "alice@university.com", 3.8, 2022);
    Student s2("Bob", "S1002", "456 Elm St", "555-0102", "bob@university.com", 3.4, 2021);

    Professor p1("Dr. Smith", "P2001", "789 Oak St", "555-0201", "smith@university.com", "Computer Science", 90000);

    Staff st1("John Doe", "ST3001", "321 Pine St", "555-0301", "john@university.com", "Administration", "Manager", 50000);

    Course c1("CS101", "Intro to Programming", 3, "Dr. Smith", "Mon-Wed 10:00-11:30");
    Course c2("CS102", "Data Structures", 4, "Dr. Smith", "Tue-Thu 12:00-1:30");

    c1.registerStudent(&s1);
    c1.registerStudent(&s2);
    c2.registerStudent(&s2);

    p1.assignCourse("CS101");
    p1.assignCourse("CS102");

    cout << "\n--- Student Info ---" << endl;
    s1.displayInfo();
    cout << endl;
    s2.displayInfo();

    cout << "\n--- Professor Info ---" << endl;
    p1.displayInfo();

    cout << "\n--- Staff Info ---" << endl;
    st1.displayInfo();

    cout << "\n--- Course Info ---" << endl;
    c1.displayCourse();
    c2.displayCourse();

    return 0;
}
