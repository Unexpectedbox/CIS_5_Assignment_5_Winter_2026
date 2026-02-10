#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// This is global variable, do not modify
#define MAX_STUDENTS 5

struct Student {
    int studentId;
    string studentName;
    float studentGrades;
};

/*!
* Function Prototypes
*/
void printMenu();
void highestGrade(Student students[], int count);
void lowestGrade(Student students[], int count);
void averageGrade(Student students[], int count);
void printStudentId(Student students[], int count);
void printStudentName(Student students[], int count);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    /*!
    * Add the students here!
    */
    //----------------------------------------------------------------------------------------
    students[0] = { 1939, "Bruce Wayne", 99.9 };
    students[1] = { 1941, "Diane Prince ", 84.2 };
    students[2] = { 1938, "Clark Kent", 72.4 };
    students[3] = { 1956, "Barry Allen", 89.0 };
    students[4] = { 1959, "Hal Jordan", 68.0 };

    count = 5;
    //----------------------------------------------------------------------------------------

    // Complete the menu with the associated function
    do {
        printMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            highestGrade(students, count);
            break;
        case 2:
            lowestGrade(students, count);
            break;
        case 3:
            averageGrade(students, count);
            break;
        case 4:
            printStudentId(students, count);
            break;
        case 5:
            printStudentName(students, count);
            break;
        case 6:
            cout << "Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

void printMenu() {
    cout << "\n=== Student Record System ===\n";
    cout << "1. Find student with the highest grade\n";
    cout << "2. Find the student with the lowest grade\n";
    cout << "3. Find the average grade in the class\n";
    cout << "4. Print all the student's ID\n";
    cout << "5. Print all the student's names\n";
    cout << "6. Exit\n";
}

/* Implemented functions */

void highestGrade(Student students[], int count)
{
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }

    int index = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].studentGrades > students[index].studentGrades) {
            index = i;
        }
    }

    cout << "Highest Grade:\n";
    cout << students[index].studentName
        << " (ID: " << students[index].studentId << ") = "
        << students[index].studentGrades << endl; 
}

void lowestGrade(Student students[], int count)
{
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }

    int index = 0;
    for (int i = 1; i < count; i++) {
        if (students[i].studentGrades < students[index].studentGrades) {
            index = i;
        }
    }

    cout << "Lowest Grade:\n";
    cout << students[index].studentName
        << " (ID: " << students[index].studentId << ") = "
        << students[index].studentGrades << endl;
}

void averageGrade(Student students[], int count)
{
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }

    float sum = 0;
    for (int i = 0; i < count; i++) {
        sum += students[i].studentGrades;
    }

    float avg = sum / count;

    cout << fixed << setprecision(2);
    cout << "Average Grade: " << avg << endl;
}

void printStudentId(Student students[], int count)
{
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }

    cout << "Student IDs:\n";
    for (int i = 0; i < count; i++) {
        cout << students[i].studentId << endl;
    }
}

void printStudentName(Student students[], int count)
{
    if (count == 0) {
        cout << "No students in the record.\n";
        return;
    }

    cout << "Student Names:\n";
    for (int i = 0; i < count; i++) {
        cout << students[i].studentName << endl;
    }
}
