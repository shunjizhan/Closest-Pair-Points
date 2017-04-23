#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<double> initialResult() {
  vector<double> result;
  result.push_back(0.0);
  result.push_back(0.0);
  result.push_back(0.0);
  result.push_back(0.0);
  result.push_back(-999999999.9);
  return result;
}

vector<double> updateVector(vector<double> v, double x0, double y0, double x1, double y1, double n) {
  v.clear();
  v.push_back(x0);
  v.push_back(y0);
  v.push_back(x1);
  v.push_back(y1);
  v.push_back(n);

  return v;
}

struct Point {
  double x;
  double y;

  Point() {
    this->x = 0;
    this->y = 0;
  }

  Point(double x, double  y) {
    this->x = x;
    this->y = y;
  }

  void print() {
    cout << "(" << x << ", " << y << ")" << endl;
  }
};

class cPoints {
public:
  double n;
  vector<Point> allPoints;

  cPoints(double n) {
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

  void add(double x, double y) {
    allPoints.push_back(Point(x, y));
  }

  double getDistance(Point p1, Point p2) {
    return sqrt((p1.x - p2.x) + (p1.y - p2.y));
  }

  /***** brute force *****/
  vector<double> bruteForce() {
    return bruteForce(this -> allPoints);
  }

  vector<double> bruteForce(vector<Point> points) {
    vector<double> result = initialResult(); 
    double comparison = 0.0;
    double distance;
    double minDistance = 999999999.9;
    Point temp1, temp2, p1, p2;

    for(vector<Point>::iterator it = points.begin(); it != points.end(); ++it) {
      temp1 = *it;
      for(vector<Point>::iterator it2 = points.begin(); it2 != points.end(); ++it2) {
        temp2 = *it2;
        distance = getDistance(temp1, temp2);
        comparison += 1.0;
        if (distance < minDistance && distance != 0) {
          minDistance = distance;
          p1 = temp1;
          p2 = temp2;
        }
      }
    }

    result = updateVector(result, p1.x, p1.y, p2.x, p2.y, comparison);

    return result;
  }

  /***** divide and conqure *****/
  vector<double> DAC() {
    // x0 y0 x1 y1 comparisons 
    return DAC(this -> allPoints);
  }

  vector<double> DAC(vector<Point> points) {
    vector<double> result = initialResult();

    if (points.size() < 2) { 
      cout << "error!"; 
      return result;
    } else if (points.size() < 10) { 
      return bruteForce(points);
    }

    double comparison = 0;
    double x0, y0, x1, y1;
    double distance;
    double minDistance = 999999999.9;

    return result;
  }

};









