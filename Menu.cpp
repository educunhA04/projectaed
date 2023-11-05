#include "Menu.h" // Include the Menu class header file
#include "AllData.h" // Include the AllData class header file
#include <iostream> // Include the input/output stream library
#include <string> // Include the string library
#include <set> // Include the set library
#include <fstream> // Include the file stream library
#include <sstream> // Include the string stream library
#include <cstdio> // Include the C Standard Input/Output library
#include "readFiles.h" // Include the readFiles class header file
#include <list> // Include the list library
#include <algorithm> // Include the algorithm library
using namespace std; // Use the standard namespace

string toLowerSTR(string str) {
    // Function to convert a string to lowercase
    for (auto& elem : str) {
        elem = tolower(elem);
    }
    return str;
}

set<Classes> UCSNCL = readucperclass(); // Create a set of Classes by calling the readucperclass function
vector<Classes> UCINSCH = readClassesData(); // Create a vector of Classes by calling the readClassesData function
set<Student> ALLSTUDENTS = readStudentsData(); // Create a set of Students by calling the readStudentsData function

Menu::Menu() : data(UCINSCH, ALLSTUDENTS) {} // Constructor for the Menu class

//############################# MENUS ##################################//
void Menu::start() {
    // Main menu function to display and handle user options
    system("clear");
    bool isOpen = true;

    while (isOpen) {
        cout << "|--[ Menu ]-------------------------------|\n"
             << "|-----------------------------------------|\n"
             << "|-[ What action do you wish to perform? ]-|\n"
             << "|-----------------------------------------|\n"
             << "|-- 1: Access Info -----------------------|\n"
             << "|-- 2: Request a change ------------------|\n"
             << "|-- 3: Changes History -------------------|\n"
             << "|-- C: Close -----------------------------|\n"
             << "|-----------------------------------------|\n";

        cout << endl << "Insert your desired option:" << endl;
        string inp;
        cin >> inp;

        if (inp == "1") accessInfo_1();
        else if (inp == "2") requestChange_2();
        else if (inp == "3") showHistory();
        else if (inp == "c" || inp == "C") {
            cout << "|-- The program will now close -----------|\n";
            isOpen = false;
        }
        else {
            cout << "|-- Invalid Input ------------------------|\n";
        }
    }
}

void Menu::requestChange_2() {
    // Function to handle change requests
    system("clear");
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ What Change request do you have? ]----|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: Add Student -----------------------|\n"
         << "|-- 2: Remove Student --------------------|\n"
         << "|-- 3: Switch Student --------------------|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option: " << endl;
    string inp;
    cin >> inp;

    if (inp == "1") {
        addStudent_1();
    }
    else if (inp == "2") {
        removeStudent_2();
    }
    else if (inp == "3") {
        switchStudent_3();
    }
    else if (inp == "B" || inp == "b") {
        start();
    }
    else {
        cout << "|-- Invalid Input ------------------------|\n";
    }
}

void Menu::accessInfo_1() {
    // Function to access different types of information
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

    cout << endl << "Insert your desired option: " << endl;
    string inp;
    cin >> inp;

    if (inp == "1") {
        showStudentSchedule_1();
    }
    else if (inp == "2") {
        showStudentsPer_2();
    }
    else if (inp == "3") {
        showStudentsInAtLeastNUCs_3();
    }
    else if (inp == "4") {
        showClassSchedule_4();
    }
    else if (inp == "5") {
        checkOccupationPer_5();
    }
    else if (inp == "6") {
        checkBiggestUc_6();
    }
    else if (inp == "7" || inp == "B" || inp == "b") {
        start();
    }
    else {
        cout << "|-- Invalid Input ------------------------|\n";
    }
}

void Menu::checkOccupationPer_5() {
    // Function to check the occupation per year, class, or UC
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

    cout << endl << "Insert your desired option: " << endl;
    string inp;
    cin >> inp;

    if (inp == "1") {
        checkOccupationPerYear_1();
    }
    else if (inp == "2") {
        checkOccupationPerClass_2();
    }
    else if (inp == "3") {
        checkOccupationPerUC_3();
    }
    else if (inp == "4" || inp == "B" || inp == "b") {
        accessInfo_1();
    }
    else {
        cout << "|-- Invalid Input ------------------------|\n";
    }
}

void Menu::showStudentsPer_2() {
    // Function to display options to show students per year, class, or UC
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

    cout << endl << "Insert your desired option: " << endl;
    string inp;
    cin >> inp;

    if (inp == "1") {
        showStudentsPerYear_1();
    }
    else if (inp == "2") {
        showStudentsPerClass_2();
    }
    else if (inp == "3") {
        showStudentsPerUC_3();
    }
    else if (inp == "4" || inp == "B" || inp == "b") {
        accessInfo_1();
    }
    else {
        cout << "|-- Invalid Input ------------------------|\n";
    }
}

//############################## FUNCTIONS INFO #################################//

