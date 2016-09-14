/*
-By Shubham Sharma 
:14-09-2016
- Referance -Tushar Roy 
*/

/*
The time complexity of this algorithm is O(m+n)
where m= length of the text and n=length of the pattern
Space complexity=O(n)
*/




#include<bits/stdc++.h>
using namespace std;

/*
utility function to compute the LPS
The time complexity for this algorithm is O(n) n size of the pattern
*/
void _compute_lps(const string pat,int * lps){
int n=pat.length();
lps[0]=0;//lps 0 is always 0
int j=0;
for(int i=1;i<n;){
if(pat[i]==pat[j]){
    lps[i]=j+1;
    j++;
    i++;
}
else if(j==0){
    lps[i]=0;
    i++;
}
else{
    /*
    This step is the best step of this algorithm
    It internally applies pattern matching inside of the pattern with 
    the pattern elements and avoids to match the prefixed and suffixed 
    elements inside the pattern itself
    
    Basically pattern is internally matching subpattern inside to search for the
    prefixes and the suffixes
    */
    j=lps[j-1];
}
}

}

/*
This wrapper method is for the KMP algorithm 
*/
void _KMP_search(const string text,const string pat){
 int _pattern_length=pat.length();    
 int *lps=(int *)malloc(sizeof(int)*_pattern_length);
 memset(lps,0,sizeof(int)*_pattern_length);
 _compute_lps(pat,lps);
 int i=0;//index of text
 int j=0;//index of pattern
 int _text_length=text.length();
 
 while(i<_text_length && j< _pattern_length){
  if(text[i]==pat[j]){
      i++;
      j++;
  }
  else{
      if(j==0){
          i++;
      }
      else{
          j=lps[j-1];
      }
  }
  
 }
 if(j==_pattern_length){
      cout << "The pattern is found at the index "<<i-j<<endl;
  }
  else{
      cout<<"The pattern not found"<<endl;
  }
 free(lps);//to avoid the memory leak
 lps=NULL;// to invalidate the pointer for the further use
}

int main(void){
    string text="ABABDABACDABABCABAB";
    string pat="ABABCABAB";
    _KMP_search(text,pat);
    return 0;
}
