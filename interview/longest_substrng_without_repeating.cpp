/**
author : Shubham Sharma
Date : 17/07/2017
*/

/**============================Finding the longest palindromic substring in linear time===================================
 *1.It uses two pointers paradigm with hashing the previous index of occurence
 * 
*/

#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(void){
    string str = "ua";
    
    vector<bool> cnt(26,false);
    vector<int> pre_index(26,0);
    
    int i = 0;
    int j = 0;
    int res = 0;
    while(j < str.length()){
        if(cnt[str[j] - 'a']){
            res = max(res,j-i);
            while(i <= pre_index[str[j] - 'a']){
               cnt[str[i] - 'a'] = false;
               pre_index[str[i] -'a'] = -1;i++;
            }
            cnt[str[j] - 'a'] = true;
            pre_index[str[j] - 'a'] = j;j++;
        }
        else{
           cnt[str[j] - 'a'] = true;
           pre_index[str[j] - 'a'] = j;
           j++;
        }
    }
    res = max(res,j-i);
    cout<<res<<endl;
    
    return 0;
}
