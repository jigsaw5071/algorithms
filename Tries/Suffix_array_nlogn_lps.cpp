/**
@ Shubham Sharma
Date: 01/05/2017
Ref:http://www.geeksforgeeks.org/suffix-array-set-2-a-nlognlogn-algorithm/
*/

/**====================Effcient Suffix Arrays==========================================
1. The time complexity of the above development is O(n* logn *logn)
2. it can be further reduced to O(n*logn) using radix sort
3. it is used in various string algorithms

*/
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

struct suffix{
  int index;
  int rank;
  int next_rank;
}SA[100];

int comp(struct suffix a,struct suffix b){
  
  return (a.rank==b.rank)?(a.next_rank < b.next_rank):(a.rank<b.rank);
}

void make_suffix_array(const string& str){
  int n=str.length();
  for(int i=0;i<n;++i){
    SA[i].index=i;
    SA[i].rank=str[i]-'a';
    SA[i].next_rank=(i+1 < n)?str[i+1]-'a':-1;
  }
  sort(SA,SA+n,comp);
  int ind[n];
  for(int k=4;k<2*n;k=2*k){
    int rank=0;
    int prev_rank=SA[0].rank;
    SA[0].rank=0;
    ind[SA[0].index]=0;
    for(int i=1;i<n;++i){
      if(SA[i].rank==prev_rank && SA[i].next_rank==SA[i-1].next_rank){
        prev_rank=SA[i].rank;
        SA[i].rank=rank;
      }
      else{
        prev_rank=SA[i].rank;
        SA[i].rank=++rank;
      }
      
      ind[SA[i].index]=i;
    }
    
    for(int i=0;i<n;++i){
      int n_index=SA[i].index+k/2;
      SA[i].next_rank=(n_index<n)?(SA[ind[n_index]].rank):-1;
    }
    sort(SA,SA+n,comp);
  }
  
  for(int i=0;i<n;++i){
    cout<<SA[i].index<<" ";
  }
  cout<<endl;
}

/**
constructing the LCP array using Kasai's algorthim in O(n)
The combination of suffix array and LPS fully simulates the Suffix trees and their both top down and 
bottom up traversals
*/
vector<int> get_LPS(const string& str){
  int n=str.length();
  vector<int> lps(n,0),rank(n);
  for(int i=0;i<n;++i){
    rank[SA[i].index]=i;
  }
  int k=0;
  for(int i=0;i<n;++i,(k>0)?k--:0){
      if(rank[i]==n-1){
        
        k=0;continue;
      }
      int j=SA[rank[i]+1].index;
      while(i+k<n && j+k<n && str[i+k]==str[j+k]){k++;}
      lps[rank[i]]=k;
  }
  for(int i=0;i<n;++i){
    cout<<lps[i]<<" ";
  }
  cout<<endl;
  return lps;
  
}


int main(void){
  string str;cin>>str;
  make_suffix_array(str);
  get_LPS(str);
  return 0;
}
