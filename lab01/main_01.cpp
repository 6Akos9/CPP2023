#include <iostream>
#include "functions.h"

int main() {
    std::cout << "Hello, Lab_01" << std::endl;
    for (int i = 0; i < 128; ++i) {
        std::cout << "n: " << i << " count: " << countBit(i) << std::endl;
    }
    for (int i = 0; i < 35; ++i) {
        int n = 0;
        if(setBit(n, i)){
            std::cout<<i<<" ---> " << n << std::endl;
        }else{
            std::cout<<"Impossible operation!" << std::endl;
        }
    }
    double array[] = {1, 2, 3, 4, 5};
    std::cout << "Mean: " << mean(array, 5) << std::endl;
    std::cout << "Stddev: " << stddev(array, 5) << std::endl;
    if(max2(array, 5).first < max2(array, 5).second){
        std::cout << "Max2: " << max2(array, 5).first << " " << max2(array, 5).second << std::endl;
    }
    else {
        std::cout << "Max2: " << max2(array, 5).second << " " << max2(array, 5).first << std::endl;
    }
    return 0;
}