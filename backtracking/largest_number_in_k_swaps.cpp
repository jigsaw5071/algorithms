#include<bits/stdc++.h>
using namespace std;
string result;

void swap(string& str,const int i,const int j){
  char temp=str[i];
  str[i]=str[j];
  str[j]=temp;
}

void make_largest_number_util(string str,const int k){
  int n=str.size();
  if(k==0){
    return;
  }
  for(int i=0;i<n;i++){
    for(int j=i+1;j<n;++j){
      if(str[j]>str[i]){
        swap(str,i,j);
        if(str>result){
          result=str;
        }
        make_largest_number_util(str,k-1);
        swap(str,i,j);
      }
    }
  }
}

void make_largest_number(string& str,const int k){
 make_largest_number_util(str,k);
}

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T;
  cin>>T;
  while(T--){
    int k;
    cin>>k;
    string str;
    cin>>str;
    result=str;
    make_largest_number(str,k);
    cout<<result<<endl;
  }
  
  return 0;
}
