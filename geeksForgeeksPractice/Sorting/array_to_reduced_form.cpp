/*
-By Shubham Sharma
:06-06-2016
*/
#include<bits/stdc++.h>
using namespace std;

/*
counting sort function to get the place of the value
*/
void _counting_sort(vector<int> &V){
    int N=V.size();
    int _max=V[0];
    for(int i=1;i<N;++i){
        _max=(V[i]>_max)?V[i]:_max;
    }
    vector<int> count(_max+1,0);
    vector<int> _output(N);
    for(int i=0;i<N;++i){
        count[V[i]]++;
    }
    for(int i=1;i<=_max;++i){
        count[i]+=count[i-1];
    }
    for(int i=0;i<N;++i){
     _output[i]=count[V[i]]-1;
     count[V[i]]--;
    }
    for(int i=0;i<N;++i){
     cout<<_output[i]<<" ";   
    }
    cout<<endl;
    
}

int main(void){
int T;
cin>>T;
while(T--){
int N;
cin>>N;
vector<int> V(N);
for(int i=0;i<N;++i){
    cin>>V[i];
}
_counting_sort(V);
    
    
}
    
return 0;    
}
