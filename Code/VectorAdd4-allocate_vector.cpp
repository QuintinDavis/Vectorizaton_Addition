#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "Stopwatch.h"

long long sum(vector<int> v) {
  long long s;
  s = 0;
  
  int size = v.size();
  for (int i=0; i<size; i++)
    s += v[i];
  
  return s;
}

int main() {
  vector<int> v(10000000);
  for (int i=0; i<10000000; i++)
    v[i] = rand();
  
  Stopwatch timer;
  long long s = sum(v);
  cout << "Time for sum is " << timer.elapsed() << endl;
  cout << "The sum is " << s << endl;
}