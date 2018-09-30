#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Combination {
  int mod; // e.g. 1000000007
  vector<int> fact; // factorial
  vector<int> invf; // inverse factorial
  vector<vector<int> > part; // partition number

  /*
    constructor : O(sz+log(mod))   
    make factorial table (fact) and inverse factorial table (invf)
  */
  Combination(int sz, int mod) : fact(sz+1), invf(sz+1), mod(mod) {
    fact[0] = 1;
    for ( int i = 1; i < (int)fact.size(); i++ ) {
      fact[i] = fact[i-1]*i%mod;
    }
    invf[sz] = inv(fact[sz]);
    for ( int i = sz-1; i >= 0; i-- ) {
      invf[i] = invf[i+1]*(i+1)%mod;
    }
  }

  int pow(int x, int n) const {
    int ret = 1;
    while ( n > 0 ) {
      if ( n & 1 ) (ret *= x) %= mod;
      (x *= x) %= mod;
      n >>= 1;
    }
    return ret;
  }

  int inv(int x) const {
    return pow(x, mod - 2);
  }

  /*
    permutation
  */
  int P(int n, int r) const {
    if ( r < 0 || n < r ) return (0);
    return fact[n]*invf[n-r]%mod;    
  }

  /*
    combination
  */
  int C(int n, int r) const {
    if ( r < 0 || n < r ) return (0);    
    return fact[n]*invf[r]%mod*invf[n-r]%mod;    
  }  

  /*
    combination with repetition
  */
  int H(int n, int r) const {
    if ( n < 0 || r < 0 ) return 0;
    if ( n == 0 && r == 0 ) return 1;
    return C(n+r-1, n);    
  }

  /*
    stirling number
  */
  int S(int n, int r) const {
    int ret = 0;
    for ( int i = 1; i <= r; i++ ) {
      int add = C(r, i)*pow(i, n)%mod;      
      if ( (r-i)&1 ) ret += mod-add;
      else ret += add;
      ret %= mod;      
    }
    (ret *= invf[r]) %= mod;
    return ret;
  }

  /*
    bell number
  */
  int B(int n, int r) const {
    int ret = 0;
    for ( int i = 1; i <= r; i++ ) {
      (ret += S(n, i)) %= mod;      
    }
    return ret;
  }

  /*
    calc partition number
    return and make partition number table (part)
  */
  vector<vector<int> > built_part(int n, int r) {
    part = vector<vector<int> >(n+1, vector<int>(r+1, 0));
    part[0][0] = 1;
    for ( int i = 0; i <= n; i++ ) {
      for ( int j = 1; j <= r; j++ ) {
	if ( i-j >= 0 ) {
	  (part[i][j] = part[i][j-1]+part[i-j][j]) %= mod;	  
	} else {
	  part[i][j] = part[i][j-1];
	}
      }
    }
    return part;    
  }

  /*
    TODO 
    make built_part() that make only part[i][i]
    https://twitter.com/kirika_comp/status/953482654787149824
    http://d.hatena.ne.jp/DEGwer/20170829
    http://mathworld.wolfram.com/BellNumber.html
  }    
  */
};
