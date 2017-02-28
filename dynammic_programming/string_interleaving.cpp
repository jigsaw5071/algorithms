/**
@Shubham Sharma
Date:28/02/2017
ref: Tushar Roy
*/
/*---------------------String Interleaving Paradigm---------------------------------------------------------------------
1. This algorithm is used to check if the given two text strings are interleaving of the main strings
2. Interleaving means that the two given strings can be combined to form main string but their order is preserved
3. Time complexity : O(l1*l2)
4. Space complexity : O(l1*l2)
where l1 and l2 are the lengths of the two strings 
*/
#include<bits/stdc++.h>
using namespace std;

bool is_interleaving_possible(string str1,string str2,string str3){
    if((str1.length()+str2.length())!=str3.length()){
        return false;
    }
    vector<vector<bool>>dp (str1.length()+1,vector<bool>(str2.length()+1,false));
    dp[0][0]=true;
    for(int j=1;j<=str2.length();++j){
        int index=j-1;
        if(str2[j-1]==str3[index]){
            dp[0][j]=dp[0][j-1];
        }
    }
    for(int i=1;i<=str1.length();++i){
        int index=i-1;
        if(str1[i-1]==str3[index]){
            dp[i][0]=dp[i-1][0];
        }
    }
    
    for(int i=1;i<=str1.length();++i){
        for(int j=1;j<=str2.length();++j){
            int index=i+j-1;
            dp[i][j]=((str1[i-1]==str3[index])?dp[i-1][j] : false) || ((str2[j-1]==str3[index])?dp[i][j-1]:false);
        }

    }
    return dp[str1.length()][str2.length()];
}

int main(void){
    string str1="XXYM";
    string str2 = "XXZT";
    string str3 = "XXXZXYTM";
    if(is_interleaving_possible(str1,str2,str3)){
        cout<<"Interleaving Possible"<<endl;
    }
    else{
        cout<<"Interleaving not possible"<<endl;
    }
    
    return 0;
}
