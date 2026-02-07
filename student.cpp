#include <iostream>
using namespace std;

int roll[50];
string name[50];
float marks[50];
int count = 0;

/* Function to add student */
void addStudent() {
    cout << "\nEnter Roll Number: ";
    cin >> roll[count];
    cin.ignore();

    cout << "Enter Name: ";
    getline(cin, name[count]);

    cout << "Enter Marks: ";
    cin >> marks[count];

    count++;
    cout << "\nStudent added successfully!";
}

/* Function to display students */
void displayStudents() {
    if (count == 0) {
        cout << "\nNo student records found!";
        return;
    }

    for (int i = 0; i < count; i++) {
        cout << "\nRoll No : " << roll[i];
        cout << "\nName : " << name[i];
        cout << "\nMarks : " << marks[i];
        cout << "\n--------------------";
    }
}

/* Function to search student */
void searchStudent() {
    int searchRoll;
    bool found = false;

    cout << "\nEnter Roll Number to search: ";
    cin >> searchRoll;

    for (int i = 0; i < count; i++) {
        if (roll[i] == searchRoll) {
            cout << "\nStudent Found!";
            cout << "\nRoll No : " << roll[i];
            cout << "\nName : " << name[i];
            cout << "\nMarks : " << marks[i];
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\nStudent not found!";
}

/* Function to delete student */
void deleteStudent() {
    int deleteRoll;
    bool found = false;

    cout << "\nEnter Roll Number to delete: ";
    cin >> deleteRoll;

    for (int i = 0; i < count; i++) {
        if (roll[i] == deleteRoll) {

            // shift data
            for (int j = i; j < count - 1; j++) {
                roll[j] = roll[j + 1];
                name[j] = name[j + 1];
                marks[j] = marks[j + 1];
            }

            count--;
            found = true;
            cout << "\nStudent deleted successfully!";
            break;
        }
    }

    if (!found)
        cout << "\nStudent not found!";
}

/* Main function */
int main() {
    int choice;

    do {
        cout << "\n\n===== STUDENT MANAGEMENT SYSTEM =====";
        cout << "\n1. Add Student";
        cout << "\n2. Display Students";
        cout << "\n3. Search Student";
        cout << "\n4. Delete Student";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "\nExiting program..."; break;
            default: cout << "\nInvalid choice!";
        }

    } while (choice != 5);

    return 0;
}
