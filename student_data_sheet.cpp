#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class Student {
private:
    int id;
    string name;
    float gpa;

public:
    // Constructor
    Student(int i, string n, float g) {
        id = i;
        name = n;
        gpa = g;
    }

    // Display Method
    void display() {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "GPA: " << gpa << endl;
        cout << "-------------------" << endl;
    }

    // Save to file
    void saveToFile() {
        ofstream file("students.txt", ios::app);

        file << id << " "
             << name << " "
             << gpa << endl;

        file.close();
    }

    // Getter
    int getId() {
        return id;
    }
};

int main() {

    vector<Student> students;

    int choice;

    do {
        cout << "\n===== STUDENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Show Students\n";
        cout << "3. Search Student\n";
        cout << "4. Exit\n";

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1) {

            int id;
            string name;
            float gpa;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter GPA: ";
            cin >> gpa;

            Student s(id, name, gpa);

            students.push_back(s);

            s.saveToFile();

            cout << "Student Added Successfully!\n";
        }

        else if(choice == 2) {

            if(students.empty()) {
                cout << "No students found!\n";
            }

            else {
                for(int i = 0; i < students.size(); i++) {
                    students[i].display();
                }
            }
        }

        else if(choice == 3) {

            int searchId;
            bool found = false;

            cout << "Enter Student ID: ";
            cin >> searchId;

            for(int i = 0; i < students.size(); i++) {

                if(students[i].getId() == searchId) {

                    students[i].display();

                    found = true;
                }
            }

            if(!found) {
                cout << "Student not found!\n";
            }
        }

    } while(choice != 4);

    cout << "Program Ended.\n";

    return 0;
}