#include <iostream>
#include "cPoint.h"
using namespace std;

int main() {
  cPoints f;
  f.add(1, 1);
  f.add(2, 1);
  f.add(1, 15);
  f.printPoints();
  return 0;
}