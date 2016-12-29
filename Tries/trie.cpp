/**
@ Shubham Sharma
Date:29/12/2016
*/

/*
-----------------------------------Introduction to Trie--------------------------------------------------- 

1. This data structure is used for fast retreival and in case of fast prefix matching in strings
2. They are used for indexing and searching strings in route table.
3. They provide the auto completion feature in strings.
4. They are also used in implementing prefix trees

Time complexity of inserting m words of average length L
T(n)=O(m*L)


Time complexity of searching a word of length L:
T(n)=O(L)

Time complexity of deleting a word of length L:
T(n)=O(L)
*/

#include<bits/stdc++.h>
using namespace std;

/*
utility struct for the single node of trie
*/
struct Trie_Node{
  bool end_of_word;
  char ch;
  unordered_map<char,Trie_Node*> children;
  Trie_Node():end_of_word(false),ch('\0'){} //member initializers are used same as class
};

/*
utility class for the trie data structure
*/
class Trie{
    private:
    Trie_Node* root;
    
    public:
    Trie();
    void insert(const string);
    void recursive_insert_wrapper(const string);
    void recursive_insert(Trie_Node* ,const string,const int);
    bool search_recursive_wrapper(const string);
    bool search_recursive(Trie_Node* ,const string,const int);
    bool search(const string);
    void delete_wrapper(const string);
    bool delete_string(Trie_Node*,const string,const int);
    
    
    
};

/*
default constructor for Trie Class
*/
Trie::Trie(){
    root=new Trie_Node();
}

/*
utiltiy function to insert a string in a trie
*/
void Trie::insert(const string s){
    int n=s.length();
    if(n<=0){return;}
    
    Trie_Node* current=root;
    for(int i=0;i<n;++i){
        Trie_Node* next =(current->children.find(s[i])==current->children.end())?NULL:current->children[s[i]];
        if(next==NULL){
            next=new Trie_Node; 
            next->ch=s[i];
            current->children[s[i]]=next;
        }
        current=next;
    }
    
    // finally we put end of word as true
    current->end_of_word=true;
    
}


/*
utility wrapper function for recursive insert
*/
void Trie::recursive_insert_wrapper(const string s){
    recursive_insert(root,s,0);
}


/*
utility member function to insert recursively in string
*/
void Trie::recursive_insert(Trie_Node* current,const string s,const int index){
    
    if(index==s.length()){
        current->end_of_word=true;
        return;
    }
    
    Trie_Node* next =(current->children.find(s[index])==current->children.end())?NULL:current->children[s[index]];
     if(next==NULL){
         next=new Trie_Node;
         next->ch=s[index];
         current->children[s[index]]=next;
     }   
     recursive_insert(next,s,index+1);
    
}


/*
utility wrapper function to search in a trie recursively
*/
bool Trie::search_recursive_wrapper(const string s){
    return search_recursive(root,s,0);
}

/*
utility function to search in a Trie recursively
*/
bool Trie::search_recursive(Trie_Node* current,const string s,const int index){
   if(index==s.length()){
       return current->end_of_word;
   }
   Trie_Node* next =(current->children.find(s[index])==current->children.end())?NULL:current->children[s[index]];
   if(next==NULL){
       return false;
   }     
   return search_recursive(next,s,index+1);    
}

/*
utility function for the iterative search
*/

bool Trie::search(const string s){
    Trie_Node* current=root;
    for(int i=0;i<s.length();++i){
       Trie_Node* next =(current->children.find(s[i])==current->children.end())?NULL:current->children[s[i]];
       if(next==NULL){
           return false;
       }
       current=next;
    }
    return current->end_of_word;
}

/*
utility wrapper function for the delete
*/
void Trie::delete_wrapper(const string s){
    if(s.length()==0){return;}
    delete_string(root,s,0);
}

/**
utility helper function for the delete routine
*/
bool Trie::delete_string(Trie_Node* current,const string s,const int index){
    
    if(index==s.length()){
        
        if(!current->end_of_word){
            return false;
        }
        current->end_of_word=false;
        return current->children.size()==0;
    }
    
    
    Trie_Node* next =(current->children.find(s[index])==current->children.end())?NULL:current->children[s[index]];
    if(next==NULL){
        return false;
    }
    
    bool should_delete_current_node=delete_string(next,s,index+1);
    
    if(should_delete_current_node){
       current->children.erase(current->children.find(s[index]));
       delete next;
       return current->children.size()==0;
    }
    
    return false;
}


int main(void){
    vector<string> test_case={"the", "a", "there", "answer", "any",
                     "by", "bye", "their"};
    vector<string> search_test={"the","these","their","thaw"};                 
    Trie T;
    for(int i=0;i<test_case.size();++i){
        T.insert(test_case[i]);
    }
    cout<<"Searching:......"<<endl;
    for(int i=0;i<search_test.size();++i){
        if(T.search_recursive_wrapper(search_test[i])){
            cout<<search_test[i]<<" :is present"<<endl;
        }
        else{
            cout<<search_test[i]<<" :is not present"<<endl;
        }
    }
    
    T.delete_wrapper("the");
    T.delete_wrapper("their");
    T.delete_wrapper("these");
    cout<<"Searching:......"<<endl;
    for(int i=0;i<search_test.size();++i){
        if(T.search_recursive_wrapper(search_test[i])){
            cout<<search_test[i]<<" :is present"<<endl;
        }
        else{
            cout<<search_test[i]<<" :is not present"<<endl;
        }
    }
    
  return 0;
}
