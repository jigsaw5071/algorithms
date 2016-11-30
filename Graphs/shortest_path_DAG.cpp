/*
@Shubham Sharma
-30/11/2016
*/

/*
Shortest Path In a Directed Acyclic Graph in linear time

Time complexity : O(v+e)
Space Complexity : O(v+e)

*/

#include<bits/stdc++.h>
using namespace std;

/*
utility function to test the topological sort of an algorithm
*/
void topological_sort(vector<list<pair<int,int>>>& G,vector<bool>& visited,const int s,stack<int>& st){
    visited[s]=true;
    for(auto iter=G[s].begin();iter!=G[s].end();++iter){
        if(!visited[iter->first]){
            topological_sort(G,visited,iter->first,st);
        }
    }
    st.push(s);
}


/*

utility function to print the shortest path
*/
void shortest_path(vector<list<pair<int,int>>>& G,const int V,const int S){
    vector<bool> visited(V,false);
    stack<int> st;
    for(int i=0;i<V;++i){
        if(!visited[i]){
            topological_sort(G,visited,i,st);
        }
    }
    vector<int> distance(V,1000);
    distance[S]=0;
    while(!st.empty()){
        int top=st.top();
        st.pop();
        for(auto iter=G[top].begin();iter!=G[top].end();++iter){
            if(distance[iter->first] > distance[top]+iter->second){
               distance[iter->first]= distance[top]+iter->second;
            }
        }
    }
    
    for(int i=0;i<V;++i){
        cout<<distance[i]<<" ";
    }
    
}



int main(void){
    int V,E;
    cin>>V>>E;
    vector<list<pair<int,int>>> G(V);
    
    for(int i=0;i<E;++i){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
    }
    int S;
    cin>>S;
    shortest_path(G,V,S);
    
return 0;    
}
