/*
@Shubham Sharma
Date:07/03/2017
Ref: tushar roy
*/

/*-------------------------Word break problem------------------------

1. This problem is in paradigm with matrix chain multiplication and boolean parenthsiztion
and palindromic partioning
2. The time complxity is O(n*n*n)
3. The space complexity is O(n*n) 


*/

#include<bits/stdc++.h>
using namespace std;

void make_string(vector<int>& parent,string& str,const int j,string& result){
    if(j==-1){
        return;
    }
    int i=parent[j];
    string temp=str.substr(i+1,j-i);
    make_string(parent,str,i,result);
    result+=temp+" ";
    
}

bool is_present(string& str,unordered_set<string>& S){
    if(S.find(str)==S.end()){
        return false;
    }
    return true;
}

void word_break(string str,vector<string>& dict){
    
    unordered_set<string> S;
    for(int i=0;i<dict.size();++i){
        S.insert(dict[i]);
    }
    int n=str.length();
    vector<vector<bool>> dp(n,vector<bool>(n,false));
    vector<int> parent(n,-1);
    for(int i=0;i<n;++i){
        string temp(1,str[i]);
        if(is_present(temp,S)){
            dp[i][i]=true;
        }
        
    }
    
    for(int L=2;L<=n;++L){
        for(int i=0;i<=n-L;++i){
            int j=i+L-1;
            string temp=str.substr(i,j-i+1);
            if(is_present(temp,S)){
                dp[i][j]=true;
                parent[j]=i;
            }
            else{
                for(int k=i;k<j;++k){
                    if(dp[i][k]==true && dp[k+1][j]==true){
                        dp[i][j]=true;
                        parent[j]=k;
                    }
                }
            }
        }
    }
    
    if(!dp[0][n-1]){
        cout<<"Word Breaking is not possible"<<endl;
    }
    else{
        string result="";
        make_string(parent,str,n-1,result);
        
        cout<<result<<endl;
    }

}

int main(void){
    vector<string> dict={"like","had","play","to","crush"};
    string str="Ihadliketoplay";
    word_break(str,dict);
    return 0;
}
