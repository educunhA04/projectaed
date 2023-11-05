#ifndef PROJETO_ALLDATA_H
#define PROJETO_ALLDATA_H

#include <vector>
#include <set>
#include <string>

#include "Student.h"
#include "Classes.h"

/**
 * @class AllData
 * @brief Retains all the UCs, students, and schedule of a class.
 */
class AllData {
private:
    vector<Classes> ucInSchedule; ///< Vector of Classes representing the schedule.
    set<Student> students; ///< Set of Students.

public:
    /**
     * @brief Default constructor for the AllData class.
     */
    AllData() { students = {}; }

    /**
     * @brief Parameterized constructor for the AllData class.
     * @param newUcInSchedule Vector of Classes representing the schedule.
     * @param newStudents Set of Students.
     */
    AllData(const vector<Classes>& newUcInSchedule, const set<Student>& newStudents) {
        this->ucInSchedule = newUcInSchedule;
        this->students = newStudents;
    }

    /**
     * @brief Getter function to retrieve the vector of Classes representing the schedule.
     * @return Vector of Classes.
     */
    vector<Classes> getUCS() const { return ucInSchedule; }

    /**
     * @brief Getter function to retrieve the set of Students.
     * @return Set of Students.
     */
    set<Student> getStudents() const { return students; }

    /**
     * @brief Setter function to update the set of Students.
     * @param newStudents New set of Students.
     */
    void setStudents(const set<Student>& newStudents) {
        this->students = newStudents;
    }

    /**
     * @brief Setter function to update the vector of Classes representing the schedule.
     * @param newClasses New vector of Classes.
     */
    void setClasses(const vector<Classes>& newClasses) {
        this->ucInSchedule = newClasses;
    }
};

#endif // PROJETO_ALLDATA_H
