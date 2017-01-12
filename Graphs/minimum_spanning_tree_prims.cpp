/**
@Shubham Sharma
Date:12/01/2017
*/

/**
----------------------------------------------------------Prims Minimum Spanning Tree--------------------------------------------------
1. This algorithm is based on the greedy approach.
2. One quality optimization is to initialize the priority queue with the source and till its get empty pickup the minimum edges
3. Time complexity: O(E logV)--> For e edges priority queue operations of size logV
4. Space Complexity:O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;

/**
utility function for the DFS
*/
void get_DFS(vector<list<pair<int,int>>>& G,vector<bool>& visited,const int s){
    visited[s]=true;
    for(auto iter=G[s].begin();iter!=G[s].end();++iter){
        if(!visited[iter->first]){
            get_DFS(G,visited,iter->first);
        }
    }
}

/**
utility function to check whether the graph s connected or not
*/

bool is_connected(vector<list<pair<int,int>>>& G,const int V,const int s){
    vector<bool> visited(V,false);
    get_DFS(G,visited,s);
    for(int i=0;i<visited.size();++i){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}

/**
utility function to get the MST using prims routine
*/
void get_MST(vector<list<pair<int,int>>>& G,const int V,const int s){

if(!is_connected(G,V,s)){
    cout<<"The graph is not connected and it cant have spanning tree!"<<endl;
    return;
}

vector<bool> in_MST(V,false);
vector<int> key(V,INT_MAX);
vector<int> parent(V,-1);

auto cmp=[](pair<int,int> x,pair<int,int> y){ return x.second>y.second;};
priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> Q(cmp);
key[s]=0;
Q.push(make_pair(s,0));

while(!Q.empty()){
    pair<int,int> top = Q.top();
    Q.pop();
    int u=top.first;
    in_MST[u]=true;
    for(auto iter=G[u].begin();iter!=G[u].end();++iter){
        if((!in_MST[iter->first]) && (iter->second<key[iter->first])){
            key[iter->first]=iter->second;
            Q.push(*iter);
            parent[iter->first]=u;
        }
    }
}

for(int i=0;i<V;++i){
    cout<<parent[i]<<" "<<i<<endl;
}
    
}


int main(void){
    
    int V,E;
    cin>>V>>E;
    vector<list<pair<int,int>>> G(V); //contains the v and w
    for(int i=0;i<E;++i){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    
    int source=0;
    get_MST(G,V,source);
    
    
return 0;    
}
