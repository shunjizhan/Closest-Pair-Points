#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "cPoint.h"
using namespace std;

// void printVector(vector<double> v) {
//   cout << "vector: " << endl;
//   for (vector<double>::iterator it = begin (v); it != end (v); ++it) {
//       cout << *it << " ";
//     }
// }

void printResult(vector<double> v) {
  // cout << "closest points: " << endl;
  cout << v.at(0) << " " << v.at(1) << " " << v.at(2) << " " << v.at(3) << endl;
  // cout << "comparisons: " << endl;
  cout << v.at(4) << endl;
}

int main() {
  double n, intX, intY;
  string x, y;

  cout << "enter point number: " << endl;
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
  printResult(dac);

  return 0;
}


