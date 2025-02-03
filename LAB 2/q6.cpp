// Write a program that creates a dynamic array of not values but structures. Each struct would contain
// another struct and in that struct a variable of subject should exist. The outer structure should be an ID
// and an array (Fixed) for subjects. (Note you can utilize vectors for this question)
#include <iostream>
#include <vector>
#include <array>
#include <string>

using namespace std;

struct Subject {
    string name;
};

struct SubjectDetails {
    Subject subject;
};

struct Student {
    int id;
    array<SubjectDetails, 3> subjects; // take only 3 subjects
};

int main() {
    vector<Student> students;
    int numStudents;

    cout << "Enter no of students: ";
    cin >> numStudents;

    for (int i = 0; i < numStudents; i++) {
        Student student;
        cout << "Enter information for student " << i + 1 << ":" << endl;

        cout << "Enter student ID: ";
        cin >> student.id;

        cout << "Enter subject names (3 subjects):" << endl;
        for (int j = 0; j < 3; j++) {
            cout << "Subject " << j + 1 << ": ";
            cin.ignore(); 
            getline(cin, student.subjects[j].subject.name); 
        }

        students.push_back(student);
    }

    cout << "\nStudent Details:\n";
    for (const auto& student: students) {
        cout << "Student ID: " << student.id << endl;
        cout << "Subjects:" << endl;
        for (const auto& subjectDetails: student.subjects) {
            cout << "- " << subjectDetails.subject.name << endl;
        }
        cout << endl;
    }

    return 0;
}