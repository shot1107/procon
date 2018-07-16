#include<bits/stdc++.h>
using namespace std;

#define int long long

struct UnionFind {
  int n;
  vector<int> r, p;
  UnionFind() {}
  UnionFind(int sz) :
    n(sz), r(sz, 1), p(sz,0 ) { iota(p.begin(), p.end(), 0); }
  int find(int x) {
    return (x==p[x] ? x : p[x]=find(p[x]));
  }
  bool same(int x, int y) {
    return find(x)==find(y);
  }
  void unite(int x, int y) {
    x = find(x);
    y = find(y);
    if ( x == y ) return;
    if ( r[x] < r[y] ) swap(x, y);
    r[x] += r[y];
    p[y] = x;
  }
};

signed main() {
  int n, q;
  cin >> n >> q;
  
  UnionFind uf(n);
  for ( int i = 0; i < q; i++ ) {
    int c, x, y;
    cin >> c>> x>> y;
    if ( c ) cout << uf.same(x, y) << endl;
    else uf.unite(x, y);
  }
  
  return 0;
}

/*
  verified on 2018/7/16
  http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3031361#1
*/
