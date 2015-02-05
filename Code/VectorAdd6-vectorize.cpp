#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "Stopwatch.h"

typedef int v4si __attribute__ (( vector_size(4*sizeof(int)) ));
typedef union {
 v4si vector;
 int array[4];
} IntVector;

long long sum(vector<int>& v) {
  long long s;
  s = 0;
  
  int size = v.size();
  int vectSize = size/4;

  IntVector *vectData = (IntVector*) &(v[0]);
  IntVector vectSum;
  for (int i=0; i<4; i++)
    vectSum.array[i] = 0;
  for (int i=0; i<vectSize; i++)
    vectSum.vector += vectData[i].vector;
  
  s = vectSum.array[0] + vectSum.array[1] 
    + vectSum.array[2] + vectSum.array[3];
  for (int i=4*vectSize; i<size; i++)
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
