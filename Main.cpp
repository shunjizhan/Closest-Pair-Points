#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "cPoint.h"
using namespace std;

int main() {
  int n, intX, intY;
  string x, y;

  cout << "enter point number: " << endl;
  cin >> n;
  cPoints cpoints(n);

  while (true) {
    cout << "enter next point: ";
    cin >> x >> y;
    intX = atoi(x.c_str());
    intY = atoi(y.c_str());

    cout << "you entered: " << intX << ", " << intY << endl;
  }

  cpoints.printPoints();
  return 0;
}


