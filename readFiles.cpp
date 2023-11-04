#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <string>
#include "Student.h"
#include "TimeType.h"
#include <utility>
#include "readFiles.h"

using namespace std;


vector<Classes> readClassesData(){
// Function to read class data from the classes.csv
    ifstream file("../Files/classes.csv");   // Open file for reading
    string line;                             // Store each line of the file
    string word;                             // Store each word in a line

    vector<string> aux;                      // Temporary storage for data
    vector<Classes> ucInSch;                 // Vector to store Classes of the schedule

    if (file.is_open()){
        getline(file, line); // Ignore first line (header)

        // Read lines from the file
        while (getline(file, line)){
            aux.clear();                   // Clear temporary storage
            istringstream iss(line);       // Create a string stream from the line

            // Tokenize the line by commas and store in aux vector
            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }

            // Extract class attributes from aux
            string classCode = aux[0];
            string ucCode = aux[1];
            string weekday = aux[2];
            string startHour = aux[3];
            string duration = aux[4];
            string type = aux[5];

            type.resize(type.length()-1);  // Remove the "\r"

            // Create a TimeType object
            TimeType time = TimeType(weekday, startHour, duration, type);

            // Create a Classes object and add to ucInSch vector
            Classes newclass = Classes(classCode, ucCode, time);
            ucInSch.push_back(newclass);
        }
    }
    else{
        cout << "The function is not working properly";  // Error message if file not open
    }
    return ucInSch;  // Return vector of Classes objects
}

// Function to print class codes and UC codes from the readClassesData function
int okay(){
    vector<Classes> allclasses = readClassesData();  // Get all classes data
    for (const auto cl:allclasses){
        cout << cl.getClassCode() << "," << cl.getUcCode() << '\n';  // Print class code and UC code
    }
    return 1;
};


set<Student> readStudentsData(){
// read the students_classes.csv

    vector<Classes> allClasses = readClassesData();  // Get all class data from the CSV file
    list<Classes> Uc;                                // Create a list of Classes
    set<Student> allStudents;                        // Create a set of Students

    ifstream file("../Files/students_classes.csv");  // Open file for reading
    string line;                                     // Store each line of the file
    string word;                                     // Store each word in a line
    string Num;
    vector<string> aux;                              // Temporary storage for data

    TimeType FoundTime;                              // Store found time

    if (file.is_open()){
        getline(file, line);  // Ignore first line (header)

        // Read lines from the file
        while (getline(file, line)){
            aux.clear();            // Clear temporary storage
            istringstream  iss(line);  // Create a string stream from the line

            // Tokenize the line by commas and store in aux vector
            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }

            string studentCode = aux[0];   // Extract student code
            string studentName = aux[1];   // Extract student name
            string ucCode = aux[2];         // Extract UC code
            string classCode = aux[3];      // Extract class code
            classCode.resize(classCode.length()-1); // Remove the "\r"

            // Search for the corresponding TimeType based on UC code and class code
            for (const Classes& cl : allClasses) {
                if (cl.getUcCode() == ucCode && cl.getClassCode() == classCode) {
                    FoundTime = cl.getTimetable();  // Assign found TimeType to FoundTime
                    break;
                }
            }

            // Create a provisional Student object
            Student provStudent = Student(studentName, studentCode);
            auto l = allStudents.find(provStudent);  // Search for the Student in the set

            if (l == allStudents.end()) {
                list<Classes> n = {Classes(classCode, ucCode, FoundTime)};  // Create a list with one class
                allStudents.insert(Student(studentName, studentCode, n));   // Insert new Student with class list
            }
            else {
                Student& existingStudent = const_cast<Student&>(*l);  // Get reference to existing Student
                list<Classes> n = existingStudent.getStudentSchedule();  // Get existing class list
                n.push_back(Classes(classCode, ucCode, FoundTime));      // Add new class
                existingStudent.setLessons(n);                           // Set updated class list
            }

            aux.clear();  // Clear temporary storage
        }
    }
    return allStudents;  // Return set with all the Students
}

set<Classes> readucperclass(){
    //read the classes.csv
    string line;
    string word;
    string Num;
    vector<string> aux;      // Temporary storage for data
    set<Classes> ucsclass;   // Set to store all the Classes with UC code and Class code
    vector<Classes> allClasses = readClassesData();  // Get all classes data
    TimeType FoundTime;      // Store found time
    ifstream file("../Files/classes_per_uc.csv");  // Open file for reading

    if (file.is_open()) {
        getline(file, line);  // Ignore first line (header)

        // Read lines from the file
        while (getline(file, line)) {
            aux.clear();            // Clear temporary storage
            istringstream iss(line);  // Create a string stream from the line

            // Tokenize the line by commas and store in aux vector
            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }

            string uCode = aux[0];   // Extract UC code
            string cCode = aux[1];   // Extract class code

            // Find the corresponding TimeType based on UC code and class code
            for (auto cl: allClasses) {
                if (cl.getUcCode() == uCode and cl.getClassCode() == cCode) {
                    FoundTime = cl.getTimetable();  // Assign found TimeType to FoundTime
                }
            }

            // Create a new Classes object with the found information
            Classes newClass = Classes(cCode, uCode, FoundTime);
            ucsclass.insert(newClass);  // Insert the new Classes object into the set

            aux.clear();  // Clear temporary storage
        }
    }

    return ucsclass;  // Return the set of the Classes their UC code and class code
}