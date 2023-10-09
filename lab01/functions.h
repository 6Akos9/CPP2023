//
// Created by balaz on 2023. 10. 09..
//

#ifndef CPP_2022_FUNCTIONS_H
#define CPP_2022_FUNCTIONS_H

#include <utility>

//using namespace std;

int countBit(int number);
bool setBit(int& number, int order);
double mean(double array[], int numElements);
double stddev(double array[], int numElements);
std::pair<double, double> max2(double array[], int numElements);


#endif //CPP_2022_FUNCTIONS_H
