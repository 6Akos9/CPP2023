//
// Created by balaz on 2023. 10. 18..
//

#include <random>
#include <algorithm>
#include <iostream>
#include "PointSet.h"

PointSet::PointSet(int n) {
    random_device rd;
    mt19937 mt(rd());
    uniform_int_distribution<int> dist(0, M);
    this->n = n;
    while(points.size() < n) {
        int x = dist(mt);
        int y = dist(mt);
        bool talalt = false;
        for(Point p : points){
            if(p.getX() == x && p.getY() == y){
                talalt = true;
                break;
            }
        }
        if(!talalt){
            points.emplace_back(x, y);
        }
    }
    computeDistances();
}

void PointSet::computeDistances() {
    for (int i = 0; i < points.size(); i++) {
        for (int j = i + 1; j < points.size(); j++) {
            distances.push_back(points[i].distanceTo(points[j]));
        }
    }
}

double PointSet::maxDistance() const {
    return *max_element(distances.begin(), distances.end());
}

double PointSet::minDistance() const {
    return *min_element(distances.begin(), distances.end());
}

int PointSet::numDistances() const {
    return distances.size();
}

void PointSet::printPoints() const {
    cout << "Points: " << endl;
    for (const Point &p : points) {
        cout << p.getX() << ", " << p.getY() << endl;
    }
}

void PointSet::printDistances() const {
    cout << "Distances: " << endl;
    for (const double &d : distances) {
        cout << d << endl;
    }
}

bool lessX(Point a, Point b){
    return a.getX() < b.getX();
}

bool lessY(Point a, Point b){
    return a.getY() < b.getY();
}

void PointSet::sortPointsX() {
    sort(points.begin(), points.end(), lessX);
}

void PointSet::sortPointsY() {
    sort(points.begin(), points.end(), lessY);
}

void PointSet::sortDistances() {
    sort(distances.begin(), distances.end());
}

int PointSet::numDistinctDistances() {
    vector<double> distances = this->distances;
    sort(distances.begin(), distances.end());
    auto uni = std::unique(distances.begin(), distances.end());
    return uni - distances.begin();
}




