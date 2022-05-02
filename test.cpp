#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
 
#define rep(i, a, b) for (auto i = (a); i < (b); ++i)
#define per(i, a, b) for (auto i = (b); i-- > (a); )
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define sz(x) static_cast<int>((x).size())

vector<vector<pair<ll, ll>>> tree;
vector<ll> a;
vector<ll> parent;
ll ans = 0;
vector<ll> a;
vector<ll> sum;
vector<pair<ll, ll>> pos;

ll mini (ll a, ll b){
  return min(a, b);
}


// struct segtree<decltype(a.begin()), decltype(&mini)> seg;

// template<typename it, typename bin_op>
// struct segtree {
  
//   using T = typename remove_reference<decltype(*declval<it>())>::type;
  
//   vector<T> t; bin_op f;
  
//   int N;
  
//   segtree (it first, it last, bin_op op) : f(op) {
//     N = distance(first, last);
//     t = vector<T>(N*4);
//     build(first, 1, 0, N-1);
//   }
  
//   void build(it first, int v, int tl, int tr){
//     if (tl == tr){
//       t[v] = *(first + tl);
//     } else {
//       int tm = (tl + tr)/2;
//       build(first, v*2, tl, tm);
//       build(first, v*2+1, tm+1, tr);
//       t[v] = f(t[2*v], t[2*v+1]);
//     }
//   }

//   //pos from 0 to n, takes logn time
//   void update_one_pos(int pos, T new_val){
//     update_one_pos(1, 0, N-1, pos, new_val);
//   }
  
//   void update_one_pos(int v, int tl, int tr, int pos, T new_val) {
//     if (tl == tr) {
//       t[v] = new_val;
//     } else {
//       int tm = (tl + tr) / 2;
//       if (pos <= tm)
// 	update_one_pos(v*2, tl, tm, pos, new_val);
//       else
// 	update_one_pos(v*2+1, tm+1, tr, pos, new_val);
//       t[v] = f(t[2*v], t[2*v+1]);
//     }
//   }

//   T get (int l, int r){
//     return get(1, 0, N-1, l, r);
//   }
//   T get(int v, int tl, int tr, int l, int r){
//     if (tl == l && tr == r){
//       return t[v];
//     }
//     int tm = (tl + tr) / 2;
//     if (tm < l){
//       return get(2*v + 1, tm+1, tr, l, r);
//     }
//     else if (r <= tm){
//       return get(2*v, tl, tm, l, r);
//     }
//     else {
//       int n1 = get(2*v, tl, tm, l, tm);
//       int n2 = get(2*v+1, tm+1, tr, tm+1, r);
//       return f(n1, n2);
//     }
//   }
// };

// ll solveNum (ll s, ll e){
//   if (sum[e+1] - sum[s] > 0){
//     return (e - s + 1);
//   }  
// }

void solve(){
  int n;
  cin >> n;
  a = vector<ll>(n);
  sum = vector<ll>(n+1, 0);
  pos = vector<ll>(n);
  for (int i = 0; i < n; i ++){
    cin >> a[i];
    sum[i+1] = sum[i] + a[i];
    pos[i] = {a[i], i};
  }
  // seg = segtree<decltype(a.begin()), decltype(&mini)>(a.begin(), a.end(), mini);
  sort(pos.begin(), pos.end());
  vector<ll> sortsum(n+1, 0);
  for (int i = 0; i < n; i ++){
    sortsum[i+1] = sortsum[i] + pos[i].first;
  }
  if (sum[n-1] > 0){
    cout << n << endl;
    return;
  }
  
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  // cout << get_diff(56) << endl;
  
  cin >> t;
  
  while(t --){
    solve();
  }
  cout << endl;
}
p
