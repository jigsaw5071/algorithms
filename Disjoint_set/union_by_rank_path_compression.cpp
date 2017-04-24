/**
@ Shubham Sharma
date: 24/04/2017
Ref:https://www.topcoder.com/community/data-science/data-science-tutorials/disjoint-set-data-structures/
*/

/**======================DISJOINT SET ==================================================
 
 1. The time complexity of m opertaions on an array of size n is <= O(4*m)
 2. The space complexity is O(n)
 3. The optimizations used are union by rank and path compression
*/

#include<bits/stdc++.h>
using namespace std;
struct Node* find_set(struct Node*);
struct Node{
  public:
  int data;
  int rank;
  struct Node* parent;
};
unordered_map<int,Node*> M;

void make_set(const int data){
  struct Node* node =new Node;
  node->rank=0;
  node->parent=node;
  node->data=data;
  M[data]=node; 
}

bool make_union(const int data1,const int data2){
  struct Node* node1=M[data1];
  struct Node* node2=M[data2];
  struct Node* parent1=find_set(node1);
  struct Node* parent2=find_set(node2);
  if(parent2==parent1){return false;}
  if(parent1->rank >=parent2->rank){
    parent1->rank=(parent1->rank==parent2->rank)?parent1->rank+1:parent1->rank;
    parent2->parent=parent1;
  }
  else{
    parent1->parent=parent2;
  }
  return true;
}

struct Node* find_set(struct Node* node){
  if(node->parent==node){
    return node;
  }
  node->parent=find_set(node->parent);
  return node->parent;
}

int find_set_element(const int data){
  return find_set(M[data])->data;
}

int main(void){
  make_set(1);
  make_set(2);
  make_union(1,2);
  cout<<find_set_element(2);
  return 0;
}
