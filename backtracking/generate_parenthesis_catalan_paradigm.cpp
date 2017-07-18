/***
author : Shubham Sharma
Date : 18/07/2017
Ref : http://www.geeksforgeeks.org/program-nth-catalan-number/
*/

/** Generating all possible valid parenthesis
 * 
 * 1. usually they carry the catalan number paradigm
 * 2. using backtracking we can solve this problem

*/

#include<bits/stdc++.h>
using namespace std;

void backtrack(string temp,vector<string>& res,const int open_left,const int close_left){
  
  if(open_left == 0 && close_left == 0){
    res.push_back(temp);return;
  }
  
  if(close_left > 0) backtrack(temp+')',res,open_left,close_left - 1);
  if(open_left > 0 ) backtrack(temp+'(',res,open_left-1,close_left+1);
  
  
}

int main(void){
  
  int n = 4;
  
  string temp = "";
  vector<string> res;
  
  backtrack(temp,res,n,0);
  
  for(int i = 0; i < res.size();++i){
    cout<<res[i]<<endl;
  }
  
  return 0;
}
