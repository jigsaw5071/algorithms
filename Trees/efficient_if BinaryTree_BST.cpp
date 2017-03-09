/**
@Shubham Sharma
Date:09/03/2017
*/

/*----------------Check if binary tree is BST or not-----------------

1. This is the space efficient method taking time O(n);
2. Ths space with o(N) is checking sorting in O(N) using inorder traversal


**/

#include<bits/stdc++.h>
using namespace std;

// only the routine is mentioned

bool is_BST(struct Node* root,const int min,const int max){
    if(root==NULL){return true;}
    if(root->data<=min || root->data>=max){
        return false;
    }
    return is_BST(root->left,min,root->data) || is_BST(root->right,root->data,max);
}
