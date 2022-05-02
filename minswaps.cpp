#include <bits/stdc++.h>

using namespace std;

//elements of a are unique, b is required arrangement
template<typename T>
int minswaps (vector<T> &a, vector<T> &b){
  int n = a.size();
  vector<bool> mark(n, false);
  vector<int> c(n); // c[i] if place of a[i] in b
  map<T, int> m;
  for (int i = 0; i < n; i ++){
    m[a[i]] = i;
  }
  for (int i = 0; i < n; i ++){
    c[m[b[i]]] = i; 
  }
  int ans = 0;
  for (int i = 0; i < n; i ++){
    if (mark[i] == false && a[i] != b[i]){
      int j = i;
      int num = 0;
      while(mark[j] == false){
	mark[j] = true;
	j = c[j]; //position of a[j] in b
	num ++;
      }
      ans += num - 1;
    }
  }
  return ans;
}
