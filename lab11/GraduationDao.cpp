//
// Created by balaz on 2023. 12. 06..
//

#include "GraduationDao.h"

void GraduationDao::enrollStudents(const string &filename) {
    ifstream f(filename);
    if(!f){
        throw out_of_range("Error when opening file.");
    }
    string line;
    while(getline(f, line)){
        stringstream ss(line);
        int id;
        string firstName, lastName;
        ss >> id >> firstName >> lastName;
        students.emplace(id, Student(id, firstName, lastName));
    }
}

void GraduationDao::saveGradesForSubject(const string &subject, const string &filename) {
    ifstream f(filename);
    if(!f){
        throw out_of_range("Error when opening file.");
    }
    string line;
    while(getline(f, line)){
        stringstream ss(line);
        int id;
        double jegy;
        try{
            ss >> id >> jegy;
            students.at(id).addGrade(subject, jegy);
        }catch(exception &e){
            cout << e.what() << endl;
        }
    }
}

void GraduationDao::computeAverage() {
    for(auto &[id, student] : students){
        student.computeAverage();
    }
}

int GraduationDao::numEnrolled() const {
    return students.size();
}

int GraduationDao::numPassed() const {
    int passed = numEnrolled();
    for(auto[id, student] : students){
        if(student.getAverage() < 6){
            passed--;
        }
    }
    return passed;
}

Student GraduationDao::findById(int id) const {
    return students.at(id);
}

double GraduationDao::getAverageBySubject(const string &subject) const {
    double avg = 0;
    for(auto[id, student] : students){
        avg += student.getGrade(subject);
    }
    return avg/students.size();
}

const map<int, Student> &GraduationDao::getStudents() const {
    return students;
}

