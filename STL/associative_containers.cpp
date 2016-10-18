/*
@Shubham Sharma
-18/10/2016
*/

/*
 ------------------------Associative Containers------------------------------------
1. They are mostly implemented using Binary trees.
2. The most important property is that the data is always sorted.
3. No push_back or push_front like the sequence containers
4. Always sorted , default criteria is <

5. Set : It has no duplicate items
6. Sequence containers dont have a find member functions as the associative 
and unordered_associative containers

7. Values of the set and the multiset are immutable . They cannot be modified.
8. Similarly keys in maps and multimaps cannot be modified


*/

#include<iostream>
#include<set>
#include<map>
#include<algorithm>
#include<string>
using namespace std;

int main(void){
   //-----------------------------SET-------------------------------------
   // set has no duplicate items
    set<int> S={4,5,3,2,1};
    S.insert(8);
    auto iter = S.find(3);// This is different from find in algorithms 
    
    // Insertion function in these containers returns values that can be used for the error handling
    pair<set<int>::iterator,bool> ret;
    ret = S.insert(4); // This insertion is unsuccessful and return false
    set<int>::iterator it;
    if(ret.second==false){
        cout<<"This number is already present \n";
        it=ret.first;
    }
    else{ cout<< "the insertion is successful \n";}
    S.insert(it,1);/// Fast way of inserting O(logn)==> o(1) telling the root to insert at the possible buckets
    
    
    S.erase(5);// you can erase value in an associative containers using value as well as iterators
    S.erase(it);
    // None of the sequnce containers provide this kind of erase
   
   /*
   Properties:
   1. Insert/remove/search takes Log(n) time
   2. No random access []
   3. Sufferes from the problem of cache inconsitency as lists.
   */
   
   //-------Multiset ----------------------------------------------
   
   // provides duplicate items 
   // insertion is always successful
   multiset<int> MS;
   MS.insert(4);
   MS.insert(4);
   MS.insert(12);
   MS.insert(6);
   multiset<int>::iterator itm=MS.find(4);
  // *itm=21; This is not allowed as you cannot change the value through iterator
   MS.erase(itm);
   for(it : MS){
       cout<<it<<" ";
   }
   cout<<endl;
   
   //---------------------------------MAP------------------------------------
   
   // No duplicate keys
   map<int,string> M;
   M.insert(make_pair(22,"Shubham"));
   M.insert(make_pair(25,"Meet"));
   
   map<int,string>::iterator itmap = M.begin();
   M.insert(itmap,pair<int,string>(31,"Pramod")); // this is used as a hint
   
   
   //-------------------------------MULTIMAP----------------------------------
   
   // allows duplicate keys
   
   
   
  
   
    return 0;
}
