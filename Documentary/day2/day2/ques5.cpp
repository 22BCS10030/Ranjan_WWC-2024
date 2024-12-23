#include <iostream>
#include <vector>
using namespace std;

// Compartment node
struct Compartment {
    int compartmentID;
    int totalSeats;
    int bookedSeats;
    Compartment* next;
};

// Train node
struct Train {
    int trainID;
    Compartment* compartments;
    Train* next;
};

// Train linked list head
Train* trainHead = nullptr;

// Function to add a train
void addTrain(int trainID) {
    Train* newTrain = new Train();
    newTrain->trainID = trainID;
    newTrain->compartments = nullptr;
    newTrain->next = nullptr;

    if (trainHead == nullptr) {
        trainHead = newTrain;
    } else {
        Train* temp = trainHead;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newTrain;
    }
}

// Function to add a compartment to a train
void addCompartment(int trainID, int compartmentID, int totalSeats) {
    Train* train = trainHead;
    while (train != nullptr && train->trainID != trainID) {
        train = train->next;
    }
    if (train == nullptr) {
        cout << "Train ID " << trainID << " not found.\n";
        return;
    }

    Compartment* newCompartment = new Compartment();
    newCompartment->compartmentID = compartmentID;
    newCompartment->totalSeats = totalSeats;
    newCompartment->bookedSeats = 0;
    newCompartment->next = nullptr;

    if (train->compartments == nullptr) {
        train->compartments = newCompartment;
    } else {
        Compartment* temp = train->compartments;
        while (temp->next != nullptr) temp = temp->next;
        temp->next = newCompartment;
    }
}

// Function to book a seat
void bookSeat(int trainID, int compartmentID) {
    Train* train = trainHead;
    while (train != nullptr && train->trainID != trainID) {
        train = train->next;
    }
    if (train == nullptr) {
        cout << "Train ID " << trainID << " not found.\n";
        return;
    }

    Compartment* comp = train->compartments;
    while (comp != nullptr && comp->compartmentID != compartmentID) {
        comp = comp->next;
    }
    if (comp == nullptr) {
        cout << "Compartment ID " << compartmentID << " not found.\n";
        return;
    }

    if (comp->bookedSeats < comp->totalSeats) {
        comp->bookedSeats++;
        cout << "Seat booked successfully in Train " << trainID << ", Compartment " << compartmentID << ".\n";
    } else {
        cout << "No seats available in Train " << trainID << ", Compartment " << compartmentID << ".\n";
    }
}

// Function to cancel a booking
void cancelBooking(int trainID, int compartmentID) {
    Train* train = trainHead;
    while (train != nullptr && train->trainID != trainID) {
        train = train->next;
    }
    if (train == nullptr) {
        cout << "Train ID " << trainID << " not found.\n";
        return;
    }

    Compartment* comp = train->compartments;
    while (comp != nullptr && comp->compartmentID != compartmentID) {
        comp = comp->next;
    }
    if (comp == nullptr) {
        cout << "Compartment ID " << compartmentID << " not found.\n";
        return;
    }

    if (comp->bookedSeats > 0) {
        comp->bookedSeats--;
        cout << "Booking canceled successfully in Train " << trainID << ", Compartment " << compartmentID << ".\n";
    } else {
        cout << "No bookings to cancel in Train " << trainID << ", Compartment " << compartmentID << ".\n";
    }
}

// Function to print reservation status
void printReservationStatus() {
    Train* train = trainHead;
    while (train != nullptr) {
        cout << "Train ID: " << train->trainID << "\n";
        Compartment* comp = train->compartments;
        while (comp != nullptr) {
            cout << "  Compartment ID: " << comp->compartmentID 
                 << " (Seats: " << comp->bookedSeats << "/" << comp->totalSeats << ")\n";
            comp = comp->next;
        }
        train = train->next;
    }
}

// Driver code
int main() {
    addTrain(1);
    addCompartment(1, 101, 50);
    addCompartment(1, 102, 30);

    addTrain(2);
    addCompartment(2, 201, 40);

    bookSeat(1, 101);
    bookSeat(1, 102);
    cancelBooking(1, 101);

    printReservationStatus();

    return 0;
}
