#include <iostream>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include "Student.h"
#include "TimeType.h"
#include <utility>
#include "AllData.h"
#include "readFiles.h"

using namespace std;

vector<Classes> readClassesData(){ 
    // leitura do ficheiro classes.csv //
    ifstream file("classes.csv");

    string line;
    string word;

    vector<string> aux;
    vector<Classes> ucInSch;

    if (file.is_open()){
        getline(file, line); //ignorar primeira linha
        while (getline(file, line)){
            aux.clear();
            istringstream  iss(line);
            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }

            string classCode = aux[0];
            string ucCode = aux[1];
            string weekday = aux[2];
            string startHour = aux[3];
            string duration = aux[4];
            string type = aux[5];

            // data hora e tipo de uma aula //
            TimeType time = TimeType(weekday, startHour, duration, type);
            // criar aula //
            Classes nclass = Classes(classCode, ucCode, time);

            // adicionar nclass a um vetor de classes // (adicionar aulas ao vetor com as aulas) //
            ucInSch.push_back(nclass);
        }
    }
    return ucInSch;
}

set<Student> readStudentsData(){
    // leitura do ficheiro students_classes.csv //

    vector<Classes> allClasses = readClassesData();
    set<pair<string,string>> allStudent;
    list<Classes> Uc;
    ifstream file("students_classes.csv");

    string line;
    string word;
    string Num;

    vector<string> aux;
    vector<string,string> ucclass;

    if (file.is_open()){
        getline(file, line);

        while (getline(file, line)){
            aux.clear();
            istringstream  iss(line);

            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }
            allStudent.insert({aux[0],aux[1]});
            if {aux[0],aux[1]}{

            }
            Student.lessons.push_back((aux[2],aux[3],get_time));

            aux.clear();

            else {
                ucclass.emplace_back(aux[2], aux[3]);
            }
        }
    }
    return allStudent;
}
