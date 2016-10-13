/*
-By Shubham Sharma
:13-10-2016

HASHING FUNCTION FOR INTEGER THAT ARE MOSTLY REPEATING FOR LEETCODE QUESTION MAJORITY ELEMENT
*/

#include<bits/stdc++.h>
using namespace std;

#define TABLE_SIZE 4999 // prime number is best probability of collisions is low

class _hash_map{
    private:
    vector<list<pair<int,int>>> _hash_table;
    public:
    _hash_map(){
        vector<list<pair<int,int>>> v(TABLE_SIZE);
        _hash_table=v;
    }
    int _get_size();
    void _insert(int);
    int _get_count(int);
    
};
/*
utility function to get the size of the hash table
*/
int _hash_map::_get_size(){
    return _hash_table.size();
}

/*
utility function to insert a variable
*/
void _hash_map::_insert(const int key){
    int n=key%TABLE_SIZE;
    if(_hash_table[n].begin()==_hash_table[n].end()){
        _hash_table[n].push_back(make_pair(key,1));
    }
    else{
        list<pair<int,int>>& L=_hash_table[n];
        bool _found=false;
        for(auto iter=L.begin();iter!=L.end();++iter){
            if(iter->first==key){
                _found=true;
                iter->second=iter->second+1;
                break;
            }
        }
        if(!_found){
            L.push_back(make_pair(key,1));
        }
    }
}

/*
utility function to get the count of the key
*/
int _hash_map::_get_count(const int key){
    int n=key%TABLE_SIZE;
    list<pair<int,int>>& L=_hash_table[n];
    for(auto iter=L.begin();iter!=L.end();++iter){
        if(iter->first==key){
            return iter->second;
        }
    }
    return 0;
}

int main(void){
  _hash_map H;
  H._insert(25);
    
    
    
return 0;    
}
