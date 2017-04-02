/***
@ Shubham Sharma
Date:02/04/2017
Ref:http://dhruvbird.com/lfu.pdf
**/

/**================================LFU CACHE===========================================
1. It is one of the most popular cache eviction techniques used in OS and databases designs to make the execution of the applications
faster.
2. It is availabe in the time complexity of O(logn) using RB tree or self balancing trees
3. This is the popular code implementing LFU code in O(1) time
*/

#include<bits/stdc++.h>
using namespace std;

struct LRUNode{
  int freq;
  list< pair<int,int> > vals;
  LRUNode(int f=0){
    freq=f;
  }
};

class LFUCache{
  public:
  typedef list< LRUNode >::iterator iptr;
  typedef list< pair<int,int> >::iterator jptr;
  LFUCache(const int SIZE){
    CACHE_SIZE=SIZE;
  }
  
  int get_size(){
    int size=0;
    for(iptr i=L.begin();i!=L.end();++i){
      size+=i->vals.size();
    }
    return size;
  }
  
  void set(const int key,const int value){
    if(CACHE_SIZE<=0){return;}
    if(M.find(key)==M.end()){
      if(get_size()==CACHE_SIZE){
        evict();
      }
      M[key]=insert(key,value);
    }
    else{
      M[key]=promote(key,value);
    }
  }
  
  int get(const int key){
    if(M.find(key)!=M.end()){
      iptr i=M[key].first;
      jptr j=M[key].second;
      M[key]=promote(j->first,j->second);
      return j->second;
    }
    return -1;
  }
  
  pair<iptr,jptr> insert(const int key,const int value){
    iptr i=L.begin();
    if(i==L.end() || i->freq!=1){
      LRUNode node(1);
      i=L.insert(i,node);
    }
    jptr j=i->vals.insert(i->vals.end(),{key,value});
    return make_pair(i,j);
  }
  
  void evict(){
    iptr i= L.begin();
    jptr j=i->vals.begin();
    M.erase(j->first);
    i->vals.erase(j);
    if(i->vals.empty()){
      L.erase(i);
    }
  }
  
  pair<iptr,jptr> promote(const int key,const int value){
    iptr i=M[key].first;
    jptr j=M[key].second;
    
    iptr k=next(i);
    int freq=i->freq+1;
    i->vals.erase(j);
    if(i->vals.empty()){
      L.erase(i);
    }
    if(k==L.end() || k->freq!=freq){
      i=L.insert(k,LRUNode(freq));
    }
    else{i=k;}
    j=i->vals.insert(i->vals.end(),make_pair(key,value));
    return make_pair(i,j);
  }
  
  void print(){
    for(iptr i=L.begin();i!=L.end();++i){
      cout<<"Frequency- "<<i->freq<<" :: ";
      for(jptr j=i->vals.begin();j!=i->vals.end();++j){
        cout<<j->first<<" "<<j->second<<"    ";
      }
      cout<<endl;
    }
    cout<<endl;
  }
  
    private:
  int CACHE_SIZE;
  list< LRUNode > L;
  unordered_map<int, pair<iptr,jptr> > M;// this is the hash map used for constant time retrieval
  
};


int main(void){
  LFUCache L(2);
  L.set(1,1);
  L.print();
  L.set(2,2);
  L.print();
  L.get(1);
  L.print();
  L.set(3,3);
  L.print();
  L.get(2);
  L.print();
  L.get(3);
  L.print();
  L.set(4,4);
  L.print();
  
  return 0;
}
