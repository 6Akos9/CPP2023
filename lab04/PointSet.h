//
// Created by balaz on 2023. 10. 18..
//

#ifndef CPP_2022_POINTSET_H
#define CPP_2022_POINTSET_H
#include "Point.h"
#include <vector>
using namespace std;


class PointSet {
    vector<Point> points;
    int n;
    vector<double> distances;
    void computeDistances();
public:
    PointSet( int n = 100 );
    double maxDistance() const;
    double minDistance() const;
    int numDistances() const;
    void printPoints() const;
    void printDistances() const;
    void sortPointsX();
    void sortPointsY();
    void sortDistances();
    int numDistinctDistances();
};


#endif //CPP_2022_POINTSET_H
