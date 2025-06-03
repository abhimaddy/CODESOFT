#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;
};

// Function declarations
void addTask(vector<Task>& tasks, const string& description);
void viewTasks(const vector<Task>& tasks);
void markTaskCompleted(vector<Task>& tasks, int index);
void removeTask(vector<Task>& tasks, int index);
void displayMenu();

int main() {
    vector<Task> tasks;
    char choice;
    string description;
    int taskIndex;

    cout << "Welcome to the To-Do List Manager!\n";

    do {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore(); // Clear newline from input buffer

        switch (choice) {
            case '1': // Add Task
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(tasks, description);
                cout << "Task added successfully!\n";
                break;

            case '2': // View Tasks
                if (tasks.empty()) {
                    cout << "No tasks in the list.\n";
                } else {
                    viewTasks(tasks);
                }
                break;

            case '3': // Mark Task as Completed
                if (tasks.empty()) {
                    cout << "No tasks to mark as completed.\n";
                } else {
                    viewTasks(tasks);
                    cout << "Enter task number to mark as completed: ";
                    cin >> taskIndex;
                    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
                        markTaskCompleted(tasks, taskIndex - 1);
                        cout << "Task marked as completed!\n";
                    } else {
                        cout << "Invalid task number!\n";
                    }
                }
                break;

            case '4': // Remove Task
                if (tasks.empty()) {
                    cout << "No tasks to remove.\n";
                } else {
                    viewTasks(tasks);
                    cout << "Enter task number to remove: ";
                    cin >> taskIndex;
                    if (taskIndex >= 1 && taskIndex <= static_cast<int>(tasks.size())) {
                        removeTask(tasks, taskIndex - 1);
                        cout << "Task removed successfully!\n";
                    } else {
                        cout << "Invalid task number!\n";
                    }
                }
                break;

            case '5': // Exit
                cout << "Goodbye!\n";
                break;

            default:
                cout << "Invalid choice! Please select 1-5.\n";
        }
        cout << endl;
    } while (choice != '5');

    return 0;
}

// Add a new task to the list
void addTask(vector<Task>& tasks, const string& description) {
    Task newTask;
    newTask.description = description;
    newTask.completed = false;
    tasks.push_back(newTask);
}

// Display all tasks with their status
void viewTasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:\n";
    cout << "-----------\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
    cout << endl;
}

// Mark a task as completed
void markTaskCompleted(vector<Task>& tasks, int index) {
    tasks[index].completed = true;
}

// Remove a task from the list
void removeTask(vector<Task>& tasks, int index) {
    tasks.erase(tasks.begin() + index);
}

// Display the menu options
void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Mark Task as Completed\n";
    cout << "4. Remove Task\n";
    cout << "5. Exit\n";
}