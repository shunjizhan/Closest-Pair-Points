#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
  int x;
  int y;

  Point() {
    this->x = 0;
    this->y = 0;
  }

  Point(int x, int  y) {
    this->x = x;
    this->y = y;
  }

  void print() {
    cout << "(" << x << ", " << y << ")" << endl;
  }
};

class cPoints {
public:
  int n;
  vector<Point> allPoints;

  cPoints(int n) {
    this->n = n;
  }

  void printPoints() {
    for (vector<Point>::iterator it = begin (allPoints); it != end (allPoints); ++it) {
      it -> print();
    }
    cout << "n = " << n << endl;
  }
  
  void add(Point p) {
    allPoints.push_back(p);
  }

  void add(int x, int y) {
    allPoints.push_back(Point(x, y));
  }

  double getDistance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) + (p1.y - p2.y));
  }

  void bruteForce() {
    int comparison = 0;
    Point temp1, temp2;
    Point p1;
    Point p2;
    double distance;
    double minDistance = 999999999.9;

    for(vector<Point>::iterator it = allPoints.begin(); it != allPoints.end(); ++it) {
      temp1 = *it;
      for(vector<Point>::iterator it2 = allPoints.begin(); it2 != allPoints.end(); ++it2) {
        temp2 = *it2;
        distance = getDistance(temp1, temp2);
        comparison++;
        if (distance < minDistance && distance != 0) {
          minDistance = distance;
          p1 = temp1;
          p2 = temp2;
        }
      }
    }

    cout << "closest points: " << endl;
    cout << p1.x << " " << p1.y << " " << p2.x << " " << p2.y << endl;
    cout << "comparisons: " << endl;
    cout << comparison << endl;
  }

  void DAC() {
    return DAC(allPoints);
  }

  void DAC(vector<Point> points) {
    
  }

};








