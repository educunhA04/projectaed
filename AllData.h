#ifndef PROJETO_ALLDATA_H
#define PROJETO_ALLDATA_H

#include <vector>
#include <set>
#include <string>

#include "Student.h"
#include "Classes.h"

using namespace std;

class AllData {
    //AllData retains all the uc's, students and schedule of a class in specific
private:
    vector<Classes> ucInSchedule;
    set<Student> students;

public:
    AllData(){students={};}
    AllData(const vector<Classes>& newUcInShedule, const set<Student>& newStudents){
        this->ucInSchedule = newUcInShedule;
        this->students = newStudents;
    }

    vector<Classes> getUCS() const {return ucInSchedule;}
    set<Student> getStudents() const {return students;}

    void setStudents(const set<Student>& newStudents){
        this->students = newStudents;
    }
    void setClasses(const vector<Classes>& newClasses){
        this -> ucInSchedule = newClasses;
    }
};

#endif // PROJETO_ALLDATA_H
