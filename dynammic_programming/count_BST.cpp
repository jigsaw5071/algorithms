/**
@Shubham Sharma
Date:08/03/2017
Ref: Tushar Roy
*/

/*---------------COUNT NUMBER OF UNIQUE BSTs--------------------------------

1. This is one of the best applications of the catalan numbers.
2. The time complexity is O(n*n) but optimized binomial theorem can also be used 
whose time complexity is O(n)
3. Space complexity is O(n) but space optimized binomial coefficient paradigm 
can also be used whose space complexity is O(1)

4. Ref for optimized binomial coefficient:
https://github.com/jigsaw5071/algorithms/blob/master/Math/efficient_linear_time_binomial)coefficient.cpp

*/

#include<bits/stdc++.h>
using namespace std;

int get_count_binary_search_tree(vector<int>& arr){
    int n=arr.size();
    if(n==0 || n==1){
        return 1;
    }
    
    vector<int> dp(n+1,0);
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;++i){
        for(int j=0;j<i;++j){
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
    return dp[n];
}

int main(void){
    vector<int> arr={1,2,3,4};
    cout<<get_count_binary_search_tree(arr)<<endl;
    return 0;
}

