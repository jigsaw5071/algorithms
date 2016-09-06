/*
-By Shubham Sharma
:06-09-2016
*/
#include<iostream>
#include<climits>
using namespace std;

//The timecomplexity of the above algorithm is O(n1+n2+n3)

/*
search common among three arrays
*/
void _search_common(int *arr1,int *arr2,int *arr3,const int m,const int n,const int p){
 if(m==0 || n==0 || p==0){
     return;//if any of the arrays is empty no point of common variable
 }
 int i=0;
 int j=0;
 int k=0;
 while(i<m && (j<n && k<p)){
 if(arr1[i]==arr2[j] && arr1[i]==arr3[k]){
     //case 1: when all the elements are same
     cout<<arr1[i]<<" ";
     i++;
     j++;
     k++;
 }
 else if(arr1[i]==arr2[j] || arr1[i]==arr3[k] || arr2[j]==arr3[k]){
     //case 2: when atmost only 2 elements are same
  if(arr1[i]==arr2[j]){
      if(arr1[i]<arr3[k]){
          i++;
          j++;
      }
      else{
          k++;
      }
  }
  else if(arr1[i]==arr3[k]){
      if(arr1[i]<arr2[j]){
          i++;
          k++;
      }
      else{
          j++;
      }
  }
  else{
      if(arr2[j]<arr1[i]){
          j++;
          k++;
      }
      else{
          i++;
      }
  }
 }
 else{
     //case 3: when none of the elements are the same
     if(arr1[i]>arr2[j] && arr1[i]>arr3[k]){
         j++;
         k++;
     }
     else if(arr2[j]>arr1[i] && arr2[j]>arr3[k]){
         i++;
         k++;
     }
     else{
         i++;
         j++;
     }
     
 }
 }
    
}

int main(void){
int arr1[]={1, 5, 10, 20, 40, 80};
int arr2[]={6, 7, 20, 80, 100};
int arr3[]={3, 4, 15, 20, 30, 70, 80, 120};
int m=sizeof(arr1)/sizeof(arr1[0]);
int n=sizeof(arr2)/sizeof(arr2[0]);
int p=sizeof(arr3)/sizeof(arr3[0]);
_search_common(arr1,arr2,arr3,m,n,p);
    
return 0;    
}
