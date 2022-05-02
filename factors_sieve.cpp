#include <bits/stdc++.h>
using namespace std;
const int MAXN = 4*1000*1000;

vector<int> fac(MAXN+1, 0);
void make_facs(){
  for (int i = 2; i <= MAXN; i ++){
    if (fac[i] == 0){
      for (int j = i; j <= MAXN; j += i){
	fac[j] = i;
      }
    }
  }
  fac[1] = 1;
}
vector<int> get_all_facs (int n){
  if (n == 1){
    vector<int> b(1);
    b[0] = 1;
    return b;
  }
  int f = n / fac[n];
  vector<int> base = get_all_facs(f);
  int s = base.size();
  for (int i = 0; i < s; i ++){
    if (f % (base[i]*fac[n]) != 0){
      base.push_back(base[i]*fac[n]);
    }
  }
  return base;
}
vector<int> get_prime_facs(int n){
  int c = n;
  vector<int> ret;
  while (c > 1){
    ret.push_back(fac[c]);
    c / fac[c];
  }
  return ret;
}
