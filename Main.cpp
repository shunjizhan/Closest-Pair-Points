#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <stdlib.h>     /* atof */
#include "cPoint.h"
using namespace std;

// void printVector(vector<double> v) {
//   cout << "vector: " << endl;
//   for (vector<double>::iterator it = begin (v); it != end (v); ++it) {
//       cout << *it << " ";
//     }
// }

void printResult(vector<double> v) {
  double b = 0.000001;
  double x0 = v.at(0);
  double y0 = v.at(1);
  double x1 = v.at(2);
  double y1 = v.at(3);

  cout << x0 << " " << y0 << " " << x1 << " " << y1 << endl;
  cout << (int) v.at(4) << endl;
}

int main() {
  double n, intX, intY;
  string x, y;

  // cout << "enter point number: " << endl;
  cin >> n;
  cPoints cpoints(n);

  for (int i = 0; i < n; i++) {
    // cout << "enter the " << i+1 <<"th point: ";
    cin >> x >> y;
    intX = atof(x.c_str());
    intY = atof(y.c_str());

    cpoints.add(intX, intY);
  }

  // cpoints.printPoints();
  vector<double> brute = cpoints.bruteForce();
  vector<double> dac = cpoints.DAC();

  printResult(brute);
  // printResult(brute);
  printResult(dac);

  return 0;
}


