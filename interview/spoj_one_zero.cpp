/**
Prob: http://www.spoj.com/problems/ONEZERO/
@ Shubham Sharma
Date:15/06/2017
*/  
#include<bits/stdc++.h>
using namespace std;

#define FAST_IN ios_base::sync_with_stdio(NULL);cin.tie(NULL);
#define rep(i,a,b) for(int i = (int)a;i<=(int)b;++i)
#define per(i,a,b) for(int i = (int)b;i>=(int)a;--i)
#define all(x) x.begin(),x.end()
#define sz(x) ((int)(x.size()))

typedef uint64_t ul;
typedef int64_t il;

#define MAX 20001

/**
This algorithm is based on the state analysis. That in any search algorithm we dont need to visit on the same state twice.
*/


int main(void){
    FAST_IN;
    int T; cin >> T;
    rep(t,1,T){
      int n; cin >> n;
      
      unordered_map<int,int> par;
      unordered_map<int,int> val;
      par[1]  = -1;
      
      queue<int> Q;
      Q.push(1);
      
      while(!Q.empty()){
        
        int current = Q.front();
        Q.pop();
        
        if(current == 0){
          // remainder is 0
          string str="";
          while(par[current]!=-1){
            str = (char)(val[current] +48) + str;
            current = par[current];
          }
          str = "1"+str;//this is for the base 1
          cout<<str<<endl;
          break;
        }
        
        
        int num = (current * 10)%n;
        if(par.find(num) == par.end()){
          par[num] = current;
          val[num] = 0;
          Q.push(num);
        }
        
        num = (current*10 + 1)%n;
        if(par.find(num) == par.end()){
          par[num] = current;
          val[num] = 1;
          Q.push(num);
        }
        
      }
      
      
    }
    return 0;
}
