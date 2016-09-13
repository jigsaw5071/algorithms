/*
-By Shubham Sharma
:13-09-2016
:reference- MIT OCW
*/

// This is developed by best mathematicians-floyd,pratt,rivest,etc
// It's worst case time complexity is O(n)
// However the constsnt c involved in O() notations is quite large 
// and it is also not in place
// So it is not used for the practical purposes
// So for the practical purposes Randomized quickselect is used whose expexted time 
// complexity is o(n)

#include<iostream>
#include<algorithm>
#include<climits>
using namespace std;

 

/*Utility
function to swap
*/
void _swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
/*
utility function for the parttion
*/
int _partition(int *arr,int l,int r,const int _med_of_med){
    int _pivot_index=r;
    for(int i=l;i<r;++i){
        if(arr[i]==_med_of_med){
            _pivot_index=i;
            break;
        }
    }
    _swap(&arr[_pivot_index],&arr[r]);
    _pivot_index=r;
 int _pivot=arr[_pivot_index];
    int pIndex=l;
    int i=l;
    
    while(i!=_pivot_index){
        if(arr[i]<=_pivot){
            _swap(&arr[i],&arr[pIndex]);
            pIndex++;
        }
        i++;
    }
    _swap(&arr[pIndex],&arr[_pivot_index]);
    return pIndex;
}

/*
Utility function to find the median of 5 and less elements
*/
int _get_median(int *arr,const int n){
 sort(arr, arr+n);  // Sort the array
    return arr[n/2];
}
/*
Worst case linear time kth smallest time algorithm function
*/
int _k_order_statistic(int *arr,int l,int r,int k){
    if(k>0 && k<=(r-l+1)){
     int n=r-l+1;
     int _median[(n+4)/5];
     int i=0;
     for(i=0;i<(n/5);++i){
         _median[i]=_get_median(arr+l+5*i,5);
     }
     if(i*5 <n){
         _median[i]=_get_median(arr+l+5*i,n%5);
         i++;
     }
     
    int _median_of_median=(i==1)?_median[i-1]:_k_order_statistic(_median,0,i-1,i/2);
     
     int pIndex=_partition(arr,l,r,_median_of_median);
     if(pIndex-l == k-1){
         return arr[pIndex];
     }
     else if(pIndex-l > k-1){
         return _k_order_statistic(arr,l,pIndex-1,k);
     }
     else{
         return _k_order_statistic(arr,pIndex+1,r,k-(pIndex-l+1));
     }
        
    }
    return INT_MAX;
}

int main(void){
int arr[]={12, 3, 5, 7, 4, 19, 26};
int n=sizeof(arr)/sizeof(arr[0]);
int k=4;
cout<<"The "<<k<<" smallest element is : "<<endl;
cout<<_k_order_statistic(arr,0,n-1,k);
    
return 0;    
}
