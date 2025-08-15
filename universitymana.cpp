#include <iostream>
#include <string>
using namespace std;

const int MAX_STUDENTS = 50;

struct Student {
    string name;
    int age;
    double gpa;
};

Student students[MAX_STUDENTS];
int numStudents = 0;

void addStudent() {
    if (numStudents >= MAX_STUDENTS) {
        cout << "Maximum number of students reached.\n";
        return;
    }

    Student student;
    cout << "Enter student name: ";
    getline(cin >> ws, student.name);

    cout << "Enter student age: ";
    cin >> student.age;

    cout << "Enter student GPA: ";
    cin >> student.gpa;

    students[numStudents++] = student;
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (numStudents == 0) {
        cout << "No students available.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < numStudents; i++) {
        cout << "Name: " << students[i].name << "\n";
        cout << "Age: " << students[i].age << "\n";
        cout << "GPA: " << students[i].gpa << "\n\n";
    }
}

void searchStudent() {
    if (numStudents == 0) {
        cout << "No students available.\n";
        return;
    }

    string name;
    cout << "Enter name to search: ";
    getline(cin >> ws, name);

    for (int i = 0; i < numStudents; i++) {
        if (students[i].name == name) {
            cout << "Name: " << students[i].name << "\n";
            cout << "Age: " << students[i].age << "\n";
            cout << "GPA: " << students[i].gpa << "\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    int choice;
    do {
        cout << "\n***********************************\n";
        cout << "*** University Management System ***\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: cout << "Exiting program...\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 4);

    return 0;
}

