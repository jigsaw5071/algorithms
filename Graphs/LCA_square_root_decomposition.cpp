/**
author : Shubham Sharma
Date: 22/06/2017
Ref:https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/#Lowest%20Common%20Ancestor%20(LCA)
*/

/**======================LCA in an directed Acyclic Graph=========================================

1. LCA problems are equivalent to RMQ(range minimum queries) paradigm. If you look closely the algorithms that you are implementing to solve RMQ can be modified to solve the LCA problem

2. This tutorial implements the LCA algotrithm using square root decomposition algorithms

3. The time complexity for preprocessing: O(n)
4. The time complexity for query : O(sqrt(n))

*/

#include<iostream>
#include<cmath>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

#define MAXN 14

int L[MAXN]; // stores the level of each node
int T[MAXN]; // stores the immediate parent of the node
int P[MAXN];//preprocess array that stores the ancestor on the last level of the upper situation

vector< vector<int> > G(MAXN);//adjacent list representation of the tree

void make_parent(){
  for(int i = 1;i<MAXN;++i){
    for(int j = 0;j<G[i].size();++j){
      T[G[i][j]] = i;
    }
  }
  T[1] = 1;
}

void make_level(){
  L[1] = 0;
  queue<int> Q;
  Q.push(1);
  
  while(!Q.empty()){
    int u = Q.front();
    Q.pop();
    for(int j = 0;j<G[u].size();++j){
      L[G[u][j]] = 1 + L[u];
      Q.push(G[u][j]);
    }
  }
  
}


void dfs(const int node,const int nr){
  
  if(L[node] < nr){
    P[node] = 1;
  }
  else{
    if((L[node]%nr) == 0){
      P[node] = T[node];
    }
    else{
      P[node] = P[T[node]];
    }
    
  }
  
  for(int j = 0;j<G[node].size();++j){
    dfs(G[node][j],nr);
  }
  
}

/*
Each query operation takes worst O(2 * sqrt(n))
*/
int query(int x,int y){
  
  while(P[x] != P[y]){
    if(L[x] > L[y]){
      x = P[x];
    }
    else{
      y = P[y];
    }
  }
  
  while(x!=y){
    if(L[x] > L[y]){
      x=T[x];
    }
    else{
      y = T[y];
    }
  }
  return x;
}

int main(void){
  //example Graph
  G[1] = {2,3,4};
  G[3] = {5,6,7};
  G[6] = {8,9};
  G[7] = {10,11};
  G[10] = {12,13};
  
  make_parent();
  make_level();
  int H = 0;
  for(int i = 1;i<MAXN;++i){
    H = max(H,L[i]);
  }
  H++;
  int nr = sqrt(H);
  
  //Preprocessing time in O(N) time
  
  int node = 1;
  dfs(node,nr);
  cout<<query(8,9)<<endl;
  
  
  
  return 0;
}

