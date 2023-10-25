//
// Created by balaz on 2023. 10. 25..
//

#ifndef CPP_2022_QUIZ_H
#define CPP_2022_QUIZ_H

#include <string>
#include "Question.h"

using namespace std;

class Quiz {
private:
    const string name;
    vector<Question> questions;
public:
    Quiz(const string &name, const vector<Question> &questions);
    explicit Quiz(const string &name);
    const string &getName() const;
    vector<Question> &getQuestions();
    void readFromFile(const string& filename);
};


#endif //CPP_2022_QUIZ_H
