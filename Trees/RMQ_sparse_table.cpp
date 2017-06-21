/**
author : Shubham Sharma
Date:22/06/2017
Ref:https://www.youtube.com/watch?v=c5O7E_PDO4U

"" What we think we become - Buddha ""

*/

/**==================================SPARSE TABLE =========================================
 1. This data structure is mainly for the purpose of Range queries.
    Precomputation Time : O(NlogN)
    QueryTime: O(1)
    Space Time complexity: O(N logN)
 */
 
 
 #include<iostream>
 #include<cmath>
 using namespace std;
 
 #define M 1000
 

 int sparse[M][M];

void preprocess(int* arr,const int n){
  for(int i = 0;i<n;++i){
    sparse[i][0] = i;
  }
  
  for(int j = 1;(1<<j) <=n ;++j){
    
    for(int i = 0; (i+ (1<<j) -1) < n;++i){
      if(arr[sparse[i][j-1]] <= arr[sparse[i+(1<<(j-1))][j-1]]){
        sparse[i][j] = sparse[i][j-1];
      }
      else{
        sparse[i][j] = sparse[i+(1<<(j-1))][j-1];
      }
    }
    
  }
  
}
int gmin(const int a,const int b){return a<b?a:b;}

int q(int* arr,const int l,const int r){
  int le = r-l+1;
  int k = log2(le);
  return gmin(arr[sparse[l][k]],arr[sparse[l+le-(1<<k)][k]]);
}
 
 int main(void){
  int arr[] = {4,6,1,5,7,3};
  
  int n = sizeof(arr)/sizeof(arr[0]);
  preprocess(arr,n);
  cout<<q(arr,0,1); 
   
   return 0;
 }
