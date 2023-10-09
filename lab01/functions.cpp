//
// Created by balaz on 2023. 10. 09..
//

#include "functions.h"
#include <cmath>

int countBit(int number) {
    int count = 0;
    while (number > 0) {
        count += number & 1;
        number >>= 1;
    }
    return count;
}

bool setBit(int& number, int order) {
    if (order < 0 || order > 31) {
        return false;
    }
    number |= 1 << order;
    return true;
}

double mean(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double sum = 0;
    for (int i = 0; i < numElements; ++i) {
        sum += array[i];
    }
    return sum / numElements;
}

double stddev(double array[], int numElements) {
    if (numElements == 0) {
        return NAN;
    }
    double sum = 0;
    for (int i = 0; i < numElements; ++i) {
        sum += pow(array[i] - mean(array, numElements), 2);
    }
    return sqrt(sum / numElements);
}

std::pair<double, double> max2(double *array, int numElements) {
    if (numElements == 0) {
        return std::make_pair(NAN, NAN);
    }
    if (numElements == 1) {
        return std::make_pair(array[0], array[0]);
    }
    double max1 = array[0];
    double max2 = array[1];
    for (int i = 1; i < numElements; ++i) {
        if (array[i] > max1) {
            max2 = max1;
            max1 = array[i];
        } else if (array[i] > max2) {
            max2 = array[i];
        }
    }
    return std::make_pair(max1, max2);
}
