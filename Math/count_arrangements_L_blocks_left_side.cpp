#include<bits/stdc++.h>
using namespace std;



int doDFS(int id , int available , int N , int L , vector<int>& vis, vector<int>& temp, int c, int mx){
    //if(available > L)return 0;
    if(available == L && c == N){
        return 1;
    }
    int cnt = 0;
    vis[id] = true;
    for(int v = 1 ; v <= N ; ++v){
        if(v != id && vis[v] == false){
            temp.push_back(v);
            if(v > mx)cnt += doDFS(v , available + 1 , N , L , vis, temp, c + 1,v);
            else cnt += doDFS(v , available , N , L , vis,temp , c + 1,mx);
            temp.pop_back();
        }
    }
    vis[id] = false;
    return cnt;
}

int countByGraph(int N , int L){
    vector<int> vis(N + 1 , false);
    int ans = 0;
    for(int i = 1 ; i <= N ; ++i){
        vector<int> temp;
        temp.push_back(i);
        ans += doDFS(i , 1 , N , L , vis, temp,1,i);
        temp.pop_back();
    }
    return ans;
}

int countByDPUtil(int N , int L , vector<int>& F , vector<vector<int>>& memo){
    if(N < L)return 0;
    if(N == L)return 1;
    if(L == 1)return F[N - 1];
    if(memo[L][L] != -1)return memo[N][L];
    return memo[N][L] = (countByDPUtil(N - 1 , L - 1 , F , memo) + (N - 1) * countByDPUtil(N - 1 , L , F , memo));
}

int countByDP(int N , int L){
    vector<int> F(N + 1 , 1);
    for(int i = 1 ; i <= N ; ++i)F[i] = i * F[i - 1];
    vector<vector<int>> memo(N + 1 , vector<int>(L + 1 , -1));

    return countByDPUtil(N , L , F , memo);
}

int main(void){
    int N = 10 , L = 4;
    cout << countByGraph(N , L) << endl;
    cout << countByDP(N , L) << endl;
    return 0;
}
