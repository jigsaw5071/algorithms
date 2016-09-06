/*
-By Shubham Sharma
:06-06-2016
*/
#include<bits/stdc++.h>
using namespace std;
//Worst case time complexity is O(n*n)+O(nlogn)

/*
wrapper function for the triplet sum
*/
int _triplet_sum(vector<int> &V,const int N,const int key){
sort(V.begin(),V.end());//This algorithm takes O(nlogn) in worst case
int result=0;
for(int i=0;i<N;++i){
int _sum=key-V[i];
int j=0;
int k=N-1;
while(j<k){
    if(j==i){j++;}
    if(k==i){k--;}
    if(V[j]+V[k]==_sum){
        result=1;
        break;
    }
    else if(V[j]+V[k] > _sum){
        k--;
    }
    else{
        j++;
    }
}
}
    return result;
}

int main(void){
int T;
cin>>T;
while(T--){
int N,key;
cin>>N>>key;
vector<int> V(N);
for(int i=0;i<N;++i){
cin>>V[i];    
}
cout<<_triplet_sum(V,N,key)<<endl;
}
return 0;    
}
