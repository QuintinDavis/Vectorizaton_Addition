#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "Stopwatch.h"

vector<int> sum(vector<int> v, vector<int> w) {
  vector<int> s;
  for(int i=0; i<v.size(); i++)
    s.push_back(v[i]+w[i]);

  return s;
}

int main() {
  vector<int> v(10000000), w(10000000);
  for (int i = 0 ; i<10000000; i++){
    v[i] = rand();
    w[i]=rand();
  }

  Stopwatch timer;
  vector<int> s = sum(v,w);
  float elapsed = timer.elapsed();
  cout<< "Time for sum is " << elapsed << endl;
}
