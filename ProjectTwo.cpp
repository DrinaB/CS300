//Drina Baptiste
// CS 300
// 12/15/24
// Final Project


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>


struct Course {
    std::string courseID;
    std::string courseName;
    std::vector<std::string> prerequisites;
};


void displayMenu();
void loadFileData(std::unordered_map<std::string, Course>& courseTable);
void printSortedCourses(const std::unordered_map<std::string, Course>& courseTable);
void printCourseDetails(const std::unordered_map<std::string, Course>& courseTable);

int main() {
    std::unordered_map<std::string, Course> courseTable;
    int choice = 0;

    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                loadFileData(courseTable);
                break;
            case 2:
                printSortedCourses(courseTable);
                break;
            case 3:
                printCourseDetails(courseTable);
                break;
            case 9:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }
}

// Menu Display
void displayMenu() {
    std::cout << "\nMenu Options:" << std::endl;
    std::cout << "1: Load file data into the data structure" << std::endl;
    std::cout << "2: Print an alphanumerically ordered list of all Computer Science courses" << std::endl;
    std::cout << "3: Print course title and prerequisites for a course" << std::endl;
    std::cout << "9: Exit the program" << std::endl;
    std::cout << "Enter your choice: ";
}

//  load file data into the data structure
void loadFileData(std::unordered_map<std::string, Course>& courseTable) {
    std::string filePath;
    std::cout << "Enter CSV file path: ";
    std::cin >> filePath;

    std::ifstream inputFile(filePath);
    if (!inputFile.is_open()) {
        std::cout << "Error: Could not open file." << std::endl;
        return;
    }

    courseTable.clear(); 
    std::string line;

    while (std::getline(inputFile, line)) {
        std::istringstream stream(line);
        Course course;
        std::string column;

        
        std::getline(stream, course.courseID, ',');
        std::getline(stream, course.courseName, ',');

       
        while (std::getline(stream, column, ',')) {
            if (!column.empty()) {
                course.prerequisites.push_back(column);
            }
        }

        courseTable[course.courseID] = course;
    }

    std::cout << "Data loaded successfully." << std::endl;
    inputFile.close();
}

//  Prints courses in alphanumeric order
void printSortedCourses(const std::unordered_map<std::string, Course>& courseTable) {
    if (courseTable.empty()) {
        std::cout << "No data available. Please load the data first." << std::endl;
        return;
    }

    std::vector<Course> sortedCourses;
    for (const auto& entry : courseTable) {
        sortedCourses.push_back(entry.second);
    }

    std::sort(sortedCourses.begin(), sortedCourses.end(), [](const Course& a, const Course& b) {
        return a.courseID < b.courseID;
    });

    std::cout << "\nComputer Science Courses in Alphanumeric Order:" << std::endl;
    for (const auto& course : sortedCourses) {
        std::cout << course.courseID << ": " << course.courseName << std::endl;
    }
}

//  Prints course details
void printCourseDetails(const std::unordered_map<std::string, Course>& courseTable) {
    if (courseTable.empty()) {
        std::cout << "No data available. Please load the data first." << std::endl;
        return;
    }

    std::string courseID;
    std::cout << "Enter course ID to search: ";
    std::cin >> courseID;

    auto it = courseTable.find(courseID);
    if (it != courseTable.end()) {
        const Course& course = it->second;
        std::cout << "Course ID: " << course.courseID << "\nCourse Name: " << course.courseName << std::endl;

        if (!course.prerequisites.empty()) {
            std::cout << "Prerequisites:" << std::endl;
            for (const auto& prereq : course.prerequisites) {
                std::cout << prereq << std::endl;
            }
        } else {
            std::cout << "No prerequisites." << std::endl;
        }
    } else {
        std::cout << "Course not found." << std::endl;
    }
}
