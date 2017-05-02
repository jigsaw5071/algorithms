/*
SPOJ:http://www.spoj.com/problems/SUBXOR/
**/
#include<bits/stdc++.h>
using namespace std;

struct Node{
  int lcount;
  int rcount;
  struct Node* lchild;
  struct Node* rchild;
  Node(){
    lcount=rcount=0;
    lchild=rchild=NULL;
  }
};

void insert(struct Node* root,const int n){
  for(int i=20;i>=0;--i){
    int ch=(n>>i) & 1;
    if(ch){
      root->rcount++;
      if(root->rchild==NULL){
        root->rchild=new Node;
      }
      root=root->rchild;
    }
    else{
      root->lcount++;
      if(root->lchild==NULL){
        root->lchild=new Node;
      }
      root=root->lchild;
    }
  }
}

uint64_t query(struct Node* root,const int n,const int k){
  uint64_t res=0;
  for(int i=20;i>=0;--i){
    int ch1=(k>>i) & 1;
    int ch2=(n>>i) & 1;
    if(ch1){
      if(ch2){
        res+=root->rcount;
        if(root->lchild==NULL){return res;}
        root=root->lchild;
      }
      else{
        res+=root->lcount;
        if(root->rchild==NULL){return res;}
        root=root->rchild;
      }
    }
    else{
      if(ch2){
        if(root->rchild==NULL){return res;}
        root=root->rchild;
      }
      else{
        if(root->lchild==NULL){return res;}
        root=root->lchild;
      }
    }
  }
  return res;
}

int main(void){
  ios_base::sync_with_stdio(false);cin.tie(NULL);
  int T;cin>>T;
  while(T--){
    int n,k;cin>>n>>k;
    vector<int> arr(n);for(int i=0;i<n;++i){cin>>arr[i];}
    int preXor=0;
    struct Node* root=new Node;
    insert(root,0);
    uint64_t count=0;
    for(int i=0;i<n;++i){
      preXor=preXor xor arr[i];
      count+=query(root,preXor,k);
      insert(root,preXor);
    }
    cout<<count<<endl;
  }
  return 0;
}
