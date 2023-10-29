#ifndef PROJETO_STUDENT_H
#define PROJETO_STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include <list>

#include "Classes.h"

using namespace std;

class Student{
    private:
        string name;
        string studentCode;
        list<Classes> lessons; // horario de um aluno específico;

    public:
        // Constructors
        Student(){}
        Student(const string& newName, const string& newStudentCode, const list<Classes>& newLessons={}){
            this->name = newName;
            this->studentCode = newStudentCode;
            this->lessons = newLessons;
        }

        bool operator<(const Student& other) const {
            return studentCode < other.studentCode;
        }

        string getName(){return name;}
        string getStudentCode(){return studentCode;}
        list<Classes> getStudentSchedule(){return lessons;}
        void setLessons(list<Classes>& others){this->lessons=others;}
};

#endif //PROJETO_STUDENT_H


