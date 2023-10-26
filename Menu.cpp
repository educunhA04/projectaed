#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;

void Menu:: showClassSchedule_4(){
    string inp;
    cout << "Insert a valid Class Code: \n";
    cin >> inp;
    bool found = false;

    for(auto element : sched.getUCS()){
        if (inp == element.getClassCode()) found = true;
    }
    if(found){
        cout << "Showing Schedule for class " << inp << "\n";
        for(auto element2 : sched.getUCS()){
            cout << "UCCode: " << element2.getUcCode() << " / "
                 << "Day: " << element2.getTimetable().getDay() << " / "
                 << "Type: " << element2.getTimetable().getTypeOfClass() << " / "
                 << "StartHour: " << element2.getTimetable().getStartHour() << " / "
                 << "Duration: " << element2.getTimetable().getClassDuration() << "\n";
        }
    }
    else (!found){
        cout << "Class not found.";
    }
    accessInfo_1();
}

void Menu::showStudentSchedule_1(){
    string inp;
    cout << "Insert a valid student Code: \n";
    cin >> inp;
    bool found = false;

    for(auto element : sched.getStudents()){
        if (element.getStudentCode() == inp){
            found = true;
            auto horario = element.getStudentSchedule();
            cout << "Showing " << element.getName() << "'s Schedule";
            for(auto aula : horario){
                cout << "UCCode: " << aula.getUcCode() << " / "
                     << "ClassCode: " << aula.getClassCode() << " / "
                     << "Day: " << aula.getTimetable().getDay() << " / "
                     << "Type: " << aula.getTimetable().getTypeOfClass() << " / "
                     << "StartHour: " << aula.getTimetable().getStartHour() << " / "
                     << "Duration: " << aula.getTimetable().getClassDuration() << "\n";
            }
        }
    }
    if (!found){
        cout << "Student not found.";
    }
    accessInfo_1();
}

void Menu::checkOccupationPer_5() {
    cout << "|--[ Access Info ]------------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ Check Occupation Per ]----------------|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: Year ------------------------------|\n"
         << "|-- 2: Class -----------------------------|\n"
         << "|-- 3: UC --------------------------------|\n"
         << "|-- B: Go Back ---------------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option:";
    string inp;
    cin >> inp;

    if (inp == "1"){checkOccupationPerYear_1();}
    else if (inp == "2"){checkOccupationPerClass_2();}
    else if (inp == "3"){checkOccupationPerUC_3();}
    else if (inp == "4" || inp == "B" || inp == "b"){accessInfo_1();}
    else {cout << "|-- Invalid Input ------------------------|\n";}
}

void Menu::showStudentsPer_2() {
    cout << "|--[ Access Info ]------------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ Show Students Per ]-------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: Year ------------------------------|\n"
         << "|-- 2: Class -----------------------------|\n"
         << "|-- 3: UC --------------------------------|\n"
         << "|-- B: Go Back -------------------------- |\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option:";
    string inp;
    cin >> inp;

    if (inp == "1"){showStudentsPerYear_1();}
    else if (inp == "2"){showStudentsPerClass_2();}
    else if (inp == "3"){showStudentsPerUC_3();}
    else if (inp == "4" || inp == "B" || inp == "b"){accessInfo_1();}
    else {cout << "|-- Invalid Input ------------------------|\n";}
}

void Menu::requestChange_2(){
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ What Change request do you have? ]----|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: Add Student to a Class ------------|\n"
         << "|-- 2: Remove Student from a Class -------|\n"
         << "|-- 3: Switch Student from UC ------------|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option:";
    string inp;
    cin >> inp;

    if (inp == "1"){addStudent_1();}
    else if (inp == "2"){removeStudent_2();}
    else if (inp == "3"){switchStudent_3();}
    else if (inp == "4" || inp == "B" || inp == "b"){start();}
    else {cout << "|-- Invalid Input ------------------------|\n";}
}

void Menu::accessInfo_1() {
    cout << "|--[ Access Info ]------------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ What Info do you wish to access? ]----|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: A Student's Schedule --------------|\n"
         << "|-- 2: Student's per Year/UC/Class ------ |\n"
         << "|-- 3: Students in at Least n UC's ------ |\n"
         << "|-- 4: A Class Schedule ----------------- |\n"
         << "|-- 5: The Occupation per Year/Class/UC --|\n"
         << "|-- 6: The UC with the most students -----|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option:";
    string inp;
    cin >> inp;

    if (inp == "1"){showStudentSchedule_1();}
    else if (inp == "2"){showStudentsPer_2();}
    else if (inp == "3"){showStudentsInAtLeastNUCs_3();}
    else if (inp == "4"){showClassSchedule_4();}
    else if (inp == "5"){checkOccupationPer_5();}
    else if (inp == "6"){checkBiggestUc_6();}
    else if (inp == "7" || inp == "B" || inp == "b"){start();}
    else {cout << "|-- Invalid Input ------------------------|\n";}
}

void Menu::start() {
    bool isOpen = true;

    while (isOpen){
        cout << "|--[ Menu ]-------------------------------|\n"
             << "|-----------------------------------------|\n"
             << "|-[ What action do you wish to perform? ]-|\n"
             << "|-----------------------------------------|\n"
             << "|-- 1: Access Info -----------------------|\n"
             << "|-- 2: Request a change ------------------|\n"
             << "|-- C: Close -----------------------------|\n"
             << "|-----------------------------------------|\n";

        cout << endl << "Insert your desired option:";
        string inp;
        cin >> inp;

        if(inp == "1") accessInfo_1();
        else if(inp == "2") requestChange_2();
        else if(inp == "3" || inp == "c" || inp == "C"){
            cout << "|-- The program will now close -----------|\n";
            isOpen = false;
        }
        else{
            cout << "|-- Invalid Input ------------------------|\n";
        }
    }
}