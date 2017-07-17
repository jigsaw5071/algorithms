  /**
  author : Shubham Sharma
  Date : 17/07/2017
  Ref : https://github.com/mission-peace/interview/blob/master/src/com/interview/string/LongestPalindromeSubstring.java
  
  ""What we think, we become""  - Gautam Buddha
  
  */
  
  
  /**===================Manacher's algorithm =============================================
  1. This is the holy grail to find the longest palindromic substring in an array in linear time.
  
  2. It just uses the precomputed lengths of the previous smaller palindromes within the current palindromes. 
  
  3. Just two pointers run : Time complexity : O(2*n)
  4. Space complexity : O(n)
  
  5. It utilises the concept of mirrors in palindromes that have been previously preprocessed
  
  */
  
  #include<iostream>
  #include<string>
  #include<vector>
  using namespace std;
  
  string _manacher_lps(string& str){
    int n = str.length();
    vector<char> inp(2*n+1);
    vector<int> T(2*n+1,1);
    
    for(int i = 0 ; i<inp.size();++i){
      if(i & 1){
        inp[i] = str[i/2];
      }
      else{
        inp[i] = '$';
      }
    }
    
    int start = 0;
    int end = 0;
    
    for(int i = 0; i < inp.size();){
      while(start >= 0 && end <= inp.size()-1 && inp[start-1] == inp[end+1]){
        start--;
        end++;
      }
      
      T[i] = end - start + 1;
      
      if(end == inp.size() - 1)break; // break if the end is reached
      
      
      // now we define the centers
      
      int new_center = end + (i%2 ==0 ? 1 : 0); // this way we are not processing newly added characters $
      
      for(int j = i+1; j <= end; ++j){
        
        T[j] = min(T[i - (j-i)],2*(end - j) + 1);
        
        if(j + T[i - (j-i)]/2 == end){
          // this is the case when the prefix is the mirror of the suffix and the lengths are same .
          // We can expand across It
          new_center = j; break;
        }
        
     
        
      }
      
      
      
         i = new_center;
        start = i - T[i]/2;
        end = i + T[i]/2;
      
      
      
      
      
    }
    
    int idx = 0;
    int mxln = 1;
    
    for(int i = 1; i<inp.size();++i){
      if(T[i] > mxln){
        mxln = T[i];
        idx = i;
      }
    }
    
    start = idx - T[idx]/2;
    end = idx + T[idx]/2;
    string res ="";
    for(int i = start;i<=end;++i){
      if(inp[i]!='$'){
        res += inp[i];
      }
    }
    return res;
  }
  
  int main(void){
    
    string str = "cdbabcbabdab";
    
    cout<<_manacher_lps(str)<<endl;
    
    return 0;
  }
  
