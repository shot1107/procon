#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  vector<int> primes{2};  
  bool isprime[100001];
  fill_n(isprime, 100001, true);
  isprime[0] = isprime[1] = false;  
  for ( int i = 3; i < 100001; i+=2 ) {
    for ( int j = 3; j <= sqrt(i); j++ ) {
      if ( i%j == 0 ) {
	isprime[i] = false;
	break;	
      }
    }
  }

  for ( int i = 3; i < 100001; i+=2 ) {
    if ( isprime[i] ) primes.emplace_back(i);    
  }
  int sz = primes.size();  

  return 0;
}
