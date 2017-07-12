/**
author : Shubham Sharma
Date : 12/07/2017
Ref : http://codeforces.com/blog/entry/14518
*/

/**===============Range Update and GCD queries=====================================
 * 1. It utilises the fact that GCD(a,b) = GCD(a,a-b)
 * 2. Therefore, GCD(a1,a2,......an) = GCD(a1,a2-a1,a3-a2,...........,an - a(n-1))
 * 3. Therefore we use BIT for range updates on the number
 * 4. We keep a segment tree for the adjacent differences

 Time complexity for each update : log(n) in BIT and 2 operations in SEG_TREE log(n)
 Time complexity for query : O(2 * logn) logn for BIT AND logn for SEG_TREE

*/

#include<iostream>
using namespace std;

typedef long long ll;

#define MAXN 100005

struct Node{
  int idl;
  int idr;
  ll val;
};

struct Node SEG_TREE[4*MAXN];
ll BIT[MAXN];
int arr[MAXN];

ll gabs(const ll a){
  
  return (a >= 0)? a : -1*a;
}

ll gcd(const ll a,const ll b){
  if(a == 0)return b;
  return gcd(b%a,a);
}

void init_BIT(const int N){
  for(int i = 0; i<=N;++i){
    BIT[i] = 0;
  }
}

void BIT_update(int idx, const ll val,const int N){
  while(idx <= N){
    BIT[idx] += val;
    idx += (idx & -idx);
  }
}

void BIT_range_update(const int l,const int r,const ll val,const int N){
  BIT_update(l,val,N);
  BIT_update(r+1,-1*val,N);
}

ll BIT_query(int idx){
  ll  sum = 0;
  while(idx > 0){
    sum += BIT[idx];
    idx -= (idx & -idx);
  }
  return sum;
}


void build_segtree(const int l,const int r,const int pos){
  if(l == r){
    SEG_TREE[pos].idl = l;
    SEG_TREE[pos].idr = l+1;
    SEG_TREE[pos].val = gabs(arr[l+1] - arr[l]); 
    return;
  }
  
  int mid = l + (r-l)/2;
  build_segtree(l,mid,2*pos);
  build_segtree(mid+1,r,2*pos+1);
  SEG_TREE[pos].idl = SEG_TREE[2*pos].idl;
  SEG_TREE[pos].idr = SEG_TREE[2*pos+1].idr;
  SEG_TREE[pos].val = gcd(SEG_TREE[2*pos].val,SEG_TREE[2*pos+1].val);
}

ll seg_query(const int ql ,const int qr,const int pos){
  
  int l = SEG_TREE[pos].idl;
  int r = SEG_TREE[pos].idr;
  
  if(ql > r || qr < l) return 0;
  
  if(ql <= l && qr >= r){
    return SEG_TREE[pos].val;
  }
  
  int mid = l + (r-l)/2;
  return gcd(seg_query(ql,qr,2*pos),seg_query(ql,qr,2*pos+1));
  
}

ll gcd_query(const int ql,const int qr){
  return gcd(BIT_query(ql),seg_query(ql,qr,1));
}


void update_segTree(const int i,const int l,const int r,const ll val,const int pos){
  
  if(l > r || i < l || i > r) return;
  
  if(l == r){
    SEG_TREE[pos].val = val; return;
  }
  
  int mid = l+(r-l)/2;
  
  if(i <= mid){
    update_segTree(i,l,mid,val,2*pos);
  }
  else{
    update_segTree(i,mid+1,r,val,2*pos+1);
  }
  SEG_TREE[pos].val = gcd(SEG_TREE[2*pos].val,SEG_TREE[2*pos+1].val);
  
}

int main(void){

  int T; cin >> T;
  
  for(int t = 1; t <= T; ++ t){
     int n,m; cin >> n >> m;
     init_BIT(n);
     for(int i = 1; i<=n;++i){
       cin >> arr[i];
       BIT_range_update(i,i,arr[i],n);
     }
     build_segtree(1,n-1,1);
     
     /*
     There are m queries of type 1 and 2
     Type 1: 1 L R C  update all elements from L to R with addition to C
     Type 2: 2 L R return GCD of all elements from L to R
     */
     for(int q = 1; q<=m; ++q){
       
       int type; cin >> type;
       if(type == 1){
         ll ql,qr,c; cin >> ql >> qr >> c;
         BIT_range_update(ql,qr,c,n);
         if(ql > 1 && ql < n){
           ql--;
           ll val = gabs(BIT_query(ql+1)  - BIT_query(ql));
           update_segTree(ql,1,n-1,val,1);
         }
         
         if(qr < n){
           ll val = gabs(BIT_query(qr+1)  - BIT_query(qr));
           update_segTree(qr,1,n-1,val,1);
         }
       }
       else{
         int ql,qr;cin >> ql >> qr;
         cout<<"GCD is : "<<gcd_query(ql,qr)<<endl;
       }
       
     }
     
     
  }
  return 0;
}
