#include "Menu.h"
#include "AllData.h"
#include "readFiles.cpp"

using namespace std;

int main(){
    // Get Data;
    AllData allData;
    allData.setClasses(readClassesData()); // classcode, uccode, time(weekday, starthour, duration, type)
    allData.setStudents(readStudentsData()); // studentname, upcode, classdata(classcode, uccode, time)

    // Initialize Menu and Move Data inside the menu;
    Menu menu;
    menu.setData(allData);
    menu.start();
}