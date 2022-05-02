
//set mod, N, call calc at start of main function

#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

const long long N = 501;

long long fac [N];
long long facinv [N];

long long gcd(long long a, long long b, long long& x, long long& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long x1, y1;
    long long d = gcd(b, a % b, x1, y1);
    x = y1;
    y = x1 - y1 * (a / b);
    return d;
}
 
long long inv (long long x){
  long long a, b;
  gcd(x, mod, a, b);
  return (a%mod + mod)%mod;
}

void calc (){
  fac[0] = 1;
  long long a = 1;
  for (int i = 1; i < N; i ++){
    fac[i] = (fac[i-1] * i)%mod;
    facinv[i] = inv(fac[i]);
  }
}

 
long long C (long long a, long long b){
  //aCb
  if (a == b || b == 0){
    return 1;
  }
  long long x = fac[a];
  long long y = facinv[b];
  long long z = (x*y)% mod;
  long long u = facinv[a-b];
  z = (z * u)% mod;
  return z;
}

//set mod, N, call calc at start of main function
