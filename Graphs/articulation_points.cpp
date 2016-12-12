/*
@Shubham Sharma

:12/12/2016

*/

/*
Utility code to find the articulation points(cut vertices) in an undirected graph

Time Complexity : O(V+E)
Space Complexity : O(V+E)

we use the DFS traversal for it
Two cases ae must for a vertex to be an articulation point:

1. it must be a root with two independent children
2. if not root the low[u] <=low[v] where low time is the earliest visited time from the vertex rooted at v

Note:if(low[u]==low[w]) it indicates the back edge for v to u
*/
#include<bits/stdc++.h>
using namespace std;

/*
utility function to find the min of two elements
*/
int _min(const int a,const int b){
    return a<b?a:b;
}

/*
utility DFS method for the articulation points
*/

void DFS(vector<list<int>>& G,int s,vector<bool>& visited,vector<bool>& result,vector<int>& visit_time,vector<int>& low_time,int parent,int& time_value){
    visited[s]=true;
    visit_time[s]=time_value;
    low_time[s]=time_value;
    time_value++;
    int child_count=0;//this child count matters only for the root vertex as a root vertex with two indp. child is Art. point 
    bool is_articulation_point=false;
    
    for(auto iter=G[s].begin();iter!=G[s].end();++iter){
        if(*iter == parent){
            continue; // ignore the parents
        }
        
        if(!visited[*iter]){
           child_count++;
           DFS(G,*iter,visited,result,visit_time,low_time,s,time_value);
           if(low_time[*iter]>=visit_time[s]){
               is_articulation_point=true;
           }
           else{
               low_time[s]=_min(low_time[s],low_time[*iter]);
           }
        }
        else{
            low_time[s]=_min(low_time[s],visit_time[*iter]);
        }
    }
    
    if((parent==-1 && child_count>=2 ) || (parent!=-1 && is_articulation_point==true)){
        result[s]=true;
    }
}

/*
utility wrappper function for the articulation points
*/
void _articulation_point_wrapper(vector<list<int>>& G,const int V,const int S){
    vector<bool> visited(V,false);
    vector<bool> result(V,false);
    vector<int> visit_time(V,0);
    vector<int> low_time(V,INT_MAX);
    int time_value=0;
    int parent=-1;
    DFS(G,S,visited,result,visit_time,low_time,parent,time_value);
    cout<<"The articulation points are:"<<endl;
    for(int i=0;i<V;++i){
        if(result[i]){
            cout<<i<<" ";
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
        G[v].push_back(u);
    }
    int S;
    cin>>S;
    _articulation_point_wrapper(G,V,S);
    
return 0;    
}


