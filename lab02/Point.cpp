//
// Created by balaz on 2023. 10. 04..
//


#include "Point.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <random>

using namespace std;

Point::Point(int x, int y) {
    if (x >= 0 && x <= 2000 && y >= 0 && y <= 2000){
        this->x = x;
        this->y = y;
    }
    else{
        this->x = 0;
        this->y = 0;
    }
}
int Point::getX() const {
    return x;
}
int Point::getY() const {
    return y;
}

void Point::print() const {
    cout << "(" << x << "," << y << ")" << endl;
}

double distance(const Point &a, const Point &b) {
    double dx = a.getX() - b.getX();
    double dy = a.getY() - b.getY();
    return sqrt(dx * dx + dy * dy);
}

bool isSquare(const Point &a, const Point &b, const Point &c, const Point &d) {
    double D[6] = {distance(a, b), distance(a, c), distance(a, d), distance(b, c), distance(b, d), distance(c, d)};
    sort(D, D + 6);
    return (D[0] == D[3] && D[4] == D[5] && D[3] < D[4]);
}

void testIsSquare(const char *filename) {
    ifstream f(filename);
    if (!f){
        cout << "File not found" << endl;
        return;
    }
    string line;
    while (getline(f, line)){
        stringstream s(line);
        int x,y;
        s >> x >> y;
        Point a(x, y);
        s >> x >> y;
        Point b(x, y);
        s >> x >> y;
        Point c(x, y);
        s >> x >> y;
        Point d(x, y);
        if (isSquare(a, b, c, d)){
            cout << "Yes    " << line << endl;
        }
        else{
            cout << "No    " << line << endl;
        }
    }
}

Point *createArray(int numPoints) {
    random_device r;
    default_random_engine e1(r());
    uniform_int_distribution<int> uniform_dist(0, 2001);
    Point *points = new Point[numPoints];
    for (int i = 0; i < numPoints; i++){
        int x = uniform_dist(e1);
        int y = uniform_dist(e1);
        points[i] = Point(x, y);
    }
    return points;
}

void printArray(Point *points, int numPoints) {
    for (int i = 0; i < numPoints; i++){
        points[i].print();
    }
}

std::pair<Point, Point> closestPoints(Point *points, int numPoints) {
    int a = 0, b = 1;
    for (int i = 0; i < numPoints; i++){
        for (int j = i + 1; j < numPoints; j++){
            if (distance(points[i], points[j]) < distance(points[a], points[b])){
                a = i;
                b = j;
            }
        }
    }
    return std::make_pair(points[a], points[b]);
}

std::pair<Point, Point> farthestPoints(Point *points, int numPoints) {
    int a = 0, b = 1;
    for (int i = 0; i < numPoints; i++){
        for (int j = i + 1; j < numPoints; j++){
            if (distance(points[i], points[j]) > distance(points[a], points[b])){
                a = i;
                b = j;
            }
        }
    }
    return std::make_pair(points[a], points[b]);
}

void sortPoints(Point *points, int numPoints) {
    sort(points, points + numPoints, [](const Point &a, const Point &b){
        return a.getX() < b.getX();
    });
}

Point *farthestPointsFromOrigin(Point *points, int numPoints) {
    if (numPoints < 10){
        throw runtime_error("Not enough points");
    }
    Point *T = new Point[10];
    for (int i = 0; i < 10; i++){
        T[i] = points[i];
    }
    for (int i = 10; i < numPoints; ++i) {
        auto min = min_element(T, T + 10, [](const Point &a, const Point &b){
            return distance(a, Point()) < distance(b, Point());
        });
        if (distance(*min,Point()) < distance(points[i], Point())){
            *min = points[i];
        }
    }
    return T;
}


