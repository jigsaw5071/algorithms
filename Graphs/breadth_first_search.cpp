/*
@Shubham Sharma
29/11/2016
*/

/*
First And the Basic Algorithm in Graph Searching:
1. Web crawlers
2. social networking(Facebook Friend Finder)
3. Network braodcast
4. Garbage collection
5. mathematical conjectures

Time Complexity :O(V+E)
Space Complexity:O(V+E)
*/
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
utility function to return the BFS vector of the graph
*/
vector<int> _get_BFS(vector<list<int>>& G,const int V,const int E,const int S){
    vector<bool> visited(V,false);
    visited[S]=true;
    vector<int> result;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
     int _front=Q.front();
     Q.pop();
     result.push_back(_front);
     for(auto iter=G[_front].begin();iter!=G[_front].end();++iter){
         if(!visited[*iter]){
             Q.push(*iter);
             visited[*iter]=true;
         }
     }
    }
    
    return result;
}

int main(void){
    int V,E;
    cin>>V>>E;
    vector<list<int>> G(V);
   for(int i=0;i<E;++i){
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    int S;
    cin>>S;
    vector<int> result=_get_BFS(G,V,E,S);
    for(int i=0;i<result.size();++i){
        cout<<result[i]<<" ";
    }
    
    
    return 0;
}
