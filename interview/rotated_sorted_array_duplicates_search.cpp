/**
author : Shubham Sharma
Ref : https://leetcode.com/problems/search-in-rotated-sorted-array-ii/discuss/
*/

/** 
Search in a rotated sorted array with duplicates
*/
#include<iostream>
#include<vector>
using namespace std;

bool search(vector<int>& nums , const int target){
  if(nums.size() == 0)return false;
  int l = nums[0] , r = nums.size() - 1;
  while(l < r){
    int mid = l + (r - l)/2;
    if(nums[mid] == target)return true;
    if(nums[l] == nums[mid]){l++;}
    else if(nums[l] < nums[mid]){
      if(target >= nums[l] && target <= nums[mid]){
        r = mid - 1;
      }
      else{
        l = mid + 1;
      }
    }
    else{
      if(target >= nums[mid] && target <= nums[r]){
        l = mid + 1;
      }
      else{
        r = mid - 1;
      }
    }
  }
  return nums[l] == target;
}

int main(void){
  vector<int> nums = {4 , 4 ,1 , 2 , 2 , 3 , 3 , 4};
  cout << search(nums , 5);
}
