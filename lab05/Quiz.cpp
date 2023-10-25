//
// Created by balaz on 2023. 10. 25..
//

#include <fstream>
#include <sstream>
#include "Quiz.h"

Quiz::Quiz(const string &name, const vector<Question> &questions) : name(name), questions(questions) {}

Quiz::Quiz(const string &name) : name(name) {}

const string &Quiz::getName() const {
    return name;
}

vector<Question> &Quiz::getQuestions(){
    return questions;
}

void Quiz::readFromFile(const string& filename) {
    ifstream file (filename);
    string line;
    if(!file){
        throw runtime_error("Could not open file");
    }
    while(getline(file, line)){
        if (line[0] == 'Q' && line[1] == ' '){
            questions.emplace_back(line.substr(2));
        }
        if(line[0] == 'A' && line[1] == ' '){
            questions.back().getAnswers().emplace_back(line.substr(2));
            continue;
        }
        stringstream s(line);
        while(1){
            int n;
            s >> n;
            if(!s){
                break;
            }
            questions.back().getAnswers()[n-1].setCorrect(true);
        }
    }
}
