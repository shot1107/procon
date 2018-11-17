#include<bits/stdc++.h>
using namespace std;

template <typename T, T INF, bool isMin>
struct ConvexHullTrick {
  using P = pair<T, T>;
  deque<P> L;

  inline T getY(const P &a, const T &x) {
    return a.first*x + a.second; 
  }

  inline bool check(const P &a, const P &b, const P &c) {
    return (b.first-a.first) * (c.second-b.second)
      >= (b.second-a.second) * (c.first-b.first);
  }
  
  void add(T a,T b) {
    if ( !isMin ) a *= -1, b *= -1;
    P line(a, b);
    if ( !L.empty() && L.back().first == a ) {
      line.second = min(line.second, L.back().second);
      L.pop_back();
    }
    while ( L.size() >=2 && check(L[L.size()-2], L[L.size()-1], line) ) L.pop_back();
    L.emplace_back(line);    
  }

  T get(T x) {
    if ( L.empty() ) return isMin ? INF : -INF;
    int low = -1, high = L.size()-1;
    while ( low+1 < high) {
      int mid = (low+high)>>1;
      if ( getY(L[mid], x) >= getY(L[mid+1], x) ) low = mid;
      else high = mid;
    }
    return (!isMin ?-1 : 1) * getY(L[high], x);
  }
  
  T getMonotone(T x) {
    if ( L.empty() ) return isMin ? INF : -INF;
    while ( L.size() >= 2 && getY(L[0], x) >= getY(L[1], x) ) L.pop_front();
    return (!isMin ?-1 : 1) * getY(L[0], x);
  }
};
