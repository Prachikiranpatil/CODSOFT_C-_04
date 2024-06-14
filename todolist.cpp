#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Task {
public:
    Task(string description) : description(description), completed(false) {}

    string getDescription() const {
        return description;
    }

    bool isCompleted() const {
        return completed;
    }

    void markCompleted() {
        completed = true;
    }

private:
    string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const string& taskDescription) {
        tasks.push_back(Task(taskDescription));
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". [" << (tasks[i].isCompleted() ? "X" : " ") << "] " << tasks[i].getDescription() << endl;
            }
        }
    }

    void markTaskCompleted(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks[index - 1].markCompleted();
        } else {
            cout << "Invalid task number." << endl;
        }
    }

    void removeTask(size_t index) {
        if (index > 0 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
        } else {
      cout << "Invalid task number." << endl;
        }
    }

private:
vector<Task> tasks;
};

void displayMenu() {
    cout << "-------------------------------------------------To-Do List Menu:-----------------------------------------------" << endl;
    cout << "1.| Add Task               |" << endl;
    cout<<"----------------------------\n";
    cout << "2.| View Tasks             |" << endl;
    cout<<"----------------------------\n";
    cout << "3.| Mark Task as Completed |" << endl;
    cout<<"----------------------------\n";
    cout << "4.| Remove Task            | " << endl;
    cout<<"----------------------------\n";
    cout << "5.| Exit                   |" << endl;
    cout<<"----------------------------\n";
    cout << "Choose an option: ";
}

int main() {
	system("cls");
	system("Color E0"); 
    ToDoList toDoList;
    int choice;
    do {
        displayMenu();
        cin >> choice;
         switch (choice) {
        case 1: {
            string taskDescription;
            getline(cin, taskDescription);
            toDoList.addTask(taskDescription);
            break;
        }
        case 2:
            toDoList.viewTasks();
            break;
        case 3: {
            size_t taskNumber;
            toDoList.viewTasks();
            cout << "Enter task number to mark as completed: ";
            cin >> taskNumber;
            toDoList.markTaskCompleted(taskNumber);
            break;
        }
        case 4: {
            size_t taskNumber;
            toDoList.viewTasks();
            cout << "Enter task number to remove: ";
            cin >> taskNumber;
            toDoList.removeTask(taskNumber);
            break;
        }
        case 5:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
