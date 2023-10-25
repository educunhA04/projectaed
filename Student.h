#ifndef PROJETO_STUDENT_H
#define PROJETO_STUDENT_H
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Schedule.h"
#include "Classes.h"

using namespace std;

class Student{
    private:
        string name;
        string studentCode;

    public:
        // Constructors
        Student(){}
        Student(const string& newName, const string& newStudentCode){
            this->name = newName;
            this->studentCode = newStudentCode;
        }

        string getName(){return name;}
        string getStudentCode(){return studentCode;}
        list<Classes> classes; //horario de um aluno específico;

};

#endif //PROJETO_STUDENT_H


