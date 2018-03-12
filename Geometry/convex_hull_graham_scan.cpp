/**
author : Shubham Sharma
Date : 13 / 03 / 2018
*/

/**
 *  Convex Hull (Graham Scan) O(nlogn)
*/

#include<bits/stdc++.h>
using namespace std;

int orientation(pair<int,int> a , pair<int,int> b , pair<int,int> c){
  /*
  0 : Collinear
  1 : clockwise
  2 : counterclockwise
  */
  int val = (b.second - a.second) * (c.first - b.first) - (b.first - a.first) * (c.second - b.second);
  if(val == 0)return 0;
  if(val > 0)return 1;
  return 2;
}

int distance(pair<int,int> a , pair<int,int> b){
  int y = b.second - a.second;
  int x = b.first - a.first;
  return (y * y + x * x);
}

pair<int,int> P0;
bool comp(pair<int,int> P1 , pair<int,int> P2){
  int val = orientation(P0 , P1 , P2);
  if(val == 0)return (distance(P0 , P1) <= distance(P0 , P2));
  return (val == 2);
}

pair<int,int> prev(stack<pair<int,int>>& st){
  pair<int,int> t = st.top(); st.pop();
  pair<int,int> res = st.top() ; st.push(t);
  return res;
}

void convexHull(vector<pair<int,int>>& points){
  int ymin = points[0].second;
  int mid = 0;
  for(int i = 1 ; i < points.size() ; ++i){
    int y = points[i].second;
    if(y < ymin || (y == ymin && points[i].first < points[mid].first)){
      ymin = y;
      mid = i;
    }
  }
  swap(points[0] , points[mid]);
  P0 = points[0];
  sort(next(points.begin()) , points.end() , comp);
  int m = 1;
  for(int i = 1 ; i < points.size() ; ++i){
    while(i < points.size() - 1 && orientation(P0 , points[i] , points[i + 1]) == 0)i++;
    points[m] = points[i];
    m++;
  }
  
  if(m < 3)return;
  stack<pair<int , int>> st;
  st.push(points[0]);
  st.push(points[1]);
  st.push(points[2]);
  for(int i = 3 ; i < m ; ++i){
    while(orientation(prev(st) , st.top() , points[i]) != 2)st.pop();
    st.push(points[i]);
  }
  
  while(!st.empty()){
    cout << st.top().first << " " << st.top().second << endl;
    st.pop();
  }
}

int main(void){
  vector<pair<int,int>> points = {{0, 3}, {1, 1}, {2, 2}, {4, 4},{0, 0}, {1, 2}, {3, 1}, {3, 3}};
  convexHull(points);
}
