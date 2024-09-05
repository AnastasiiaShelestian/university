#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Task {
public:
    virtual void display() const = 0;
    virtual bool isCompleted() const = 0;
    virtual void markAsCompleted() = 0;
    virtual ~Task() = default;
};

class TaskItem : public Task {
private:
    string title;
    string description;
    bool completed;
public:
    TaskItem(const string& title, const string& description)
        : title(title), description(description), completed(false) {}

    void display() const override {
        cout << "Task: " << title << "\nDescription: " << description
            << "\nStatus: " << (completed ? "Completed" : "Incomplete") << endl;
    }

    bool isCompleted() const override {
        return completed;
    }

    void markAsCompleted() override {
        completed = true;
    }

    const string& getTitle() const {
        return title;
    }
};
class Note {
private:
    string content;
public:
    Note(const string& content) : content(content) {}

    void display() const {
        cout << "Note: " << content << endl;
    }
};

class TaskList {
private:
    vector<TaskItem> tasks;
    vector<Note> notes;

public:
    void addTask(const TaskItem& task) {
        tasks.push_back(task);
    }

    void addNote(const Note& note) {
        notes.push_back(note);
    }

    void displayAll() const {
        cout << "Tasks:\n";
        for (const auto& task : tasks) {
            task.display();
            cout << endl;
        }

        cout << "Notes:\n";
        for (const auto& note : notes) {
            note.display();
            cout << endl;
        }
    }

    TaskItem& getTask(int index) {
        return tasks.at(index);
    }

    const Note& getNote(int index) const {
        return notes.at(index);
    }

    static int getTotalTasks(const TaskList& taskList) {
        return taskList.tasks.size();
    }
};
enum class Priority {
    LOW,
    MEDIUM,
    HIGH
};

bool operator<(const TaskItem& lhs, const TaskItem& rhs) {
    return lhs.getTitle() < rhs.getTitle();
}

bool operator==(const TaskItem& lhs, const TaskItem& rhs) {
    return lhs.getTitle() == rhs.getTitle();
}

bool operator!=(const TaskItem& lhs, const TaskItem& rhs) {
    return !(lhs == rhs);
}
void displayMenu() {
    cout << "1. Add Task\n"
        << "2. Add Note\n"
        << "3. Display All\n"
        << "4. Mark Task as Completed\n"
        << "5. Get Total Tasks\n"
        << "6. Compare Tasks\n"
        << "7. Exit\n";
}

int main() {
    TaskList taskList;
    int choice;
    

    while (true) {
        displayMenu();
        cin >> choice;

        if (choice == 7) {
            break;
        }

        switch (choice) {
        case 1: {
            string title, description;
            cout << "Enter task title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter task description: ";
            getline(cin, description);
            taskList.addTask(TaskItem(title, description));
            break;
        }
        case 2: {
            string content;
            cout << "Enter note content: ";
            cin.ignore();
            getline(cin, content);
            taskList.addNote(Note(content));
            break;
        }
        case 3: {
            taskList.displayAll();
            break;
        }
        case 4: {
            int index;
            cout << "Enter task index to mark as completed: ";
            cin >> index;
            try {
                taskList.getTask(index).markAsCompleted();
            }
            catch (const out_of_range&) {
                cout << "Invalid task index." << endl;
            }
            break;
        }
        case 5: {
            cout << "Total tasks: " << TaskList::getTotalTasks(taskList) << endl;
            break;
        }
        case 6: {
            int index1, index2;
            cout << "Enter first task index: ";
            cin >> index1;
            cout << "Enter second task index: ";
            cin >> index2;
            try {
                TaskItem& task1 = taskList.getTask(index1);
                TaskItem& task2 = taskList.getTask(index2);
                if (task1 < task2) {
                    cout << "Task 1 has lower priority than Task 2" << endl;
                }
                else if (task1 == task2) {
                    cout << "Tasks have equal priority" << endl;
                }
                else {
                    cout << "Task 1 has higher priority than Task 2" << endl;
                }
            }
            catch (const out_of_range&) {
                cout << "Invalid task index." << endl;
            }
            break;
        }
        default: {
            cout << "Invalid choice." << endl;
            break;
        }
        }
    }

    return 0;
}
