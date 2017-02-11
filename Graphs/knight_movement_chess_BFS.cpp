/**
@Shubham Sharma
Date:11/02/2017
*/

/**
------------------------------------------KNIGHT TOUR PROBLEM------------------------------------------------------------------
1. This is a knight tour problem to find if the knight can move on the chess board to the destination

2. The time complexity of this algorithm is O(n*n)

3. The space complexity is O(n*n)
*/

#include<bits/stdc++.h>
using namespace std;

/**
utility function to check if the coordinates are valid
*/
bool is_valid(const int x,const int y,const int n){
    if(x<0 || y<0 || x>=n || y>=n){
        return false;
    }
    return true;
}

/*
utility BFS routine to check if the knight can reach destination
*/
pair<bool,int> is_reachable(const int n,vector<vector<int>>& conf){
    
    pair<int,int> source=make_pair(0,0);
    pair<int,int> dest=make_pair(n-1,n-1);
    vector<vector<bool>> visited(n,vector<bool>(n,false));
    queue<pair<int,int>> Q;
    Q.push(source);
    int count=0;
    while(!Q.empty()){
        
        int level_count=Q.size();
        while(level_count--){
            pair<int,int> temp=Q.front();
            Q.pop();
            if(temp.first==dest.first && temp.second==dest.second){
                return make_pair(true,count);
            }
            visited[temp.first][temp.second]=true;
            for(int i=0;i<conf[0].size();++i){
                 int a=conf[0][i];
                 int b=conf[1][i]; 
                 int x=temp.first + a;
                 int y=temp.second+b;
                  if(is_valid(x,y,n) && (!visited[x][y])){
                    Q.push(make_pair(x,y));
                 }
            }
            
        }
        count++;
    }
    return make_pair(false,-1);
}

vector<vector<int>> get_same_vector(const int i){
    return {{i,i,i*-1,i*-1},{i,i*-1,i,i*-1}};
}

vector<vector<int>> get_diff_vector(const int i,const int j){
    return {{i, i, i*-1, i*-1, j, j, j*-1, j*-1},{j*-1, j, j, j*-1, i, i*-1, i, i*-1}};
}

void print_reaches(const int n){
    vector<vector<int>> result(n-1,vector<int>(n-1,0));
    
    for(int i=1;i<n;++i){
        for(int j=i;j<n;++j){
            vector<vector<int>> conf;
            if(i==j){
                conf=get_same_vector(i);
            }
            else{
                conf=get_diff_vector(i,j);
            }
            pair<bool,int> temp=is_reachable(n,conf);
            result[i-1][j-1]=(temp.first)?temp.second:-1;
        }
    }
    
    for(int i=1;i<result.size();++i){
        for(int j=0;j<i;++j){
            result[i][j]=result[j][i];
        }
    }
    
    for(int i=0;i<result.size();++i){
        for(int j=0;j<result[0].size();++j){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main(void){
    int n;
    cin>>n;
    print_reaches(n);
    return 0;
}
