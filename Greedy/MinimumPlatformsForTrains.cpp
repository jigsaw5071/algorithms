#include<bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=(int)a;i<=(int)b;++i)
#define ARRIVAL 0
#define DEPARTURE 1

struct Node{
  int type;
  int val;
};

int main(void){
  int T ; cin >> T;
  rep(t , 1 , T){
    int n ; cin >> n;
    vector<Node> arr;
    rep(i , 0 , n - 1){
      int num ; cin >> num ; arr.push_back({ARRIVAL , num});
    }
    rep(i , 0 , n - 1){
      int num ; cin >> num ; arr.push_back({DEPARTURE , num});
    }
    sort(arr.begin() , arr.end() , [](Node x , Node y){
      return x.val < y.val;
    });
    int ans = 0;
    int curr = 0;
    rep(i , 0 , arr.size() - 1){
      if(arr[i].type == ARRIVAL)curr++;
      else curr--;
      ans = max(ans , curr);
    }
    cout << ans << endl;
  }
  return 0;
}
