/**
author : Shubham Sharma
Date : 16/06/2017
Ref:https://www.youtube.com/watch?v=KW0UvOW0XIo&index=5&list=PLBF3763AF2E1C572F

"" Training is nothing . Will is everything. -- Ra's al Ghul(The Batman Begins)""
*/

/**=============Implementing Hash Table using open addressing==================

1. Here m is the table size and n is the number of elements . So m>=n and load factor of table <=1;
2. This program implements the double hashing mode of open addressing. The improvement that double hashing provides over linear probing
is that it does not form clusters and distributes keys uniformly
3. One thing to notice is that always use M as prime as all the keys generations would never form the cycle unless the entire table is
visited once.
*/
#include<iostream>
using namespace std;

#define M 100003 // the count of all numbers at single time instant <=10^5
#define R 1213  // this is used for the second hash function    

struct Node{
  public:
  int key;
  int data;
  bool is_empty;
  bool del;
};

class Hash{
  private:
  struct Node arr[M];
  int h1(const int key){
    return key%M;
  }
  int h2(const int key){
    return (R - (key%R));
  }
  
  public:
  Hash(){
    for(int i=0;i<M;++i){
      arr[i].is_empty = true;
      arr[i].del = false;
    }
  }
  
  void insert(const int key,const int data){
    
    int n =h1(key);
    while(arr[n].del!=true && arr[n].is_empty!=true){
      n = (n + h2(key))%M;
    }
    
    arr[n].key = key;
    arr[n].data = data;
    arr[n].is_empty = false;
    arr[n].del = false;
    
  }
  
  pair<bool,pair<int,int>> search(const int key){
    int n = h1(key);
    while(1){
      if(arr[n].is_empty == true){
        return {false,{0,0}};
      }
      if(arr[n].del == false && arr[n].is_empty == false && arr[n].key == key){
        return {true,{n,arr[n].data}};
      }
      n = (n + h2(key))%M;
    }
  }
  
  
  void rem(const int key){
    pair<bool,pair<int,int>> res = search(key);
    if(res.first == false) return;
    
    arr[res.second.first].del = true;
    
  }
  
};

int main(void){
  Hash H;
  
  H.insert(5,7);
  H.insert(5+M,7);
  H.insert(5+2*M,7);
  H.insert(5+3*M,7);
  H.insert(6,7);
  H.insert(7,7);
  cout<<H.search(5+2*M).first<<endl;
  H.rem(5+2*M);
  cout<<H.search(5+2*M).first<<endl;
  H.insert(5+2*M,7);
  cout<<H.search(5+2*M).first<<endl;
  return 0;
}







