#include<bits/stdc++.h>
using namespace std;

int getViewRight(vector<int>& vec){
    int n = vec.size() ,  cnt = 1 , mx = vec[n - 1];
    for(int i = n - 2 ; i >= 0 ; --i){
        if(vec[i] > mx)cnt++;
        mx = max(mx , vec[i]);
    }
    return cnt;
}

int doDFS(int id , int available , int N , int L , int R, vector<int>& vis, vector<int>& temp, int c, int mx){
    if(available > L)return 0;
    if(available == L && c == N && getViewRight(temp) == R){
        return 1;
    }
    int cnt = 0;
    vis[id] = true;
    for(int v = 1 ; v <= N ; ++v){
        if(v != id && vis[v] == false){
            temp.push_back(v);
            if(v > mx)cnt += doDFS(v , available + 1 , N , L ,R, vis, temp, c + 1,v);
            else cnt += doDFS(v , available , N , L ,R, vis,temp , c + 1,mx);
            temp.pop_back();
        }
    }
    vis[id] = false;
    return cnt;
}

int countByGraph(int N , int L , int R){
    vector<int> vis(N + 1 , false);
    int ans = 0;
    for(int i = 1 ; i <= N ; ++i){
        vector<int> temp;
        temp.push_back(i);
        ans += doDFS(i , 1 , N , L , R ,vis, temp,1,i);
        temp.pop_back();
    }
    return ans;
}

int memo[50][50];

int fact(int n){
    int ans = 1;
    for(int i = 2 ; i <= n ; ++i)ans *= i;
    return ans;
}

int countByDPUtil(int N , int L ,  vector<vector<int>>& F){
    if(N < L || N < 0)return 0;
    if(N == L)return 1;
    if(L == 1)return fact(N - 1);
    if(memo[N][L] != -1)return memo[N][L];
    return memo[N][L] = (countByDPUtil(N - 1 , L - 1 , F ) + (N - 1) * countByDPUtil(N - 1 , L , F ));
}

int countByDP(int N , int L , int R){
    vector<vector<int>> F(N + 1 , vector<int>(N + 1 , 0));
    for(int i = 0 ; i <= N ; ++i){
        for(int j = 0 ; j <= i ; ++j){
            if(i == 0 || i == j)F[i][j] = 1;
            else F[i][j] = F[i - 1][j] + F[i - 1][j - 1];
        }
    }
    for(int i = 0 ; i <= N ; ++i){
        for(int j = 0 ; j <= L ; ++j){
            memo[i][j] = -1;
        }
    }
    int ans = 0;
    for(int k = 1 ; k <= N ; ++k){
        if(N >= k){
            //cout << N << ": " << k << ":: " << F[N - 1][k - 1] << endl;
            ans += F[N - 1][k - 1] * countByDPUtil(k - 1 , L - 1,F)  * countByDPUtil(N - k , R - 1,F);
            }
    }
    return ans;
}

int main(void){
    int N = 10 , L = 4 , R = 5;
    cout << countByGraph(N , L , R) << endl;
    cout << countByDP(N , L , R) << endl;
    return 0;
}
