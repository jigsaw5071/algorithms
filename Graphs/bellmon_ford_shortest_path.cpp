/**
@Shubham Sharma
Date: 13/01/2017
*/

/**
-------------------Bellmon Ford Single Source Shortest Path-------------------------------------
1. This is better then dijkstra as this works for the weight with negative cycle also

2. The time complexity of this algorithm is O(VE)


*/

#include<bits/stdc++.h>
using namespace std;

/*
utility function to relax in the bellmon ford algorithm
*/
void relax(vector<pair<int,pair<int,int>>>& G,vector<int>& key){
    for(int i=0;i<G.size();++i){
        int u=G[i].first;
        int v=G[i].second.first;
        int w=G[i].second.second;
        if(key[v]>key[u]+w){
            key[v]=key[u]+w;
        }
    }
}

/*
utility function for the bellmon ford
*/
void get_shortest_path_bellmonFord(vector<pair<int,pair<int,int>>>& G,const int V,const int s){
    vector<int> key(V,5000000);
    key[s]=0;
    
    for(int i=0;i<V-1;++i){
        relax(G,key);
    }
    
    bool negative_cycle=false;
    vector<int> result=key;
    relax(G,result);
    for(int i=0;i<V;++i){
        if(result[i]!=key[i]){
            cout<<"There is a negative weight cycle "<<endl;
            return;
        }
    }
    
    for(int i=0;i<V;++i){
        cout<<key[i]<<endl;
    }
}

int main(void){
    int V,E;
    cin>>V>>E;
    vector<pair<int,pair<int,int>>> G(E);
    
    for(int i=0;i<E;++i){
        int u,v,w;
        cin>>u>>v>>w;
        G[i]=make_pair(u,make_pair(v,w));
    }
    int source;
    cin>>source;
    get_shortest_path_bellmonFord(G,V,source);
    return 0;
}
