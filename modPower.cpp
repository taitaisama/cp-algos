#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;

long long binpow(long long a, long long b) {
  a %= mod;
  long long res = 1;
  while (b > 0) {
    if (b & 1)
      res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
