/*
Date 23/10/2016
@Shubham Sharma

ref: Tushar Roy Lazy Tree Optimization in segment tree
*/

/*
A segment tree data structure is used to store intervals or segments for range queries.  Lazy Propagation is used  when there are a large number of 
update queries.

 Time complexity of Building segment tree : O(n)

 Space Complexity : O(n)

 Time complexity of search query : O(log n)

 Time Complexity of update query : O(log n)

 The essence of the Segment Tree lies in the fact that it is based on the post order traversal of the trees and search is returned 
 when complete overlap between the interval happens (summation of two intervals = required intervals [2,2] + [3,5] =[2,5]) 

*/
#include<bits/stdc++.h>
using namespace std;

class RangeMin {
    vector<int> seg_tree;
    vector<int> lazy_tree;
    int _next_power_2(int);
    int input_size;
    void construct_rangemin_tree(vector<int>&,vector<int>& ,int,int,int);
    void update_segment_tree_range_lazy(vector<int>&,vector<int>&,int,int,int,int,int,int);
    int query_segment_tree_range_lazy(vector<int>&,vector<int>&,int,int,int,int,int);
    int min(int,int);
     public:
     	RangeMin(vector<int> V){
            int n=V.size();
            input_size=n;
            n=_next_power_2(n);
            n=2*n-1;
            vector<int> temp(n,0);
            lazy_tree=temp;
            seg_tree=temp;
            construct_rangemin_tree(V,seg_tree,0,input_size-1,0);
     	}
     	int get_size();
     	void update_range_lazy(int,int,int);
     	int query_range_min(int,int);
};

/*
utility function to find the next power of 2
*/
int RangeMin::_next_power_2(int num){
	if(num==0){return 1;}
	if((num & (num-1))==0){return num;}
	int p=1;
	while(p<num){
		p=(p<<1);
	}
	return p;
}

/*
utlility function to get the size
*/    
int RangeMin::get_size(){
    return seg_tree.size();
}

/*
utiltiy function to find the minimum of two elements
*/
int RangeMin::min(const int a,const int b){
	return (a<b)?a:b;
}

/*
utility function to construct segment tree
*/
void RangeMin::construct_rangemin_tree(vector<int>& input,vector<int>& seg_tree,int l,int r,int pos){
    if(l==r){
    	// these are the leaf nodes
    	seg_tree[pos]=input[l];
    	return;
    }
	int mid=l+(r-l)/2;
	construct_rangemin_tree(input,seg_tree,l,mid,2*pos+1);
	construct_rangemin_tree(input,seg_tree,mid+1,r,2*pos+2);
	seg_tree[pos]=min(seg_tree[2*pos+1],seg_tree[2*pos+2]);
}

/*
utility function for the lazy update operation
*/
void RangeMin::update_segment_tree_range_lazy(vector<int>& seg_tree,vector<int>& lazy_tree,int startRange,int endRange,int l,int r,int delta,int pos){
	
	
    // firstly propagate the update to the next childs if current node is not updated
    if(lazy_tree[pos]!=0){
    	seg_tree[pos]+=lazy_tree[pos];
    	if(l!=r){
    		// if not leaf
    		lazy_tree[2*pos+1]=lazy_tree[pos];
    		lazy_tree[2*pos+2]=lazy_tree[pos];
    	}
    	lazy_tree[pos]=0;
    }

    // no overlap condition
    if(startRange > r || endRange <l){
    	return ;
    }

	// complete overlap
	if(startRange<=l && r<=endRange){
		seg_tree[pos]+=delta;
		if(l!=r){
			// if not leaf
			lazy_tree[2*pos+1]+=delta;
			lazy_tree[2*pos+2]+=delta;
		}
		return ;
	}
	int mid=l+(r-l)/2;
	update_segment_tree_range_lazy(seg_tree,lazy_tree,startRange,endRange,l,mid,delta,2*pos+1);
	update_segment_tree_range_lazy(seg_tree,lazy_tree,startRange,endRange,mid+1,r,delta,2*pos+2);
	seg_tree[pos]=min(seg_tree[2*pos+1],seg_tree[2*pos+2]);

}

/*
utility wrapper function for the update query
*/
void RangeMin::update_range_lazy(int startRange,int endRange,int delta){
	update_segment_tree_range_lazy(seg_tree,lazy_tree,startRange,endRange,0,input_size-1,delta,0);
}

/*
utility function for the range minimium query
*/
int RangeMin::query_segment_tree_range_lazy(vector<int>& seg_tree,vector<int>& lazy_tree,int startRange,int endRange,int l,int r,int pos){

    // firstly propagate the update to the next childs if current node is not updated
    if(lazy_tree[pos]!=0){
    	seg_tree[pos]+=lazy_tree[pos];
    	if(l!=r){
    		// if not leaf
    		lazy_tree[2*pos+1]=lazy_tree[pos];
    		lazy_tree[2*pos+2]=lazy_tree[pos];
    	}
    	lazy_tree[pos]=0;
    }

    if(startRange> r || endRange< l){
    	return INT_MAX;
    }

    if(startRange<=l && endRange>=r){
    	return seg_tree[pos];
    }

    int mid=l+(r-l)/2;
    return min(query_segment_tree_range_lazy(seg_tree,lazy_tree,startRange,endRange,l,mid,2*pos+1),query_segment_tree_range_lazy(seg_tree,lazy_tree,startRange,endRange,mid+1,r,2*pos+2));
}
/*
utility wrapper function  for range min query
*/
int RangeMin::query_range_min(int startRange,int endRange){
	return query_segment_tree_range_lazy(seg_tree,lazy_tree,startRange,endRange,0,input_size-1,0);
}


int main(void){
	int arr[]={-1,3,4,0,1,2};
    vector<int> V(arr,arr+(sizeof(arr)/sizeof(arr[0])));
    RangeMin R(V);
    cout<<R.query_range_min(1,1)<<endl;;
    R.update_range_lazy(0,2,4);
    cout<<R.query_range_min(0,5)<<endl;;
	return 0;
}
