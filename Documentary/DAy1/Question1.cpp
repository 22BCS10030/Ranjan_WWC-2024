#include <iostream>
#include <string>
using namespace std;

int main() {
    // Variables to store biodata
    string name, uid, section, dob, hometown;
    int age;

    // Input biodata
    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your UID: ";
    cin >> uid;

    cout << "Enter your section: ";
    cin >> section;

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your date of birth (DD/MM/YYYY): ";
    cin.ignore(); // To consume the leftover newline character
    getline(cin, dob);

    cout << "Enter your hometown: ";
    getline(cin, hometown);

    // Display biodata
    cout << "\n--- Academic Biodata ---\n";
    cout << "Name        : " << name << endl;
    cout << "UID         : " << uid << endl;
    cout << "Section     : " << section << endl;
    cout << "Age         : " << age << endl;
    cout << "Date of Birth: " << dob << endl;
    cout << "Hometown    : " << hometown << endl;

    return 0;
}
