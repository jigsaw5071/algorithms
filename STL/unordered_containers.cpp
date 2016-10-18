/*
@Shubham Sharma
-18/10/2016
*/

/*
 ------------------------Unordered Associative Containers------------------------------------
1. These are implemented using hash tables handling collisions through chaining.
2. Time complexity is amortized O(1+a) a=load factor.

3. In unordered_set/multiset value cannot be changed . Either you can erase and then insert 
elsewise hash property will not be maintained. same is the case with unordered map/unordered_multimap
key values.

4. Very Important point regarding containers 

Subscript operator provide write access to the containers
Eg:
    void foo(const map<int,int>& M){
        cout<<M[4]<<endl;// This will cause compilation error as map is declared constant and subscript operator means writing
    }
    
5. Unordered multimap and associative multimap cannot be used as associative arrays
as they dont use [] subscript operator. They use .find() function.

*/

#include<iostream>
#include<vector>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<numeric>
#include<string>
using namespace std;

int main(void){
  //--------------------------------unordered_set----------------------------
  
  // they dont contain duplicates
  unordered_set<int> S={4,5,3,1,2};
  unordered_set<int>::const_iterator it_unset = S.find(8);
  if(it_unset!=S.end()){
      cout<<"SuccessFully Found \n";
  }
  else{
      cout<<"Not Found \n";
  }
  S.insert(12);
  
  // can be added through vector 
  vector<int> V={8,7,6,5,4,3,2,1};
 S.insert(V.begin(),V.end());
 
 // Popular hash Tables APIs
 
 cout<<S.load_factor()<<endl;// This is the load factor of the Tables
 
 cout<<S.bucket(95)<<endl;//bucket method is a hash coding map function (converting input to integer) and also hash compression map
 
 cout<<S.bucket_count()<<endl;// displays the table size  
 
 /*
 Properties:
 1.Search is amortized O(1)
 2.Insert is amortized O(1)
 3.Remove is amortized O(1)
 */
 
 //---------------Associative arrays ------------------------------

 // they can be implemented using maps or unordered maps
 
 unordered_map<char,string> UM={{'S',"Sunday"},{'M',"Monday"}};
 cout<<UM['S']<<endl;// does not apply range check
 cout<<UM.at('M')<<endl;// this applies range check .. range_error exception is thrown
 
 /*vector<int> V={1,2,3};
 V[5]=5; This will cause compliler error
   */
  UM['W']="Wednesday";// This inserts fine
  
  UM.insert(make_pair('F',"Friday"));// works fine
  UM.insert(make_pair('M',"Meanday"));// cause a runtime throw error as unordered maps are immutable containers 
  UM['M']="Meanday";// succeeded to modify
  
  
   
    return 0;
}
