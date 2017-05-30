/**
author : Shubham Sharma
Ref: http://www.geeksforgeeks.org/sieve-eratosthenes-0n-time-complexity/,
https://www.hackerearth.com/practice/math/number-theory/basic-number-theory-2/tutorial/

"Hard work beats talent when talent fails to work hard"
*/

/**===============SEGMENTED SEIVE ===============================================================
    1. This is not used for very large inputs 
    2. The time complexity of this algorithm is O(sqrt(R))
*/


#include<bits/stdc++.h>
using namespace std;
#define fastin cin.tie(NULL);ios_base::sync_with_stdio(false);



int main(void){
  fastin;
  int L,R; cin >> L >> R;
  
  bool is_prime[ R - L + 1 ];
  memset(is_prime,true,sizeof(is_prime));
  
  for(int i = 2; i*i <= R;++i){
    
    for(int j = max(i*i, (L + i - 1)/i * i);j<=R;j+=i){
      is_prime[j-L]=false;
    }
    
  }
  
  for(int i=L;i<=R;++i){
    if(is_prime[i-L]) cout<<i<<" ";
  }
  
  return 0;
}
