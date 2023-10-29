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
        Classes( const string& cCode, const string& uCode, TimeType& newTimetable) {
            this -> classCode = cCode;
            this -> ucCode = uCode;
            this -> timetable = newTimetable;
        }

        string getClassCode() const {return classCode;}
        string getUcCode() const {return ucCode;}
        TimeType getTimetable() const {return timetable;}
        bool operator<( Classes& other) const {
            return timetable < other.getTimetable();
        }
        int convertDay(const string& day) const{
            if (day == "Monday") return 1;
            if (day == "Tuesday") return 2;
            if (day == "Wednesday") return 3;
            if (day == "Thursday") return 4;
            if (day == "Friday") return 5;
            else return 0;
        }

        bool operator<(const Classes& other) const{
            bool result = false;

            if (convertDay(timetable.getDay()) < convertDay(other.timetable.getDay())) result = true;
            else if (timetable.getStartHour() < other.timetable.getStartHour()) result = true;

            return result;
        }

        void setClassCode(const string& newCode) {classCode = newCode;}
        void setUcCode(const string& newUcCode) {ucCode = newUcCode;}

};

#endif //PROJETO_CLASSES_H
