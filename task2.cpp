#include <iostream>
#include <vector>
#include <string>
struct Student {
    std::string name;
    int age;
    char grade;
};
int main() {
    std::vector<Student> students;
    char choice;
    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add student record\n";
        std::cout << "2. Delete student record\n";
        std::cout << "3. Display student records\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        if (choice == '1') {
            Student newStudent;
            std::cout << "Enter student name: ";
            std::cin >> newStudent.name;
            std::cout << "Enter student age: ";
            std::cin >> newStudent.age;
            std::cout << "Enter student grade: ";
            std::cin >> newStudent.grade;
            students.push_back(newStudent);
            std::cout << "Student record added.\n";
        } else if (choice == '2') { 
            if (students.empty()) {
                std::cout << "No student records to delete.\n";
            } else {
                std::string nameToDelete;
                std::cout << "Enter student name to delete: ";
                std::cin >> nameToDelete;
                bool recordDeleted = false;
                for (auto it = students.begin(); it != students.end(); ++it) {
                    if (it->name == nameToDelete) {
                        students.erase(it);
                        std::cout << "Student record deleted.\n";
                        recordDeleted = true;
                        break;
                    }
                }
                if (!recordDeleted) {
                    std::cout << "Student not found.\n";
                }
            }
        } else if (choice == '3') {
            if (students.empty()) {
                std::cout << "No student records available.\n";
            } else {
                std::cout << "\nStudent records:\n";
                for (const auto& student : students) {
                    std::cout << "Name: " << student.name << ", Age: " << student.age << ", Grade: " << student.grade << "\n";
                }
            }
        } else if (choice == '4') {
            std::cout << "Exiting program.\n";
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
