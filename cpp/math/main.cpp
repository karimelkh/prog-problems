#include <iostream>
#include "algebra.h"

using namespace std;

int main() {
  cout << "is -1 negative? ";
  is_neg<int>(-1) ? cout << "YES" : cout << "NO";
  cout  << endl;
  cout << "is -1 positive? ";
  is_pos<int>(-1) ? cout << "YES" : cout << "NO";
  cout  << endl;
  cout << "|-2| = " << abs_val<int>(-2) << endl;
  cout << "2^9 = " << pwr<int>(2, 5) << endl;
  return 0;
}
