/*
@Shubham Sharma
Date:27/02/2017
*/
/*-------------------------------------------------MAX AREA HISTOGRAM----------------------------------------------
1. This is one of the best examples of the stack usage apart from next greater element problem
2. Time complexity:O(2*n)
3. space complexity:O(n)
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
                current_right=i-1;
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
                current_right=i-1;
            }
            if(area>max_area){
                max_area=area;
                overall_left=current_left;
                overall_right=current_right;
            }
    }
    return make_pair(make_pair(overall_left,overall_right),max_area);
}

void build_maximum_area_histogram(vector<int>& arr){
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
    cout<<"The maximum area is :"<<area<<endl;
    cout<<"The starting and the ending points are: "<<start<<" "<<end<<endl;
}

int main(void){
    vector<int> arr={0,0,2,4,1,0,1,7,23,14,12,0,0,1};
    build_maximum_area_histogram(arr);
    return 0;
}
