#include "Menu.h"
#include "AllData.h"
#include <iostream>
#include <string>
#include <set>
#include <fstream>
#include <sstream>
#include <cstdio>
#include "readFiles.h"

using namespace std;

string toLowerSTR (string str){
    for(auto& elem : str){
        elem = tolower(elem);}
    return str;
}

Menu::Menu() : data(vector<Classes>(), set<Student>()) {} //contructor



void Menu::checkOccupationPerClass_2() {
    cout << "Insert a valid Class code: \n";
    string inp;
    cin >> inp;

    int count = 0;
    bool found = false;

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
    if(!found){
        cout << "Class not found.\n\n";
    }
    else{
        cout << "The number of students with lessons in class " << inp << " is " << count << ".\n\n";
    }
    checkOccupationPer_5();
}

void Menu::checkOccupationPerUC_3() {
    string inp;
    cout << "Insert a valid UC Code: \n";
    cin >> inp;
    int count = 0;
    bool found = false;

    for (auto element: data.getStudents()){
        auto horario = element.getStudentSchedule();

        for(auto aula : horario){
            if(toLowerSTR(inp) == toLowerSTR(aula.getUcCode())) {
                count++;
                found = true;
                break;
            }
        }
    }
    if(!found){cout << "UC not found.\n\n";}
    else{
        cout << "The number of students studying the UC " << inp << " is " << count << ".\n\n";
    }
    checkOccupationPer_5();
}

void Menu:: showClassSchedule_4(){
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
    accessInfo_1();
}

void Menu::showStudentSchedule_1(){
    string inp;
    cout << "Insert a valid student Code: ";
    cin >> inp;
    bool found = false;

    for(auto element : data.getStudents()){
        if (element.getStudentCode() == inp){
            found = true;
            auto horario = element.getStudentSchedule();
            cout << "Showing " << element.getName() << "'s Schedule" << endl << endl;
            for(auto aula : horario){
                cout << "UCCode: " << aula.getUcCode() << " / "
                     << "ClassCode: " << aula.getClassCode() << " / "
                     << "Day: " << aula.getTimetable().getDay() << " / "
                     << "Type: " << aula.getTimetable().getTypeOfClass() << " / "
                     << "StartHour: " << aula.getTimetable().getStartHour() << " / "
                     << "Duration: " << aula.getTimetable().getClassDuration() << "\n\n";
            }
        }
    }
    if (!found){
        cout << "Student not found.\n\n";

    }
    accessInfo_1();
}

void Menu::showStudentsPerUC_3(){
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
    showStudentsPer_2();
};

void Menu::showStudentsPerClass_2() {
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
    showStudentsPer_2();
};

void Menu::showStudentsInAtLeastNUCs_3() {
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
    accessInfo_1();
}

