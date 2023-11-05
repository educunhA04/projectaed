#ifndef PROJETO_READFILES_H
#define PROJETO_READFILES_H

#include <vector>
#include <set>
#include <string>
#include "Classes.h"
#include "Student.h"

/**
 * @file
 * @brief Header file for reading data from files.
 */

using namespace std;

/**
 * @brief Reads data for classes from a file.
 *
 * This function reads data for classes from a file and returns a vector of Classes objects.
 *
 * @return A vector of Classes objects containing the class data.
 */
vector<Classes> readClassesData();

/**
 * @brief Reads data for students from a file.
 *
 * This function reads data for students from a file and returns a set of Student objects.
 *
 * @return A set of Student objects containing the student data.
 */
set<Student> readStudentsData();

/**
 * @brief Reads data for classes and their corresponding students from a file.
 *
 * This function reads data for classes and their corresponding students from a file
 * and returns a set of Classes objects.
 *
 * @return A set of Classes objects containing class data with associated students.
 */
set<Classes> readucperclass();

#endif // PROJETO_READFILES_H
