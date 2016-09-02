#include<iostream>
#include<bits/stdc++.h>
using namespace std;


void bucketSort(float *arr,const int N){
vector<vector<float>> V(N);
for(int i=0;i<N;++i){
int bi = N*arr[i];
V[bi].push_back(arr[i]);
}
for(int i=0;i<N;++i){
sort(V[i].begin(),V[i].end());
}

int index=0;
for(int i=0;i<N;++i){
vector<float> L=V[i];
for(vector<float>::iterator iter=L.begin();iter!=L.end();++iter){
arr[index]=*iter;
index++;
}

}

}


int main(void){
float arr[]={0.897, 0.565, 0.656, 0.1234, 0.665, 0.3434,0.214,0.314,0.957,0.289};
int N=sizeof(arr)/sizeof(arr[0]);
bucketSort(arr,N);
for(int i=0;i<N;++i){
cout<<arr[i]<<" ";
}
return 0;
}
