#include<bits/stdc++.h>
using namespace std;

int longest_even_length_substring(string& str){
    if(str.length()<=1){return 0;}
    int n=str.length();
    vector<vector<int>> S(n,vector<int>(n,0));
    
    for(int i=0;i<n;++i){
        S[i][i]=(int)(str[i]-48);
    }
    
    for(int L=2;L<=n;++L){
        for(int i=0;i<=n-L;i++){
            int j=i+L-1;
            
            if(j==i+1){
                S[i][j]=(int)(str[i]-48) + (int)(str[j]-48);
            }
            else{
                S[i][j]=(int)(str[i]-48) + (int)(str[j]-48) + S[i+1][j-1];
            }
        }
    }
    int max_length=0;
    for(int L=2;L<=n;L=L+2){
        for(int i=0;i<=n-L;++i){
            int j=i+L-1;
            int k=i+(j-i)/2;
            if(S[i][k]==S[k+1][j] && (j-i+1)>max_length){
                max_length=(j-i+1);
                break;
            }
        }
    }
    
    return max_length;
}

int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin>>T;
while(T--){
string s;
cin>>s;
cout<<longest_even_length_substring(s)<<endl;
}
return 0;
}