void Menu::showStudentSchedule_1() {
    // Function to display a student's schedule
    system("clear");
    string inp;
    cout << "Insert a valid student Code: " << endl;
    cin >> inp;
    bool found = false;

    for (auto element : data.getStudents()) {
        if (element.getStudentCode() == inp) {
            found = true;

            cout << "Showing " << element.getName() << "'s Schedule" << endl << endl;
            for (auto aula : element.getStudentSchedule()) {
                cout << "UCCode: " << aula.getUcCode() << " / "
                     << "ClassCode: " << aula.getClassCode() << " / "
                     << "Day: " << aula.getTimetable().getDay() << " / "
                     << "Type: " << aula.getTimetable().getTypeOfClass() << " / "
                     << "StartHour: " << aula.getTimetable().getStartHour() << " / "
                     << "Duration: " << aula.getTimetable().getClassDuration() << endl;
            }
        }
    }
    if (!found) {
        cout << "Student not found.\n\n";
    }

    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        accessInfo_1();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

void Menu::showStudentsPerYear_1() {
    // Function to display students by a specific year
    system("clear");
    int num;
    int n;
    cout << "Insert a number correspondent to a year: " << endl;
    cin >> num;

    // Initialize variables for year and class code comparison
    int max = 0;

    // Iterate through the students and their schedules to check for the specified year
    for (auto element : data.getStudents()) {
        max = 0;

        // Find the maximum class code for the student
        for (auto aula : element.getStudentSchedule()) {
            n = aula.getClassCode()[0] - '0';
            if (n > max) {
                max = n;
            }
        }

        // Display student information if the year matches
        if (max == num) {
            cout << " " << element.getStudentCode() << "     |   " << element.getName() << endl;
        }
    }

    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        accessInfo_1();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

void Menu::showStudentsPerUC_3() {
    // Function to display students per UC
    system("clear");
    cout << endl << "Insert the code of the UC: ";
    string inp;
    cin >> inp;
    set<Student> aux;
    bool foundUC = false;

    // Iterate through students and their schedules to check for the specified UC
    for (auto elem : data.getStudents()) {
        bool foundSTN = false;

        // Keep checking student schedules until the UC is found
        while (!foundSTN) {
            for (auto elem2 : elem.getStudentSchedule()) {
                if (elem2.getUcCode() == inp) {
                    foundSTN = true;
                    foundUC = true;
                    aux.insert(elem);
                }
            }
        }
    }

    // Display students studying the specified UC
    if (foundUC) {
        cout << "Now showing students studying " << inp << ".\n";
        for (auto student : aux) {
            cout << "Student Code: " << student.getStudentCode() << " / Student Name: " << student.getName() << endl;
        }
        cout << "\n\n";
    }
    else {
        cout << "UC not found.\n\n";
    }

    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to quit" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        showStudentsPer_2();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

void Menu::showStudentsPerClass_2() {
    // Function to display students in a specific class
    system("clear");
    cout << endl << "Insert the code of the class: ";
    string inp;
    cin >> inp;

    set<Student> aux;
    bool foundClass = false;

    // Iterate through students and their schedules to check for the specified class
    for (auto elem : data.getStudents()) {
        bool foundSTN = false;

        for (auto elem2 : elem.getStudentSchedule()) {
            if (elem2.getClassCode() == inp) {
                foundSTN = true;
                foundClass = true;
                aux.insert(elem);
                break;
            }
        }
    }

    // Display students in the specified class
    if (foundClass) {
        cout << "Now showing students studying in class " << inp << ".\n";
        cout << "Student Code" << " | Student Name" << endl;
        for (auto student : aux) {
            cout << " " << student.getStudentCode() << "   |   " << student.getName() << endl;
        }
        cout << "\n\n";
    }
    else {
        cout << "Class not found.\n\n";
    }

    char what;

    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        showStudentsPer_2();
    }
    else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}


void Menu::showStudentsInAtLeastNUCs_3() {
    // Clear the console screen
    system("clear");

    // Prompt the user to input the number of UCs
    cout << endl << "Insert the number of UCs: ";
    int input;
    cin >> input;

    // Create a set to store unique UC codes for each student
    set<string> uniqueUCCodes;
    int count = 0; // Initialize the count of students

    // Inform the user about the purpose of the operation
    cout << "The following students study at least " << input << " UC's:\n";

    // Iterate through the list of students
    for (auto element : data.getStudents()) {
        // Get the student's schedule
        auto horario = element.getStudentSchedule();

        // Iterate through the classes in the student's schedule
        for (auto aula : horario) {
            uniqueUCCodes.insert(aula.getUcCode()); // Collect unique UC codes
        }

        // Check if the student is enrolled in at least 'input' UCs
        if (uniqueUCCodes.size() >= input) {
            uniqueUCCodes.clear(); // Reset the set for the next student
            count++; // Increment the count for each student meeting the condition
            cout << "Student Code: " << element.getStudentCode() << " / Student Name: " << element.getName() << endl;
        }
    }

    char what;

    // Display the total count of eligible students
    cout << endl << "Total: " << count << " students. " << endl << endl;

    if (count == 0) {
        cout << "There are no students enrolled in at least this number of UC's. " << endl;
    }

    // Ask the user for further action
    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        accessInfo_1();
    } else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

void Menu::showClassSchedule_4() {
    // Clear the console screen
    system("clear");

    // Prompt the user to input a valid Class Code
    string inp;
    cout << "Insert a valid Class Code: \n";
    cin >> inp;
    bool found = false;

    // Iterate through the list of UCs to find a matching class code
    for (auto element : data.getUCS()) {
        if (toLowerSTR(inp) == toLowerSTR(element.getClassCode())) {
            found = true;
        }
    }

    if (found) {
        // Display the schedule for the specified class
        cout << "Showing Schedule for class " << inp << "\n";
        for (auto element2 : data.getUCS()) {
            cout << "UCCode: " << element2.getUcCode() << " / "
                 << "Day: " << element2.getTimetable().getDay() << " / "
                 << "Type: " << element2.getTimetable().getTypeOfClass() << " / "
                 << "StartHour: " << element2.getTimetable().getStartHour() << " / "
                 << "Duration: " << element2.getTimetable().getClassDuration() << "\n\n";
        }
    } else {
        cout << "Class not found.\n\n";
    }

    char what;

    // Ask the user for further action
    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        accessInfo_1();
    } else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}
// Rest of the code follows a similar pattern with comments for each section.



void Menu::checkOccupationPerYear_1() {
    // Clear the console screen
    system("clear");

    int num;
    int n;

    // Prompt the user to input a year number
    cout << "Insert a number correspondent to a year: " << endl;
    cin >> num;

    // Determine the ordinal indicator for the year (e.g., 1st, 2nd, 3rd, etc.)
    string indicator = "nd";
    if (num == 1) {
        indicator = "st";
    }

    int sum = 0;
    int max = 0;

    // Iterate through the list of students
    for (auto element : data.getStudents()) {
        max = 0;

        // Iterate through the classes in the student's schedule
        for (auto aula : element.getStudentSchedule()) {
            n = aula.getClassCode()[0] - '0';
            if (n > max) {
                max = n;
            }
        }

        // Check if the maximum year number matches the input
        if (max == num) {
            sum++;
        }
    }

    // Display the count of students in the specified year
    cout << "There are " << sum << " students enrolled in the " << num << indicator << " year." << endl;

    char what;

    // Ask the user for further action
    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        accessInfo_1();
    } else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

void Menu::checkOccupationPerClass_2() {
    // Prompt the user to input a valid Class code
    cout << "Insert a valid Class code: \n";
    string inp;
    cin >> inp;

    // Display a menu with two options to choose from
    cout << "|--[ Access Info ]------------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ Check Occupation Per Class]-----------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ Do you want to know the occupation ]--|\n"
         << "|---[ of the class in a specific UC? ]---|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: Yes -------------------------------|\n"
         << "|-- 2: No --------------------------------|\n"
         << "|-----------------------------------------|\n";
    string n;
    cout << endl << "Insert an option: " << endl;

    cin >> n;
    string uc;
    int count = 0;
    bool found = false;

    if (n == "1") {
        cout << "Insert the UC code of the class:";
        cin >> uc;

        // Iterate through the list of students and their schedules
        for (auto element : data.getStudents()) {
            auto horario = element.getStudentSchedule();

            // Iterate through the classes in each student's schedule
            for (auto aula : horario) {
                if (toLowerSTR(aula.getClassCode()) == toLowerSTR(inp) && toLowerSTR(aula.getUcCode()) == toLowerSTR(uc)) {
                    count++;
                    found = true;
                    break; // No need to continue searching
                }
            }
        }
    } else if (n == "2") {
        // Iterate through the list of students and their schedules
        for (auto element : data.getStudents()) {
            auto horario = element.getStudentSchedule();

            // Iterate through the classes in each student's schedule
            for (auto aula : horario) {
                if (toLowerSTR(aula.getClassCode()) == toLowerSTR(inp)) {
                    count++;
                    found = true;
                    break; // No need to continue searching
                }
            }
        }
    }

    if (!found) {
        cout << "Class not found.\n\n";
    } else {
        // Display the count of students with lessons in the specified class
        cout << "The number of students with lessons in class " << inp << " is " << count << ".\n\n";
    }

    char what;

    // Ask the user for further action
    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        checkOccupationPer_5();
    } else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}


