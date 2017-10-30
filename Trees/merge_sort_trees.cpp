/*
author : Shubham Sharma
Date : 30/10/2017
Ref : https://discuss.codechef.com/questions/94448/merge-sort-tree-tutorial
*/

/** ============================== MERGE SORT TREES =======================================================
=> This datastructure is a subset of Segment trees and utilise the underlying principles of the Segment trees and Merge Sort Algorithm.
=> This is similar to merge sort except that we store each state of the data of merge sort in a segment tree node.
=> Then the queries are performed normally as the segment trees.
=> Use Cases : Online querying the kth order statistic in the subarray of an array , online querying the number of elements smaller than k in a 
subarray from L to R
=> These problems can also be done using Mo's algorithm(Offline Querying) or Persistent Segment trees(Online Querying) but this data structure is 
easy to code and fun to learn.
=> Since each node of segment tree stores the sorted vector(dynamic state of merge sort algorithm) , time for each query O(logn^2)
=> Time for buiding data structure : O(nlogn) same as merge sort paradigm

@this implementation is about number of elements smaller then k in a subarray from L to R
*/

#include<iostream>
#include<vector>
using namespace std;

#define MAXN 100000
vector<int> SEGTREE[4 * MAXN];
vector<int> arr = {6, 4, 8, 2, 7, 5, 1, 3 };
struct Query{
	int l, r, k;
};

void merge(vector<int>& a, vector<int>& l, vector<int>& r){
	int i = 0, j = 0;
	a.clear();
	while (i < l.size() && j < r.size()){
		if (l[i] < r[j]){
			a.push_back(l[i++]);
		}
		else{
			a.push_back(r[j++]);
		}
	}
	while (i < l.size()){
		a.push_back(l[i++]);
	}
	while (j < r.size()){
		a.push_back(r[j++]);
	}
}

int getUpperBound(vector<int>& a , const int k){
    int n = a.size(); if(n == 0)return 0;
    if(a[0] > k)return 0;
    if(a[n - 1] <= k)return n;
    int l = 0 , r = n - 1;
    while(l < r){
        int mid = l + (r - l)/2 + 1;
        if(a[mid] <= k){
            l = mid ;
        }
        else{
            r = mid - 1;
        }
    }
    return l + 1;
}

void buildTree(const int l, const int r, const int pos){
	if (l == r){
		SEGTREE[pos].push_back(arr[l]);
		return;
	}
	int mid = l + (r - l) / 2;
	buildTree(l, mid, 2 * pos + 1);
	buildTree(mid + 1, r, 2 * pos + 2);
	merge(SEGTREE[pos], SEGTREE[2 * pos + 1], SEGTREE[2 * pos + 2]);
}

int query(const int ql , const int qr , const int l , const int r , const int pos , const int k){
    if(ql > r || qr < l)return 0;
    if(ql <= l && qr >= r){
        return getUpperBound(SEGTREE[pos] , k);
    }
    int mid = l + (r - l)/2;
    return query(ql , qr , l , mid , 2 * pos + 1 , k) + query(ql , qr , mid + 1 , r , 2 * pos + 2 , k);
}

int main(void){
	
	vector<Query> queries = { { 3, 6, 6 }, { 2, 7, 5 }, { 1, 4, 5 }, { 2, 7, 3 } };
	buildTree(0, arr.size() - 1, 0);
    for(int i = 0; i < queries.size() ; ++i){
        cout << query(queries[i].l , queries[i]. r , 0 , arr.size() - 1 , 0 , queries[i].k) << " ";
    }
    
	return 0;
}
