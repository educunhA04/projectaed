#ifndef PROJETO_CLASSES_H
#define PROJETO_CLASSES_H

#include <string>
#include <vector>
#include "TimeType.h"

/**
 * @class Classes
 * @brief Represents a class with its Class Code, UC Code, Day, Start Hour, Duration, and Type
 */
using namespace std;

class Classes {
private:
    string classCode;   ///< Private member variable for class code
    string ucCode;      ///< Private member variable for UC code
    TimeType timetable; ///< Private member variable for timetable

public:
    Classes() {
        ///< Default constructor
        ucCode = ""; ///< Initialize ucCode with an empty string
    }

    /**
     * @brief Constructor with parameters
     * @param cCode Class Code
     * @param uCode UC Code
     * @param newTimetable TimeType object representing the class timetable
     */
    Classes(const string& cCode, const string& uCode, TimeType& newTimetable) {
        this->classCode = cCode; ///< Initialize classCode with cCode
        this->ucCode = uCode;    ///< Initialize ucCode with uCode
        this->timetable = newTimetable; ///< Initialize timetable with newTimetable
    }

    /// Getter functions to retrieve classCode, ucCode, and timetable
    string getClassCode() const { return classCode; }
    string getUcCode() const { return ucCode; }
    TimeType getTimetable() const { return timetable; } ///< Time when the class occurs

    /**
     * @brief Overloaded less-than operator for comparing Classes objects based on timetable
     * @param other Another Classes object to compare
     * @return true if this class's timetable is less than the other's timetable
     */
    bool operator<(Classes& other) const {
        return timetable < other.getTimetable();
    }

    /**
     * @brief Helper function to convert day string to an integer representation
     * @param day Day of the week as a string
     * @return Integer representation of the day (1 for Monday, 2 for Tuesday, etc.)
     */
    int convertDay(const string& day) const {
        if (day == "Monday") return 1;
        if (day == "Tuesday") return 2;
        if (day == "Wednesday") return 3;
        if (day == "Thursday") return 4;
        if (day == "Friday") return 5;
        else return 0;
    }

    /**
     * @brief Overloaded less-than operator for comparing Classes objects based on timetable
     * @param other Another Classes object to compare
     * @return true if this class's timetable is less than the other's timetable
     */
    bool operator<(const Classes& other) const {
        // Classes are organized by the timetable
        bool result = false;

        if (convertDay(timetable.getDay()) < convertDay(other.timetable.getDay())) result = true;
        else if (timetable.getStartHour() < other.timetable.getStartHour()) result = true;

        return result;
    }

    /// Setter functions to update classCode, ucCode, and timetable
    void setClassCode(const string& newCode) { classCode = newCode; }
    void setUcCode(const string& newUcCode) { ucCode = newUcCode; }
    void setTimetable(TimeType newTimetable) { timetable = newTimetable; }
};

#endif //PROJETO_CLASSES_H

