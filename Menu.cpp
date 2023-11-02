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

Menu::Menu() : data(UCINSCH, ALLSTUDENTS) {} //contructor

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
        if (toLowerSTR(inp) == toLowerSTR(element.getClassCode())) found = true;
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
            cout << "Showing " << element.getName() << "'s Schedule";
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
         << "|-- 1: Add Student -----------------------|\n"
         << "|-- 2: Remove Student --------------------|\n"
         << "|-- 3: Switch Student --------------------|\n"
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
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|--[ Do you wish to add the student to ]--|\n"
         << "|----------[ a Class or a UC? ]-----------|\n"
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

    cout << endl << "Insert student's code";
    string studentcode;
    cin >> studentcode;
    string wtc;
    string ccode;
    string ucode;
    if (i == 1) {
        cout << endl << "Insert the UC code witch you want student to be added:";
        cin >> ucode;
        cout << "This are the classes of the " << ucode << '\n';
        for (auto n: UCINSCH) {
            if (n.getUcCode() == ucode) {
                cout << n.getClassCode() << '\n';
            }
        }

        cout << endl << "Insert the code of the class you wish to change:";
        cin >> wtc;
    }
    if (i == 2) {
        cout << endl << "Insert the class code witch you want student to be added:";
        cin >> ccode;
        cout << "This are the UC's of the " << ccode << '\n';
        for (auto n: UCINSCH) {
            if (n.getClassCode() == ccode) {
                cout << n.getUcCode() << '\n';
            }
        }

        cout << endl << "Insert the code of the UC you wish to change:";
        cin >> wtc;
    }
    //-----------------------------------------------------------------//

    Student student1=Student("",studentcode);
    for(auto stu : ALLSTUDENTS){
        if (studentcode==stu.getStudentCode()){
            student1=stu;
        }
    }
    list<Classes> sch=student1.getStudentSchedule();
    TimeType FoudTime;
    for (auto cl: UCINSCH){
        if(cl.getUcCode()==ucode and cl.getClassCode()==ccode){
            FoudTime=cl.getTimetable();} }
    Classes newclass=Classes(ccode,ucode,FoudTime);
    sch.push_back(newclass);
    student1.setLessons(sch);
}
// TODO

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

    cout << endl << "Insert student's code";
    string studentcode;
    cin >> studentcode;
    string wtc;
    string ccode;
    string ucode;
    Student Studentprov;
    list <Classes> sch;
    for(auto stu : ALLSTUDENTS){
        if(stu.getStudentCode()==studentcode){
            Studentprov=stu;
        }
    }
    if(i==1){
        for(auto cl: Studentprov.getStudentSchedule()){
            if(cl.getUcCode()!=ucode){
                sch.push_back(cl);
            }
        }
        Studentprov.setLessons(sch);
    }
    if(i==2){
        for(auto cl: Studentprov.getStudentSchedule()){
            if(cl.getClassCode()!=ccode){
                sch.push_back(cl);
            }
        }
        Studentprov.setLessons(sch);
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
    list <Classes> sch;
    if(i==1){
        cout<<"What is Student's currently UC code that you wish to change? ";
        cin>>uccode1;
        cout<<"What is the UC code you want Student to be? ";
        cin>>uccode2;
        Classes n;

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
    else{
        cout<<"What is Student's currently class code that you wish to change? ";
        cin>>ccode1;
        cout<<"What is the class code you want Student to be? ";
        cin>>ccode2;
        Classes n;

        for(auto cl:Student1.getStudentSchedule()){

            if(cl.getClassCode()==ccode1){
                n.setUcCode(cl.getUcCode());
                n.setClassCode(ccode2);

                TimeType FoudTime;
                for (auto cl1: UCINSCH){
                    if(cl1.getUcCode()==n.getUcCode() and cl1.getClassCode()==n.getClassCode()){
                        FoudTime=cl1.getTimetable();}
                }
                n.setTimetable(FoudTime);
                sch.push_back(n);
            }
            else{sch.push_back(cl);}
        }}
}

//############################# SHOW ##################################//

void Menu::showStudentsPerYear_1() {
    cout<<"Insert the Year you want to consult: "<<'\n';
    string inp;
    cin>>inp;
    int c1;
    int c2;
    int c3;
    for (auto stu : ALLSTUDENTS){
        auto schedule = stu.getStudentSchedule();

        for(auto cl : schedule){
            string ccode=cl.getClassCode();
            if (ccode.substr(0,1)=="1"){c1++;}
            else if (ccode.substr(0,1)=="2"){  c2++;}
            else if (ccode.substr(0,1)=="3"){  c3++;}
        }
        list<int> maxi={c1,c2,c3};
        int count=*max_element(maxi.begin(),maxi.end());
        if (c1==count and "1"==inp){cout<<stu.getStudentCode()<<","<<stu.getName()<<'\n';}
        else if (c2==count and inp=="2"){cout << stu.getStudentCode() << "," << stu.getName() << '\n';}
        else if (c3==count and inp=="3"){cout<<stu.getStudentCode()<<","<<stu.getName()<<'\n';}
        c1 = 0;
        c2 = 0;
        c3 = 0;
    }

}; // TODO


void Menu::checkOccupationPerYear_1() {
    cout<<"Insert the Year you want to consult occupation: "<<'\n';
    string inp;
    cin>>inp;
    int c1;
    int c2;
    int c3;
    int counttotal=0;
    for (auto stu : ALLSTUDENTS){
        auto schedule = stu.getStudentSchedule();

        for(auto cl : schedule){
            string ccode=cl.getClassCode();
            if (ccode.substr(0,1)=="1"){c1++;}
            else if (ccode.substr(0,1)=="2"){  c2++;}
            else if (ccode.substr(0,1)=="3"){  c3++;}
        }
        list<int> maxi={c1,c2,c3};
        int count=*max_element(maxi.begin(),maxi.end());
        if (c1==count and "1"==inp){counttotal++;}
        else if (c2==count and inp=="2"){counttotal++;}
        else if (c3==count and inp=="3"){counttotal++;}
        c1 = 0;
        c2 = 0;
        c3 = 0;
    }
    cout<<"The "<<inp<<" of LEIC has"<<counttotal;
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




