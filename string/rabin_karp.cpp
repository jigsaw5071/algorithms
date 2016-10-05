/*
By Shubham Sharma
ref: Tushar Roy

Rabin Karp Algorithm

The worst case time complexity is O(m*n)
m=length of text
n=length of pattern

The average and best case time complexity is O(n+m)
 
The hash function is not rolling hash function
it is Value(pat)%_prime

The space complexity of this algorithm is O(1)
 
*/

#include<bits/stdc++.h>
using namespace std;

/*
utility function to create the pattern hash and is 
also used for the first hash of the text
*/

int _create_pat_hash(string& str,int l,int r,const int _prime,const int d){
    int hash=0;
    for(int i=l;i<=r;++i){
        hash=(hash*d+(int)str[i])%_prime;
    }
    return hash;
}

bool _check_equality(string& text ,string& pat,const int l){
    int n=pat.length();
    for(int i=0;i<n;++i){
        if(pat[i]!=text[i+l]){
            return false;
        }
    }
    return true;
}
void _rabinKarp(string& text,string& pat,const int _prime,const int d){
    int m=text.length();
    int n=pat.length();
    int _hash_pat=_create_pat_hash(pat,0,n-1,_prime,d);
    int _hash_text=_create_pat_hash(text,0,n-1,_prime,d);
    int _dn=1; // need to calculate (d^n)% prime initiallly to reduce the computation
    for(int i=0;i<n-1;++i){
        _dn=(_dn*d)%_prime;
    }
    
    for(int i=0;i<=m-n;++i){
        if(_hash_text== _hash_pat && _check_equality(text,pat,i)){
            cout<<"Pattern found at index : "<<i<<endl;
        }
        
          if(i<(m-n)){
              //rehash calculating
              _hash_text=((_hash_text-(_dn*(int)text[i]))*d +(int)text[i+n])%_prime;
              _hash_text=(_hash_text<0)?(_hash_text+_prime):_hash_text;
        }
    }
    
}

int main(void){
    int _prime=101; // This is the prime number to reduce hash to computer memory limit
    int d=256;//radix (for integer string it is 10)
    string text="GEEKSFORGEEKS";
    string pat="GEEKS";
    _rabinKarp(text,pat,_prime,d);
return 0;    
}
