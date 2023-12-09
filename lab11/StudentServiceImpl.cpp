//
// Created by balaz on 2023. 12. 06..
//

#include "StudentServiceImpl.h"

bool StudentServiceImpl::isEnrolled(int id) const {
    return this->dao->getStudents().contains(id);
}

vector<string> StudentServiceImpl::getSubjects(int id) const {
    auto grades = this->dao->findById(id).getGrades();
    vector <string> subjects;
    for(auto[key, value] : grades){
        subjects.push_back(key);
    }
    return subjects;
}

double StudentServiceImpl::getResultBySubject(int id, const string &subject) const {
    return this->dao->findById(id).getGrade(subject);
}

double StudentServiceImpl::getAverage(int id) const {
    return this->dao->findById(id).getAverage();
}
