#include <iostream>
#include <vector>
#include <algorithm> 
#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <cstdint>
#include <cstdlib>
#include <stdio.h>
#include <set>
#include <tuple>
#include <fstream>
using namespace std;

int num = 100001;

struct Edge {
  int src, dest, wt;
};

bool compareEdges (Edge &a, Edge &b){
  return (a.wt < b.wt);
};

struct DisjointSets
{
  int *parent, *rnk;
  int n;
  
  DisjointSets(int n)
  {
    this->n = n;
    parent = new int[n+1];
    rnk = new int[n+1];
    for (int i = 0; i <= n; i++)
      {
	rnk[i] = 0;
	parent[i] = i;
      }
  }
  
  int find(int u)
  {
    if (u != parent[u])
      parent[u] = find(parent[u]);
    return parent[u];
  }
  
  void merge(int x, int y)
  {
    x = find(x), y = find(y);
    if (rnk[x] > rnk[y])
      parent[y] = x;
    else
      parent[x] = y;
  
    if (rnk[x] == rnk[y])
      rnk[y]++;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, m;
  cin >> n >> m;
  
  DisjointSets tree(num);
  Edge allEdges [num];
  for (int i = 0; i < m; i ++){
    int x, y, w;
    cin >> x >> y >> w;
    x--;
    y--;
    allEdges[i] = {x, y, w};
  }
  sort(allEdges, allEdges + m, compareEdges);
  long long sum = 0;
  int added = 0;
  for(int i = 0; i < m; i ++){
    int node1 = allEdges[i].src;
    int node2 = allEdges[i].dest;
    int par1 = tree.find(node1);
    int par2 = tree.find(node2);
    if (par1 != par2){
      sum += allEdges[i].wt;
      added ++;
      tree.merge(par1, par2);
    }
    if(added == n-1){
      break;
    }
  }
  cout << sum << endl;
}
