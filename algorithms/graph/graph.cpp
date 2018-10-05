#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename T>
struct Edge {
  int from, to;
  T cost;

  Edge(int to, T cost) : from(-1), to(to), cost(cost) {}

  Edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}

  bool operator<(const Edge& e) const {    
    return cost<e.cost;    
  }
  bool operator>(const Edge& e) const {
    return cost>e.cost;    
  }
};

template<typename T>
using Edges = vector<Edge<T> >;

template<typename T>
using Graph = vector<Edges<T> >;

template<typename T>
using Tree = vector<Edges<T> >;

template< typename T >
using Matrix = vector<vector<T> >;
