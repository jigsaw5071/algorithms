/**
@ Shubham Sharma
Date:03/01/2016
**/

/*
------------------------------------Longest Palindrome Starting at a prefix of a String

1. KMP algorithm can be used in O(n)

2. Z algorithm can also be used O(n)

3. trie can also be used in O(n*n)

*/

#include<bits/stdc++.h>
using namespace std;

/**
z algorithm based routine
*/

void longest_prefix_palindrome_Z(string& s){
    string rev=s;
    reverse(rev.begin(),rev.end());
    s=s+"$"+rev;
    vector<int> Z(s.length(),0);
    
    int left=0;
    int right=0;
    for(int k=1;k<s.length();++k){
        if(k>right){
            left=right=k;
            while(right<s.length() && s[right]==s[right-left]){
                right++;
            }
            Z[k]=right-left;
            right--;
        }
        else{
            int k1=k-left;
            if(Z[k1]+k-1<right){
                Z[k]=Z[k1];
            }
            else{
                left=k;
                while(right<s.length() && s[right]==s[right-left]){
                    right++;
                }
                Z[k]=right-left;
                right--;
            }
        }
    }
    int max=1;
    for(int i=0;i<s.length();++i){
        if(Z[i]+i==s.length()){
            max=Z[i];
            break;
        }
        
        
    }
    cout<<"The maximum prefix is :"<<max<<endl;
}

/**
This is the KMP based algorithm
*/

void longest_prefix_palindrome_KMP(string& s){
    string rev=s;
    reverse(rev.begin(),rev.end());
    s=s+"$"+rev;
    vector<int> lps(s.length(),0);
    int j=0;
    for(int i=1;i<s.length();){
        if(s[i]==s[j]){
            lps[i]=j+1;
            j++;
            i++;
        }
        else{
            if(j==0){
                lps[i]=0;
                i++;
            }
            else{
                j=lps[j-1];
            }
        }
    }
    cout<<"The maximum length is :"<<lps[s.length()-1]<<endl;
}

int main(void){
    string s="abac";
    longest_prefix_palindrome_Z(s);
    return 0;
}
