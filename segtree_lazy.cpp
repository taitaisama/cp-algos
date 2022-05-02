#include <bits/stdc++.h>
using namespace std;


//works with min, max, sum etc
template<typename it, typename bin_op>
struct segtree_lazy {
  
  using T = typename remove_reference<decltype(*declval<it>())>::type;
  
  vector<T> t, lazy; bin_op f;
  
  int N;
  
  segtree_lazy (it first, it last, bin_op op) : f(op) {
    N = distance(first, last);
    t = vector<T>(N*4);
    lazy = vector<T>(N*4, 0);
    build(first, 1, 0, N-1);
  }
  
  void build(it first, int v, int tl, int tr){
    if (tl == tr){
      t[v] = *(first + tl);
    } else {
      int tm = (tl + tr)/2;
      build(v*2, tl, tm);
      build(v*2+1, tm+1, tr);
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

  void add_in_range (int l, int r, T add){
    add_in_arnge(1, 0, N-1, l, r, add);
  }
  
  void add_in_range (int v, int tl, int tr, int l, int r, T add){
    if (tl == l && tr == r){
      lazy[v] += add;
    }
    int tm = (tl + tr) / 2;
    if (tm < l){
      return add_in_range(2*v + 1, tm+1, tr, l, r, add);
    }
    else if (r <= tm){
      return add_in_range(2*v, tl, tm, l, r, add);
    }
    else {
      add_in_range(2*v, tl, tm, l, tm, add);
      add_in_range(2*v+1, tm+1, tr, tm+1, r, add);
    }
  }
  
  T get (int l, int r){
    return get(1, 0, N-1, l, r);
  }
  T get(int v, int tl, int tr, int l, int r){
    if (tl == l && tr == r){
      return lazy[v] + t[v];
    }
    int tm = (tl + tr) / 2;
    if (tm < l){
      return lazy[v] + get(2*v + 1, tm+1, tr, l, r);
    }
    else if (r <= tm){
      return lazy[v] + get(2*v, tl, tm, l, r);
    }
    else {
      int n1 = lazy[v] + get(2*v, tl, tm, l, tm);
      int n2 = lazy[v] + get(2*v+1, tm+1, tr, tm+1, r);
      return f(n1, n2);
    }
  }
};
