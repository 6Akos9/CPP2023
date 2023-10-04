#include <iostream>
#include "Point.h"
using namespace std;

int main(int argc, char ** argv) {
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
    cout<<"Enter number of points: ";
    cin>>n;
    Point *points = createArray(n);
    for(int i = 0; i < n; i++) {
        points[i].print();
    }
    cout<<endl;
    printArray(points, n);
    return 0;
}
