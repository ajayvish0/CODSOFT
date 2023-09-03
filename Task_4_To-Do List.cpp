#include <iostream>
#include <vector>

struct Task {
    std::string description;
    bool completed;
};

void displayTasks(const std::vector<Task>& tasks) {
    std::cout << "----- To-Do List -----" << std::endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << "[" << i + 1 << "] ";
        if (tasks[i].completed) {
            std::cout << "[X] ";
        } else {
            std::cout << "[ ] ";
        }
        std::cout << tasks[i].description << std::endl;
    }
    std::cout << "----------------------" << std::endl;
}

int main() {
    std::vector<Task> tasks;

    while (true) {
        std::cout << "To-Do List Manager" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. View Tasks" << std::endl;
        std::cout << "3. Delete Task" << std::endl;
        std::cout << "4. Quit" << std::endl;
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                Task newTask;
                std::cin.ignore(); // Consume the newline character left by previous input
                std::cout << "Enter task description: ";
                std::getline(std::cin, newTask.description);
                newTask.completed = false;
                tasks.push_back(newTask);
                std::cout << "Task added." << std::endl;
                break;
            }
            case 2:
                displayTasks(tasks);
                break;
            case 3: {
                int index;
                std::cout << "Enter the task number to delete: ";
                std::cin >> index;
                if (index >= 1 && index <= tasks.size()) {
                    tasks.erase(tasks.begin() + index - 1);
                    std::cout << "Task deleted." << std::endl;
                } else {
                    std::cout << "Invalid task number." << std::endl;
                }
                break;
            }
            case 4:
                std::cout << "Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
