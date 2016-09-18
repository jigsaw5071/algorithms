/*
-By Shubham Sharma
:17-09-2016

*/

/*
This is an optimized version of the Longest Increasing Subsequence
1. In worst case
Eg arr= {1,20,19,18,22,28,42,12,26}
T(n)<= log 1 + log 2 + log 3 +log 4 + log 4 +log 5.........log n
T(n)< log n! (fairly less then)
T(n) < nlogn

In The space complexity analysis , the auxillary space required by temp array and the parent array .
so it is O(n)

The crux of this solution is that instead of storing the direct array values in the temp array we indeed store 
the indexes of these elements in the temp array and further these indexes help us to fill
the parent array which is used for printing the required sequence.
*/

#include<bits/stdc++.h>
using namespace std;

/*
utility function to print the LIS
*/
void _print_LIS(vector<int>& _parent,int *arr,int n){
    if(n==-1){return ;}
    _print_LIS(_parent,arr,_parent[n]);
    cout<<arr[n]<<" ";
}
/*
utility function to find the ceil index through binary search
*/
int _get_ceil_index(vector<int>& temp,const int len,const int key,int *arr){
    int l=0;
    int r=len;
    while(r-l>1){
        int mid=l+(r-l)/2;
        if(arr[temp[mid]]>=key){
            r=mid;
        }
        else{
            l=mid;
        }
    }
    return r;

}

/*
utility function for the optimized lis
*/
void _optimized_LIS(int *arr,const int n){
  if(n==0){return ;}
  vector<int> _temp(n,0);
  vector<int> _parent(n,-1);
  _temp[0]=0;
  int len=1;
  for(int i=1;i<n;++i){
      if(arr[i]<arr[_temp[0]]){
          _temp[0]=i;
          _parent[i]=-1;// it is the smallest element and thus its parent is -1
      }
      else if(arr[i]>arr[_temp[len-1]]){
          _temp[len]=i;
          _parent[i]=_temp[len-1]; // it is the largest element and its parent is one element before the insertion
          len++;
      }
      else {
          int _ceil_index=_get_ceil_index(_temp,len-1,arr[i],arr);
          _temp[_ceil_index]=i;
          _parent[i]=_temp[_ceil_index-1];// this step should not be _parent[i]=_parent[_temp[_ceil_index]] as both might be representing 
          //different sequences and hence they may have different parents

      }
  }
  cout<<"The length of the longest common subsequence is "<<len<<endl;
 cout << "The actual subsequence is :"<<endl;
 _print_LIS(_parent,arr,_temp[len-1]);

}
int main(void){
int arr[]={3, 4, -1, 5, 8, 2,3,12,7,9,10};
int n=sizeof(arr)/sizeof(arr[0]);
_optimized_LIS(arr,n);
return 0;
}
