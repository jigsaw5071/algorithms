/**
 Travelling salesman Problem using dp bit masking optimization

==> Travelling saleman problem can be summrized as finding the minimum weight hamiltonian 
circuit in the graph
*/
#include<bits/stdc++.h>
using namespace std;

int N = 4;
int dist[10][10] ={
    {0,20,42,25},
    {20,0,30,34},
    {42,30,0,10},
    {25,34,10,0}
}; 
int vis_all = (1 << N) - 1;
int dp[16][4];

int tsp(int mask, int pos){
    if(mask == vis_all)return dist[pos][0];
    if(dp[mask][pos] != -1)return dp[mask][pos];
    int ans = INT_MAX;
    for(int city = 0 ; city < N ; ++city){
        if(((1 << city) & mask) == 0){
            ans = min(ans , dist[pos][city] + tsp(mask | (1 << city),city));
        }
    }
    return dp[mask][pos] = ans;
}

int main(void){
    for(int i = 0, j = (1 << N) ; i < j ; ++i){
        for(int k = 0 ; k < N ; ++k)dp[i][k] = -1;
    }
    cout << tsp(1,0);
    return 0;
}
