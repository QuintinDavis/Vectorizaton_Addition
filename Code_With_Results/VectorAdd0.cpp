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

vector<int> sum(vector<int>& v, vector<int>& w) {
  vector<int> s(10000000);
  int size = v.size();
  int vectSize = 10000000/4;

  IntVector *vectV = (IntVector*) &(v[0]);
  IntVector *vectW = (IntVector*) &(w[0]);
  IntVector *vectSum = (IntVector*) &(s[0]);

  for(int i=0; i<vectSize; i++){
    vectSum[i].vector = vectV[i].vector+vectW[i].vector;
  }

  for (int i=vectSize*4; i<size; i++){
    vectSum[vectSize].array[i-vectSize*4]=v[i]+w[i];
  }

  return s;
}

int main() {
  vector<int> v(10000000), w(10000000);
  for (int i=0; i<10000000; i++) {
    v[i] = rand();
    w[i] = rand();
  }

  Stopwatch timer;
  vector<int> s = sum(v, w);
  float elapsed = timer.elapsed();
  cout << "Time for sum is " << elapsed << endl;
}
