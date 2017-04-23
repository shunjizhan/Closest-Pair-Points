#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "cPoint.h"
using namespace std;

int main() {
  double n, intX, intY;
  string x, y;

  cout << "enter point number: " << endl;
  cin >> n;
  cPoints cpoints(n);

  for (int i = 0; i < n; i++) {
    cout << "enter the " << i+1 <<"th point: ";
    cin >> x >> y;
    intX = atof(x.c_str());
    intY = atof(y.c_str());

    cpoints.add(intX, intY);
  }

  cpoints.printPoints();
  cpoints.bruteForce();
  cpoints.DAC();

  return 0;
}


