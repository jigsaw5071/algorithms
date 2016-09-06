/*
-By Shubham Sharma
:06-09-2016
*/

#include<bits/stdc++.h>
using namespace std;

// The time complexity is O(nlogn) and auxillary space O(n)

/*
utility functions to count the inversions while merging
*/

int _merge(vector<int> &V,const int l,const int mid,const int r){
int count=0;
int m=mid-l+1;
int n=r-mid;
int _left_temp[m];
int _right_temp[n];
for(int k=0;k<m;++k){
_left_temp[k]=V[l+k];    
}
for(int k=0;k<n;++k){
_right_temp[k]=V[mid+1+k];    
}
int i=0;
int j=0;
int k=l;
while(i!=m && j!=n){
if(_left_temp[i]<=_right_temp[j]){
    V[k]=_left_temp[i];
    i++;
    k++;
}
else{
    V[k]=_right_temp[j];
    count+=m-i;
    j++;
    k++;
}
}
while(i!=m){
V[k]=_left_temp[i];
i++;
k++;
}
while(j!=n){
V[k]=_right_temp[j];
j++;
k++;
}
return count;    
}


/*
Utility MergeSort Function to count the number of the inversions
*/
int _mergersort_inversions(vector<int> &V,const int l,const int r){
int inv_count=0;    
if(l<r){
int mid=l+(r-l)/2;
inv_count+=_mergersort_inversions(V,l,mid);
inv_count+=_mergersort_inversions(V,mid+1,r);
inv_count+=_merge(V,l,mid,r);
}
return inv_count;
}

int main(void){
int T;
cin>>T;
while(T--){
int M,S,N;
cin>>M>>S>>N;
vector<int> V(N);
for(int i=0;i<N;++i){
cin>>V[i];    
}
int _inversions=_mergersort_inversions(V,0,N-1);    
if((M - (_inversions*S)/60)>0 ){
    cout<<1<<endl;
}  
else{
    cout<<0<<endl;
}
}
return 0;    
}
