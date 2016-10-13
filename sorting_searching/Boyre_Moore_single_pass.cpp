/*
-Shubham Sharma
:13-10-2016
*/
/*
reference:https://en.wikipedia.org/wiki/Boyer%E2%80%93Moore_majority_vote_algorithm

This is the Boyre And Moore Algorithm for finding the majority element
in the sequence  in constant space

majority element is the element that occurs for more than floor(n/2) times
in an array

Time Complexity: O(n)
space Complexity:O(1)
*/
#include<bits/stdc++.h>
using namespace std;

int _majority_element(int *arr,const int n){
    int _current_major=0;
    int _count=0;
    for(int i=0;i<n;++i){
        if(_count==0){
            _current_major=arr[i];
            _count=1;
        }
        else{
            if(_current_major=arr[i]){
                _count++;
            }
            else{
                _count--;
            }
        }
    }
    return _current_major;
}

int main(void){
    int arr[]={-1,1,1,1,2,1};
    int n=sizeof(arr)/sizeof(arr[0]);
    cout<<_majority_element(arr,n);
    return 0;
}
