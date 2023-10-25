#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Schedule.h"

using namespace std;

void Schedule::readClassesData(){
    ifstream file("classes.csv");

    string line;

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

            string classCode = aux[0];
            string ucCode = aux[1];
            string weekday = aux[2];
            string startHour = aux[3];
            string duration = aux[4];
            string type = aux[5];

            TimeType time = TimeType(weekday, startHour, duration, type);
        }
    }

}

void Schedule::readStudentsData(){
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


int main(){
    // Get Data;
    Schedule sched;
    sched.readClassesData();
    sched.readStudentsData();

    // Initialize Menu and Move Data inside the menu;
    Menu menu;
    menu.setSched(sched);
    menu.start();
}