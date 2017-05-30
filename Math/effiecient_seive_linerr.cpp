/**
author : Shubham Sharma
Ref: http://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/,
https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/tutorial/

"Hard work beats talent when talent fails to work hard"
*/

/**===============MODIFIED SEIVE ===============================================================
 * 1. This is an optimization over elementary seive whose time complexity is O(N log log N);
 * 2. The time complexity of this algorithm is O(N)
 * 3. It is not good for the large input . Prefer segmented seive for large input 
 * 
 * 4. Another very important paradigm of this problem is used to factorize this number in logN using SPF array
*/


#include<bits/stdc++.h>
using namespace std;
#define fastin cin.tie(NULL);ios_base::sync_with_stdio(false);

int N;

bool is_prime[50000];
vector<int> SPF(50000);
vector<int> prime;

void make_seive(){
  is_prime[0]=is_prime[1]=false;
  for(int i=2;i<=N;++i){
    
    if(is_prime[i]){
      prime.push_back(i);
      SPF[i] = i;
    }
    
    for(int j = 0; j<(int)(prime.size()) && i*prime[j]<=N && prime[j]<=SPF[i];++j){
      is_prime[i*prime[j]] = false;
      SPF[i*prime[j]] = prime[j];
    }
  }
  
}

/*
This algorithm factorises in O(Log N)
*/
void factorize(int N){
  vector<int> res ; 
  while(N!=1){
    res.push_back(SPF[N]);
    N/=SPF[N];
  }
  
  for(int i=0;i<res.size();++i){
    cout<<res[i]<<" ";
  }
  cout<<endl;
}

int main(void){
  fastin;cin>>N;
  memset(is_prime,true,sizeof(is_prime));
  make_seive();
  factorize(N);
  for(int i=0;i<prime.size();++i) cout<<prime[i]<<" ";
  return 0;
}
