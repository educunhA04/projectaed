#ifndef PROJETO_MENU_H
#define PROJETO_MENU_H

#include "Schedule.h"

class Menu{
    private:
        Schedule sched;

    public:
        Menu();
        void start();
        void setSched(const Schedule& newSched){
            this->sched = newSched;
        }

        // 1st Part of the Menu //
        void accessInfo_1();
        void requestChange_2();

        // 2nd Part -> accessInfo //
        void showStudentSchedule_1();
        void showStudentsPer_2();
        void showStudentsInAtLeastNUCs_3();

        void showClassSchedule_4();
        void checkOccupationPer_5();
        void checkBiggestUc_6(); // TODO

        // 3rd Part -> requestChange //
        void addStudent_1(); // TODO
        void removeStudent_2(); // TODO
        void switchStudent_3(); // TODO

        // 4th Part -> accessInfo -> showStudentsPer
        void showStudentsPerYear_1(); // TODO
        void showStudentsPerClass_2(); // TODO
        void showStudentsPerUC_3(); // TODO

        // 5th Part -> accessInfo -> checkOccupationPer
        void checkOccupationPerYear_1(); // TODO
        void checkOccupationPerClass_2();
        void checkOccupationPerUC_3();
};

#endif //PROJETO_MENU_H