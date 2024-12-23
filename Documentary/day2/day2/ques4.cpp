#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

// Task structure
struct Task {
    int taskID;
    int priority;
    int executionTime;
    int period; // For periodic tasks
    Task* next;
};

// Circular linked list head
Task* head = nullptr;
mutex taskMutex;

// Function to insert a task in priority order
void insertTask(int taskID, int priority, int executionTime, int period = 0) {
    lock_guard<mutex> lock(taskMutex);

    Task* newTask = new Task{taskID, priority, executionTime, period, nullptr};

    if (head == nullptr) { // First task
        head = newTask;
        head->next = head;
        return;
    }

    Task* temp = head;
    Task* prev = nullptr;

    do {
        if (temp->priority < priority) break;
        prev = temp;
        temp = temp->next;
    } while (temp != head);

    if (prev == nullptr) { // Insert at head
        Task* last = head;
        while (last->next != head) last = last->next;
        newTask->next = head;
        head = newTask;
        last->next = head;
    } else { // Insert in middle or end
        prev->next = newTask;
        newTask->next = temp;
    }
}

// Function to remove a completed task
void removeTask(int taskID) {
    lock_guard<mutex> lock(taskMutex);

    if (head == nullptr) return;

    Task* temp = head;
    Task* prev = nullptr;

    do {
        if (temp->taskID == taskID) {
            if (temp == head && temp->next == head) { // Only one task
                delete temp;
                head = nullptr;
                return;
            } else if (temp == head) { // Removing head
                Task* last = head;
                while (last->next != head) last = last->next;
                head = head->next;
                last->next = head;
                delete temp;
                return;
            } else { // Removing middle or end
                prev->next = temp->next;
                delete temp;
                return;
            }
        }
        prev = temp;
        temp = temp->next;
    } while (temp != head);
}

// Function to handle periodic tasks
void reinsertPeriodicTasks() {
    lock_guard<mutex> lock(taskMutex);

    Task* temp = head;
    if (temp == nullptr) return;

    do {
        if (temp->period > 0) { // If it's a periodic task
            insertTask(temp->taskID, temp->priority, temp->executionTime, temp->period);
        }
        temp = temp->next;
    } while (temp != head);
}

// Function to simulate task execution
void executeTasks() {
    while (true) {
        {
            lock_guard<mutex> lock(taskMutex);

            if (head == nullptr) {
                cout << "Task queue is empty.\n";
                break;
            }
        }

        Task* current;
        {
            lock_guard<mutex> lock(taskMutex);
            current = head;
        }

        cout << "Executing Task ID: " << current->taskID
             << " (Priority: " << current->priority
             << ", Execution Time: " << current->executionTime << "s)" << endl;

        this_thread::sleep_for(chrono::seconds(current->executionTime));
        removeTask(current->taskID);

        cout << "Task ID " << current->taskID << " completed.\n";

        reinsertPeriodicTasks();
    }
}

// Function to display the current task queue
void printTaskQueue() {
    lock_guard<mutex> lock(taskMutex);

    if (head == nullptr) {
        cout << "Task queue is empty.\n";
        return;
    }

    Task* temp = head;
    cout << "Current Task Queue:\n";
    do {
        cout << "Task ID: " << temp->taskID
             << " (Priority: " << temp->priority
             << ", Execution Time: " << temp->executionTime
             << ", Period: " << temp->period << ")\n";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}

// Driver code
int main() {
    // Add tasks
    insertTask(1, 3, 2);
    insertTask(2, 5, 1);
    insertTask(3, 2, 3);
    insertTask(4, 4, 1);
    insertTask(5, 1, 4, 10); // Periodic task

    // Print initial queue
    printTaskQueue();

    // Execute tasks in a separate thread
    thread executor(executeTasks);

    // Simulate adding a high-priority task dynamically
    this_thread::sleep_for(chrono::seconds(3));
    cout << "\nAdding a new high-priority task (Task ID: 6).\n";
    insertTask(6, 6, 2);

    // Print updated queue
    printTaskQueue();

    executor.join();
    return 0;
}
