/*
-By Shubham Sharma
-06-09-2016
*/

// the time complexity is O(logn + K);
//logn is for the binary search
// k is for the merging paradigm
// It is a bit different solution from the geeksforgeeks.org problem
// It includes the key match if the key occurs in the array
#include<iostream>
using namespace std;

/*
Binary search to find the floor of the crossover point
*/

int _binary_search(int *arr,int N,int key){
int l=0;
int r=N-1;
while(r-l>1){
int mid=l+(r-l)/2;    
if(arr[mid]<=key){
l=mid;    
}
else{
r=mid;    
}
}
 if(abs(arr[l+1]-key) < abs(key-arr[l])){
return l+1;    
}
else {
    return l;
}

}

/*
wrapper function to find the k closest elements in the array 
*/
void _k_closest_elements(int *arr,int N,int k,int key){
if(N==0){
    cout<<"The array is already empty!"<<endl;
    return ;
}
if(key<=arr[0]){
for(int i=0;i<k;++i){
    cout<<arr[i]<<" ";
}
cout<<endl;
return ;
}
if(key>=arr[N-1]){
    for(int i=N-1;i>N-1-k;i--){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return ;
}

int _crossover=_binary_search(arr,N,key);
int *result=new int[k];
result[0]=arr[_crossover];
int count=1;
int l=_crossover-1;
int r=_crossover+1;
while(count!=k && l>=0 && r<=N-1){//This function is just like the merge function of the merge sort .
if((abs(arr[l]-key) < abs(arr[r]-key))){//It takes O(K) timeto process this
result[count]=arr[l];
l--;
}
else{
result[count]=arr[r];
r++;
}
count++;
}
if(l<0){
while(count!=k){
result[count]=arr[r];
r++;
count++;
}    
}
if(r>N-1){
while(count!=k){
result[count]=arr[l];
l--;
count++;
}    
}

for(int i=0;i<k;++i){
    cout<<result[i]<<" ";
}
cout<<endl;
}


int main(void){
int arr[]={12, 16, 22, 30, 35, 39, 42,45, 48, 50, 53, 55, 56};
int N=sizeof(arr)/sizeof(arr[0]);
int k=4;
int key=52;
_k_closest_elements(arr,N,k,key);
    
return 0;    
}
