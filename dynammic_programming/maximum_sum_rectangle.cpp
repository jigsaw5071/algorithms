/*
@Shubham Sharma
Date: 27/02/2017
*/
/*-------------------------------Largest Sum Rectangle in a given matrix-----------------------------------

1. It is one of the best and most useful application of the kadane algorithm
2. It maintains a temporary array on which the kadane algorithm is applied

3. The time complexity is O(row*col*col)
4. The space complexity is O(row)
*/

#include<bits/stdc++.h>
using namespace std;


/**
utility function for the kadane implementation
*/
pair<pair<int,int>,int> get_kadane_details(vector<int>& arr){
    int start=0;
    int end=0;
    int overall_start=0;
    int current_max=arr[0];
    int overall_max=arr[0];
    for(int i=1;i<arr.size();++i){
        if(arr[i]>=arr[i]+current_max){
            start=i;
            current_max=arr[i];
        }
        else{
            current_max=current_max+arr[i];
            
        }
        if(current_max>=overall_max){
            end=i;
            overall_start=start;
            overall_max=current_max;
        }
    }
    return make_pair(make_pair(overall_start,end),overall_max);
}

void build_maximum_sum_subrectangle(vector<vector<int>>& arr){
    int row=arr.size();
    int col=arr[0].size();
    int result=INT_MIN;
    int max_up;
    int max_down;
    int max_left;
    int max_right;
    for(int L=0;L<col;++L){
        vector<int> dp(row,0);
        for(int R=L;R<col;++R){
            for(int i=0;i<row;++i){
                dp[i]+=arr[i][R];
            }
            pair<pair<int,int>,int> temp=get_kadane_details(dp);
            if(temp.second>result){
               max_up=temp.first.first;
               max_down=temp.first.second;
               result=temp.second;
               max_left=L;
               max_right=R;
            }
        }
    }
    
    cout<<"The sum of the maximum rectangle is "<<result<<endl;
    cout<<"The x coordinates arr: "<<max_left<<" "<<max_right<<endl;
    cout<<"The y coordinates are: "<<max_up<<" "<<max_down<<endl;
}

int main(void){
    vector<vector<int>> arr={{ 2,  1, -3, -4,  5},
                         { 0,  6,  -33,  4,  1},
                         { 2, -2, -1,  4, -5},
                         {-3,  3,  1,  0,  3}};
    build_maximum_sum_subrectangle(arr);                     
    return 0;
}
