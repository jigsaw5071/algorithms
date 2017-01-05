#include<bits/stdc++.h>
using namespace std;

/*-----------------------O(n) Paradigm---------------------
using stack
*/

string build_minimum_number(string& str,const int n){
    string result="";
    if(str.length()==0 || n>=str.length()){
        return "";
    }
    if(n==0){
        return str;
    }
    stack<char> S;
    int count=str.length()-n;
    for(int i=0;i<str.length();++i){
        
        while(!S.empty() && str[i]<S.top() && S.size()+str.length()-i-1>=count){
            S.pop();
        }
        if(S.size()<count){
            S.push(str[i]);
        }
    }
    while(!S.empty()){
        result=S.top()+result;
        S.pop();
    }
    return result;
}


int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin>>T;
while(T--){
int n;
string s;
cout<<build_minimum_number(s,n)<<endl;
}
return 0;
}
