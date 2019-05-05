#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> string2vector(string &s) {  
  int l = s.size();  
  vector<int> ret(l);  
  for ( int i = 0; i < l; i++ ) {
    ret[i] = s[i]-'0';    
  }

  return ret;  
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  string s = "12345";  
  vector<int> v = string2vector(s);
  for ( int i = 0; i < v.size(); i++ ) {
    cout << v[i] << " ";
  }
  cout << endl; // 1 2 3 4 5
  
  return 0;
}
