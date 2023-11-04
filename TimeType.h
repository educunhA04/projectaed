#ifndef PROJETO_TIMETYPE_H
#define PROJETO_TIMETYPE_H

#include <string>
#include "Classes.h"

using namespace std;

class TimeType {
    private:
        string startHour;       // Private member variable for start hour
        string classDuration;   // Private member variable for class duration
        string typeOfClass;     // Private member variable for type of class
        string day;             // Private member variable for start day

    public:
        TimeType(){}    // Default constructor

        TimeType(const string& newDay, const string& newStartHour, const string& newClassDuration, const string& newTypeOfClass) {
            // Constructor with parameters
            this->day = newDay;                   // Initialize day with newDay
            this->startHour = newStartHour;       // Initialize startHour with newStartHour
            this->classDuration = newClassDuration;   // Initialize classDuration with newClassDuration
            this->typeOfClass = newTypeOfClass;   // Initialize typeOfClass with newTypeOfClass
        }

        // Overloaded less-than operator for comparing TimeType objects based on day
        bool operator<(const TimeType& notyet) const {
            if (day < notyet.getDay()) return true;  // Compare days
            if (day > notyet.getDay()) return false; // Compare days
        }

        // Getter functions to retrieve day, startHour
        string getDay() const { return day; }
        string getStartHour() const { return startHour; }

        // Overloaded getter functions (non-const version)
        string getDay() { return day; }
        string getStartHour() { return startHour; }
        string getClassDuration() { return classDuration; }
        string getTypeOfClass() { return typeOfClass; }

};

#endif //PROJETO_TIMETYPE_H