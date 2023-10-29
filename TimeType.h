#ifndef PROJETO_TIMETYPE_H
#define PROJETO_TIMETYPE_H

#include <string>
#include "Classes.h"

using namespace std;

class TimeType {
    private:
        string day;
        string startHour;
        string classDuration;
        string typeOfClass;

    public:
        TimeType(){}
        TimeType(const string& newDay, const string& newStartHour, const string& newClassDuration, const string& newTypeOfClass){
            this -> day = newDay;
            this -> startHour = newStartHour;
            this -> classDuration = newClassDuration;
            this -> typeOfClass = newTypeOfClass;
        }
        bool operator<(const TimeType& notyet) const {
            if (day < notyet.getDay()) return true;
            if (day > notyet.getDay()) return false;
        }
        string getDay() const {return day;}
        string getStartHour() const {return startHour;}
        string getClassDuration() const {return classDuration;}
        string getTypeOfClass() const {return typeOfClass;}

        string getDay() {return day;}
        string getStartHour() {return startHour;}
        string getClassDuration() {return classDuration;}
        string getTypeOfClass() {return typeOfClass;}

};

#endif //PROJETO_TIMETYPE_H