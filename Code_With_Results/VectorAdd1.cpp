typedef int v4si __attribute__ ((vector_size(4*sizeof(int)) ));
typedef union {
  v4si vector;
  int array[4];
} IntVector;

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "Stopwatch.h"

vector<int> sum(vector<int>&v, vector<int>&w) {
  //  vector<int> s(10000000);
  for(int i=0; i<10000000; i++)
   v[i]+=w[i];

  return v;
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
