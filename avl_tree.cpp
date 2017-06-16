/**
author : Shubham Sharma
Date: 16/06/2017
Ref:https://www.youtube.com/watch?v=rbg7Qf8GkQ4

""The only hinderance in your way is your thinking""
*/

/*=========================AVL TREE============================

1. This program implements insert, delete and search
2. All operations take logn time
*/

#include<iostream>
#include<malloc.h>
using namespace std;

int gmax(const int a,const int b){
  return (a>b)?a:b;
}



struct Node{
  int data;
  int height;
  struct Node* left;
  struct Node* right;
};

int gheight(struct Node* root){
  if(root == NULL) return 0;
  
  return root->height;
}

int setHeight(struct Node* root){
  if(root==NULL) return 0;
  
   return 1 + gmax(gheight(root->left),gheight(root->right));
}

struct Node* leftRotate(struct Node* root){
  struct Node* newRoot = root->right;
  root->right = newRoot->left;
  newRoot->left = root;
  root->height = setHeight(root);
  newRoot->height = setHeight(newRoot);
  return newRoot;
}

struct Node* rightRotate(struct Node* root){
  struct Node* newRoot = root->left;
  root->left = newRoot->right;
  newRoot->right = root;
  root->height = setHeight(root);
  newRoot->height = setHeight(newRoot);
  return newRoot;
}

struct Node* insert(struct Node* root,const int data){
  if(root == NULL){
    struct Node* node = (struct Node*)malloc(sizeof(Node));
    node->data = data;
    node->left =NULL;
    node->right = NULL;
    node->height = 1;
    return node;
  }
  else if(data <= root->data){
    root->left = insert(root->left,data);
  }
  else{
    root->right = insert(root->right,data);
  }
  
  //balancing algorithm
  int balance = gheight(root->left) - gheight(root->right);
  
  if(balance > 1){
    if(gheight(root->left->left) >= gheight(root->left->right)){
      //LL
      root = rightRotate(root);
    }
    else{
      //LR
      root->left = leftRotate(root->left);
      root = rightRotate(root);
    }
  }
  else if(balance < -1){
     if(gheight(root->right->right) >= gheight(root->right->left)){
       //RR
       root = leftRotate(root);
       
     }
     else{
       //RL
       root->right = rightRotate(root->right);
       root = leftRotate(root);
     }
  }
  else{
    root->height = setHeight(root);
  }
  return root;
}


bool search(struct Node* root,const int data){
  if(root == NULL){
    return false;
  }
  if(root->data == data) return true;
  
  if(data < root->data) return search(root->left,data);
  
  return search(root->right,data);
}

int findMin(struct Node* root){
  if(root->left == NULL ){
    return root->data;
  }
  return findMin(root->left);
}

struct Node* del(struct Node* root,const int data){
  if(root == NULL){
    return NULL;
  }
  
  if(data < root->data){
    root->left = del(root->left,data);
  }
  else if(data > root->data){
    root->right = del(root->right,data);
  }
  else{
    
    if(root->left == NULL && root->right==NULL){
      struct Node* temp = root;
      free(temp);
      return NULL;
    }
    else if(root->left == NULL){
      struct Node* temp = root->right;
      free(root);
      return temp;
    }
    else if(root->right == NULL){
      struct Node* temp = root->left;
      free(root);
      return temp;
    }
    else{
      root->data = findMin(root->right);
      root->right = del(root->right,root->data);
    }
    
  }
  
  if(root == NULL){return root;}
  root->height = setHeight(root);
  
  int balance = gheight(root->left) - gheight(root->right);
  
  if(balance > 1){
    
    if(gheight(root->left->left) >= gheight(root->left->right)){
      //LL
      root = rightRotate(root);
    }
    else{
     //LR 
     root->left = leftRotate(root->left);
     root = rightRotate(root);
    }
    
  }
  else if(balance < -1){
    if(gheight(root->right->right) >= gheight(root->right->left)){
      //RR
      root = leftRotate(root);
    }
    else{
      //RL
      root->right = rightRotate(root->right);
      root = leftRotate(root);
    }
  }
  
  return root;
  
}

void inorder(struct Node* root){
  if(root == NULL){return;}
  
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

int main(void){
  struct Node* root = NULL;
  root=insert(root,30);
  root=insert(root,20);
  root=insert(root,10);
  root=insert(root,25);
  root=insert(root,40);
  root=insert(root,50);
  cout<<search(root,20)<<endl;;
  root = del(root,100);
  inorder(root);
  return 0;
}



