//
// Created by balaz on 2023. 10. 25..
//

#include "Question.h"

Question::Question(const string &text, const vector<Answer> &answers) : text(text), answers(answers) {}

Question::Question(const string &text) : text(text) {}

const string &Question::getText() const {
    return text;
}

vector<Answer> &Question::getAnswers(){
    return answers;
}
