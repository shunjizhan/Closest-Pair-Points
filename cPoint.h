#include <iostream>
#include <vector>
using namespace std;

struct point {
  int x;
  int y;

  point(int x, int  y) {
    this->x = x;
    this->y = y;
  }

  void print() {
    cout << x << ", " << y << endl;
  }
};

class cPoints {
public:
  int n;
  vector<point> allPoints;

  cPoints() {
    n = 0;
  }

  void printPoints() {
    for (vector<point>::iterator it = begin (allPoints); it != end (allPoints); ++it) {
      it -> print();
    }
    cout << "n = " << n << endl;
  }
  
  void add(point p) {
    allPoints.push_back(p);
    n++;
  }

  void add(int x, int y) {
    allPoints.push_back(point(x, y));
    n++;
  }
};