#ifndef PROJETO_MENU_H
#define PROJETO_MENU_H

#include "AllData.h"
#include <iostream>
#include <set>
#include <string>
#include <stack>

/**
    * @class Menu
    * @brief Retains all Menus used in this program and the functions used inside these menus;
    */

using namespace std;

class Menu{
    private:
        AllData data;
        std::stack<std::string> changeHistory;

public:
        Menu();
        void start();
        void setData(const AllData& newData){
            this->data = newData;
        }

        /// 1st Part of the Menu //
        void accessInfo_1();
        void requestChange_2();

        /// 2nd Part -> accessInfo //
        void showStudentSchedule_1();
        void showStudentsPer_2();
        void showStudentsInAtLeastNUCs_3();

        void showClassSchedule_4();
        void checkOccupationPer_5();
        void checkBiggestUc_6();

        /// 3rd Part -> requestChange //
        void addStudent_1();
        ///Helper functions of the ADDREQUEST//
        vector<pair<Classes,int>> checkocu();
        bool balanceclasses(vector <pair<Classes,int>> original);
        bool overlap(list<Classes> Sch, Classes clwantchange);

        void removeStudent_2();
        void switchStudent_3();

        void showHistory();

        /// 4th Part -> accessInfo -> showStudentsPer
        void showStudentsPerYear_1();
        void showStudentsPerClass_2();
        void showStudentsPerUC_3();

        /// 5th Part -> accessInfo -> checkOccupationPer
        void checkOccupationPerYear_1();
        void checkOccupationPerClass_2();
        void checkOccupationPerUC_3();

    void addToHistory(const string &change);
};

#endif //PROJETO_MENU_H