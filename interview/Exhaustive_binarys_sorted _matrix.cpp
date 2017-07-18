/**
author : Shubham Sharma 
Date : 18/07/2017
Ref : https://stackoverflow.com/questions/25811502/modify-saddleback-search-to-handle-duplicates

""What we think , we become"" - Buddha

*/

/**================================Ordered statistics in row wise and column wise sorted matrix========================================

1. The input is a row wise and column wise sorted 2d array
2. The time complexity for search is O(32 R logC)
3. The space complexity is O(1)
4. The algorithm used is exhaustive binary search
*/

#include<bits/stdc++.h>
using namespace std;

int main(void){
    
    vector<vector<int>> mat = { {10, 20, 30, 40},
                      {15, 25, 35, 45},
                      {27, 29, 37, 48},
                      {32, 33, 39, 50}};
                      
    int k = 1;int R = mat.size(); int C = mat[0].size();
    assert(k >= 0  && k < R*C);
    
    int l = mat[0][0]; int r = mat[R-1][C-1];
    
    while(l < r){
        int mid = l + (r-l)/2;
        
        int cnt = 0;
        for(int i = 0; i< R;++i){
            cnt += upper_bound(mat[i].begin(),mat[i].end(),mid) - mat[i].begin();
        }
        
        if(cnt < (k)){
            l = mid+1;
        }
        else{
            r = mid;
        }
        
    }
    
    cout<< r<<endl;
     
    
    return 0;
}