void Menu::checkOccupationPerUC_3() {
    // Clear the console screen
    system("clear");

    string inp;

    // Prompt the user to input a valid UC Code
    cout << "Insert a valid UC Code: \n";
    cin >> inp;

    // Display a menu with two options to choose from
    cout << "|--[ Access Info ]------------------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ Check Occupation Per UC]-------------|\n"
         << "|-----------------------------------------|\n"
         << "|-[ Do you want to know the occupation ]--|\n"
         << "|---[ of the UC in a specific class? ]---|\n"
         << "|-----------------------------------------|\n"
         << "|-- 1: Yes -------------------------------|\n"
         << "|-- 2: No --------------------------------|\n"
         << "|-----------------------------------------|\n";
    string n;

    // Prompt the user to choose an option
    cout << endl << "Insert an option: " << endl;
    cin >> n;
    string classe;
    int count = 0;
    bool found = false;

    if (n == "1") {
        cout << "Insert the class code of the UC:";
        cin >> classe;

        // Iterate through the list of students and their schedules
        for (auto element : data.getStudents()) {
            auto horario = element.getStudentSchedule();

            // Iterate through the classes in each student's schedule
            for (auto aula : horario) {
                if (toLowerSTR(aula.getUcCode()) == toLowerSTR(inp) && toLowerSTR(aula.getClassCode()) == toLowerSTR(classe)) {
                    count++;
                    found = true;
                    break; // No need to continue searching
                }
            }
        }
    } else if (n == "2") {
        // Iterate through the list of students and their schedules
        for (auto element : data.getStudents()) {
            auto horario = element.getStudentSchedule();

            // Iterate through the classes in each student's schedule
            for (auto aula : horario) {
                if (toLowerSTR(aula.getUcCode()) == toLowerSTR(inp)) {
                    count++;
                    found = true;
                    break; // No need to continue searching
                }
            }
        }
    }

    if (!found) {
        cout << "UC not found.\n\n";
    } else {
        // Display the count of students enrolled in the specified UC
        cout << "The number of students enrolled in the UC " << inp << " is " << count << ".\n\n";
    }

    char what;

    // Ask the user for further action
    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        checkOccupationPer_5();
    } else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}



