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
        Classes(){

        }
        Classes(const string& cCode, const string& uCode, const TimeType& newTimetable) {
            this->classCode = cCode;
            this->ucCode = uCode;
            this->timetable = newTimetable;
        }

        string getClassCode() const {return classCode;}
        string getUcCode() const {return ucCode;}
        TimeType getTimetable() const {return timetable;}


        void setClassCode(const string& newCode) {classCode = newCode;}
        void setUcCode(const string& newUcCode) {ucCode = newUcCode;}

};

#endif //PROJETO_CLASSES_H
