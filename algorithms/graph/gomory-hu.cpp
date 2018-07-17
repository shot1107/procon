#include<bits/stdc++.h>
using namespace std;

#define int long long

// BEGIN 
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
struct Dinic {
  T INF = 1<<28;
  
  struct FlowEdge {    
    int to, rev;
    T cap;    
    FlowEdge() {}
    FlowEdge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
  };

  int n;
  vector<vector<FlowEdge> > G;
  vector<int> level; // distance from s
  vector<int> iter; // how far is it finished searching

  Dinic() {}
  Dinic(int sz) : n(sz), G(n), level(n), iter(n) {}

  void add_edge(int from, int to, T cap) {
    G[from].push_back(FlowEdge(to, cap, G[to].size()));    
    // undirected
    G[to].push_back(FlowEdge(from, cap, G[from].size()-1));
    // directed
    // G[to].push_back(FlowEdge(from, 0, G[from].size()-1));    
  }
  
  // calc shortest distance from s  
  void bfs(int s) {
    fill(level.begin(), level.end(), -1);
    queue<int> Q;
    level[s] = 0;
    Q.push(s);
    while ( !Q.empty() ) {
      int v = Q.front(); Q.pop();
      for ( int i = 0; i < (int)G[v].size(); i++ ) {
	FlowEdge &e = G[v][i];
	if ( e.cap > 0 && level[e.to] < 0 ) {
	  level[e.to] = level[v]+1;
	  Q.push(e.to);
	}
      }
    }
  }

  // search extpath 
  T dfs(int v, int t, T f) {
    if ( v == t ) return f;
    for ( int &i = iter[v]; i < (int)G[v].size(); i++ ) {
      FlowEdge &e = G[v][i];
      if ( e.cap > 0 && level[v] < level[e.to] ) {
	T d = dfs(e.to,t,min(f,e.cap));
	if ( d > 0 ) {
	  e.cap -= d;
	  G[e.to][e.rev].cap += d;
	  return d;
	}
      }
    }
    return 0;
  }
  
  T max_flow(int s, int t, int lim) {
    T flow = 0;
    while ( 1 ) {
      bfs(s);
      if ( level[t] < 0 || lim == 0 ) return flow;
      fill(iter.begin(), iter.end(), 0);
      T f;
      while ( (f=dfs(s, t, lim)) > 0 ) {	
	flow += f;
	lim -= f;
      }
    }
  }

  T max_flow(int s, int t){    
    return max_flow(s, t, INF);
  }

  /*
    get_cut() is used ONLY after using max_flow()
    (because get_cut needs the infomation of level)
    
    @ret 
    infomation about the graph after using max_flow()    
    if res[i] == false, vertex i belongs to same set as s
    else vertex i belongs to same set as t
  */  
  vector<bool> get_cut() {    
    vector<bool> res(n);
    for ( int i = 0; i < n; i++ ) {
      res[i] = (level[i] == -1);      
    }
    return res;  
  }
};

template<typename T>
struct GomoryHu {
  int n;
  Dinic<T> dinic;
  Edges<T> GH; // gomory hu tree  
  
  GomoryHu() {}
  GomoryHu(int sz) : n(sz), dinic(n) {}

  void add_edge(int from, int to, T cap) {
    dinic.add_edge(from, to, cap);    
  }

  /*
    @ret
    Edges<T> : gomory hu tree (set of Edge)
  */
  Edges<T> build() {
    Edges<T> ret;
    vector<int> pr(n, 0);
    Dinic<T> tmp = dinic;
    for ( int i = 1; i < n; i++ ) {
      dinic = tmp;      
      T flow = dinic.max_flow(i, pr[i]);
      vector<bool> cut = dinic.get_cut();      
      for ( int j = i+1; j < n; j++ ) {
	if ( cut[j] == cut[i] && pr[j] == pr[i] ) {
	  pr[j] = i;
	}
      }
      ret.emplace_back(Edge<T>(i, pr[i], flow));     
    }
    return GH = ret;    
  }
};
// END

struct UnionFind {
  int n;
  vector<int> r, p;
  UnionFind() {}
  UnionFind(int sz) :
    n(sz), r(sz, 1), p(sz,0) { iota(p.begin(), p.end(), 0); }
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
    // if ( r[x] < r[y] ) swap(x, y);
    r[x] += r[y];
    p[y] = x;
  }
};

void CF343E() {
  int n, m;
  cin >> n >> m;

  GomoryHu<int> gh(n);
  for ( int i = 0; i < m; i++ ) {
    int a, b, c;
    cin >> a >> b >> c;
    a--; b--;
    gh.add_edge(a, b, c);
  }

  Edges<int> tree = gh.build();
  
  int sum = 0;
  for ( Edge<int> e : tree ) {    
    sum += e.cost;    
  }
  cout << sum << endl;

  vector<pair<int, int> > edges;
  for ( int i = 0; i < n-1; i++ ) {
    edges.emplace_back(tree[i].cost, i);    
  }

  sort(edges.begin(), edges.end(), greater<pair<int, int> >());  

  UnionFind uf(n);
  vector<vector<int> > seq(n);
  for ( int i = 0; i < n; i++ ) seq[i].emplace_back(i);  
  for ( int i = 0; i < n-1; i++ ) {
    Edge<int> e = tree[edges[i].second];
    int x = uf.find(e.from), y = uf.find(e.to);
    uf.unite(x, y);
    seq[x].insert(seq[x].end(), seq[y].begin(), seq[y].end());
  }
  
  vector<int> ans = seq[uf.find(0)];  
  for ( int i = 0; i < n; i++ ) {
    if ( i ) cout << " ";
    cout << ans[i]+1;    
  }
  cout << endl;
}

signed main(){
  CF343E();  
  return 0;
}

/*
  verified on 2018/7/17
  https://codeforces.com/contest/343/submission/40480295
*/
