/**
@ Shubham Sharma
Date: 03/05/2017
Ref: https://www.topcoder.com/community/data-science/data-science-tutorials/using-tries/
*/


/**
This trie paradigm supports 3 functions
1. add a word to the dictionary

2. count number of words with the prefix ending at current vertex

3. count the number of complete words ending at this current vertex

4. we are dealing only with the english alphabets

*/

#include<iostream>
using namespace std;

struct Trie_node{
  int prefixes; //stores the count of words that have prefix of this vertex
  int words;// stores the count of the words that end at this node
  struct Trie_node* children[26];  //this stores all the english alphabets lower case
  Trie_node(){
    prefixes=0;words=0;
    for(int i=0;i<26;++i) children[i]=NULL;
  }
};

void insert(struct Trie_node* root,const string& word){
  int n=word.length();
  /*
  This is an iterative paradigm but recursive counterpart is also feasible
  */
  struct Trie_node* current=root;
  for(int i=0;i<n;++i){
    current->prefixes=current->prefixes+1;
    struct Trie_node* next=current->children[(int)(word[i]-97)];
    if(next==NULL){
      next = new Trie_node;
      current->children[(int)(word[i]-97)]=next;
    }
    current=next;
  }
  current->prefixes++;
  current->words=current->words+1;
}

int count_words(struct Trie_node* root,const string& word){
  int n=word.length();
  struct Trie_node* current=root;
  for(int i=0;i<n;++i){
    struct Trie_node* next=current->children[(int)(word[i]-97)];
    if(next == NULL)return 0;
    
    current=next;
  }
  return current->words;
}

int count_prefixes(struct Trie_node* root,const string& word){
  int n=word.length();
  struct Trie_node* current=root;
  for(int i=0;i<n;++i){
    struct Trie_node* next=current->children[(int)(word[i]-97)];
    if(next == NULL)return 0;
    
    current=next;
  }
  return current->prefixes;
  
}


int main(void){
  struct Trie_node* root=new Trie_node;
  insert(root,"Tree");
  insert(root,"Trie");
  cout<<count_prefixes(root,"Tree");
  return 0;
}


