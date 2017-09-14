/*
author : Shubham Sharma
Date :14/09/2017
Ref : https://www.toptal.com/algorithms/aho-corasick-algorithm
*/

/*  *********************** AHO CORASICK Algorithm ****************************************

" What you think , you become" - Buddha

=> suppose there are M patterns of lengths L1 , L2 , L3 .... Ln. We need to find the matches of patterns from a dictionary
in a text of length N , Using KMP we can do this in O(N*M + L) but using aho-corasick-algorithm we can do it in O(N + L + Z)
where Z = count of all matches and L is the sum of all the lengths of the pattern
=>In this algorithm we will make the KMP like calculations but in contrast to the KMP algorithm , where we find the maximum
length prefix that was also the suffix of the current substring , now we will find the maximum length suffix of the current
string that is also the prefix of some pattern in the trie.
*/

#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

struct Vertex{
  public:
  unordered_map<char,struct Vertex*> children; // Links to the child vertexes in the trie:
  bool leaf; // Flag that some word from the dictionary ends in this vertex
  struct Vertex* parent; // Link to the parent vertex
  char parentChar; //Char which moves us from the parent vertex to the current vertex
  struct Vertex* suffixLink; //Suffix link from current vertex (the equivalent of P[i] from the KMP algorithm)
  struct Vertex* endWordLink;//Link to the leaf vertex of the maximum-length word we can make from the current prefix
  int wordId ; //If the vertex is the leaf, we store the ID of the word
  Vertex(){
    leaf = false;
    parent = NULL;
    suffixLink = NULL;
    endWordLink = NULL;
    wordId = -1;
    parentChar = '\0';
  }
};

class Aho{
  private:
  struct Vertex* root;
  void addString(string , int);
  void prepareAho();
  void calculateSuffixLink(struct Vertex*);

  public:
  Aho(vector<string>& patterns){
    root = new Vertex();
    for(int i = 0; i < patterns.size() ; ++i){
      addString(patterns[i] , i);
    }
    prepareAho();
  }
  unordered_map<int , vector<int>> searchText(string text);

};

/**
 *  add a string of the pattern to the existing trie
*/
void Aho::addString(string str , int wordId){
  struct Vertex* curVertex = root;
  for(int i = 0; i < str.length() ; ++i){
    char c = str[i];
    struct Vertex* nextVertex = (curVertex->children.find(c) == curVertex->children.end() ? NULL : curVertex->children[c]);
    if(nextVertex == NULL){
      nextVertex = new Vertex();
      nextVertex->parent = curVertex;
      nextVertex->parentChar = c;
      curVertex->children[c] = nextVertex;
    }
    curVertex = nextVertex;
  }
  curVertex->leaf = true;
  curVertex->wordId = wordId;
}

/**
 *  Prepare the precomputation using BFS traversal
*/
void Aho::prepareAho(){
  queue<struct Vertex*> Q;
  Q.push(root);
  while(!Q.empty()){
    struct Vertex* curVertex = Q.front();
    Q.pop();
    calculateSuffixLink(curVertex);
    for(auto iter = curVertex->children.begin() ; iter != curVertex->children.end() ; ++iter){
      Q.push(iter->second);
    }
  }
}

/**
 *  method for calculating the suffix link for each vertex
*/
void Aho::calculateSuffixLink(struct Vertex* curVertex){
  if(curVertex == root){
    curVertex->suffixLink = root;
    curVertex->endWordLink = root;
    return;
  }
  if(curVertex->parent == root){
    curVertex->suffixLink = root;
    if(curVertex->leaf){
      curVertex->endWordLink = curVertex;
    }
    else{
      curVertex->endWordLink = curVertex->parent->suffixLink->endWordLink;
    }
    return;
  }

  struct Vertex* currBetterVertex = curVertex->parent->suffixLink;
  char c = curVertex->parentChar;
  while(true){
    if(currBetterVertex->children.find(c) != currBetterVertex->children.end()){
      curVertex->suffixLink = currBetterVertex->children[c];
      break;
    }
    if(currBetterVertex == root){
      curVertex->suffixLink = root;
      break;
    }
    currBetterVertex = currBetterVertex->suffixLink;
  }
  
  if(curVertex->leaf){
    curVertex->endWordLink = curVertex;
  }
  else{
    curVertex->endWordLink = curVertex->suffixLink->endWordLink;
  }
  
}

/**
 *  pattern searching in a string
*/
unordered_map<int , vector<int>> Aho::searchText(string text){
  struct Vertex* curVertex = root;
  int result = 0;
  unordered_map<int,vector<int>> res;
  for(int i = 0; i < text.length() ; ++i){
    while(true){
      if(curVertex->children.find(text[i]) != curVertex->children.end()){
        curVertex = curVertex->children[text[i]];
        break;
      }
      if(curVertex == root){
        break;
      }
      curVertex = curVertex->suffixLink;
    }

    struct Vertex* checkVertex = curVertex;
    while(true){
      checkVertex = checkVertex->endWordLink;
      if(checkVertex == root){
        break;
      }
      result++;
      res[checkVertex->wordId].push_back(i);
      checkVertex = checkVertex->suffixLink;
    }

  }
  cout << "There are a total of : " << result << " matches." << endl;
  return res;
}


int main(void){
  vector<string> patterns = {"he", "she", "hers", "his"};
  string text = "ahishers";
  Aho aho(patterns);
  unordered_map<int,vector<int>> ans = aho.searchText(text);
  for(auto iter = ans.begin() ; iter != ans.end() ; ++iter){
    int wordId = iter->first ; 
    vector<int> vec = iter->second;
    cout << patterns[wordId] << " is found at : ";
    for(int i = 0; i < vec.size(); ++i){
      cout << vec[i] - patterns[wordId].length() + 1 << " "; 
    }
    cout << endl;
  }
}
