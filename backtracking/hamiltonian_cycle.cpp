/**
@ Shubham Sharma
Date:30/03/2017
*/

/**=============HAMILTONIAN CYCLES=============================
1. To check if the hamiltonian cycles exist in the graph
2. The time complexity is O(n!)
3. This is the best paradigm of using the space state tree in the solution as in mQueen Problem and in subset sum problem
*/

#include<iostream>
#include<vector>
using namespace std;

bool is_valid(vector< vector<int> > &G,const int i,vector<bool>& visited,const int parent){
  if(visited[i]==true){
    return false;
  }
  if(G[parent][i]==0){
    return false;
  }
  return true;
}

void ham_cycle_util(vector< vector<int> > &G,vector<int> &count,vector<int>& result,vector<bool>& visited,const int level,const int parent){
  
  if(level==result.size()){
    //we have generated all the nodes
    if(G[result[level-1]][0]==1){
      for(int i=0;i<level;i++){
        cout<<result[i]<<" "; 
      }
      cout<<endl;
    }
  }
  else{
    
    for(int i=1;i<count.size();++i){
      if(count[i]==0){continue;}
      if(is_valid(G,i,visited,parent)){
        count[i]=0;
        visited[i]=true;
        result[level]=i;
        ham_cycle_util(G,count,result,visited,level+1,i);
        count[i]=1;
        visited[i]=false;
      }
    }
  }
}

void make_ham_cycle(vector< vector<int> > &G,const int V){
  //we are taking 0 as the first vertex of the cycle
  vector<int> count(V,1);
  vector<int> result(V,0);
  result[0]=0;
  vector<bool> visited(V,false);
  ham_cycle_util(G,count,result,visited,1,0);
}

int main(void){
  vector< vector<int> > G= {{0, 1, 0, 1, 0},
                      {1, 0, 1, 1, 1},
                      {0, 1, 0, 0, 1},
                      {1, 1, 0, 0, 0},
                      {0, 1, 1, 0, 0},
                     };
  int V=G.size();
 make_ham_cycle(G,V);
  return 0;
}
