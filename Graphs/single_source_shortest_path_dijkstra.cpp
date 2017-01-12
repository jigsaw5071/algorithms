/**
@Shubham Sharma
Date: 12/01/2017
*/

/*
-----------------------------Single Source Dijkstra------------------------------
1. This algorithm does not works for the negative weight cycle. Bellmon Ford(Dynamic Programming)
based algorithm is used for this purpose

2. This also uses priority queue data structure.

3. Time complexity :O(ElogV)

4. Space complexity:O(E+V)

*/
#include<bits/stdc++.h>
using namespace std;

struct compare{
    public:
    bool operator() (pair<int,int> x,pair<int,int> y){
        return x.second > y.second;
    }
};

/*
utility function for the Dijkstra
*/
void get_shortest_path(vector<list<pair<int,int>>>& G,const int V,const int s){
    vector<int> key(V,INT_MAX);
    vector<int> parent(V,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,compare> Q;
    key[s]=0;
    Q.push(make_pair(s,0));
    while(!Q.empty()){
        int u=Q.top().first;
        Q.pop();
        for(auto iter=G[u].begin();iter!=G[u].end();++iter){
            if(key[iter->first]> key[u]+iter->second){
                key[iter->first]=key[u]+iter->second;
                Q.push(*iter);
                parent[iter->first]=key[u]+iter->second;
            }
        }
    }
    
    // printing the distances
    for(int i=0;i<V;++i){
        cout<<key[i]<<" ";
    }
    cout<<endl;
}

int main(void){
    int V,E;
    cin>>V>>E;
    vector<list<pair<int,int>>> G(V);
    for(int i=0;i<E;++i){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
        G[v].push_back(make_pair(u,w));
    }
    int source;
    cin>>source;
    get_shortest_path(G,V,source);
    return 0;
}
