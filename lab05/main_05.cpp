#include <iostream>
#include "Quiz.h"
#include "QuizGame.h"

int main() {
    Quiz quiz("labor5 quiz");
    /*quiz.readFromFile("lab05/quiz.txt");
    for (Question q : quiz.getQuestions()) {
        cout << q.getText() << endl;
        for (const Answer& a: q.getAnswers()) {
            cout << "\t" << a.getText() << endl;
        }
    }*/

    QuizGame game("labor5 quiz", "lab05/quiz.txt");
    game.startGame();
    return 0;
}