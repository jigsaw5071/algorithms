#include<bits/stdc++.h>
using namespace std;
set<string> S;
void make_all_subsets_util(vector<int>& arr,const int n ,const int level,string str){
  
  if(level==n){
    S.insert(str);
    return;
    
  }
  make_all_subsets_util(arr,n,level+1,str+(char)(arr[level]+48));
  make_all_subsets_util(arr,n,level+1,str);
  
}


void make_all_subsets(vector<int>& arr,const int n){
  string str="";
  make_all_subsets_util(arr,n,0,str);
  for(string str:S){
    cout<<"(";
    if(str==""){
      cout<<")";
    }
    else{
      for(int i=0;i<str.length()-1;++i){
        cout<<str[i]<<" ";
      }
      cout<<str[str.length()-1]<<")";
    }
  }
}

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T;
  cin>>T;
  while(T--){
    S.clear();
    int n;
    cin>>n;
    vector<int> h(10,0);
    for(int i=0;i<n;++i){
      int x;
      cin>>x;
      h[x]++;
    }
    vector<int> arr;
    for(int i=0;i<10;++i){
      if(h[i]==0){continue;}
      for(int j=0;j<h[i];++j){
        arr.push_back(i);
      }
    }
    make_all_subsets(arr,n);
    cout<<endl;
  }
  return 0;
}
