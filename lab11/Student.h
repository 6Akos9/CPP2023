//
// Created by balaz on 2023. 12. 06..
//

#ifndef CPP_2022_STUDENT_H
#define CPP_2022_STUDENT_H
#include <iostream>
#include <string>
#include <map>
using namespace std;

class Student {
private:
    int id;
    string firstName;
    string lastName;
    map<string, double> grades;
    double average {0.0};
public:
    Student(int id, const string &firstName, const string &lastName);
    int getId() const;
    void setId(int id);
    const string &getFirstName()const;
    const string &getLastName() const;
    void addGrade(const string& subject, double grade);
    double getGrade(const string& subject);
    const map<string, double> &getGrades() const;
    void computeAverage();
    double getAverage() const;
    friend ostream& operator<<(ostream& os, const Student& student);
};


#endif //CPP_2022_STUDENT_H
