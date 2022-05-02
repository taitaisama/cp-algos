#include <iostream>
#include <bits/stdc++.h>
using namespace std;

template<typename it, typename bin_op>
struct sparse_table {
 
  using T = typename remove_reference<decltype(*declval<it>())>::type;
  vector<vector<T>> t; bin_op f;

  int N;
 
  sparse_table(it first, it last, bin_op op) : t(1), f(op) {
    int n = distance(first, last);
    N = n;
    t.assign(32-__builtin_clz(n), vector<T>(n));
    t[0].assign(first, last);
    for (int i = 1; i < t.size(); i++)
      for (int j = 0; j < n-(1<<i)+1; j++)
	t[i][j] = f(t[i-1][j], t[i-1][j+(1<<(i-1))]);
  }
 
  // returns f(a[l..r]) in O(1) time
  T query_overlap(int l, int r) {
    int h = floor(log2(r-l+1));
    return f(t[h][l], t[h][r-(1<<h)+1]);
  }

  // returns f(a[l..r]) in O(logn) time
  T query (int l, int r){
    if (r == l) return t[0][l];
    int h = floor(log2(r-l+1));
    int nl = l + (1 << h);
    if (nl > r) return t[h][l];
    return f(t[h][l], query(nl, r));
  }

  // retrurns maximum r for which condition satisfies in O(logn) time
  // works in overlap type only
  // its basically binary search
  int findR (int l){
    if (!condition(l, l)) return l - 1;
    int r = N - 1;
    if (condition(l, r)){
      return r;
    }
    int b = l;
    while (r - l > 1){
      int m = (r + l)/2;
      if (condition(b, m)) l = m;
      else r = m;
    }
    return l;
  }

  // change this function for findR
  inline bool condition (int l, int r){
    //query_overlap(l, r) >/=/< something usually
    return true;
  }
  
};
