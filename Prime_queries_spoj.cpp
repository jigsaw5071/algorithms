#include<iostream>
#include<string.h>
using namespace std;
#define MAXP 1000050
#define MAXN 10005
bool isPrime[MAXP + 1];
int arr[MAXN];
int SEGTREE[4 * MAXN];
int LAZYTREE[4 * MAXN];

int T , N  , Q ; 

void init(){
    for(int i = 0; i <= MAXP ; ++i)isPrime[i] = true;
    
    isPrime[0] = isPrime[1] = false;
    for(int i = 2 ; i * i <= MAXP ; ++i){
        if(isPrime[i]){
            for(int j = i * i ; j <= MAXP ; j += i){
                isPrime[j] = false;
            }
        }
    }
}

void buildTree(const int l , const int r , const int pos){
    if(l == r){
       SEGTREE[pos] = isPrime[arr[l]];  return; 
    }
    int mid = l + (r - l)/2;
    buildTree(l , mid , 2 * pos);
    buildTree(mid + 1 , r , 2 * pos + 1);
    SEGTREE[pos] = SEGTREE[2 * pos] + SEGTREE[2 * pos + 1];
}

void update(const int ql , const int qr , const int l , const int r , const int pos , const int val){
    if(LAZYTREE[pos] != 0){
        if(isPrime[LAZYTREE[pos]]){
            SEGTREE[pos] = (r - l + 1);
            if(l != r){
                LAZYTREE[2 * pos] = LAZYTREE[pos];
                LAZYTREE[2 * pos + 1]= LAZYTREE[pos];
            }
        }
        else{
            SEGTREE[pos] = 0;
            if(l != r){
                LAZYTREE[2 * pos] = LAZYTREE[pos];
                LAZYTREE[2 * pos + 1]= LAZYTREE[pos];
            }
        }
        LAZYTREE[pos] = 0;
    }
    if(l > r || ql > r || qr < l)return;
    if(ql <= l && qr >= r){
        if(isPrime[val]){
            SEGTREE[pos] = r - l + 1;
            if(l != r){
                LAZYTREE[2 * pos] = val;
                LAZYTREE[2 * pos + 1] = val;
            }
        }
        else{
            SEGTREE[pos] = 0;
            if(l != r){
                LAZYTREE[2 * pos] = val;
                LAZYTREE[2 * pos + 1] = val;
            }
        }
        return;
    }
    int mid = l + (r - l)/2;
    update(ql , qr , l , mid , 2 * pos , val);
    update(ql , qr , mid + 1 ,  r , 2 * pos + 1 , val);
    SEGTREE[pos] = SEGTREE[2 * pos ] + SEGTREE[2 * pos + 1];
}

int query(const int ql , const int qr , const int l ,const int r , const int pos){
    if(LAZYTREE[pos] != 0){
        if(isPrime[LAZYTREE[pos]]){
            SEGTREE[pos] = r - l + 1;
        }
        else{
            SEGTREE[pos] = 0;
        }
        if(l != r){
            LAZYTREE[2 * pos] = LAZYTREE[2 * pos + 1] = LAZYTREE[pos];
        }
        LAZYTREE[pos] = 0;
    }
    if(l > r || ql > r || qr < l)return 0;
    if(ql <= l && qr >= r)return SEGTREE[pos];
    int mid = l + (r - l)/2;
    return query(ql , qr  , l , mid , 2 * pos) + query(ql , qr , mid + 1 , r , 2 * pos + 1);
}

int main(void){
    scanf("%d" , &T); init();
    for(int t = 1 ; t <= T ; ++t){
        scanf("%d %d" , &N , &Q);
        memset(LAZYTREE , 0 , sizeof(LAZYTREE));
        for(int i = 1 ; i <= N ; ++i)scanf("%d" , &arr[i]);
        buildTree(1 , N , 1);
        printf("Case %d:\n" , t);
        for(int q = 1 ; q <= Q ; ++q){
            int tc , x , y ; scanf("%d %d %d" , &tc , &x , &y);
            if(tc == 0){
                int val ; scanf("%d" , &val);
                update(x , y , 1 , N , 1 , val);
            }
            else{
                printf("%d\n" , query(x , y , 1 , N , 1));
            }
        }
    }
    return 0;
}
