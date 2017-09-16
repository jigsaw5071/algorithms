/**
 * author : Shubham Sharma
 * Date : 16 - 09 - 2017
 * Ref : https://leetcode.com/problems/find-all-duplicates-in-an-array/description/
 *      "We are only limited by our thinking."
*/

/**
=> This problem discusses a very interesting approach  regarding the array manipulation and coming up with some non-rudimentary
solutions.
=> Important observations from question :
   x. 1 ≤ a[i] ≤ n (n = size of array)
   x.some elements appear twice and others appear once.
   x.Could you do it without extra space and in O(n) runtime?
   
=> Yes Indeed we can do it in constant auxillary memory. We can think that it takes to transform the array to a modified array
such that every element is at its right place in sorted array , i.e. , nums[i] = nums[nums[i] - 1] or 4 == nums[3]

=> This process can be done in linear time and check on the remaining array which elements are not at their right place.
*/
#include<bits/stdc++.h>
using namespace std;

int main(void){
  vector<int> nums = {4,3,2,7,8,2,3,1};
  
  for(int i = 0; i < nums.size(); ){
    if(nums[i] != nums[nums[i] - 1]){
      swap(nums[i] , nums[nums[i] - 1]);
    }
    else{
      i++;
    }
  }
  
  for(int i = 0; i < nums.size(); ++i){
    if(nums[i] != i + 1){
      cout << nums[i] <<" ";
    }
  }
  
  return 0;
}
