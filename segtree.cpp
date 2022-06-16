#include <bits/stdc++.h>
using namespace std;

template<typename it, typename bin_op>
struct segtree {
  
  using T = typename remove_reference<decltype(*declval<it>())>::type;
  
  vector<T> t; bin_op f;
  
  int N;
  
  segtree (it first, it last, bin_op op) : f(op) {
    N = distance(first, last);
    t = vector<T>(N*4);
    build(first, 1, 0, N-1);
  }
  
  void build(it first, int v, int tl, int tr){
    if (tl == tr){
      t[v] = *(first + tl);
    } else {
      int tm = (tl + tr)/2;
      build(first, v*2, tl, tm);
      build(first, v*2+1, tm+1, tr);
      t[v] = f(t[2*v], t[2*v+1]);
    }
  }

  //pos from 0 to n, takes logn time
  void update_one_pos(int pos, T new_val){
    update_one_pos(1, 0, N-1, pos, new_val);
  }
  
  void update_one_pos(int v, int tl, int tr, int pos, T new_val) {
    if (tl == tr) {
      t[v] = new_val;
    } else {
      int tm = (tl + tr) / 2;
      if (pos <= tm)
	update_one_pos(v*2, tl, tm, pos, new_val);
      else
	update_one_pos(v*2+1, tm+1, tr, pos, new_val);
      t[v] = f(t[2*v], t[2*v+1]);
    }
  }

  T get (int l, int r){
    return get(1, 0, N-1, l, r);
  }
  T get(int v, int tl, int tr, int l, int r){
    if (tl == l && tr == r){
      return t[v];
    }
    int tm = (tl + tr) / 2;
    if (tm < l){
      return get(2*v + 1, tm+1, tr, l, r);
    }
    else if (r <= tm){
      return get(2*v, tl, tm, l, r);
    }
    else {
      T n1 = get(2*v, tl, tm, l, tm);
      T n2 = get(2*v+1, tm+1, tr, tm+1, r);
      return f(n1, n2);
    }
  }
};
/*
long long sum (long long a, long long b){
  return a + b;
  }*/
/*

  vector<long long> dp (n, 0);
*/

// use as  struct segtree<decltype(dp.begin()), decltype(&sum)> seg = segtree<decltype(dp.begin()), decltype(&sum)>(dp.begin(), dp.end(), sum);
