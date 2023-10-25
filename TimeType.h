#ifndef PROJETO_TIMETYPE_H
#define PROJETO_TIMETYPE_H

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
            this-> day = newDay;
            this-> startHour = newStartHour;
            this-> classDuration = newClassDuration;
            this-> typeOfClass = newTypeOfClass;
        }

        string getDay() {return day;}
        string getStartHour() {return startHour;}
        string getClassDuration() {return classDuration;}
        string getTypeOfClass() {return typeOfClass;}
};

#endif //PROJETO_TIMETYPE_H