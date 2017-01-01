/**
@ Shubham Sharma
Date:01/01/2017
*/

/**
---------------------------------Z Algorithm----------------------------------------------------------

1. This is a linear time and linear space algorithm used for pattern matching 

2. It maintains an array Z(K) =length of the longest substring starting at k which is also the preix of the starting

3. It optimizes the array by maintaining the interval [L,R]

4. R always increases during the whole course of z array building and so as L. Also in case of mismatch there is only one mismatch(R stops increasing) for every i. So overall time complexity of building the Z array is o(N)


*/

#include<bits/stdc++.h>
using namespace std;

/**
utility function to calculate the z array
*/

void _calculate_Z(string& input,vector<int>& Z){
    
    int l=0;
    int r=0;
    
    for(int k=1;k<input.length();++k){
        
        if(k>r){
            l=r=k;
            while(r<input.length() && input[r]==input[r-l]){
                r++;
            }
            
            Z[k]=r-l;
            r--;
        }
        
        else{
            int k1=k-l;
            
            if(Z[k1]+k-1<r){
                Z[k]=Z[k1];
            }
            else{
                l=k;
                while(r<input.length() && input[r]==input[r-l]){
                    r++;
                }
                Z[k]=r-l;
                r--;
            }
            
        }
    }
}

/**
utility function for the z algortihm
*/
void _z_algorithm(string& text,string& pattern){
  if(text.length()==0 || pattern.length()==0){
    cout<<"The input data is not valid"<<endl;
    return;
  }
  
  string input=pattern;
  input+='$';
  input+=text;
  vector<int> Z(input.length(),0);
  
  _calculate_Z(input,Z);
  
  vector<int> result;
  for(int i=0;i<Z.size();++i){
      if(Z[i]==pattern.length()){
          result.push_back(i-pattern.length()-1);
      }
  }
  
  for(int i=0;i<result.size();++i){
      cout<<result[i]<<" ";
  }
  
  
  
}


int main(void){
  string text="aaabcxyzaaaabczaaczabbaaaaaabc";
  string pattern="aaabc";
  _z_algorithm(text,pattern);
  
  
  
  return 0;
}
