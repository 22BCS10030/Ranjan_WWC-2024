#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

// Structure to represent a patient
struct Patient {
    std::string name;         // Patient's name
    int triagePriority;       // Priority level (1: highest priority, 5: lowest priority)
    int severity;             // Severity of the condition (higher value means more severe)
    int arrivalTime;          // Time of arrival (smaller value means earlier arrival)

    // Constructor for easier initialization
    Patient(std::string n, int priority, int sev, int time)
        : name(n), triagePriority(priority), severity(sev), arrivalTime(time) {}
};

// Function to dynamically sort patients based on triage priority, severity, and arrival time
void sortPatients(std::vector<Patient>& patients) {
    std::sort(patients.begin(), patients.end(), [](const Patient& a, const Patient& b) {
        if (a.triagePriority != b.triagePriority) {
            return a.triagePriority < b.triagePriority; // Higher priority first
        } else if (a.severity != b.severity) {
            return a.severity > b.severity; // More severe cases first
        } else {
            return a.arrivalTime < b.arrivalTime; // Earlier arrivals first
        }
    });
}

int main() {
    // Example list of patients
    std::vector<Patient> patients = {
        Patient("John Doe", 2, 90, 10),
        Patient("Jane Smith", 1, 95, 12),
        Patient("Alice Brown", 3, 80, 11),
        Patient("Bob Johnson", 1, 85, 9),
        Patient("Charlie Davis", 2, 88, 13)
    };

    // Sort the patients based on the criteria
    sortPatients(patients);

    // Output the sorted list of patients
    std::cout << "Sorted Patients:\n";
    for (const auto& patient : patients) {
        std::cout << "Name: " << patient.name
                  << ", Triage Priority: " << patient.triagePriority
                  << ", Severity: " << patient.severity
                  << ", Arrival Time: " << patient.arrivalTime << "\n";
    }

    // Simulate a new patient arrival
    std::cout << "\nNew Patient Arrival:\n";
    patients.emplace_back("Emily White", 1, 98, 14);

    // Re-sort patients dynamically
    sortPatients(patients);

    // Output the updated sorted list of patients
    std::cout << "\nUpdated Sorted Patients:\n";
    for (const auto& patient : patients) {
        std::cout << "Name: " << patient.name
                  << ", Triage Priority: " << patient.triagePriority
                  << ", Severity: " << patient.severity
                  << ", Arrival Time: " << patient.arrivalTime << "\n";
    }

    return 0;
}
