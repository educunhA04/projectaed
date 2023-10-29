#include <fstream>
#include <iostream>
#include <sstream>
#include <set>
#include <vector>
#include <string>
#include "Student.h"
#include "TimeType.h"
#include <utility>
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
        getline(file, line); // ignorar primeira linha //
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
            type.resize(type.length()-1); //remove the "\r"

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
    list<Classes> Uc;
    set<Student> allStudents;

    ifstream file("students_classes.csv");
    string line;
    string word;
    string Num;
    vector<string> aux;

    TimeType FoundTime;

    if (file.is_open()){
        getline(file, line);

        while (getline(file, line)){
            aux.clear();
            istringstream  iss(line);

            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }

            string studentCode = aux[0];
            string studentName = aux[1];
            string ucCode = aux[2];
            string classCode = aux[3];
            classCode.resize(classCode.length()-1); //remove the "\r"

            for (const Classes& cl : allClasses) {
                if (cl.getUcCode() == ucCode && cl.getClassCode() == classCode) {
                    FoundTime = cl.getTimetable();
                    break;
                }
            }

            Student provStudent = Student(studentName, studentCode);
            auto l = allStudents.find(provStudent);

            if (l == allStudents.end()) {
                list<Classes> n = {Classes(classCode, ucCode, FoundTime)};
                allStudents.insert(Student(studentName, studentCode, n));
            }
            else {
                Student& existingStudent = const_cast<Student&>(*l);
                list<Classes> n = existingStudent.getStudentSchedule();
                n.push_back(Classes(classCode, ucCode, FoundTime));
                existingStudent.setLessons(n);
            }

            aux.clear();
        }
    }
    return allStudents;
}
set<Classes> readucperclass(){
    string line;
    string word;
    string Num;
    vector<string> aux;
    set<Classes> ucsclass;
    vector<Classes> allClasses = readClassesData();
    TimeType FoundTime;
    ifstream file("classes_per_uc.csv");

    if (file.is_open()) {
        getline(file, line);

        while (getline(file, line)) {
            aux.clear();
            istringstream iss(line);

            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }
            string uCode = aux[0];
            string cCode = aux[1];
            for (auto cl: allClasses) {
                if (cl.getUcCode() == uCode and cl.getClassCode() == cCode) {
                    FoundTime = cl.getTimetable();
                }
            }
            Classes newClass = Classes(cCode, uCode, FoundTime);
            ucsclass.insert(newClass);
            aux.clear();
        }
    }
    return ucsclass;
}