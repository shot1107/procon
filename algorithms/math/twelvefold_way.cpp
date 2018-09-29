#include <bits/stdc++.h>
using namespace std;

#define int long long

struct Combination
{
  int mod;
  vector<int> mfact;
  vector<int> rfact;

  /*
    constructor : O(sz+log(mod))    
   */
  Combination(int sz, int mod) : mfact(sz+1), rfact(sz+1), mod(mod) {
    mfact[0] = 1;
    for ( int i = 1; i < (int)mfact.size(); i++ ) {
      mfact[i] = mfact[i-1]*i % mod;
    }
    rfact[sz] = inv(mfact[sz]);
    for ( int i = sz-1; i >= 0; i-- ) {
      rfact[i] = rfact[i+1]*(i+1) % mod;
    }
  }

  int fact(int k) const {
    return (mfact[k]);
  }

  int pow(int x, int n) const {
    int ret = 1;
    while ( n > 0 ) {
      if ( n & 1 ) (ret *= x) %= mod;
      (x *= x) %= mod;
      n >>= 1;
    }
    return (ret);
  }

  int inv(int x) const {
    return (pow(x, mod - 2));
  }

  /*
    permutation
   */
  int P(int n, int r) const {
    if ( r < 0 || n < r ) return (0);
    return (mfact[n]*rfact[n-r] % mod);
  }

  /*
    combination
   */
  int C(int n, int r) const {
    if ( r < 0 || n < r ) return (0);    
    return (mfact[n]*rfact[r]%mod * rfact[n-r]%mod);    
  }  

  /*
    combination with repetition
   */
  int H(int n, int r) const {
    if ( n < 0 || r < 0 ) return (0);
    return (r == 0 ? 1 : C(n+r-1, r));
  }

  /*
    stirling number
   */
  int S(int n, int r) const {
    int ret;
    for ( int i = 1; i <= r; i++ ) {
      
    }
  }

  /*
    bell number
   */
  int B(int n, int r) const {

  }
};

signed main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cout << fixed << setprecision(12);

  
  
  return 0;
}
