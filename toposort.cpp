#include <bits/stdc++.h>
using namespace std;


bool dfs (vector<vector<int>> &directed, vector<int> &state, int v, vector<int> &list){
  state[v] = 1;
  for (int i = 0; i < directed[v].size(); i ++){
    if (state[directed[v][i]] == 1){
      return false;
    }
    else if (state[directed[v][i]] == 0){
      bool flag = dfs(directed, state, directed[v][i], list);
      if (flag == false){
	return false;
      }
    }
  }
  state[v] = 2;
  list.push_back(v);
  return true;
}

//use like this
//directed are directed edges
/*vector<int> state(n, 0);
  vector<int> list;
  for (int i = 0; i < n; i ++){
    if (state[i] == 0){
      bool flag = dfs(directed, state, i, list);
      if (flag == false){
        //condition for cycle in directed graph
      }
    }
    }
reverse(list.begin(), list.end());
*/
