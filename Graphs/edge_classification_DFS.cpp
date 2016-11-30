/*
@Shubham Sharma
-30/11/2016
*/
/*
An important property of the DFS in edge classification

1. Tree Edges : Edges of the sub trees that are part of the forest
2. Forward Edge: Edges in DFS that are from a  node to its descendant
3. Backward Edge: Edges in DFS that are from a node to its ancestors
4. Cross Edges : All the other Edges

The presence of atleaset one Backwward edge indicates the loop in the graph

Note: In case of undirected graphs we have only tree edge and the backward edge.

*/


#include<bits/stdc++.h>
using namespace std;

/*
utility struct for the edges in classification
*/
struct Edge {
    vector<pair<int,int>> tree_edge;
    vector<pair<int,int>> forward_edge;
    vector<pair<int,int>> back_edge;
    vector<pair<int,int>> cross_edge;
};


/*
utility function for the DFS for the edge classification
*/
void _DFS(vector<list<int>>& G,vector<bool> & visited,const int s,int& time_value,vector<int>& entry_t,vector<int>& exit_t,Edge& result){
    visited[s]=true;
    cout<<s<<" ";
    time_value++;
    entry_t[s]=time_value;
    for(auto iter=G[s].begin();iter!=G[s].end();++iter){
        if(!visited[*iter]){
            // tree edges
         _DFS(G,visited,*iter,time_value,entry_t,exit_t,result); 
         result.tree_edge.push_back(make_pair(s,*iter));
        }
        else if(exit_t[s]==-1 && exit_t[*iter]==-1){
          // back edge
            result.back_edge.push_back(make_pair(s,*iter));
        }
        else if(exit_t[s]==-1 && entry_t[s]<entry_t[*iter]){
            // forward edge
            result.forward_edge.push_back(make_pair(s,*iter));
        }
        else{
            // cross edge
            result.cross_edge.push_back(make_pair(s,*iter));
        }
    }
    exit_t[s]=time_value;
}

/*
Wrapper function for the DFS for edge classification
*/
void _DFS_wrapper(vector<list<int>>& G,const int V){
    vector<bool> visited(V,false);
    vector<int> entry_t(V,0);
    vector<int> exit_t(V,-1);
    Edge result;
    int time_value=0;
    cout<<"DFS Traversal: ";
    for(int i=0;i<V;++i){
        if(!visited[i]){
            _DFS(G,visited,i,time_value,entry_t,exit_t,result);
        }
    }
    cout<<endl;
    
    // printing the tree edges
    cout<<"Tree Edges: "<<endl;
    for(auto iter=result.tree_edge.begin();iter!=result.tree_edge.end();++iter){
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    cout <<endl;
    // printing the back edges
    cout<<"back Edges: "<<endl;
    for(auto iter=result.back_edge.begin();iter!=result.back_edge.end();++iter){
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    cout <<endl;
    // printing the forward edges
    cout<<"Forward Edges: "<<endl;
    for(auto iter=result.forward_edge.begin();iter!=result.forward_edge.end();++iter){
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    cout <<endl;
    // printing the cross edges
    cout<<"Cross Edges: "<<endl;
    for(auto iter=result.cross_edge.begin();iter!=result.cross_edge.end();++iter){
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    cout <<endl;
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
