#include<iostream>
using namespace std;
int result;

int get_sqrt(const int n){
  if(n<=1){
    return n;
  }
  if(n<=3){return 1;}
  int p=1;
  while(p*p <=n){p++;}
  return (p-1);
}

int get_abs(const int a){
  return (a<0)?(-1*a):(a);
}

int get_min(const int a,const int b){
  return a<b?a:b;
}

int get_row(const int n){
  int s=get_sqrt(2*n);
  int temp=((s+1)*s)/2;
  if(temp>=n){
    return s;
  }
  return s+1;
}



void make_minimum_path(const int a,const int b){
  if(a==b){
    result=0;
    return;
  }
  int rowA=get_row(a);
  int rowB=get_row(b);
  if(rowA==rowB){
    result=get_abs(a-b);
    return;
  }
  int colA=a-((rowA)*(rowA-1))/2;
  int colB=b-(rowB*(rowB-1))/2;
  if(colA==colB){
    result=get_abs(rowB-rowA);
    return;
  }
  int size=rowB - rowA +1;
  int left[size];
  int right[size];
  left[0]=a;
  right[0]=a;
  int r=rowA;
  for(int i=1;i<size;++i,++r){
    left[i]=left[i-1]+r;
    right[i]=right[i-1]+r+1;
  }
  
  if(b>=right[size-1]){
    result=rowB-rowA + b-right[size-1];
  }
  else if(b<=left[size-1]){
    result=rowB-rowA + left[size-1] -b;
  }
  else{
    result=rowB-rowA;
  }
  
  
}

int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  int T;
  cin>>T;
  for(int t=1;t<=T;++t){
    result=50000;
    int a,b;
    cin>>a>>b;
    if(a>b){
     int temp=a;
     a=b;
     b=temp;
    }
    make_minimum_path(a,b);
    cout<<"#"<<t<<" ";
    cout<<result<<endl;
  }
  return 0;
}
