// Include necessary libraries and header files
#ifndef PROJETO_STUDENT_H
#define PROJETO_STUDENT_H

#include <iostream>    ///< Include the standard input/output library
#include <string>      ///< Include the string library
#include <vector>      ///< Include the vector library
#include <list>        ///< Include the list library
#include "Classes.h"   ///< Include the Classes header file

/**
 * @class Student
 * @brief Represents a student by their name, student code, and schedule (list of Classes)
 */
using namespace std;

/**
 * @brief This class defines every student by name, student code, and their schedule.
 */
class Student{

private:
    string name;            ///< Private member variable for student's name
    string studentCode;     ///< Private member variable for student's code
    list<Classes> lessons;  ///< Private member variable for student's lessons

public:
    /// Constructors
    Student(){}  ///< Default constructor

    /**
     * @brief Constructor with parameters
     * @param newName Student's name
     * @param newStudentCode Student's code
     * @param newLessons List of classes representing the student's schedule
     */
    Student(const string& newName, const string& newStudentCode, const list<Classes>& newLessons={}) {
        this->name = newName;               ///< Initialize name with newName
        this->studentCode = newStudentCode; ///< Initialize studentCode with newStudentCode
        this->lessons = newLessons;         ///< Initialize lessons with newLessons
    }

    /**
     * @brief Overloaded less-than operator for comparing Student objects based on student code
     * @param other Another Student object to compare
     * @return true if this student's code is less than the other's code
     */
    bool operator<(const Student& other) const {
        return studentCode < other.studentCode;
    }

    /// Getter functions to retrieve name, studentCode, and lessons
    string getName() { return name; }
    string getStudentCode() { return studentCode; }
    list<Classes> getStudentSchedule() { return lessons; }

    /**
     * @brief Setter function to update lessons
     * @param others List of classes representing the updated schedule
     */
    void setLessons(list<Classes>& others) { this->lessons = others; }
};

#endif //PROJETO_STUDENT_H
