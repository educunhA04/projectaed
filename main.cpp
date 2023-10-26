#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Schedule.h"
#include "readFiles.cpp"

using namespace std;

int main(){
    // Get Data;
    Schedule allData;
    allData.setClasses(readClassesData()); // classcode, uccode, weekday, starthour, duration, type
    allData.setStudents(readStudentsData()); // studentname, upcode, classcode, uccode

    // Initialize Menu and Move Data inside the menu;
    Menu menu;
    menu.setSched(allData);
    menu.start();
}