/**
@ Shubham Sharma
Date: 01/04/2017
Ref: geeksforgeeks.org
**/
/**=====================================LRU CACHE===========================================================
1. LRU is the page replacement algorithm used in the hardware and software designs of the cache memory.
2. Suppose you have a large number of pages and your limited cache memory can accomodate only a very few number of page frames suppose n so 
some technique has to be devised to insert a new page when the cache is full. You got to throw out the least recently used page number from the cache.
3. The recentness of the page is maintained through a double link list where the most recent page is at the fron and the least recent page 
is at the bottom.
4.The hash map is used for O(1) time complexity  
5. The time complexity is O(1)

*/

#include<iostream>
using namespace std;

//===============Doubly Linked List Paradigms================================================
struct Node{
  public:
  int data;
  struct Node* next;
  struct Node* prev;
};

class DLList{
  private:
  struct Node* head;
  struct Node* tail;
  int count;
  public:
  DLList(){
    head=NULL;
    tail=NULL;
    count=0;
  }
  
  int get_size(){return count;}
  struct Node* get_tail(){
    return tail;
  }
  
  struct Node* insert(const int page_number){
    struct Node* node=new Node;
    node->data=page_number;
    node->next=NULL;
    node->prev=NULL;
    
    if(head==NULL && tail==NULL){
      head=node;
      tail=node;
    }
    else{
      node->next=head;
      head->prev=node;
      head=node;
    }
    count++;
    return node;
  }
  
  void remove_tail(){
    if(tail==NULL){
      return;
    }
    count--;
    if(head==tail){
      delete head;
      head=NULL;
      tail=NULL;
    }
    else{
      struct Node* temp=tail;
      tail=tail->prev;
      tail->next=NULL;
      delete temp;
      
    }
  }
  
  void move_to_head(struct Node* node){
    if(node==NULL){
      return;
    }
    // we can perform delete operation in O(1) time in a List
    if(node==head){return;}
    if(head==NULL && tail==NULL){return ;}
    node->prev->next=node->next;
    if(node->next==NULL){
      tail=node->prev;
    }
    else{
      node->next->prev=node->prev;
    }
    
    node->next=head;
    head->prev=node;
    node->prev=NULL;
    head=node;
  }
  
  void print(){
    struct Node* current=head;
    while(current!=NULL){
      cout<<current->data<<" ";
      current=current->next;
    }
    cout<<endl;
  }
  
};

//===========================================Class Hash Map================================================================
class Hash{
  private:
  int TABLE_SIZE;
  struct Node* hash_table[197621];
  public:
  Hash(){
    TABLE_SIZE=197621;
    init_start();
  }
  
  void init_start(){
    for(int i=0;i<TABLE_SIZE;i++){hash_table[i]=NULL;}
  }
  void insert(const int page_number,struct Node* node){
    hash_table[page_number]=node;
  }
  struct Node* search(const int page_number){
    return hash_table[page_number];
  }
  void rem(const int page_number){
    hash_table[page_number]=NULL;
  }
  
};


//==================================LRU Cache Class==================================
class LRUCache{
  private:
  int CACHE_SIZE;
  DLList L;
  Hash H;
  public:
  LRUCache(const int SIZE){
    CACHE_SIZE=SIZE;
  }
  void fetchPage(const int page_number){
    struct Node* node=H.search(page_number);
    if(node==NULL){
      if(L.get_size()==CACHE_SIZE){
        struct Node* tail=L.get_tail();
        if(tail==NULL){
          cout<<"Some error occured"<<endl;
          return;
        }
        L.remove_tail();
        H.rem(tail->data);
        
      }
      H.insert(page_number,L.insert(page_number));
    }
    else{
      L.move_to_head(node);
    }
    L.print();
  }
};






int main(void){
  cin.tie(NULL);
  ios_base::sync_with_stdio(false);
  LRUCache lruCache(10);

    lruCache.fetchPage(5);
    lruCache.fetchPage(7);
    lruCache.fetchPage(15);
    lruCache.fetchPage(34);
    lruCache.fetchPage(23);
    lruCache.fetchPage(21);
    lruCache.fetchPage(7);
    lruCache.fetchPage(32);
    lruCache.fetchPage(34);
    lruCache.fetchPage(35);
    lruCache.fetchPage(15);
    lruCache.fetchPage(37);
    lruCache.fetchPage(17);
    lruCache.fetchPage(28);
    lruCache.fetchPage(16);
  return 0;
}
