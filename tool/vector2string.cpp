#include <bits/stdc++.h>
using namespace std;

#define int long long

string vector2string(vector<int> &v) {
  int l = v.size();  
  string ret(l, ' ');  
  for ( int i = 0; i < l; i++ ) {
    ret[i] = '0'+v[i];    
  }

  return ret;  
}

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  vector<int> v = {1, 2, 3, 4, 5};
  cout << vector2string(v) << endl; // 12345  
  
  return 0;
}
