/**
author : Shubham Sharma
Date : 06/13/2017
Ref : http://www.geeksforgeeks.org/bridge-in-a-graph/

"It's only when we have lost everything, we are free to do anything "  - Tyler Durden (Fightclub)

*/


/** =========== Bridges In a graph =======================================
 1. A bridge in a graph means an edge after removal of those will lead to graph being divided in connected subtrees
 2. The time complexity of this is O(V+E)
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

vector< pair<int,int> > bridge;

void DFS(vector< list<int> >& G,const int s,vector<bool>& vis,vector<int>& dis,vector<int>& low,int& clk , const int parent){
  vis[s] = true;
  low[s] = dis[s] = clk;
  ++clk;
  
  for(auto iter = G[s].begin();iter!=G[s].end();++iter){
    if(*iter == parent) continue;
    
    if(!vis[*iter]){
      DFS(G,*iter,vis,dis,low,clk,s);
      low[s] = min(low[s],low[*iter]);
      if(low[*iter] > dis[s]){
        //bridge edge
        // if low[v] == low[u] means that there is also an edge from v to u
        bridge.push_back({s,*iter});
      }
    }
    else{
      low[s] = gmin(low[s],dis[*iter]);
    }
  }
  
}

void bridge_util(vector< list<int> >& G,const int V,const int E){
  vector<bool> vis(V,false);
  vector<int> dis(V,0);
  vector<int> low(V,INT_MAX);
  int clk = 1;
  int parent = -1;
  rep(i,0,V-1){
    if(!vis[i]){
      DFS(G,i,vis,dis,low,clk,parent);
    }
  }
  
  rep(i,0,bridge.size()-1){
    cout<<bridge[i].first<<"->"<<bridge[i].second<<endl;
  }
}

int main(void){
  FAST_INP;
  int V,E; cin >> V >> E;
  vector< list<int> > G(V);
  
  rep(i,0,E-1){
    int u,v; cin >> u >> v;
    G[u].push_back(v);
    G[v].push_back(u);
  }
  
  bridge_util(G,V,E);
  
  return 0;
}


 
