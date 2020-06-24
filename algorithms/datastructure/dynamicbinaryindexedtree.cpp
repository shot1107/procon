#include <bits/stdc++.h>
using namespace std;

#define int long long
#define REP(i, n) for ( int i = 0; i < (n); i++ )

template< typename T>
struct BinaryIndexedTree {
  int n;
  unordered_map<int, T> data;

  BinaryIndexedTree(int sz) {
    n = sz+1;
    // data.assign(++sz, 0);
  }

  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }

  void add(int k, T x) {
    for(++k; k < n; k += k & -k) data[k] += x;
  }
};