void Menu::checkBiggestUc_6() {
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

    accessInfo_1();
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
//#############################  CHANGES  ##################################//

void Menu::addStudent_1() {
    //set<Student> allstudents=readStudentsData();

    //interaction//

    //cout << endl << "Insert student's code";
    //string studentcode;
    //cin >> studentcode;
    //cout << endl << "Insert the UC code witch you want to change class:";
    //  string ucode;
    //cin >> ucode;
    //cout << endl <<"Insert the code of the class you wish to change:";
    //string wtc;
    //cin>> wtc;
    //-----------------------------------------------------------------//


    //string ccclass;
    //string line;
    //string word;
    //string Num;
    //vector<string> aux;
    //Student student1=Student("",studentcode);
    //for(auto student : allstudents){
    //    if (studentcode==student.getStudentCode()){
    //        student1=student;
    //    }
    //}
    //list<Classes> sch=student1.getStudentSchedule();
    //for (auto cl:sch){
    //    if (cl.getUcCode()==ucode){
    //        ccclass=cl.getClassCode();
    //    }
    //}

    //ifstream iFile("students_classes.csv");
    //ofstream oFile("changed_students_classes.csv");
    //oFile.is_open();
    //if(iFile.is_open()) {
    //    cout<<"2"<<'\n';
    //    getline(iFile, line);
    //    oFile << line << "\n";
    //   while (getline(iFile, line)) {
    //       cout<<"3"<<'\n';
    //        aux.clear();
    //        istringstream iss(line);
    //        while (getline(iss, word, ',')) {
    //            aux.push_back(word);
    //        }
    //        cout<<"4"<<'\n';
    //        string stucode = aux[0];
    //        string stname = aux[1];
    //        string uccode = aux[2];
    //        string ccode = aux[3];
    //        if (stucode == studentcode and uccode == ucode) {
    //           ccode = wtc;
    //        }
//        oFile << stucode << "," << stname << "," << uccode << "," << ccode;
    //    }
    //}
    //iFile.close();
    //oFile.close();
} // TODO

void Menu::removeStudent_2() {
    int n;
    cout << "|------------[ Remove student ]-----------|\n"
         << "|-----------------------------------------|\n"
         << "|--[ You wish to remove the student of ]--|\n"
            "|---[ every class or one in specific ]----|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: Every class--------- --------------|\n"
         << "|-- 2: Only one ------------------------- |\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";
    cout << endl << "Insert your desired option:";
    string inp;
    cin >> inp;
    if (inp=="1"){
        removeallStudent();
    }
    if (inp=="2"){
        removeltlStudent();
    }
    else if (inp == "3" || inp == "B" || inp == "b"){requestChange_2();}
}; // TODO

void Menu::removeallStudent() {
    cout<<endl<<"Insert the student's code:";
    string studentscode;
    cin>>studentscode;
    ifstream ifile("../Files/students_classes.csv");
    ofstream ofile("../Files/students_change.csv");
    string line;
    string word;
    vector<string> aux;

    if(ifile.is_open() and ofile.is_open()){
        getline(ifile,line);
        ofile << line << '\n';
        while (getline(ifile,line)){
            aux.clear();
            istringstream  iss(line);
            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }
            string stuCode = aux[0];
            if(stuCode!=studentscode){
                ofile<<aux[0]<<","<<aux[1]<<","<<aux[2]<<","<<aux[3]<<'\n';
            }
        }
        ifile.close();
        ofile.close();

        remove("../Files/students_classes.csv");
        rename("../Files/students_change.csv", "../Files/students_classes.csv");

    }
    else{cout<<"file not found";}
}; //TODO

void Menu::removeltlStudent() {
    int n;
    cout<<endl<<"Insert the student's code:";
    string studentscode;
    cin>>studentscode;
    cout<<endl<<"Insert the UC's code:";
    string ucscode;
    cin>>ucscode;
    ifstream ifile("../Files/students_classes.csv");
    ofstream ofile("../Files/students_change.csv");
    string line;
    string word;
    vector<string> aux;

    if(ifile.is_open() and ofile.is_open()){
        getline(ifile,line);
        ofile << line << '\n';
        while (getline(ifile,line)){
            aux.clear();
            istringstream  iss(line);
            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }
            string stuCode = aux[0];
            string uccode =aux[2];
            if(stuCode==studentscode and ucscode==uccode){
                n=1;
            }
            else{ofile<<aux[0]<<","<<aux[1]<<","<<aux[2]<<","<<aux[3]<<'\n';}
        }
        ifile.close();
        ofile.close();

        remove("../Files/students_classes.csv");
        rename("../Files/students_change.csv", "../Files/students_classes.csv");

    }
    else{cout<<"file not found";}
}; //TODO

void Menu::switchStudent_3(){

}; // TODO

//############################# SHOW ##################################//

void Menu::showStudentsPerYear_1() {
    int input;
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
    }


};


void Menu::checkOccupationPerYear_1() {
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
}; // TODO

//###############################################################//

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