/*
@Shubham Sharma
Date:27/02/2017
*/

/*-------------------Maximum Size Rectangle With All 1s-----------------------
1. This is the best application of Max Area Histogram Algorithm
2. Time complexity is O(row*col)
3. Space Comlexity is O(min(row,col))// transpose in case of either is larger 
*/

#include<bits/stdc++.h>
using namespace std;

pair<pair<int,int>,int> get_histogram_details(const int l,vector<int>& arr){
   int n=arr.size();
    int current_left=l;
    int current_right=l;
    int overall_left=l;
    int overall_right=l;
    if(n==1){
        return make_pair(make_pair(current_left,current_right),arr[0]);
    }
    int max_area=0;
    int area=0;
    stack<int> S;
    int i;
    for(i=0;i<n;){
        if(S.empty() || arr[i]>arr[S.top()]){
            S.push(i);
            i++;
        }
        else{
            int top=S.top();
            S.pop();
            if(!S.empty()){
                area=arr[top]*(i-S.top()-1);
                current_left=l+i-S.top()-2;
                current_right=l+i-1;
            }
            else{
                area=arr[top]*i;
                current_left=l;
                current_right=l+i-1;
            }
            if(area>max_area){
                max_area=area;
                overall_left=current_left;
                overall_right=current_right;
            }
        }
    }
    while(!S.empty()){
         int top=S.top();
            S.pop();
            if(!S.empty()){
                area=arr[top]*(i-S.top()-1);
                current_left=l+i-S.top()-2;
                current_right=l+i-1;
            }
            else{
                area=arr[top]*i;
                current_left=l;
                current_right=l+i-1;
            }
            if(area>max_area){
                max_area=area;
                overall_left=current_left;
                overall_right=current_right;
            }
    }
    return make_pair(make_pair(overall_left,overall_right),max_area);
}

pair<pair<int,int>,int> make_histogram_data(vector<int>& arr){
    int n=arr.size();
    int area=0;
    int start=0;
    int end=0;
    for(int i=0;i<n;){
        if(arr[i]==0){
            i++;
            continue;
        }
        vector<int> temp;
        int j=i;
        while(j<n && arr[j]>0){
            temp.push_back(arr[j]);
            j++;
        }
        //main algorithm
        pair<pair<int,int>,int> details=get_histogram_details(i,temp);
        if(area<details.second){
            area=details.second;
            start=details.first.first;
            end=details.first.second;
        }
        if(j==n){
            break;
        }
        else{
            i=j;
        }
    }
    return make_pair(make_pair(start,end),area);
}

void build_maximum_all_1s_rectangle(vector<vector<int>>& arr){
    
    int row=arr.size();
    int col=arr[0].size();
    int start=0;
    int end=0;
    int up=0;
    int area=0;
    vector<int> dp(col,0);
    for(int i=0;i<row;++i){
        if(i==0){
            dp=arr[i];
        }
        else{
            for(int j=0;j<col;++j){
                if(arr[i][j]==0){
                    dp[j]=0;
                }
                else{
                    dp[j]=dp[j]+1;
                }
            }
        }
        pair<pair<int,int>,int> result=make_histogram_data(dp);
        if(area<result.second){
            start=result.first.first;
            end=result.first.second;
            area=result.second;
            int k=area/(end-start+1);
            up=i-k+1;
            
        }
    }
    cout<<"Area is : "<<area<<endl;
    cout<<"Left and Right Coordinates are:"<<start<<" "<<end<<endl;
    cout<<"Up Coordinates are: "<<up<<endl;
}

int main(void){
    vector<vector<int>> arr={{1,1,1,0},
                         {1,1,1,1},
                         {0,1,1,0},
                         {0,1,1,1},
                         {1,0,0,1},
                         {1,1,1,1}};
    build_maximum_all_1s_rectangle(arr);                     
    return 0;
}
