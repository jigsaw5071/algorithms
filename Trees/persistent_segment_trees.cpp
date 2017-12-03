/**
author : Shubham Sharma
Date : 31/10/2017
Ref : https://blog.anudeep2011.com/persistent-segment-trees-explained-with-spoj-problems/
*/

/**  ======================= PRESISTENT SEGMENT TREES ====================================================
=> Persistent data structures are used to store the all versions of the data from the past in less space.
=> Question : Find the kth orderstatistic in subarray in an array 
=> In this paradigm we are only making n segment trees for each prefix of an array 
=> For each successive prefix , the change is only of logn nodes from the prefix
Time complexity of preprocessing : O(nlogn)
Time complexity of each query : O(logn)
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAXN 100005
int arr[MAXN];
int temp[MAXN];
int a[MAXN];

struct Node{
    int l;
    int r;
    int count;
    struct Node* left;
    struct Node* right;
    Node(){
        this->left = this->right = NULL;
    }
};
vector<Node*> version(MAXN , NULL);

int gmin(const int a , const int b){return a < b ? a : b;}
int gmax(const int a , const int b){return a > b ? a : b;}

int getIndex(const int key , const int n){
    int l = 1 , r = n;
    while(l <= r){
        int mid = l + (r - l)/2;
        if(temp[mid] == key)return mid;
        if(temp[mid] < key){
            l = mid + 1;
        }
        else{
            r = mid - 1;
        }
    }
    return -1;
}

void buildTree(struct Node* root , const int l , const int r){
    if(l == r){
        root->l = root->r = l;
        root->count = 0;
        return;
    }
    int mid = l + (r - l)/2;
    root->left = new Node();
    root->right = new Node();
    buildTree(root->left , l , mid);
    buildTree(root->right , mid + 1 , r);
    root->l = gmin(root->left->l , root->right->l);
    root->r = gmax(root->left->r , root->right->r);
    root->count = root->left->count + root->right->count;
}

void update(struct Node* prev , struct Node* curr , const int idx , const int l , const int r){
    if(idx > r || idx < l || l > r)return;
    
    if(l == r){
        curr->count = 1;
        curr->l = curr->r = l;
        return;
    }
    
    int mid = l + (r - l)/2;
    if(idx <= mid){
        curr->left = new Node();
        curr->right = prev->right;
        update(prev->left , curr->left , idx , l , mid);
    }
    else{
        curr->left = prev->left;
        curr->right = new Node();
        update(prev->right , curr->right , idx , mid + 1 , r);
    }
    curr->l = gmin(curr->left->l , curr->right->l);
    curr->r = gmax(curr->left->r , curr->right->r);
    curr->count = curr->left->count + curr->right->count;
}

int getQueryUtil(struct Node* prev , struct Node* curr , const int k , const int l ,const int r){
    
    if(l == r){
        return l;
    }
    
    int cnt = curr->left->count - prev->left->count;
    int mid = l + (r - l)/2;
    if(cnt >= k){
        return getQueryUtil(prev->left , curr->left , k , l , mid);
    }
    else{
        return getQueryUtil(prev->right , curr->right , k - cnt , mid + 1 , r);
    }
}

int main(void){
    int n , q ; cin >> n >> q;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i] ; temp[i] = arr[i];
    }
    sort(temp + 1 , temp + n + 1);
    for(int i = 1 ; i <= n ; ++i){
        a[i] = getIndex(arr[i] , n);
    }
    struct Node* root = new Node();
    buildTree(root , 1 , n);
    version[0] = root;
    for(int i = 1 ; i <= n ; ++i){
        version[i] = new Node();
        update(version[i - 1] , version[i] , a[i] , 1 , n);
    }
    
    for(int i = 1 ; i <= q ; ++i){
        int l , r , k ; cin >> l >> r >> k;
        cout << temp[getQueryUtil(version[l - 1] , version[r] , k , 1 , n)] << endl;
    }
    
    
    
    return 0;
}

