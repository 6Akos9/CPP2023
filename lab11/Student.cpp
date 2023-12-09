//
// Created by balaz on 2023. 12. 06..
//

#include "Student.h"

Student::Student(int id, const string &firstName, const string &lastName) : id(id), firstName(firstName),
lastName(lastName){}

int Student::getId() const {
    return id;
}

void Student::setId(int id) {
    this->id = id;
}

const string &Student::getFirstName() const {
    return this->firstName;
}

const string &Student::getLastName() const {
    return this->lastName;
}

void Student::addGrade(const string &subject, double grade) {
    grades[subject] = grade;
}

double Student::getGrade(const string &subject) {
//    auto it = grades.find(subject);
//    if(it == grades.end())
//        throw out_of_range("Nincs ilyen tantargy.");
//    return it->second;
    return grades.at(subject);
}

const map<string, double> &Student::getGrades() const {
    return grades;
}

void Student::computeAverage() {
    this->average = 0.0;
    double average = 0;
    for (auto[key, value] : grades) {
        if(value < 5){
            return;
        }
        average += value;
    }
    this->average = average/grades.size();
}

double Student::getAverage() const {
    return this->average;
}

ostream &operator<<(ostream &os, const Student &student) {
    os << student.getFirstName() << " " << student.getLastName() << " ";
    for(auto[key, value] : student.grades){
        os << key << ": " << value << '\t';
    }
    return os;
}
