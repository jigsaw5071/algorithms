/**
@Shubham Sharma

*/

/*
Utility algorithm for validating the preorder traversal of the BST and also using 
it to calculate the postorder traversal

In this algorithm we put all the left elaments to the root in the stack and check in the 
right most side of the minimum root that it does not have any key smaller than 
the minimum possible root

*/

#include<bits/stdc++.h>
using namespace std;


/*
utility function to convert preorder to postorder
*/
void to_postorder(vector<int>& arr,const int l,const int r,vector<int>& result){
   if(l>r){
       return;
   }
   if(l==r){
       result.push_back(arr[l]);
       return;
   }
   int root_index=l;
   int j;
   for(j=l+1;j<=r;++j){
       if(arr[j]>arr[root_index]){break;}
   }
   
   to_postorder(arr,l+1,j-1,result);
   to_postorder(arr,j,r,result);
   result.push_back(arr[root_index]);
   return;
}

void preorder_to_postorder(vector<int>& arr){
    int n=arr.size();
    if(n==1){
        cout<<arr[0]<<endl;
        return;
    }
    
    //validating preorder array
    stack<int> S;
    int root=INT_MIN;
    
    for(int i=0;i<n;++i){
        
        if(arr[i]<root){
            cout<<"NO"<<endl;
            return;
        }
        
        while(!S.empty() && S.top()<arr[i]){
            root=S.top();
            S.pop();
        }
        S.push(arr[i]);
    }
    
    // converting the valid preorder to postorder
    vector<int> result;
    to_postorder(arr,0,n-1,result);
    for(int i=0;i<result.size();++i){
        cout<<result[i]<<" ";
    }
    cout<<endl;
}

int main(void){
ios_base::sync_with_stdio(false);
cin.tie(NULL);
int T;
cin>>T;
while(T--){
int n;
cin>>n;
vector<int> arr(n);
for(int i=0;i<n;++i){
    cin>>arr[i];
}
preorder_to_postorder(arr);
}
return 0;
}
