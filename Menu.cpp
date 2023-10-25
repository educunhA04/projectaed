#include "Menu.h"
#include <iostream>
#include <string>
using namespace std;


void Menu::checkOccupationPer_5() {
    cout << "|--- Access Info -------------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-- Check Occupation Per -----------------|\n"
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
    else {cout << "|-- Invalid Output -----------------------|\n";}
}

void Menu::showStudentsPer_2() {
    cout << "|--- Access Info -------------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-- Show Students Per --------------------|\n"
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
    else {cout << "|-- Invalid Output -----------------------|\n";}
}

void Menu::requestChange_2(){
    cout << "|--- Request Change ----------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-- What Change request do you have? -----|\n"
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
    else {cout << "|-- Invalid Output -----------------------|\n";}
}

void Menu::accessInfo_1() {
    cout << "|--- Access Info -------------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-- What Info do you wish to access? -----|\n"
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
    else {cout << "|-- Invalid Output -----------------------|\n";}
}

void Menu::start() {
    bool isOpen = true;

    while (isOpen){
        cout << "|--- Menu --------------------------------|\n"
             << "|-----------------------------------------|\n"
             << "|-- What action do you wish to perform? --|\n"
             << "|-----------------------------------------|\n"
             << "|-- 1: Access Info -----------------------|\n"
             << "|-- 2: Request a change ------------------|\n"
             << "|-- Q: Quit ------------------------------|\n"
             << "|-----------------------------------------|\n";

        cout << endl << "Insert your desired option:";
        string inp;
        cin >> inp;

        if(inp == "1") accessInfo_1();
        else if(inp == "2") requestChange_2();
        else if(inp == "3" || inp == "q" || inp == "Q"){
            cout << "|-- The program will now close -----------|\n";
            isOpen = false;
        }
        else{
            cout << "|-- Invalid Output -----------------------|\n";
        }
    }
}