void Menu::checkBiggestUc_6() {
    // Clear the console screen
    system("clear");

    // Initialize variables to keep track of the biggest UC
    string t = data.getUCS()[0].getUcCode(); // Store the first UC code
    string m; // Store the biggest UC
    int count = 0;
    int max = 0;

    // Iterate through the list of classes
    for (auto aula : data.getUCS()) {
        if (aula.getUcCode() == t) {
            count++;
        } else {
            if (count > max) {
                m = aula.getUcCode();
                max = count;
            }
            count = 0;
            t = aula.getUcCode();
        }
    }

    // Display the biggest UC in the format "The biggest UC in L.EIC is {UC Code}."
    cout << "The biggest UC in L.EIC is " << m << ".\n\n" << endl;

    char what;

    // Ask the user for further action
    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;

    cin >> what;

    if (what == 'R' || what == 'r') {
        accessInfo_1();
    } else {
        cout << "Program will now exit" << endl;
        exit(0);
    }
}

//############################## FUNCTIONS CHANGE #################################//

void Menu::addStudent_1() {
    // Clear the console screen
    system("clear");

    // Display a menu for adding a student to a class or a UC
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|--[ Do you wish to add the student to ]--|\n"
         << "|----------[ a Class or a UC? ]-----------|\n"
         << "|-- 1: UC --------------------------------|\n"
         << "|-- 2: Class -----------------------------|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    // Prompt the user for their choice
    cout << endl << "Insert your desired option: " << endl;
    string inp;
    cin >> inp;
    int i = 0;

    // Handle user's choice for UC (1), Class (2), or going back to the menu
    if (inp == "1") { i = 1; }
    else if (inp == "2") { i = 2; }
    else if (inp == "B" || inp == "b") { start(); }
    else { cout << "|-- Invalid Input ------------------------|\n"; }

    // Prompt the user to insert the student's code
    cout << endl << "Insert student's code: " << endl;
    string studentcode;
    cin >> studentcode;

    string wtc;
    string ccode;
    string ucode;
    string change;
    int Cap = 30;
    bool afile;
    bool flag = false;

    Student Student1;

    // Find the Student object with the given student code
    for (auto element : data.getStudents()) {
        if (element.getStudentCode() == studentcode) {
            Student1 = element;
            flag = true;
            break;
        }
    }

    // If the student code is not found, inform the user and restart the process
    if (!flag) {
        cout << endl << "The student code is invalid. " << endl;
        addStudent_1();
    }

    int count;

    // Check if the student is already enrolled in 7 UCs, which is the maximum
    if (Student1.getStudentSchedule().size() == 7 && i == 1) {
        cout << "Student is already in 7 UC's.";
    } else if (i == 1) {
        // Prompt the user to insert the UC code to which the student should be added
        cout << endl << "Insert the UC code to which you want the student to be added: " << endl;
        cin >> ucode;

        for (auto cl : Student1.getStudentSchedule()) {
            if (cl.getUcCode() == ucode) {
                cout << "Student is already in this UC." << '\n';
                addStudent_1();
            }
        }

        bool flag = false;
        bool print = true;

        // Iterate through available classes and display the ones for the selected UC
        for (auto n : UCINSCH) {
            if (n.getUcCode() == ucode) {
                if (print) {
                    cout << "These are the classes of " << ucode << ":" << '\n';
                    print = false;
                }
                flag = true;
                cout << n.getClassCode() << '\n';
            }
        }

        // If the selected UC doesn't exist, inform the user
        if (!flag) {
            cout << "The UC you inserted does not exist" << endl;
        }

        // Prompt the user to insert the code of the class they wish to add
        cout << endl << "Insert the code of the class you wish to add: " << endl;
        cin >> ccode;

        // Checking if the class has reached its maximum occupancy
        vector<pair<Classes, int>> ocupation = checkocu();

        for (auto p : ocupation) {
            if (p.first.getUcCode() == ucode && p.first.getClassCode() == ccode && p.second == Cap) {
                cout << "This class is full, please choose another one." << '\n';
                addStudent_1();
            } else if (p.first.getUcCode() == ucode && p.first.getClassCode() == ccode) {
                p.second = p.second + 1;
            }
        }

        // Check if the overall balance of classes is exceeded
        if (balanceclasses(ocupation) == false) {
            cout << "This class is full, please choose another one." << '\n';
            addStudent_1();
        } else {
            afile = true;
        }
    }

    if (i == 2) {
        // Prompt the user to insert the class code to which the student should be added
        cout << endl << "Insert the class code in which you want the student to be added: ";
        cin >> ccode;
        cout << "These are the UCs of the " << ccode << ":" << '\n';

        for (auto n : UCINSCH) {
            if (n.getClassCode() == ccode) {
                cout << n.getUcCode() << '\n';
            }
        }
        // Prompt the user to insert the code of the UC they wish to be added
        cout << endl << "Insert the code of the UC you wish to be added: ";
        cin >> ucode;

        // Checking if the class has reached its maximum occupancy
        vector<pair<Classes, int>> ocupation = checkocu();

        for (auto p : ocupation) {
            if (p.first.getUcCode() == ucode && p.first.getClassCode() == ccode && p.second == Cap) {
                cout << "This class is full, please choose another one." << '\n';
                addStudent_1();
            } else if (p.first.getUcCode() == ucode && p.first.getClassCode() == ccode) {
                p.second = p.second + 1;
            }
        }

        // Check if the overall balance of classes is exceeded
        if (balanceclasses(ocupation) == false) {
            cout << "This class is full, please choose another one." << '\n';
            addStudent_1();
        } else {
            afile = true;
        }
    }

    // Adding the changes to the Student
    list<Classes> sch = Student1.getStudentSchedule();
    TimeType FoudTime;
    for (auto cl : UCINSCH) {
        if (cl.getUcCode() == ucode && cl.getClassCode() == ccode) {
            FoudTime = cl.getTimetable();
        }
    }

    // Create a new Classes object for the class to be added
    Classes newclass = Classes(ccode, ucode, FoudTime);

    // Checking if the new class overlaps with the student's existing schedule
    if (overlap(sch, newclass) == true) {
        cout << "You already have a TP or a PL class at the time of the class you want the student to be." << '\n'
             << "Please choose another one." << '\n';
        addStudent_1();
    } else {
        afile = true;
    }

    // Add the new class to the student's schedule
    sch.push_back(newclass);
    Student1.setLessons(sch);

    // Open the file for writing changes
    ofstream file("../Files/students_classes.csv", std::ios::app);

    if (file.is_open()) {
        if (i == 1) {
            // Create a line to be written to the file when adding to a UC
            string line = studentcode + "," + Student1.getName() + "," + ucode + "," + ccode;
            file << endl;
            file << line;

            // Create a change record and add it to the history
            change = "ADDED(+): The student " + Student1.getName() + " whose student code is " + Student1.getStudentCode()
                     + " was added to the UC " + ucode + " in " + ccode + " class.";
            addToHistory(change);
        }
        if (i == 2) {
            // Create a line to be written to the file when adding to a class
            string line = studentcode + "," + Student1.getName() + "," + ucode + "," + ccode;
            file << endl;
            file << line;

            // Create a change record and add it to the history
            change = "ADDED(+): The student " + Student1.getName() + " whose student code is " + Student1.getStudentCode()
                     + " was added to the class " + ccode + " at " + ucode + " UC.";
            addToHistory(change);
        }
    }

    // Close the file
    file.close();

    // Update data objects with the latest data from files
    data.setClasses(readClassesData());
    data.setStudents(readStudentsData());
}


