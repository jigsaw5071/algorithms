/**
author : Shubham Sharma
Date: 22/06/2017
Ref:https://www.topcoder.com/community/data-science/data-science-tutorials/range-minimum-query-and-lowest-common-ancestor/#Lowest%20Common%20Ancestor%20(LCA)
*/

/**======================LCA in an directed Acyclic Graph=========================================

1. LCA problems are equivalent to RMQ(range minimum queries) paradigm. If you look closely the algorithms that you are implementing to solve RMQ can be modified to solve the LCA problem

2. This tutorial implements the LCA algotrithm using sparse Table dynamic programming approach

3. The time complexity for preprocessing: O(n logn)
4. The time complexity for query : O(logn)
5. The space complexity is O(logn)

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



int P[MAXN][MAXN];//preprocess sparse table such that P[i][j] is 2^jth ancestor of i

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

/**
preprocessing time in O(n logn)
*/

void preprocess(){
  
  for(int i = 1;i<MAXN;++i){
    for(int j = 0;(1 << j) <= MAXN; ++j){
      P[i][j] = -1;
    }
  }
  
  for(int i = 1;i<MAXN;++i){
    P[i][0] = T[i];
  }
  
  for(int j = 1; (1 << j) <= MAXN;++j){
    for(int i = 1;i<MAXN;++i){
      if(P[i][j-1]!=-1){
        P[i][j] = P[P[i][j-1]][j-1];
      }
    }
  }
  
  
}

/**
query takes O(2*logn) time
*/
int query(int u,int v){
  
  // make same levels if not same
  if(L[u] < L[v]){
    swap(u,v);
  }
  
  int dist = L[u] - L[v];
  while(dist){
    
    int raise_by = log2(dist);
    u =P[u][raise_by];
    dist -=(1<<raise_by);
  }
  
  if(u == v) return u;
  
  // now we just need to find the k-1 th encestor of u and void
  int MAXLOG = log2(MAXN-1);
  for(int j = MAXLOG;j>=0;j--){
    if(P[u][j]!=-1 && (P[u][j] != P[v][j])){
      u = P[u][j];
      v = P[v][j];
    }
  }
  
  return T[u];
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
  
  preprocess();
  cout<<query(12,2);
  
  
  return 0;
}

