#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<double> initialResult() {
  // x0 y0 x1 y1 comparisons minDistance
  vector<double> result;
  result.push_back(0.0);
  result.push_back(0.0);
  result.push_back(0.0);
  result.push_back(0.0);
  result.push_back(0);
  result.push_back(9999999999.9);
  return result;
}

vector<double> updateVector(vector<double> v, double x0, double y0, double x1, double y1, double n, double minD) {
  v.clear();
  v.push_back(x0);
  v.push_back(y0);
  v.push_back(x1);
  v.push_back(y1);
  v.push_back(n);
  v.push_back(minD);

  return v;
}

struct Point {
  double x;
  double y;

  Point() {
    this->x = 0;
    this->y = 0;
  }

  Point(double x, double y) {
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

  // void printPoints() {
  //   for (vector<Point>::iterator it = std::begin (allPoints); it != std::end (allPoints); ++it) {
  //     it -> print();
  //   }
  //   cout << "n = " << n << endl;
  // }
  
  void add(Point p) {
    allPoints.push_back(p);
  }

  void add(double x, double y) {
    allPoints.push_back(Point(x, y));
  }

  double getDistance(Point p1, Point p2) {
    return sqrt(abs(p1.x - p2.x) + abs(p1.y - p2.y));
  }

  double findhalf(vector<Point> v) {
    double sum = 0;
    int size = v.size();
    for (int i = 0; i < size; i++) {
      sum += v.at(i).x;
    }
    return sum / size;
  }

  /***** brute force *****/
  vector<double> bruteForce() {
    return bruteForce(this -> allPoints);
  }

  vector<double> bruteForce(vector<Point> points) {
    vector<double> result = initialResult(); 
    if (points.size() <= 1) {
      return result;
    }

    double comparison = 0.0;
    double distance;
    double minDistance = 999999999.9;
    Point temp1, temp2, p1, p2;

    for(int i = 0; i < points.size(); i++) {
      for(int j = i + 1; j < points.size(); j++) {
        temp1 = points.at(i);
        temp2 = points.at(j);
        distance = getDistance(temp1, temp2);

        // cout << temp1.x << " " << temp1.y << " " << temp2.x << " " << temp2.y << " " << distance << endl;

        comparison += 1.0;
        if (distance < minDistance && distance != 0) {
          minDistance = distance;
          p1 = temp1;
          p2 = temp2;
        }
      }
    }

    result = updateVector(result, p1.x, p1.y, p2.x, p2.y, comparison, minDistance);
    // cout << "min distance = " << minDistance << endl;

    return result;
  }

  /***** divide and conqure *****/
  vector<double> DAC() {
    return DAC(this -> allPoints);
  }

  vector<double> DAC(vector<Point> points) {
    // cout << "points size = " << points.size() << endl;
    vector<double> result = initialResult();

    if (points.size() < 5) { 
      return bruteForce(points);
    } else {
      vector<Point> left;
      vector<Point> right;
      double halfX = findhalf(points);

      for (int i = 0; i < points.size(); i++) {
        if (points.at(i).x < halfX) {
          left.push_back(points.at(i));
        } else {
          right.push_back(points.at(i));
        }
      }

      // cout << "left size = " << left.size() << endl;
      // cout << "right size = " << right.size() << endl;

      vector<double> leftResult = DAC(left);
      vector<double> rightResult = DAC(right);

      double leftMin = leftResult.at(5);
      double rightMin = rightResult.at(5);
      double min = leftMin < rightMin ? leftMin : rightMin;

      // check the points in the strip
      bool returnMiddle = false;
      vector<double> middleResult = initialResult();
      double count = 0;
      double leftBound = halfX - min;
      double rightBound = halfX + min;

      // cout << "leftBound = " << leftBound << endl;
      // cout << "rightBound = " << rightBound << endl;

      for (int m = 0; m < points.size(); m++) {
        Point p1 = points.at(m);
        if (p1.x > leftBound && p1.x < rightBound) {
          for (int n = m + 1; n < points.size(); n++) {
            Point p2 = points.at(n);
            if (p2.x > leftBound && p2.x < rightBound) {
              // now both points are in the strip
              if (abs(p2.y - p1.y) < min) {
                double dist = getDistance(p1, p2);
                count += 1.0;
                if (dist < min) {
                  returnMiddle = true;
                  min = dist;
                  
                  middleResult.clear();
                  middleResult.push_back(p1.x);
                  middleResult.push_back(p1.y);
                  middleResult.push_back(p2.x);
                  middleResult.push_back(p2.y);
                  middleResult.push_back(0);
                  middleResult.push_back(min);
                }
              }
            }
          }
        }
      }

      // cout << "count = " << count << endl;

      double newSum = leftResult[4] + rightResult[4] + count;
      leftResult[4] = newSum;
      rightResult[4] = newSum;
      middleResult[4] = newSum;

      if (returnMiddle) {
        return middleResult;
      } else {
        return leftMin > rightMin ? rightResult : leftResult;
      }     

    }
  }

};









