/*
@ Shubham Sharma
-06/12/2016
*/

/*
Chek if the graph is Bipartite(2-color) or not 

The time complexity is O(V+E)
The space complexity is O(V+E)
*/

#include<bits/stdc++.h>
using namespace std;


/*
utility function to check if a graph is Bipartite
*/
bool is_bipartite(vector<list<int>>& G,const int V,const int S){
    vector<int> color(V,-1);
    color[S]=-1;
    queue<int> Q;
    Q.push(S);
    while(!Q.empty()){
        int front=Q.front();
        Q.pop();
        for(auto iter=G[front].begin();iter!=G[front].end();++iter){
            if(color[*iter]==-1){
                color[*iter]=1-color[front];
                Q.push(*iter);
            }
            else if(color[front]==color[*iter]){
                return false;
            }
        }
    }
    return true;

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
    bool result=is_bipartite(G,V,S);
    if(result){
        cout<<"Is Bipartite"<<endl;
    }
    else{
        cout<<"Is not Bipartite"<<endl;
    }
    return 0;
}
