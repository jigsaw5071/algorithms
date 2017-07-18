/**
author : Shubham Sharma 
Date : 18/07/2017
Ref : https://stackoverflow.com/questions/25811502/modify-saddleback-search-to-handle-duplicates

""What we think , we become"" - Buddha

*/

/**================================Saddle back search========================================

1. The input is a row wise and column wise sorted 2d array
2. The time complexity for search is O(R + C)
3. The space complexity is O(1)
*/

#include<iostream>
#include<vector>
using namespace std;


int main(void){
    vector< vector<int> > mat = { {10, 20, 30, 40},{15, 25, 35, 45},{27, 29, 37, 48},{32, 33, 39, 50}};
                      
    int x = 29;
    
    int R = mat.size(); int C = mat[0].size();
    
    int i = R-1; int j = 0;
    
    while(i >= 0  && j < C){
        
        if(mat[i][j] == x){
            cout <<"soln found at : "<<i<<" "<<j<<endl; break; 
        }
        
        if(mat[i][j] < x){
            j++;
        }
        else{
            i--;
        }
        
    }
    
                      
                      
                      
    return 0;
}
