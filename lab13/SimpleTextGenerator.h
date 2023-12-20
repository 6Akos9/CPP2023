//
// Created by balaz on 2023. 12. 20..
//

#ifndef CPP_2022_SIMPLETEXTGENERATOR_H
#define CPP_2022_SIMPLETEXTGENERATOR_H
#include <vector>
#include <map>
#include "TextGenerator.h"

class SimpleTextGenerator: public TextGenerator {
    map<string, vector<string>> data;
public:
    virtual void trainFromText(string trainingText) override;
    virtual void trainFromFile(string filename) override;
    virtual string generate(string startWords, int numWords=6) override;
    void printData() const;
};



#endif //CPP_2022_SIMPLETEXTGENERATOR_H