vector<pair<Classes, int>> Menu::checkocu() {
    // Function to check the occupation of classes

    vector<pair<Classes, int>> ocupation;

    // Iterate through the available classes
    for (auto cl : UCSNCL) {
        pair<Classes, int> pair;
        pair.first = cl;
        int a = 0;

        // Iterate through all students' schedules to count how many are enrolled in the class
        for (auto stu : ALLSTUDENTS) {
            for (auto cl1 : stu.getStudentSchedule()) {
                if (cl1.getClassCode() == cl.getClassCode() && cl1.getUcCode() == cl.getUcCode()) {
                    a++;
                }
            }
        }

        pair.second = a;
        ocupation.push_back(pair);
    }

    return ocupation;
}

// Function to check if the class occupancy is balanced
bool Menu::balanceclasses(vector<pair<Classes, int>> original) {
    for (int l = 0; l < original.size(); l++) {
        for (int l1 = 0; l1 < original.size(); l1++) {
            int d = original[l].second - original[l1].second;

            // Check if the difference in occupancy is more than 4 or less than -4
            if (d > 4 || d < -4) {
                return false;
            }
        }
    }
    return true;
}

// Function to check if a class overlaps with the student's existing schedule
bool Menu::overlap(list<Classes> Sch, Classes clwantchange) {
    int TC = 0;
    int ov = 0;
    double CLstartHour, wtcstartHour;
    double CLduration, wtcduration;
    double CLendHour, wtcendHour;

    // Iterate through the student's existing classes
    for (auto cl : Sch) {
        TimeType Tcl = cl.getTimetable();
        TimeType Twtc = clwantchange.getTimetable();

        if (Tcl.getDay() == Twtc.getDay()) {
            CLstartHour = stod(Tcl.getStartHour());
            CLduration = stod(Tcl.getClassDuration());
            CLendHour = CLstartHour + CLduration;
            wtcstartHour = stod(Twtc.getStartHour());
            wtcduration = stod(Twtc.getClassDuration());
            wtcendHour = wtcstartHour + wtcduration;

            // Checking the types of the classes
            if (Tcl.getTypeOfClass() == "TP" && Twtc.getTypeOfClass() == "TP") {
                TC = 1;
            } else if ((Tcl.getTypeOfClass() == "TP" && Twtc.getTypeOfClass() == "PL") || (Tcl.getTypeOfClass() == "PL" && Twtc.getTypeOfClass() == "TP")) {
                TC = 1;
            } else if (Tcl.getTypeOfClass() == "PL" && Twtc.getTypeOfClass() == "PL") {
                TC = 1;
            } else {
                TC = 0;
            }

            // Checking if the classes overlap
            if (CLstartHour <= wtcstartHour && CLendHour >= wtcendHour) {
                ov = 1;
            } else if (CLstartHour < wtcstartHour && CLendHour < wtcendHour && wtcstartHour < CLendHour) {
                ov = 1;
            } else if (wtcstartHour < CLstartHour && CLstartHour < wtcendHour && CLendHour > wtcendHour) {
                ov = 1;
            }

            if (ov == 1 && TC == 1) {
                return true;
            }
        }
    }

    return false;
}




