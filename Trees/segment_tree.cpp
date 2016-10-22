/*
@Shubham Sharma
-22/10/2016

ref : Tushar Roy
*/

/*

Def: A segment tree is a tree data structure for storing intervals or segments for fast 
querying and updates. Lazy propagation is important when there are high number of updates 
in the input array.

Code for simple Segment Tree For Range Sum Queries

1. Time complexity of constructing Segment tree = O(n)
2. Worst case space complexity : O(4n)==O(n)
3. Time complexity of search query : O(4*logn)== O(logn)
At most we go in 4 different paths on the binary tree or on each level there are 
maximum of 4 comparisions

This complete analysis of segment tree including construction,updation is based on 
postorder traversal of the binary tree
*/

#include<bits/stdc++.h>
using namespace std;

class RangeSum {
  vector<int> _seg_tree;
  int _next_power_2(int);
  int input_size;
  void _construct_segment_tree(vector<int> &,vector<int>&,int,int,int);
  int _range_sum_query(vector<int>&,int,int,int,int,int);
  void _update_single_key(vector<int>& ,int ,int,int, int,int);
  void _update_range_key(vector<int>& ,int,int ,int ,int ,int ,int);
  public:
  RangeSum(vector<int>& V){
      int n=V.size();
      input_size=n;
      n=_next_power_2(n);
      n=(n<<1)-1;
      vector<int> temp(n,0);
      _seg_tree=temp;
      _construct_segment_tree(V,_seg_tree,0,V.size()-1,0);
  }
  int _get_size();
  int _range_sum_wrapper(int,int);
  void _update_single_wrapper(int,int);
  void _update_range_wrapper(int,int,int);
  
    
};

/*
utility function to calculate the next power of 2
The time complexity of this algorithm is O(log num)
*/
int RangeSum:: _next_power_2(const int num){
    if(num==0){return 1;}
    if((num && (num-1))==0){return num;}
    int p=1;
    while(p<num){
        p=p<<1;
    }
    return p;
}
/*
utlility function to get the size
*/    
int RangeSum::_get_size(){
    return _seg_tree.size();
}

/*
utility function to construct the segment tree
Time Complexity = O(n)
*/
void RangeSum::_construct_segment_tree(vector<int>& input,vector<int>& _seg_tree,int l,int r,int pos){
    if(l==r){
        _seg_tree[pos]=input[l];
        return ;
    }
    int mid=l+(r-l)/2;
    _construct_segment_tree(input,_seg_tree,l,mid,2*pos+1);
    _construct_segment_tree(input,_seg_tree,mid+1,r,2*pos+2);
    _seg_tree[pos]=_seg_tree[2*pos+1]+_seg_tree[2*pos+2];
}

/*
utility function for the range sum query
*/
int RangeSum::_range_sum_query(vector<int>& _seg_tree,int ql,int qr,int l,int r,int pos){
    // case of no overlap
    if(ql>r || qr<l){
        return 0;
    }
    
    // case of complete overlap
    if(ql<=l && qr>=r){
        return _seg_tree[pos];
    }
    
    // case of the partial overlap
    int mid=l+(r-l)/2;
    return _range_sum_query(_seg_tree,ql,qr,l,mid,2*pos+1) + _range_sum_query(_seg_tree,ql,qr,mid+1,r,2*pos+2);
}

/*
utility fuction for range sum wrapper
*/
int RangeSum::_range_sum_wrapper(int ql,int qr){
    return _range_sum_query(_seg_tree,ql,qr,0,input_size-1,0);
}

/*
utility function to update the single key
Time Complexity = O(logn)
*/
void RangeSum::_update_single_key(vector<int>& _seg_tree,int l,int r,int key,int value,int pos){
    if(key<l || key > r){return ;}
    if(l==r){
        _seg_tree[pos]+=value;
        return ;}// This is the termination condition that the element has reached the root
    int mid=l+(r-l)/2;
    _update_single_key(_seg_tree,l,mid,key,value,2*pos+1);
    _update_single_key(_seg_tree,mid+1,r,key,value,2*pos+2);
    _seg_tree[pos]=_seg_tree[2*pos+1]+_seg_tree[2*pos+2];
}

/*
utility wrapper function for the _update_single_key
*/
void RangeSum::_update_single_wrapper(int key,int value){
    _update_single_key(_seg_tree,0,input_size-1,key,value,0);
}

/*
utility function for the range update query
*/
void RangeSum::_update_range_key(vector<int>& _seg_tree,int ql,int qh,int l,int r,int delta,int pos){
    if(ql>r || qh<l){
        return ; // incase of non-overlap
    }
    
    if(l==r){
        _seg_tree[pos]+=delta;
        return ;
    }
    int mid=l+(r-l)/2;
    _update_range_key(_seg_tree,ql,qh,l,mid,delta,2*pos+1);
    _update_range_key(_seg_tree,ql,qh,mid+1,r,delta,2*pos+2);
    _seg_tree[pos]=_seg_tree[2*pos+1]+_seg_tree[2*pos+2];
}

/*
utility function for the range update wrapper 
*/
void RangeSum::_update_range_wrapper(int ql,int qr,int delta){
    
    _update_range_key(_seg_tree,ql,qr,0,input_size-1,delta,0);
}
int main(void){
    vector<int> V={-1,3,4,0,1,2};
    RangeSum R(V);
    cout<<R._range_sum_wrapper(0,5)<<endl;
    R._update_range_wrapper(0,2,4);
    cout<<R._range_sum_wrapper(0,2)<<endl;
    return 0;
    
}
