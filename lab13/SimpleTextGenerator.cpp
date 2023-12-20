//
// Created by balaz on 2023. 12. 20..
//

#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <random>
#include "SimpleTextGenerator.h"

//Now is not the time for sleep, now is the time for party!
void SimpleTextGenerator::trainFromText(string trainingText) {
    string word1, word2, word3;
    for(char &c : trainingText){
        c = tolower(c);
        if(c < 'a' || c > 'z'){
            c = ' ';
        }
    }
    stringstream ss(trainingText);
    ss >> word1 >> word2;
    while(ss >> word3){
        string key = word1 + " " + word2;
        if(!data.contains(key)){
            data.insert(pair(key, vector<string>()));
        }
        vector<string> &words = data.at(key);
        if(std::find(words.begin(), words.end(), word3) == words.end()){
            words.push_back(word3);
        }
        word1 = word2;
        word2 = word3;
    }
    string key = word1 + " " + word2;
    if(!data.contains(key)){
        data.insert(pair(key, vector<string>()));
    }
}

void SimpleTextGenerator::printData() const {
    for(auto [key, words] : data){
        cout << key << "{";
        for(auto const &word : words){
            cout << word << ", ";
        }
        cout << "}" << endl;
    }
}

void SimpleTextGenerator::trainFromFile(string filename) {
    ifstream file(filename);
    if(!file){
        cout << "File not found" << endl;
    }
    string line;
    while(getline(file, line)){
        trainFromText(line);
    }
}

string SimpleTextGenerator::generate(string startWords, int numWords) {
    string word1, word2, word3;
    stringstream ss(startWords);
    ss >> word1 >> word2;

    random_device rd;
    mt19937 mt(rd());

    for (int i = 0; i < numWords; ++i) {
        string key = word1 + " " + word2;
        if(!data.contains(key)){
            break;
        }
        const vector<string> words = data.at(key);
        if(words.empty()){
            break;
        }
        uniform_int_distribution<int> dist(0, words.size() - 1);
        word3 = words[dist(mt)];
        startWords.append(" ").append(word3);
        word1 = word2;
        word2 = word3;
    }
    return startWords;
}
