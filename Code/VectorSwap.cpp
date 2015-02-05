#include <iostream>
#include <cstdlib>
#include <vector>
using namespace std;

#include "Stopwatch.h"

void swap(vector<int>& v, vector<int>& w) {
  vector<int> t = v;
  v = w;
  w = t;
}

int main() {
  vector<int> v(10000000), w(10000000);
  for (int i=0; i<1000000; i++) {
    v[i] = rand();
    w[i] = rand();
  }
  
  Stopwatch timer;
  
  // swap(v,w);     -- Original version using swap function
  v.swap(w);    // Use the built in swap method
  
  float elapsed = timer.elapsed();
  cout << elapsed << " seconds to swap" << endl;
}
