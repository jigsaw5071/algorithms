/*
author : Shubham Sharma
Date : 26/07/2017
*/

/* ======= Search for the target range in sorted array =======

*/

#include<bits/stdc++.h>
using namespace std;

int start_index(vector<int>& arr,const int key){
  int n = arr.size(); if(n == 0)return -1;
  if(key < arr[0] || key > arr[n-1]) return -1;
  
  int l = 0, r = n-1;
  while(l < r){
    int mid = l + (r-l)/2;
    if(arr[mid] < key){
      l = mid + 1;
    }
    else{
      r = mid;
    }
  }
  if(arr[l]  == key) return l;
  return -1;
}

int end_index(vector<int>& arr,const int key){
 int n = arr.size(); if(n == 0)return -1;
 if(key < arr[0] || key > arr[n-1]) return -1;
  
  int l = 0, r = n-1;
  while(l < r){
    int mid = l + (r- l)/2 + 1;
    if(arr[mid] > key){
      r = mid - 1;
    }
    else{
      l = mid;
    }
  }
  if(arr[r] == key) return r;
  return -1;
}

vector<int> search_Range(vector<int>& arr,const int target){
  return {start_index(arr,target),end_index(arr,target)};
}

int main(void){
  vector<int> arr = {5,7,7,8,8,10};
  int target = 8;
  vector<int> range = search_Range(arr,target);
  cout<<range[0]<<" "<<range[1]<<endl;
  return 0;
}
