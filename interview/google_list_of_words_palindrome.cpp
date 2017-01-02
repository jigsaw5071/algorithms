/**
@ Shubham Sharma
Date:02/01/2016
*/

/*

Q.  You are given a list of words. Find if any two words can be joined to form a palindrome.


Sol: This is a hashing based solution solved by me .
The time complexity is O(n*k)
n=length of list
k=average length of string
*/

#include<bits/stdc++.h>
using namespace std;

/*
utility function to swap two varaibles
*/
void _swap(char *a,char *b){
    char temp=*a;
    *a=*b;
    *b=temp;
}

/*
utlity function to reverse the string
*/
string get_reverse(string& s){
    if(s.length()<=1){return s;}
    
    int i=0;
    int j=s.length()-1;
    while(i<j){
        _swap(&s[i],&s[j]);
        i++;
        j--;
    }
    return s;
}

/*
utility function to get palindrome 
*/
string get_palindrome(vector<string>& L){
    if(L.size()<=1){
        return "Palindrome not possible";
    }
    unordered_set<string> S;
    string result="";
    for(int i=0;i<L.size();++i){
        if(S.find(L[i])==S.end()){
            S.insert(get_reverse(L[i]));
        }
        else{
            result=L[i]+get_reverse(L[i]);
            break;
        }
    }
    if(result==""){
        return "No string can be combined";
    }
    else{
        return result;
    }
}

int main(void){
    vector<string> L={"bab","bab"};
    cout<<get_palindrome(L)<<endl;
    return 0;
}
