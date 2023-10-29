#ifndef PROJETO_CLASSES_H
#define PROJETO_CLASSES_H

#include <string>
#include <vector>
#include "TimeType.h"

using namespace std;

class Classes{
    private:
        string classCode;
        string ucCode;
        TimeType timetable;

    public:
        Classes(){ucCode="";}
        Classes(const string& cCode, const string& uCode, const TimeType& newTimetable) {
            this -> classCode = cCode;
            this -> ucCode = uCode;
            this -> timetable = newTimetable;
        }

        string getClassCode() const {return classCode;}
        string getUcCode() const {return ucCode;}
        TimeType getTimetable() const {return timetable;}

        bool operator<(TimeType& notyet) {
            if (timetable.getDay() < notyet.getDay()) return true;
            if (timetable.getDay() > notyet.getDay()) return false;

            if (timetable.getStartHour() < notyet.getStartHour()) return true;
            if (timetable.getStartHour() > notyet.getStartHour()) return false;

            if (timetable.getClassDuration() <notyet.getClassDuration()) return true;
            if (timetable.getClassDuration() > notyet.getClassDuration()) return false;}

        void setClassCode(const string& newCode) {classCode = newCode;}
        void setUcCode(const string& newUcCode) {ucCode = newUcCode;}

};

#endif //PROJETO_CLASSES_H
