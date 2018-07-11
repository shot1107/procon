#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename T>
struct edge {
  int from, to;
  T cost;

  edge(int to, T cost) : from(-1), to(to), cost(cost) {}

  edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

  bool operator<(const edge& e) const {    
    return cost<e.cost;    
  }
  bool operator>(const edge& e) const {
    return cost>e.cost;    
  }
};

template<typename T>
using Edges = vector<edge<T> >;

template<typename T>
using WeightedGraph = vector<Edges<T> >;
using UnWeightedGraph = vector<vector<int> >;

template< typename T >
using Matrix = vector<vector<T> >; 
