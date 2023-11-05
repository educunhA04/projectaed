#include "Menu.h"
#include "AllData.h"
#include "readFiles.cpp"

using namespace std;

int main(){
    /**
     * @brief Creating the Data to work in the project, and reading it from the files;
     */
    /// Get Data;
    AllData allData;
    allData.setClasses(readClassesData()); // classcode, uccode, time(weekday, starthour, duration, type)
    allData.setStudents(readStudentsData()); // studentname, upcode, classdata(classcode, uccode, time)

    /**
     * @brief Initializing the Menu with the Data read before;
     */
    Menu menu;
    menu.setData(allData);
    menu.start();
}