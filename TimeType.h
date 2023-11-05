#ifndef PROJETO_TIMETYPE_H
#define PROJETO_TIMETYPE_H

#include <string>
#include "Classes.h"

using namespace std;

/**
 * @class TimeType
 * @brief Represents a time for a class.
 */
class TimeType {
private:
    string startHour;       ///< Private member variable for start hour
    string classDuration;   ///< Private member variable for class duration
    string typeOfClass;     ///< Private member variable for type of class
    string day;             ///< Private member variable for start day

public:
    /**
     * @brief Default constructor for TimeType.
     */
    TimeType(){}

    /**
     * @brief Constructor with parameters for TimeType.
     * @param newDay The day of the class.
     * @param newStartHour The start hour of the class.
     * @param newClassDuration The duration of the class.
     * @param newTypeOfClass The type of class.
     */
    TimeType(const string& newDay, const string& newStartHour, const string& newClassDuration, const string& newTypeOfClass) {
        this->day = newDay;
        this->startHour = newStartHour;
        this->classDuration = newClassDuration;
        this->typeOfClass = newTypeOfClass;
    }

    /**
     * @brief Overloaded less-than operator for comparing TimeType objects based on day.
     * @param notyet The TimeType object to compare with.
     * @return True if this TimeType is less than 'notyet', otherwise false.
     */
    bool operator<(const TimeType& notyet) const {
        if (day < notyet.getDay()) return true;
        if (day > notyet.getDay()) return false;
        return false; // Add return statement for all cases.
    }

    /**
     * @brief Getter function to retrieve the day.
     * @return The day of the class.
     */
    string getDay() const { return day; }

    /**
     * @brief Getter function to retrieve the start hour.
     * @return The start hour of the class.
     */
    string getStartHour() const { return startHour; }

    /**
     * @brief Getter function to retrieve the class duration.
     * @return The duration of the class.
     */
    string getClassDuration() { return classDuration; }

    /**
     * @brief Getter function to retrieve the type of class.
     * @return The type of class.
     */
    string getTypeOfClass() { return typeOfClass; }
};

#endif //PROJETO_TIMETYPE_H
