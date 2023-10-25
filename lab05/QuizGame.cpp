//
// Created by balaz on 2023. 10. 25..
//

#include <random>
#include <iostream>
#include "QuizGame.h"

QuizGame::QuizGame(string quizName, string fileName) : quiz(quizName){
    quiz.readFromFile(fileName);
}

void QuizGame::startGame() {
    int n = quiz.getQuestions().size();
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, n);
    vector<int> order;
    for (int i = 0; i < n; ++i) {
        order.push_back(i);
    }

    auto first = order.begin();
    auto last = order.end();

    for (auto i=(last-first)-1; i>0; --i) {
        swap (first[i], first[dist(mt)]);
    }
    //for (int i = 0; i < order.size(); ++i) {
     //   cout << i << "-->" << order[i] << endl;
   // }
    rightAnswers - 0;
    for (int i = 0; i < order.size(); ++i) {
        Question q = quiz.getQuestions()[order[i]];
        cout << q.getText() << endl;
        for (const Answer &a: q.getAnswers()) {
            cout << "\t" << a.getText() << endl;
        }
        cout << "Adja meg a helyes valaszt : ";
        int n;
        cin >> n;
        if(q.getAnswers()[n].isCorrect()){
            rightAnswers++;
        }
    }
    cout << endl << "Helyes valaszok szama: " << rightAnswers;
}
