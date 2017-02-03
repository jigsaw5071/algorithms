/*
Problem:http://www.practice.geeksforgeeks.org/problem-page.php?pid=700428
*/


/*You are required to complete below method */
int get_max(const int a,const int b){
    return a>b?a:b;
}

int get_min(const int a,const int b){
    return a<b?a:b;
}

int get_maximum_score(int A[],const int i,const int j,vector<vector<int>>& dp){
    if(i>j){
        return 0;
    }
    if(i==j){
        dp[i][j]=A[i];
        return dp[i][j];
    }
    if((i+1)==j){
        dp[i][j]=get_max(A[i],A[j]);
        return dp[i][j];
    }
    if(dp[i][j]>-1){
        return dp[i][j];
    }
    dp[i][j]=get_max(A[i] + get_min(get_maximum_score(A,i+2,j,dp),get_maximum_score(A,i+1,j-1,dp)),A[j]+get_min(get_maximum_score(A,i+1,j-1,dp),get_maximum_score(A,i,j-2,dp)));
    return dp[i][j];
}
int maxCoins(int A[],int N)
{
   //Your code here
   if(N==1){
       return A[0];
   }
   if(N==2){
       return get_max(A[0],A[1]);
   }
   vector<vector<int>> dp(N,vector<int>(N,-1));
   return get_maximum_score(A,0,N-1,dp);
}
