#ifndef PROJETO_CLASSROOM_H
#define PROJETO_CLASSROOM_H
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"

using namespace std;

/**
 * Esta classe define uma turma composta por:
 *  -> turma (um vetor com os alunos inscritos nesta turma)
 */

class Classroom{
    private:
        vector<Student> turma;

    public:
        Classroom(){

        }
        Classroom (const vector&<Student> newTurma){
            this->turma = newTurma;
        }

        getClassroom() const{return turma;}
        getClassroomSize() const {return turma.size();}
};

using namespace std;

#endif //PROJETO_CLASSROOM_H