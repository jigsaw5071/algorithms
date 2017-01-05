/**
@Shubham Sharma
Date:06-01-2017
*/

/**
------------------------------TEXT JUSTIFICATION PROBLEM---------------------------------

1. Given a screen size how to fit a sequence in it such that the extra spaces are evenly distributed( or text looks good).

2.To organize this way we introduce a badness[i][j] as the variable that calculates how bad would it be if try to fit words starting from index i to index j in a 
single line.

3. Our task is to select the starting words to minimize the badness factor(cost of extra spaces in each line)

Badness factor = (badness factor of line 1)^3 + (badness factor of line 2)^3 +(badness factor of line 3 )^3 +--------------

Time complexity : O(n*n)

Space Complexity: O(n*n)

4. This algorithm is used by Latec and MS Word for justification of text.

*/

#include<bits/stdc++.h>
using namespace std;


/*
utility function for the text justification
*/

void justify_text(vector<string>& V,const int screen_size){
    
    // we are assuming that the length of the single word is less than the screen size
    if(V.size()==1){
        cout<<V[0]<<endl;
        return;
    }
    int n=V.size();
    vector<vector<int>> L(n,vector<int>(n,0));// this is the length of the string starting at index i and ending at index j with spaces in between
    
    for(int i=0;i<n;++i){
        L[i][i]=V[i].length();
    }
    
    for(int i=0;i<n;++i){
        for(int j=i+1;j<n;++j){
            L[i][j]=L[i][j-1]+L[j][j]+1;
        }
    }
    
    vector<vector<int>> B(n,vector<int>(n,0));//badness of storing [i--j] in one line
    
    for(int i=0;i<n;++i){
        for(int j=i;j<n;++j){
            if(L[i][j]>screen_size){
                B[i][j]=INT_MAX;
            }
            else{
                B[i][j]=pow(screen_size-L[i][j],3);
            }
        }
    }
    
    vector<int> C(n,0);// stores the minimum cost with i as the starting of new line
    vector<int> P(n,0);//Parent array for calculating the justified string
    
    for(int i=n-1;i>=0;i--){
        C[i]=B[i][n-1];
        P[i]=n;
        for(int j=n-1;j>i;j--){
            if(B[i][j-1]==INT_MAX){
               continue; 
            }
            if(C[i] > C[j]+B[i][j-1]){
                C[i]=C[j]+B[i][j-1];
                P[i]=j;
            }
            
        }
    }
    
    string result="";
    int i=0;
    while(i!=n){
        int last=P[i];
        for(int j=i;j<last-1;j++){
            result+=V[j]+" ";
        }
        result+=V[last-1]+"\n";
        i=last;
    }
    
    cout<<result;
}

int main(void){
    vector<string> V={"Shubham","Sharma","is","passionate","about","Algorithms"};
    int screen_size=16;
    justify_text(V,screen_size);
}
