#include <iostream>
#include "SimpleTextGenerator.h"

int main() {
    SimpleTextGenerator generator;
    //generator.trainFromText("Now is not the time for sleep, now is the time for party!");
    generator.trainFromFile("bible.txt");
    //generator.printData();
    for (int i = 0; i < 100; ++i) {
        cout << generator.generate("god said") << endl;
    }
    return 0;
}