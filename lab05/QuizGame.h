//
// Created by balaz on 2023. 10. 25..
//

#ifndef CPP_2022_QUIZGAME_H
#define CPP_2022_QUIZGAME_H


#include "Quiz.h"

class QuizGame {
private:
    Quiz quiz;
public:
    explicit QuizGame(string quizName, string fileName);
    void startGame();

    int rightAnswers;
};


#endif //CPP_2022_QUIZGAME_H
