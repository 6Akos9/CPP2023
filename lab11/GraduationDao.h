//
// Created by balaz on 2023. 12. 06..
//

#ifndef CPP_2022_GRADUATIONDAO_H
#define CPP_2022_GRADUATIONDAO_H
#include "Student.h"
#include <fstream>
#include <sstream>

class GraduationDao {
    int year{2023};
    map<int, Student> students;
public:
    explicit GraduationDao(int year) : year(year) {}
    void enrollStudents(const string &filename);
    void saveGradesForSubject(const string &subject, const string &filename);
    void computeAverage();
    int numEnrolled() const;
    int numPassed() const;
    Student findById(int id) const;
    double getAverageBySubject(const string &subject) const;
    //friend class StudentServiceImpl;
    const map<int, Student> &getStudents()const;
};


#endif //CPP_2022_GRADUATIONDAO_H
