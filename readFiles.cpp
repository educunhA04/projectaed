#include <iostream>
#include <fstream>
#include <sstream>
#include "Student.h"
#include "TimeType.h"
#include "Schedule.h"

using namespace std;

void Schedule::readClassesData(){
    // leitura do ficheiro classes.csv
    ifstream file("classes.csv");

    string line;
    string word;

    vector<string> aux;
    vector<TimeType> t;
    vector<Classes> ucInSch;
    if (file.is_open()){
        cout << "top";
        while (getline(file, line)){
            aux.clear();
            istringstream  iss(line);
            while (iss >> word) {
                if (word != ",") {
                    aux.push_back(word);
                }
            }

            string classCode = aux[0];
            string ucCode = aux[1];
            string weekday = aux[2];
            string startHour = aux[3];
            string duration = aux[4];
            string type = aux[5];

            //horário de um aluno
            TimeType time = TimeType(weekday, startHour, duration, type);
            t.push_back(time);
            //criar classes
            Classes nclass = Classes(classCode, ucCode, t);

            //adicionar nclass a um vetor de classes
            ucInSch.push_back(nclass);
        }
    }



}

void Schedule::readStudentsData(){
    // leitura do ficheiro students_classes.csv
    ifstream file("students_classes.csv");

    string line;
    string word;

    vector<string> aux;

    if (file.is_open()){

        while (getline(file, line)){
            aux.clear();
            istringstream  iss(line);
            while (iss >> word) {
                if (word != ",") {
                    aux.push_back(word);
                }
            }

            string studentCode = aux[0];
            string studentName = aux[1];
            string ucCode = aux[2];
            string classCode = aux[3];

            Student student = Student(studentName, studentCode);
        }
    }

}
