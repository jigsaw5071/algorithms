/*
@Shubham Sharma
: 17/12/2016
*/

/*
Kosaraju's Algorithm to find the Strongly connected components

1. A strongly connected components in a graph means that there is a path from every vertex to every other vertex
2. In this we take a data structure stack to put vertices in the increasing time of exploration to graph other vertices
3. Basically strongely connected components make independent cycles and on reversal of the vertices as well the component remains strongly connected.
4. The task is to enquire about the bridge edges such that in the first pass the source vertex FROM one SCC to sink vertex in another SCC comes first
in the first traversal.
5. Then we reverse the graph and the source becomes the sink and vice versa.

6. On taking the previoies visites from stack  if the sinks are visited before the stack then taht means that it is a bridge edge and there are tow SCC
on the either side of that edge

Time Complexity : O(V+E)
Space Complexity: O(V+E)


*/

#include<bits/stdc++.h>
using namespace std;

/*
utility function for the DFS of the reverse graph
*/
void DFS_reverseGraph(vector<list<int>>& G, int s,vector<bool>& visited,vector<int>& temp){
    visited[s]=true;
    temp.push_back(s);
    for(list<int>::iterator iter=G[s].begin();iter!=G[s].end();++iter){
        if(!visited[*iter]){
            DFS_reverseGraph(G,*iter,visited,temp);
        }
    }
}


/*
utility function to reverse the graph
*/
vector<list<int>> reverseGraph(vector<list<int>> G,const int V){
    vector<list<int>> result(V);
    for(int i=0;i<V;++i){
        for(auto iter=G[i].begin();iter!=G[i].end();++iter){
            result[*iter].push_back(i);
        }
    }
    return result;
}
/*
utility DFS Function
*/
void DFS(vector<list<int>>& G,const int s,vector<bool>& visited,stack<int>& S){
    visited[s]=true;
    for(auto iter=G[s].begin();iter!=G[s].end();++iter){
        if(!visited[*iter]){
            DFS(G,*iter,visited,S);
        }
    }
    S.push(s);
}

/*
utility wrapper function for the kosaraju scc
*/
vector<vector<int>> _kosaraju_SCC_wrapper(vector<list<int>>& G,const int V){
    vector<bool> visited(V,false);
    stack<int> S;
    vector<vector<int>> result;
    for(int i=0;i<V;++i){
        if(!visited[i]){
            DFS(G,i,visited,S);
        }
    }
    G=reverseGraph(G,V);
    visited=vector<bool> (V,false);
    
    while(!S.empty()){
        int s=S.top();
        S.pop();
        if(!visited[s]){
            vector<int> temp;
            DFS_reverseGraph(G,s,visited,temp);
            result.push_back(temp);
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
    vector<vector<int>> result=_kosaraju_SCC_wrapper(G,V);
    
    for(int i=0;i<result.size();++i){
        for(int j=0;j<result[i].size();++j){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
return 0;    
}
