#include<bits/stdc++.h>
using namespace std;

int BIT[20004];
int arr[20004];

void init_start(const int n){
  for(int i=0;i<=n;i++){BIT[i]=0;}
}

void update(int idx,const int val,const int MAX){
  for(;idx<=MAX;idx+=(idx & -idx)){BIT[idx]+=val;}
}

int query(int idx){
  int sum=0;
  for(;idx>0;idx-=(idx & -idx)){sum+=BIT[idx];}
  return sum;
}

int main(void){
  cin.tie(NULL);ios_base::sync_with_stdio(false);
  int T;cin>>T;
  while(T--){
    int n;
    cin>>n;
    init_start(n);
    for(int i=1;i<=n;i++){update(i,1,n);}
    int count_left=n;
    int L=1;
    for(int i=1;i<=n;++i){
      L=(L+i)%count_left;
      if(L==0){L=count_left;}
      int l=1;
      int r=n;
      while(l<=r){
        int mid=l+((r-l)>>1);
        if(query(mid)>=L){
          r=mid-1;
        }
        else{
          l=mid+1;
        }
      }
      arr[l]=i;
      update(l,-1,n);
      count_left--;
    }
    for(int i=1;i<=n;i++){cout<<arr[i]<<" ";}
    cout<<endl;
  }
  return 0;
}
