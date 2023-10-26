#include <fstream>
#include <sstream>
#include "Menu.h"
#include "Schedule.h"
#include "readFiles.cpp"

using namespace std;


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