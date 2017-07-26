/**
author : Shubham Sharma
Date : 26/07/2017
Ref : https://leetcode.com/problems/combination-sum/#/description
*/

/*============= Combination Sum : same element can be used infinitesimally ========================================
===> but the same solution must not be used again and again
*/

#include<bits/stdc++.h>
using namespace std;

void combinationSumUtil(vector<int>& arr,const int l,const int target,vector<int>& temp,vector<vector<int>>& res){
  
  if(target == 0){
    res.push_back(temp);return;
  }
  
  for(int i =l; i<arr.size(); ++i){
    if(target >= arr[i]){
      temp.push_back(arr[i]);
      combinationSumUtil(arr,i,target - arr[i],temp,res);
      temp.pop_back();
    }
  }
  
}

vector<vector<int>> combinationSum(vector<int>& arr,const int target){
  vector<vector<int>> res;
  set<int> S; for(int num : arr) S.insert(num);
  
  arr.clear(); copy(S.begin(),S.end(),back_inserter(arr));
  
  int l = 0;
  vector<int> temp;
  combinationSumUtil(arr,l,target,temp,res);
  
  return res;
}

int main(void){
  vector<int> arr = {2,2,5,6,3,7,1}; 
  int target = 7;
  
  vector<vector<int>> res = combinationSum(arr,target);
  for(int i = 0; i < res.size(); ++i){
    for(int j = 0; j < res[i].size();++j){
      cout<<res[i][j]<<" ";
    }
    cout<<endl;
  }
  
  return 0;
}
