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

int k = 123456789; 

vector<int> sum(vector<int>& v, vector<int>& w) {
  vector<int> s(k);
  int size = v.size();
  int vectSize = k/4;

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
  vector<int> v(k), w(k);
 
  for (int i=0; i<k; i++) {
    v[i] = rand()%10;
    w[i] = rand()%10;
  }

  Stopwatch timer;
  for(int h=0;h<5;h++){
  vector<int> s = sum(v, w);
  int n =rand()%56729;
  cout << s[n] << " = " << v[n] << " + " << w[n] << " = "<< v[n]+w[n]<<endl;
  }
  float elapsed = timer.elapsed();
 
  cout << "Time for sums is " << elapsed << endl;
}
