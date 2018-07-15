#include<bits/stdc++.h>
using namespace std;

#define int long long

template<typename T>
struct Dinic {
  const T INF = 1<<28;
  
  struct FlowEdge {    
    int to, rev;
    T cap;    
    FlowEdge() {}
    FlowEdge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
  };

  int n;
  vector<vector<FlowEdge> > G;
  vector<int> level, iter;

  Dinic() {}
  Dinic(int sz) : n(sz), G(n), level(n), iter(n) {}
  
  void add_edge(int from, int to, T cap) {
    G[from].push_back(FlowEdge(to, cap, G[to].size()));    
    // undirected
    //G[to].push_back(FlowEdge(from, cap, G[from].size()-1));
    // directed
    G[to].push_back(FlowEdge(from, 0, G[from].size()-1));    
  }
  
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
  vector<bool> get_cut(int s, int t) {
    vector<bool> res(n);
    for ( int i = 0; i < n; i++ ) {
      res[i] = (level[i] == -1);      
    }
    return res;  
  }
};



signed main(){
  int V,E;
  cin >> V >> E;
  
  Dinic<int> dinic(V);  
  for ( int i = 0; i < E; i++ ) {
    int u, v, c;
    cin >> u >> v >> c;
    dinic.add_edge(u, v, c);
  }
  
  cout << dinic.max_flow(0,V-1) << endl;
  
  return 0;
}

/*
  verified on 2018/7/15
  http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=3029326#1
*/
