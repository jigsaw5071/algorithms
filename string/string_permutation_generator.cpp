/**
@ Shubham Sharma
Date:01/01/2017
*/

/*
----------------------------String Permutation generator--------------------------------------------------
1. This algorithm is used to handle the string with duplicates also.

2. The Time complexity is O(n!)

3. The space complexity is O(n)


*/

#include<bits/stdc++.h>
using namespace std;

/**
utility function to print the array
*/

void print_string(vector<char>& result){
    for(int i=0;i<result.size();++i){
        cout<<result[i]<<"";
    }
    cout<<endl;
}

/**
utility function to print all the permutations of the given string
*/

void premute_util(vector<char>& str,vector<int>& count,vector<char>& result,const int level){
       
       if(result.size()==level){
           print_string(result);
           return;
       }
    
    for(int i=0;i<count.size();++i){
        if(count[i]==0){
            continue;
        }
        result[level]=str[i];
        count[i]--;
        premute_util(str,count,result,level+1);
        count[i]++;
    }
}

/**
utility function to generate all the lexicographical permutations
*/
void permute(string& s){
    if(s.length()==0){return;}
    if(s.length()==1){
        cout<<s[0]<<endl;
        return;
    }
    int n=s.length();
    vector<int> _hash_table(26,0);
    for(int i=0;i<n;++i){
        _hash_table[(int)(s[i]-97)]++;
    }
    
    vector<char> str;
    vector<int> count;
    
    for(int i=0;i<26;++i){
        if(_hash_table[i]>0){
            str.push_back((char)(i+97));
            count.push_back(_hash_table[i]);
        }
    }
    
    vector<char> result(s.length());
    premute_util(str,count,result,0);//0 here indicates the level
}

int main(void){
    
    string s="abcd";
    permute(s);
    return 0;
}
