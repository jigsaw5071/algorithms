/**
author : Shubham Sharma
Date : 13/06/2017
Ref : http://www.geeksforgeeks.org/tarjan-algorithm-find-strongly-connected-components/
*/

/** ======================================= TARJAN ALGORITHM FOR SCC====================================

1. This algorithm is used to find all the strongely connected components in a directed graph
2. unlike the kosaraju , they implement DFS only once.
3. The time complexity is O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;

#define FAST_INP  ios_base::sync_with_stdio(false);cin.tie(NULL)
#define rep(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define per(i,a,b) for(int i=(int)b;i>=(int)a;--i)	

typedef unsigned long long ul;
typedef long long ll;

const int INF = 1e9 + 143;
const ll LINF = 1e18 + 143;

template<class T> inline T gmax(T a,T b){return a>b?a:b;}
template<class T> inline T gmin(T a,T b){return a<b?a:b;}
template<class T> inline T gabs(T a){ return a > 0 ? a : -a ; }


vector<vector<int>> res;

void DFS(vector< list<int> >& G,const int s,vector<bool>& vis,vector<int>& dis,vector<int>& low,stack<int>& st,vector<bool>& in_stack,int& clk){
  vis[s] = true;
  dis[s] = low[s] = clk;
  ++clk;
  st.push(s);
  in_stack[s] = true; // this hash_table + stack provides constant time searching
  
  for(auto iter = G[s].begin();iter!=G[s].end();++iter){
    
    if(!vis[*iter]){
      DFS(G,*iter,vis,dis,low,st,in_stack,clk);
      low[s] = min(low[s],low[*iter]);
    }
    else{
      //this is just to check the recursion stack as both the nodes across the back edges needs to be present in recursion (current)
      if(in_stack[*iter]){
        low[s] = min(low[s],dis[*iter]);
      }
    }
    
  }
  
  if(low[s] == dis[s]){
    vector<int> temp;
    while(st.top()!=s){
      temp.push_back(st.top());
      in_stack[st.top()] = false;
      st.pop();
    }
    temp.push_back(s);
    in_stack[s]=false;
    st.pop();
    res.push_back(temp);
  } 
  
}

void tarjan_scc(vector< list<int> >& G, const int V,const int E){
  vector<bool> vis(V,false);
  vector<int> dis(V,0);
  vector<int> low(V,INT_MAX);
  stack<int> st;
  vector<bool> in_stack(V,false); // this basically indicates whether it is in current recursion or not
  int clk = 1;
  DFS(G,0,vis,dis,low,st,in_stack,clk);
  for(int i=0;i<res.size();++i){
    for(int j = 0;j<res[i].size();++j){
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
}


int main(void){
  FAST_INP;
  int V,E ; cin >> V >> E;
  
  vector< list<int> > G(V);
  rep(i,0,E-1){
    int u,v; cin >> u >> v;
    G[u].push_back(v);
  }
  
  tarjan_scc(G,V,E);
  
  return 0;
}

