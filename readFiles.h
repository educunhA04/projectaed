#ifndef PROJETO_READFILES_H
#define PROJETO_READFILES_H
#include <vector>
#include <set>
#include <string>
#include "Classes.h"
#include "Student.h"
#include "UC.h"

using namespace std;

vector<Classes> readClassesData();
set<Student> readStudentsData();
set<UC> readucperclass();

#endif //PROJETO_READFILES_H
