#include "Menu.h"
#include "AllData.h"
#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "readFiles.h"
#include <list>
#include <algorithm>
using namespace std;

string toLowerSTR (string str){
    for(auto& elem : str){
        elem = tolower(elem);}
    return str;
}

vector <Classes> UCINSCH=readClassesData();
set<Student> ALLSTUDENTS=readStudentsData();
vector<string> changes;

Menu::Menu() : data(UCINSCH, ALLSTUDENTS) {} //contructor


//############################# MENUS ##################################//
void Menu::start() {
    system("clear");
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

        cout << endl << "Insert your desired option:" << endl;
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

void Menu::requestChange_2(){
    system("clear");
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ What Change request do you have? ]----|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: Add Student -----------------------|\n"
         << "|-- 2: Remove Student --------------------|\n"
         << "|-- 3: Switch Student --------------------|\n"
         << "|-- 4: Changes Historic ------------------|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option:";
    string inp;
    cin >> inp;

    if (inp == "1"){addStudent_1();}
    else if (inp == "2"){removeStudent_2();}
    else if (inp == "3"){switchStudent_3();}
    else if (inp == "4"){activity();}
    else if (inp == "B" || inp == "b"){start();}
    else {cout << "|-- Invalid Input ------------------------|\n";}
}

void Menu::accessInfo_1() {
    system("clear");
    cout << "|--[ Access Info ]------------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ What Info do you wish to access? ]----|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: A Student's Schedule --------------|\n"
         << "|-- 2: Students per Year/UC/Class --------|\n"
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

void Menu::checkOccupationPer_5() {
    system("clear");
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
    system("clear");
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



//############################## FUNCTIONS INFO #################################//

void Menu::showStudentSchedule_1(){
    system("clear");
    string inp;
    cout << "Insert a valid student Code: ";
    cin >> inp;
    bool found = false;

    for(auto element : data.getStudents()){
        if (element.getStudentCode() == inp){
            found = true;

            cout << "Showing " << element.getName() << "'s Schedule" << endl << endl;
            for(auto aula : element.getStudentSchedule()){
                cout << "UCCode: " << aula.getUcCode() << " / "
                     << "ClassCode: " << aula.getClassCode() << " / "
                     << "Day: " << aula.getTimetable().getDay() << " / "
                     << "Type: " << aula.getTimetable().getTypeOfClass() << " / "
                     << "StartHour: " << aula.getTimetable().getStartHour() << " / "
                     << "Duration: " << aula.getTimetable().getClassDuration() << endl;
            }
        }
    }
    if (!found){
        cout << "Student not found.\n\n";

    }


    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R') {
        accessInfo_1();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

void Menu::showStudentsPerYear_1() {
    /*int input;
    cout << "Insert a number correspondent to a year: " << endl;

    cin >> input;
    cout << "Student Code   |   Student Name" << endl;
    set<char> anos;

    for (auto element : data.getStudents()) {
        for (auto aula : element.getStudentSchedule()) {
            anos.insert(aula.getClassCode()[0]);
        }

        for (char num : anos) {
            if (num - '0' == input) {
                cout << " " << element.getStudentCode() << "     |   " << element.getName() << endl;
            }
        }
    }*/

    system("clear");
    int num;
    int n;
    cout << "Insert a number correspondent to a year: " << endl;
    cin >> num;


    // caso se considere um aluno do ano em que está a fazer a uc de ano mais elevado //
    int max = 0;
    for (auto element : data.getStudents()) {
        max = 0;
        for (auto aula : element.getStudentSchedule()) {
            n = aula.getClassCode()[0] - '0';
            if (n > max) {
                max = n;
            }
        }
        if (max == num) {
            cout << " " << element.getStudentCode() << "     |   " << element.getName() << endl;
        }
    }

    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R') {
        accessInfo_1();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }


}

void Menu::showStudentsPerUC_3(){
    system("clear");
    cout << endl <<  "Insert the code of the UC: ";
    string inp;
    cin >> inp;
    set<Student> aux;
    bool foundUC = false;

    for(auto elem : data.getStudents()){
        bool foundSTN = false;
        while (!foundSTN){
            for(auto elem2 : elem.getStudentSchedule()){
                if(elem2.getUcCode() == inp) {
                    foundSTN = true;
                    foundUC = true;
                    aux.insert(elem);
                }
            }
        }
    }

    if (foundUC){
        cout << "Now showing students studying " << inp << ".\n";
        for(auto student : aux){
            cout << "Student Code: "  << student.getStudentCode() << " / Student Name: " << student.getName() << endl;
        }
        cout << "\n\n";
    }
    else{
        cout << "UC not found.\n\n";
    }
    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to quit" << endl;

    cin >> what;

    if (what == 'R') {
        showStudentsPer_2();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }

}

void Menu::showStudentsPerClass_2() {
    system("clear");
    cout << endl <<  "Insert the code of the class: ";
    string inp;
    cin >> inp;

    set<Student> aux;
    bool foundClass = false;

    for(auto elem : data.getStudents()){
        bool foundSTN = false;
        for(auto elem2 : elem.getStudentSchedule()){
            if(elem2.getClassCode() == inp) {
                foundSTN = true;
                foundClass = true;
                aux.insert(elem);
                break;
            }
        }
    }

    if (foundClass){
        cout << "Now showing students studying in class " << inp << ".\n";
        cout << "Student Code"  << " | Student Name" << endl;
        for(auto student : aux){
            cout << " " << student.getStudentCode() << "   |   " << student.getName() << endl;
        }
        cout << "\n\n";
    }
    else{
        cout << "Class not found.\n\n";
    }
    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R') {
        showStudentsPer_2();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

void Menu::showStudentsInAtLeastNUCs_3() {
    system("clear");
    cout << endl << "Insert the number of UCs: ";
    int input;
    cin >> input;
    set<string> a;

    cout << "The following students study at least " << input << " UC's:\n";
    for (auto element : data.getStudents()) {
        auto horario = element.getStudentSchedule();

        for (auto aula : horario) {
            a.insert(aula.getUcCode());
        }
        if (a.size() >= input) {
            cout << "Student Code: "  << element.getStudentCode() << " / Student Name: " << element.getName() << endl;
        }
    }
    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R') {
        accessInfo_1();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

void Menu:: showClassSchedule_4(){
    system("clear");
    string inp;
    cout << "Insert a valid Class Code: \n";
    cin >> inp;
    bool found = false;

    for(auto element : data.getUCS()){
        if (toLowerSTR(inp) == toLowerSTR(element.getClassCode())) {
            found = true;
        }
    }
    if(found){
        cout << "Showing Schedule for class " << inp << "\n";
        for(auto element2 : data.getUCS()){
            cout << "UCCode: " << element2.getUcCode() << " / "
                 << "Day: " << element2.getTimetable().getDay() << " / "
                 << "Type: " << element2.getTimetable().getTypeOfClass() << " / "
                 << "StartHour: " << element2.getTimetable().getStartHour() << " / "
                 << "Duration: " << element2.getTimetable().getClassDuration() << "\n\n";
        }
    }
    else {
        cout << "Class not found.\n\n";
    }
    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R') {
        accessInfo_1();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}


void Menu::checkOccupationPerYear_1() {
    system("clear");
    int num;
    int n;
    cout << "Insert a number correspondent to a year: " << endl;
    cin >> num;
    string indicator = "nd";
    if (num == 1) {
        indicator = "st";
    }
    int sum = 0;


    // caso se considere um aluno do ano em que está a fazer a uc de ano mais elevado //
    int max = 0;
    for (auto element : data.getStudents()) {
        max = 0;
        for (auto aula : element.getStudentSchedule()) {
            n = aula.getClassCode()[0] - '0';
            if (n > max) {
                max = n;
            }
        }
        if (max == num) {
            sum++;
        }
    }

    //caso se considere um aluno inscrito em ucs de vários anos, de todos esses anos //

    /*
    int sum = 0;
    for (auto element : data.getStudents()) {
        for (auto aula : element.getStudentSchedule()) {

            if (aula.getClassCode()[0] - '0' == num) {
                sum++;
                break;
            }
        }
    }
    */

    cout << "There are " << sum << " students enrolled in the " << num << indicator << " year." << endl;

    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R') {
        accessInfo_1();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}; // TODO

void Menu::checkOccupationPerClass_2() {
    system("clear");
    cout << "Insert a valid Class code: \n";
    string inp;
    cin >> inp;
    cout  << "|--[ Access Info ]------------------------|\n"
          << "|-----------------------------------------|\n"
          << "|-[ Check Occupation Per Class]-----------|\n"
          << "|-----------------------------------------|\n"
          << "|-[ Do you want to know the occupation ]--|\n"
          << "|---[ of the class in a especific UC? ]---|\n"
          << "|-----------------------------------------|\n"
          << "|-- 1: Yes -------------------------------|\n"
          << "|-- 2: No --------------------------------|\n"
          << "|-----------------------------------------|\n";
    string n;
    cin>>n;
    string uc;
    int count = 0;
    bool found = false;
    if (n=="1"){
        cout<<"Insert the UC code of the class:";
        cin>> uc;
        for (auto element : data.getStudents()){
            auto horario = element.getStudentSchedule();
            for(auto aula : horario){
                if (toLowerSTR(aula.getClassCode()) == toLowerSTR(inp) and toLowerSTR(aula.getUcCode()) == toLowerSTR(uc)){
                    count++;
                    found = true;
                    break;
                }
            }
        }
    }
    else if(n=="2"){
        for (auto element : data.getStudents()){
            auto horario = element.getStudentSchedule();
            for(auto aula : horario){
                if (toLowerSTR(aula.getClassCode()) == toLowerSTR(inp)){
                    count++;
                    found = true;
                    break;
                }
            }
        }
    }
    if(!found){
        cout << "Class not found.\n\n";
    }
    else{
        cout << "The number of students with lessons in class " << inp << " is " << count << ".\n\n";
    }
    checkOccupationPer_5();
    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R') {
        accessInfo_1();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

void Menu::checkOccupationPerUC_3() {
    system("clear");
    string inp;
    cout << "Insert a valid UC Code: \n";
    cin >> inp;
    cout  << "|--[ Access Info ]------------------------|\n"
          << "|-----------------------------------------|\n"
          << "|-[ Check Occupation Per UC]-----------|\n"
          << "|-----------------------------------------|\n"
          << "|-[ Do you want to know the occupation ]--|\n"
          << "|---[ of the UC in a especific class? ]---|\n"
          << "|-----------------------------------------|\n"
          << "|-- 1: Yes -------------------------------|\n"
          << "|-- 2: No --------------------------------|\n"
          << "|-----------------------------------------|\n";
    string n;
    cin>>n;
    string classe;
    int count = 0;
    bool found = false;

    if (n=="1"){
        cout<<"Insert the class code of the UC:";
        cin>> classe;
        for (auto element : data.getStudents()){
            auto horario = element.getStudentSchedule();
            for(auto aula : horario){
                if (toLowerSTR(aula.getUcCode()) == toLowerSTR(inp) and toLowerSTR(aula.getClassCode()) == toLowerSTR(classe)){
                    count++;
                    found = true;
                    break;
                }
            }
        }
    }
    else if(n=="2"){
        for (auto element : data.getStudents()){
            auto horario = element.getStudentSchedule();
            for(auto aula : horario){
                if (toLowerSTR(aula.getUcCode()) == toLowerSTR(inp)){
                    count++;
                    found = true;
                    break;
                }
            }
        }
    }

    if(!found){cout << "UC not found.\n\n";}
    else{
        cout << "The number of students studying the UC " << inp << " is " << count << ".\n\n";
    }
    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R') {
        checkOccupationPer_5();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}


void Menu::checkBiggestUc_6() {
    system("clear");
    string t = data.getUCS()[0].getUcCode(); //primeira uc
    string m; //biggest uc;
    int count = 0;
    int max = 0;
    for (auto aula : data.getUCS()) {
        if (aula.getUcCode() == t) {
            count++;
        }
        else {
            if (count > max) {
                m = aula.getUcCode();
                max = count;
            }
            count = 0;
            t = aula.getUcCode();
        }
    }
    cout << "The biggest UC in L.EIC is " << m << ".\n\n" << endl;

    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R') {
        accessInfo_1();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

//############################## FUNCTIONS CHANGE #################################//

void Menu::addStudent_1() {
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|--[ Do you wish to add the student to ]--|\n"
         << "|----------[ a Class or a UC? ]-----------|\n"
         << "|-- 1: UC --------------------------------|\n"
         << "|-- 2: Class -----------------------------|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option:";
    string inp;
    cin >> inp;
    int i = 0;
    //interaction//
    if (inp == "1") { i = 1; }
    else if (inp == "2") { i = 2; }
    else if (inp == "B" || inp == "b") { start(); }
    else { cout << "|-- Invalid Input ------------------------|\n"; }
    cout << endl << "Insert student's code: " << endl;
    string studentcode;
    cin >> studentcode;

    string wtc;
    string ccode;
    string ucode;
    string change;

    bool flag = false;


    Student Student1;
    for (auto element : data.getStudents()) {
        if (element.getStudentCode() == studentcode) {
            Student1=element;
            flag = true;
            break;
        }
    }
    if (!flag) {
        cout << endl << "The student code is invalid. " << endl;
    }
    if (!flag) {
        addStudent_1();
    }
    int count;
    //Student restriction
    if (Student1.getStudentSchedule().size()==7 and i==1){
        cout<<"Student is already in 7 UC's.";
    }
    //
    else if (i == 1) {
        cout << endl << "Insert the UC code witch you want student to be added: " << endl;
        cin >> ucode;
        for (auto cl:Student1.getStudentSchedule()){
            if(cl.getUcCode()==ucode){
                cout<<"Student is already in this UC."<<'\n';
                addStudent_1();
            }
        }
        cout << "These are the classes of " << ucode << '\n';
        for (auto n: UCINSCH) {
            if (n.getUcCode() == ucode) {
                cout << n.getClassCode() << '\n';
            }
        }

        cout << endl << "Insert the code of the class you wish to change: ";
        cin >> wtc;

        //------------------Checking if the class has the occupation---------------//
        set<string> classes;
        vector<pair<string,int>> ocupation;
        for(auto cl:UCINSCH){
            classes.insert(cl.getClassCode());
        }
        for(auto cl :classes){
            int a=0;
            for(auto stu :ALLSTUDENTS){
                for(auto cl1: stu.getStudentSchedule()){
                    if (cl1.getClassCode()==cl){
                        a++;
                    }
                }
            }
        }
        for (auto p:ocupation){if (p.first==wtc){p.second=p.second+1;}}
        if (helperclasses(ocupation)==false){
            cout<<"This class if full, please choose another one."<<'\n';
            addStudent_1();
        }
        //--------------------------------------------------------------//
    }
    if (i == 2) {
        cout << endl << "Insert the class code in witch you want student to be added: ";
        cin >> ccode;

        cout << "This are the UC's of the " << ccode << '\n';
        for (auto n: UCINSCH) {
            if (n.getClassCode() == ccode) {
                cout << n.getUcCode() << '\n';
            }
        }
        cout << endl << "Insert the code of the UC you wish to change: ";
        cin >> wtc;

        //------------------Checking if the class has the occupation---------------//

        set<string> classes;
        vector<pair<string,int>> ocupation;
        for(auto cl:UCINSCH){
            classes.insert(cl.getClassCode());
        }
        for(auto cl :classes){
            int a=0;
            for(auto stu :ALLSTUDENTS){
                for(auto cl1: stu.getStudentSchedule()){
                    if (cl1.getClassCode()==cl){
                        a++;
                    }
                }
            }
        }
        for (auto p:ocupation){if (p.first==wtc){p.second=p.second+1;}}
        if (helperclasses(ocupation)==false){
            cout<<"This class if full, please choose another one."<<'\n';
            addStudent_1();
        }
        //--------------------------------------------------------------//
    }
    //-----------------------------------------------------------------//

    list<Classes> sch = Student1.getStudentSchedule();
    TimeType FoudTime;
    for (auto cl: UCINSCH){
        if(cl.getUcCode()==ucode and cl.getClassCode()==ccode){
            FoudTime=cl.getTimetable();} }
    Classes newclass=Classes(ccode,ucode,FoudTime);
    sch.push_back(newclass);
    Student1.setLessons(sch);

    if (i == 1) {
        change = "The student " + Student1.getName() + " whose student code is " + Student1.getStudentCode()
                 + " was added to the UC " + ucode + " at " + ccode + " class.";
        changes.push_back(change);
    }
    if (i == 2) {
        change = "The student " + Student1.getName() + " whose student code is " + Student1.getStudentCode()
                 + " was added to the class " + ccode + " at " + ucode + " UC.";
        changes.push_back(change);
    }

}

bool Menu::helperclasses(vector <pair<string,int>> original) {
    for (int l = 0; l < original.size(); l++) {
        for (int l1 = 0; l1 < original.size(); l1++) {
            int d = original[l].second - original[l1].second;
            if (d > 4 || d < -4) {
                return false;
            }
        }
    }
    return true;
}


void Menu::removeStudent_2() {
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|--[ Do you wish to remove the student  ]-|\n"
         << "|--------[ from a Class or a UC? ]--------|\n"
         << "|-- 1: UC --------------------------------|\n"
         << "|-- 3: Class -----------------------------|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option:";
    string inp;
    cin >> inp;
    int i = 0;
    //interaction//
    if (inp == "1") { i = 1; }
    else if (inp == "2") { i = 2; }
    else if (inp == "3" || inp == "B" || inp == "b") { start(); }
    else { cout << "|-- Invalid Input ------------------------|\n"; }

    cout << endl << "Insert student's code: " << endl;
    string studentcode;
    cin >> studentcode;
    string wtc;
    string ccode;
    string change;
    string ucode;
    Student Studentprov;
    list <Classes> sch;
    for (auto stu : ALLSTUDENTS){
        if (stu.getStudentCode() == studentcode){
            Studentprov = stu;
        }
    }
    if (i == 1){
        cout << endl << "Insert the UC code: " << endl;
        cin >> ucode;
        for (auto cl: Studentprov.getStudentSchedule()){
            if (cl.getUcCode() != ucode){
                sch.push_back(cl);
            }
        }
        Studentprov.setLessons(sch);
        change = "The student " + Studentprov.getName() + " whose student code is " + Studentprov.getStudentCode()
                + " was removed from " + ucode + " UC.";
        changes.push_back(change);
    }
    if (i == 2){
        cout << endl << "Insert the class code: " << endl;
        cin >> ccode;
        for(auto cl: Studentprov.getStudentSchedule()){
            if(cl.getClassCode()!=ccode){
                sch.push_back(cl);
            }
        }
        Studentprov.setLessons(sch);
        change = "The student " + Studentprov.getName() + " whose student code is " + Studentprov.getStudentCode()
                 + " was removed from " + ccode + " class.";
        changes.push_back(change);
    }

};

void Menu::switchStudent_3(){
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|--[ Do you wish to switch the student ]--|\n"
         << "|----------[ a Class or a UC? ]-----------|\n"
         << "|-- 1: UC --------------------------------|\n"
         << "|-- 3: Class -----------------------------|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option: ";
    string inp;
    cin >> inp;
    int i = 0;
    //interaction//
    if (inp == "1") { i = 1; }
    else if (inp == "2") { i = 2; }
    else if (inp == "3" || inp == "B" || inp == "b") { start(); }
    else { cout << "|-- Invalid Input ------------------------|\n"; }

    cout<<"Insert the student code: ";
    string studentcode;
    cin>> studentcode;
    Student Student1;
    for(auto stu : ALLSTUDENTS){
        if(stu.getStudentCode()==studentcode){
            Student1=stu;
        }
    }

    string uccode1;
    string uccode2;
    string ccode1;
    string ccode2;
    string wtc;
    list <Classes> sch;
    if(i==1){
        cout<<"What is Student's currently UC code that you wish to change? ";
        cin>>uccode1;
        cout<<"What is the UC code you want Student to be? ";
        cin>>uccode2;
        cout << "These are the classes of " << uccode2 << '\n';
        for (auto n: UCINSCH) {
            if (n.getUcCode() == uccode2) {
                cout << n.getClassCode() << '\n';
            }
        }

        cout << endl << "Insert the code of the class you wish to change: ";
        cin >> wtc;
        Classes n;
        //--------------------------------------------------------------//
        string ccodebefore;
        set<string> classes;
        vector<pair<string,int>> ocupation;
        for(auto cl:UCINSCH){
            classes.insert(cl.getClassCode());
        }
        for(auto cl :classes){
            int a=0;
            for(auto stu :ALLSTUDENTS){
                for(auto cl1: stu.getStudentSchedule()){
                    if (cl1.getClassCode()==cl){
                        a++;
                    }
                }
            }
        }
        for (auto cl:Student1.getStudentSchedule()){
            if(cl.getUcCode()==uccode1){ccodebefore=cl.getClassCode();}}
        for (auto p:ocupation){
            if (p.first==wtc){p.second=p.second+1;}
            else if(p.first==ccodebefore){p.second=p.second-1;}}
        if (helperclasses(ocupation)==false){
            cout<<"This class if full, please choose another one."<<'\n';
            addStudent_1();
        }
        //------------------------------------------------------------//
        for(auto cl:Student1.getStudentSchedule()){

            if(cl.getUcCode()==uccode1){
                n.setClassCode(cl.getClassCode());
                n.setUcCode(uccode2);

                TimeType FoudTime;
                for (auto cl1: UCINSCH){
                    if(cl1.getUcCode()==uccode2 and cl1.getClassCode()==n.getClassCode()){
                        FoudTime=cl1.getTimetable();}
                }
                n.setTimetable(FoudTime);
                sch.push_back(n);
            }
            else{sch.push_back(cl);}
        }
    }
    else {
        cout << "What is Student's currently class code that you wish to change? ";
        cin >> ccode1;
        cout << "What is the class code you want Student to be? ";
        cin >> ccode2;
        Classes n;

        //----------------------------STUDENT CAN CHANGE CLASS--------------------------------------//
        set<string> classes;
        vector<pair<string,int>> ocupation;
        for(auto cl:UCINSCH){
            classes.insert(cl.getClassCode());
        }
        for(auto cl :classes){
            int a=0;
            for(auto stu :ALLSTUDENTS){
                for(auto cl1: stu.getStudentSchedule()){
                    if (cl1.getClassCode()==cl){
                        a++;
                    }
                }
            }
        }
        for (auto p:ocupation){
            if (p.first==ccode1){p.second=p.second-1;}
            else if(p.first==ccode2){p.second=p.second+1;}}
        if (helperclasses(ocupation)==false){
            cout<<"This class if full, please choose another one."<<'\n';
            switchStudent_3();
        }

        //-------------------------------------------------------------------------//
        for (auto cl: Student1.getStudentSchedule()) {

            if (cl.getClassCode() == ccode1) {
                n.setUcCode(cl.getUcCode());
                n.setClassCode(ccode2);

                TimeType FoudTime;
                for (auto cl1: UCINSCH) {
                    if (cl1.getUcCode() == n.getUcCode() and cl1.getClassCode() == n.getClassCode()) {
                        FoudTime = cl1.getTimetable();
                    }
                }
                n.setTimetable(FoudTime);
                sch.push_back(n);
            } else { sch.push_back(cl); }
        }
    }
}

void Menu::activity() {
    for (auto activ : changes) {
        cout << activ << endl;
    }
}