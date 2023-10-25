#ifndef PROJETO_SCHEDULE_H
#define PROJETO_SCHEDULE_H

#include <vector>
#include <set>

#include "Student.h"
#include "Classes.h"

using namespace std;

class Schedule {
    private:
        vector<Classes> ucInSchedule;
        set<Student> students;

    public:
        Schedule();
        Schedule(const vector<Classes> newUcInShedule, const set<Student> newStudents){
            this->ucInSchedule = newUcInShedule;
            this->students = newStudents;
        }

        vector<Classes> getUCS() const {return ucInSchedule;}
        set<Student> getStudents() const {return students;}

        void setStudents(const set<Student> & newStudents){
            this->students = newStudents;
        }
};

#endif //PROJETO_SCHEDULE_H
