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

template <typename T>
vector<T> dijkstra(int s, Graph<T> &G,T INF) {
  int n = (int)G.size();  
  vector<T> d(n, INF);
  vector<int> b(n, -1);
  using P = pair<T, int>;  
  priority_queue<P, vector<P>, greater<P> > Q;
  
  d[s] = 0;
  Q.emplace(d[s], s);
  
  while ( !Q.empty() ) {
    P p = Q.top(); Q.pop();
    int v = p.second;
    if ( d[v] < p.first ) continue;
    for ( auto& e : G[v] ) {
      int u = e.to;
      T c = e.cost;
      if ( d[u] > d[v]+c ) {
	d[u] = d[v]+c;
	b[u] = v;
	Q.emplace(d[u], u);	
      }
    }
  }
  
  return d;
}

// http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3195738#1
signed main() {
  int n;
  cin >> n;

  Graph<int> G(n);
  for ( int i = 0; i < n; i++ ) {
    int u, k;
    cin >> u >> k;
    for ( int j = 0; j < k; j++ ) {
      int v, c;
      cin >> v >> c;
      G[u].emplace_back(Edge<int>(v, c));      
    }
  }

  vector<int> d = dijkstra<int>(0, G, 1e9+1);
  for ( int i = 0; i < n; i++ ) {
    cout << i << " " << d[i] << endl;    
  }
  
  return 0;
}
