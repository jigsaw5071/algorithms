/*
@Shubham Sharma
-29/11/2016

*/

/*
Depth First Search
1. This is the most common graph search algorithm
2. It is same as k-ary tree search but no overlapping allowed
3. It generally is used to search across entire graph even when it is broken 
*/

#include<bits/stdc++.h>
using namespace std;


/*
utility function for the DFS
*/
void _DFS(vector<list<int>>& G,const int s,vector<bool> & visited){
    visited[s]=true;
    cout<<s<<" ";
    for(auto iter=G[s].begin();iter!=G[s].end();++iter){
        if(!visited[*iter]){
         _DFS(G,*iter,visited);   
        }
    }
}

/*
Wrapper function for the DFS
*/
void _DFS_wrapper(vector<list<int>>& G,const int V){
    vector<bool> visited(V,false);
    for(int i=0;i<V;++i){
        if(!visited[i]){
            _DFS(G,i,visited);
        }
    }
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
    _DFS_wrapper(G,V);
    
    
return 0;   
}
