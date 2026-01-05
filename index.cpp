#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Task {
private:
    string description;
    bool completed;

public:
    Task(string desc) {
        description = desc;
        completed = false;
    }

    void markCompleted() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    string getDescription() const {
        return description;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask() {
        string desc;
        cin.ignore();
        cout << "Enter task description: ";
        getline(cin, desc);
        tasks.emplace_back(desc);
        cout << "Task added successfully.\n";
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }

        cout << "\n------ To-Do List ------\n";
        for (size_t i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". "
                 << tasks[i].getDescription()
                 << " [" << (tasks[i].isCompleted() ? "Completed" : "Pending") << "]\n";
        }
        cout << "------------------------\n";
    }

    void completeTask() {
        int taskNumber;
        viewTasks();
        if (tasks.empty()) return;

        cout << "Enter task number to mark as completed: ";
        cin >> taskNumber;

        if (taskNumber > 0 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed.\n";
        } else {
            cout << "Invalid task number.\n";
        }
    }
};

int main() {
    ToDoList todo;
    int choice;

    cout << "===== Console-Based To-Do List =====\n";

    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: todo.addTask(); break;
            case 2: todo.viewTasks(); break;
            case 3: todo.completeTask(); break;
            case 4: cout << "Exiting application...\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