void Menu::removeStudent_2() {
    // Function to remove a student from a class or UC
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|--[ Do you wish to remove the student  ]-|\n"
         << "|--------[ from a Class or a UC? ]--------|\n"
         << "|-- 1: UC --------------------------------|\n"
         << "|-- 2: Class -----------------------------|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option: " << endl;
    string inp;
    char what;
    cin >> inp;
    int i = 0;
    // Interaction with the user to choose the removal option
    if (inp == "1") { i = 1; }
    else if (inp == "2") { i = 2; }
    else if (inp == "3" || inp == "B" || inp == "b") { start(); } // Option to go back to the main menu
    else { cout << "|-- Invalid Input ------------------------|\n"; }

    cout << endl << "Insert student's code: " << endl;
    string studentcode;
    cin >> studentcode;
    Student Student1;
    bool flag = false;

    // Check if the provided student code exists
    for (auto stu : ALLSTUDENTS){
        if (stu.getStudentCode() == studentcode){
            flag = true;
            Student1 = stu;
        }
    }
    if (!flag) {
        cout << "Invalid student code. " << endl;
        cout << "Insert 'R' to RETURN" << endl;
        cout << "Insert 'Q' to QUIT" << endl;

        cin >> what;

        if (what == 'R' || what == 'r') {
            removeStudent_2(); // Return to the student removal option
        }
        else {
            cout << "Program will now exit" << endl;
            exit(0); // Exit the program
        }
    }
    string ccode1;
    string change;
    string ucode1;
    list <Classes> sch;

    // If the user chose to remove the student from a UC
    if (i == 1){
        cout << endl << "Insert the UC code: " << endl;
        cin >> ucode1;
        bool flag = false;

        // Create a new schedule without the specified UC
        for (auto cl: Student1.getStudentSchedule()){
            if (cl.getUcCode() != ucode1){
                sch.push_back(cl);
            }
            else {
                flag = true; // UC found
            }
        }
        if (!flag) {
            cout << "Student is not enrolled in this UC. " << endl;
            cout << "Insert 'R' to RETURN" << endl;
            cout << "Insert 'Q' to QUIT" << endl;

            cin >> what;

            if (what == 'R' || what == 'r') {
                removeStudent_2(); // Return to the student removal option
            }
            else {
                cout << "Program will now exit" << endl;
                exit(0); // Exit the program
            }
        }

        int n;
        ifstream ifile("../Files/students_classes.csv");
        ofstream ofile("../Files/students_change.csv");
        string line;
        string word;
        vector<string> aux;
        if (ifile.is_open() and ofile.is_open()) {

            // Copy and modify the student's class information in the data file
            getline(ifile, line);
            ofile << line << '\n';
            while (getline(ifile, line)) {
                aux.clear();
                istringstream iss(line);
                while (getline(iss, word, ',')) {
                    aux.push_back(word);
                }
                string stuCode = aux[0];
                string ucode = aux[2];
                string ccode = aux[3];
                if (stuCode == Student1.getStudentCode() and ucode == ucode1) {n = 1;}

                else { ofile << aux[0] << "," << aux[1] << "," << aux[2] << "," << aux[3] << '\n'; }
            }
            ifile.close();
            ofile.close();
            remove("../Files/students_classes.csv");
            rename("../Files/students_change.csv", "../Files/students_classes.csv");

        } else { cout << "file not found"; }

        Student1.setLessons(sch);

        if (flag) {
            change = "REMOVED(-): The student " + Student1.getName() + " whose student code is " +
                     Student1.getStudentCode() + " was removed from " + ucode1 + " UC.";
        }

        addToHistory(change); // Add the removal action to the history
    }
        // If the user chose to remove the student from a class
    else if (i == 2){
        cout << endl << "Insert the class code: " << endl;
        cin >> ccode1;
        bool flag = false;

        // Create a new schedule without the specified class
        for(auto cl: Student1.getStudentSchedule()){
            if(cl.getClassCode()!=ccode1){
                sch.push_back(cl);
            }
            else {
                flag = true; // Class found
            }
        }
        if (!flag) {
            cout << "Student is not enrolled in this class. " << endl;
            cout << "Insert 'R' to RETURN" << endl;
            cout << "Insert 'Q' to QUIT" << endl;

            cin >> what;

            if (what == 'R' || what == 'r') {
                removeStudent_2(); // Return to the student removal option
            }
            else {
                cout << "Program will now exit" << endl;
                exit(0); // Exit the program
            }
        }

        int n;
        ifstream ifile("../Files/students_classes.csv");
        ofstream ofile("../Files/students_change.csv");
        string line;
        string word;
        vector<string> aux;
        if (ifile.is_open() and ofile.is_open()) {

            // Copy and modify the student's class information in the data file
            getline(ifile, line);
            ofile << line << '\n';
            while (getline(ifile, line)) {
                aux.clear();
                istringstream iss(line);
                while (getline(iss, word, ',')) {
                    aux.push_back(word);
                }
                string stuCode = aux[0];
                string ucode = aux[2];
                string ccode = aux[3];
                if (stuCode == Student1.getStudentCode() and ccode == ccode1) {n = 1;}

                else { ofile << aux[0] << "," << aux[1] << "," << aux[2] << "," << aux[3] << '\n'; }
            }
            ifile.close();
            ofile.close();
            remove("../Files/students_classes.csv");
            rename("../Files/students_change.csv", "../Files/students_classes.csv");

        } else { cout << "file not found"; }

        Student1.setLessons(sch);

        if (flag) {
            change = "REMOVED(-): The student " + Student1.getName() + " whose student code is " + Student1.getStudentCode()
                     + " was removed from " + ccode1 + " class.";
        }

        addToHistory(change); // Add the removal action to the history
    }
}


