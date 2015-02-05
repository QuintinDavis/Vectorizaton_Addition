#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

#include "Stopwatch.h"

int k = 123456789; 

vector<int> sum(vector<int> v, vector<int> w) {
  vector<int> s;
  for (int i=0; i<v.size(); i++)
    s.push_back(v[i]+w[i]);

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
