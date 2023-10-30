//
// Created by magui on 29-10-2023.
//

#ifndef UNTITLED_UC_H
#define UNTITLED_UC_H
#include <vector>
#include <set>
#include <string>

#include "Student.h"
#include "Classes.h"

using namespace std;

class UC{
    //AllData retains all the uc's, students and schedule of a class in specific
private:
    string uccode;
    set<string> ccodes;

public:
    UC(){}
    UC( string newuccode, const set<string> ccodes){
        this->uccode = newuccode;
        this->ccodes = ccodes;
    }

    string getUC() const {return uccode;}
    set<string> getclassesofuc() const {return ccodes;}


    void setClasses(string newccode){
        ccodes.insert(newccode);
    }
    bool operator<(const UC other) const{
        if(uccode<other.getUC()){return true;}
        return false;
    }
};
#endif //UNTITLED_UC_H