// Function to switch a student from one class/UC to another
void Menu::switchStudent_3() {
    // Display menu for choosing class or UC
    cout << "|--[ Request Change ]---------------------|\n"
         << "|-----------------------------------------|\n"
         << "|--[ Do you wish to switch the student ]--|\n"
         << "|------[ from a Class or a UC? ]----------|\n"
         << "|-- 1: UC --------------------------------|\n"
         << "|-- 2: Class -----------------------------|\n"
         << "|-- B: Go Back to Menu -------------------|\n"
         << "|-----------------------------------------|\n";

    cout << endl << "Insert your desired option: " << endl;
    string inp;
    cin >> inp;
    int i = 0;
    // Interaction: Choose between UC or Class
    if (inp == "1") { i = 1; }
    else if (inp == "2") { i = 2; }
    else if (inp == "3" || inp == "B" || inp == "b") { start(); } // Option to go back to the main menu
    else { cout << "|-- Invalid Input ------------------------|\n"; }

    // Find the student based on their student code
    cout << "Insert the student code: " << endl;
    string studentcode;
    cin >> studentcode;
    Student Student1;
    for (auto stu : ALLSTUDENTS) {
        if (stu.getStudentCode() == studentcode) {
            Student1 = stu;
        }
    }

    bool afile;
    int Cap = 30;
    string change;
    string uccode1;
    string uccode2;
    string ccode1;
    string ccode2;
    string ccbefore;
    string wtc;

    if (i == 1) {
        // Switching within UCs
        cout << "What is the student's current UC code that you wish to change? " << endl;
        cin >> uccode1;
        cout << "What is the UC code you want the student to join? " << endl;
        cin >> uccode2;
        cout << "These are the classes of " << uccode2 << ":" << '\n';
        for (auto n : UCINSCH) {
            if (n.getUcCode() == uccode2) {
                cout << n.getClassCode() << '\n';
            }
        }

        cout << endl << "Insert the code of the class you wish to change: " << endl;
        cin >> wtc;

        for (auto cl : Student1.getStudentSchedule()) {
            if (uccode1 == cl.getUcCode()) { ccbefore = cl.getClassCode(); }
        }
    } else {
        // Switching within classes
        cout << "What is the student's current class code that you wish to change? " << endl;
        cin >> ccbefore;
        cout << "What is the UC code of that class? " << endl;
        cin >> uccode1;
        cout << "These are the classes of " << uccode1 << '\n';
        for (auto n : UCINSCH) {
            if (n.getUcCode() == uccode1) {
                cout << n.getClassCode() << '\n';
            }
        }
        cout << endl << "Insert the code of the class you wish to change: " << endl;
        cin >> wtc;
        uccode2 = uccode1;
    }

    // Check class occupation
    vector<pair<Classes, int>> ocupation = checkocu();
    for (auto p : ocupation) {
        if (p.first.getUcCode() == uccode2 && p.first.getClassCode() == wtc && p.second == Cap) {
            cout << "This class is full, please choose another one." << '\n';
            addStudent_1();
        } else if (p.first.getUcCode() == uccode2 && p.first.getClassCode() == wtc) {
            p.second = p.second + 1;
        } else if (p.first.getUcCode() == uccode1 && p.first.getClassCode() == ccbefore) {
            p.second = p.second - 1;
        }
    }

    // Check if class switching results in class overlap
    if (!balanceclasses(ocupation)) {
        cout << "This class is full, please choose another one." << '\n';
        addStudent_1();
    } else {
        afile = true;
    }

    // Prepare the new schedule and check for overlaps
    list<Classes> sch = Student1.getStudentSchedule();
    TimeType FoudTimebefore;
    TimeType FoundTimeafter;
    Classes oldclass;
    auto it = sch.begin();

    while (it != sch.end()) {
        auto &cl = *it;

        if (cl.getUcCode() == uccode1 && cl.getClassCode() == ccbefore) {
            oldclass = cl;
            FoudTimebefore = cl.getTimetable();
            it = sch.erase(it);
        } else if (cl.getUcCode() == uccode2 && cl.getClassCode() == wtc) {
            FoundTimeafter = cl.getTimetable();
            ++it;
        } else {
            ++it;
        }
    }

    Classes newclass = Classes(wtc, uccode2, FoundTimeafter);

    // Check for class overlaps
    if (overlap(sch, newclass)) {
        cout << "You already have a TP or a PL class at the time of the class you want the student to be." << '\n'
             << "Please choose another one." << '\n';
        addStudent_1();
    } else {
        afile = true;
    }

    sch.push_back(newclass);
    Student1.setLessons(sch);

    // Update the class information in the data file and add to history
    int n;
    ifstream ifile("../Files/students_classes.csv");
    ofstream ofile("../Files/students_change.csv");
    string line;
    string word;
    vector<string> aux;
    if (ifile.is_open() and ofile.is_open()) {
        getline(ifile, line);
        ofile << line << '\n';
        while (getline(ifile, line)) {
            aux.clear();
            istringstream iss(line);
            while (getline(iss, word, ',')) {
                aux.push_back(word);
            }
            string stuCode = aux[0];
            string ucode = aux[2];
            string ccode = aux[3];

            if (stuCode == Student1.getStudentCode() && ccode == oldclass.getClassCode() && ucode == oldclass.getUcCode()) {
                n = 1;
            } else {
                ofile << aux[0] << "," << aux[1] << "," << aux[2] << "," << aux[3] << '\n';
            }
        }

        change = "SWITCH(<->): The student " + Student1.getName() + " whose student code is " + Student1.getStudentCode()
                 + " is now enrolled in " + uccode2 + " in class " + wtc + ".";
        addToHistory(change);

        ofile << Student1.getStudentCode() << "," << Student1.getName() << "," << uccode2 << "," << wtc;
        ifile.close();
        ofile.close();
        remove("../Files/students_classes.csv");
        rename("../Files/students_change.csv", "../Files/students_classes.csv");
        data.setClasses(readClassesData());
        data.setStudents(readStudentsData());
    } else {
        cout << "file not found";
    }
}
// Function to add a change to the history file
void Menu::addToHistory(const string &change) {
    ofstream out("../Files/history.txt", ios::app);  // Open the history file for appending
    if (out.is_open()) {
        out << change << endl;  // Write the change to the history file
    }
    // Note: If the file cannot be opened, it will silently fail without any error handling.
}

// Function to display the history from the history file
void Menu::showHistory() {
    cout << endl;
    ifstream hist("../Files/history.txt");  // Open the history file for reading
    string line;
    if (hist.is_open()) {
        while (getline(hist, line)) {
            cout << line << endl;  // Display each line of the history file
        }
    }
    hist.close();  // Close the history file

    char what;
    cout << "Insert 'R' to RETURN" << endl;
    cout << "Insert 'Q' to QUIT" << endl;
    cin >> what;

    if (what == 'R' || what == 'r') {
        start();  // Return to the main menu if 'R' is entered
    } else {
        cout << "Program will now exit" << endl;  // Exit the program if 'Q' or any other input is entered
        exit(0);
    }
}

