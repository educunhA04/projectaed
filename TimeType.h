#ifndef PROJETO_TIMETYPE_H
#define PROJETO_TIMETYPE_H

#include <string>

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

        string getDay() const {return day;}
        string getStartHour() const {return startHour;}
        string getClassDuration() const {return classDuration;}
        string getTypeOfClass() const {return typeOfClass;}
};

#endif //PROJETO_TIMETYPE_H