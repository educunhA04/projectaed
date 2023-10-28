#include <fstream>
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

    ifstream file("../files/classes.csv");
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

    ifstream file("../files/students_classes.csv");
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

            for (Classes cl: allClasses){
                if (cl.getUcCode() == aux[2] and cl.getClassCode() == aux[3]){
                    FoundTime = cl.getTimetable();
                }
            }

            Classes NewClass = Classes(classCode,ucCode,FoundTime);
            Student provStudent = Student(studentName,studentCode);

            auto l = allStudents.find(provStudent);

            if(l == allStudents.end()){
                list<Classes> n = {NewClass};
                allStudents.insert(Student(studentName,studentCode,n));
            }

            else{
                list<Classes> n = provStudent.getStudentSchedule();
                n.push_back(NewClass);
                provStudent.setLessons(n);
            }

            aux.clear();
        }
    }
    return allStudents;
}
