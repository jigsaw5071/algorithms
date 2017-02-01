/**
@Shubham Sharma
Date: 01/02/2017
*/

/*
--------------------------------------------BOX STACKING PROBLEM---------------------------------------------------

1. This is a variation of LIS Problem like building bridges , Chain Pairs Problem
2. The time complexity of this algorithm is O(n*n) but can be done in O(n logn)
3. Space complexity is O(n)
*/


#include<bits/stdc++.h>
using namespace std;


/*
utility function to print the resulting architecture of the stack boxes
*/
void print_stack_dimension(vector<pair<pair<pair<int,int>,int>,int>>& arr,vector<int>& parent,int i,int& max_height){
    if(i==-1){
        return;
    }
    max_height+=arr[i].first.second;
    
    print_stack_dimension(arr,parent,parent[i],max_height);
    cout<<arr[i].first.first.first<<" "<<arr[i].first.first.second<<" "<<arr[i].first.second<<endl;
}

/**
utility function for the maximum height of the stack
*/
void get_stack_height(vector<pair<pair<pair<int,int>,int>,int>>& arr){
    if(arr.size()==3){
        cout<<"The height is 1 and the dimensions are: "<<endl;
        cout<<arr[0].first.first.first<<" "<<arr[0].first.first.second<<" "<<arr[0].first.second<<endl;
        return;
    }
    sort(arr.begin(),arr.end(),[](pair<pair<pair<int,int>,int>,int>& x,pair<pair<pair<int,int>,int>,int>& y){
       return x.second<y.second; 
    });
    
    int n=arr.size();
    vector<int> dp(n,1),parent(n,-1);
    
    for(int i=1;i<n;++i){
        for(int j=0;j<i;++j){
            if(arr[i].first.first.first > arr[j].first.first.first && arr[i].first.first.second > arr[j].first.first.second){
                if(dp[i]<(dp[j]+1)){
                    dp[i]=1+dp[j];
                    parent[i]=j;
                }
            }
        }
    }
    
    int max_index=0;
    for(int i=1;i<n;++i){
        if(dp[i]>dp[max_index]){
            max_index=i;
        }
    }
    int max_height=0;
    cout<<"The resulting architecture is :"<<endl;
    print_stack_dimension(arr,parent,max_index,max_height);
    cout<<endl;
    cout<<"The maximum height is :"<<max_height<<endl;
}

int main(void){
    vector<vector<int>> V={ {4, 6, 7}, {1, 2, 3}, {4, 5, 6}};
    vector<pair<pair<pair<int,int>,int>,int>> arr;
    for(int i=0;i<V.size();++i){
        arr.push_back(make_pair(make_pair(make_pair(V[i][0],V[i][1]),V[i][2]),V[i][0]*V[i][1]));
        arr.push_back(make_pair(make_pair(make_pair(V[i][0],V[i][2]),V[i][1]),V[i][0]*V[i][2]));
        arr.push_back(make_pair(make_pair(make_pair(V[i][1],V[i][2]),V[i][0]),V[i][1]*V[i][2]));
    }
    get_stack_height(arr);
    return 0;
}
