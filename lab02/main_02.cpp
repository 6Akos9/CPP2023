#include <iostream>
#include "Point.h"

using namespace std;

int main(int argc, char** argv) {
    /*Point p1(2,3);
    cout<<"p1( "<<p1.getX()<<","<<p1.getY()<<")"<<endl;
    Point p2(100, 200);
    cout<<"p2( "<<p2.getX()<<","<<p2.getY()<<")"<<endl;
    Point * pp1 = new Point(300, 400);
    Point * pp2 = new Point(500, 1000);
    cout<<"pp1( "<<pp1->getX()<<","<<pp1->getY()<<")"<<endl;
    cout<<"pp2( "<<pp2->getX()<<","<<pp2->getY()<<")"<<endl;
    delete pp1;
    delete pp2;*/

    //testIsSquare("lab02/points.txt");

    int n;
    cout<< "Enter a number of points: ";
    cin>> n;
    Point *points = createArray(n);
    /*printArray(points, n);
    cout << endl;
    pair<Point, Point> closestPoints2 = closestPoints(points, n);
    if (n == 3){
        for (int i = 0; i < 3; ++i) {
            for (int j = i+1; j < 3; ++j) {
                points[i].print();
                points[j].print();
                cout << distance(points[i], points[j]) << endl;
                cout<< endl;
            }
        }
    }
    closestPoints2.first.print();
    closestPoints2.second.print();

    pair<Point, Point> farthestPoints2 = farthestPoints(points, n);
    if (n == 3){
        for (int i = 0; i < 3; ++i) {
            for (int j = i+1; j < 3; ++j) {
                points[i].print();
                points[j].print();
                cout << distance(points[i], points[j]) << endl;
                cout<< endl;
            }
        }
    }
    farthestPoints2.first.print();
    farthestPoints2.second.print();*/

    /*sortPoints(points, n);
    printArray(points, n);*/
    printArray(points, n);
    Point *max10 = farthestPointsFromOrigin(points, n);
    cout<< endl;
    printArray(max10,10);
    delete[] max10;
    delete[] points;
    return 0;
}

