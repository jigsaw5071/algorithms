/**
author : Shubham Sharma
Date : 12 / 03 / 2018
**/

/**
Convex Hull using Jarvis-March(Gift wrapping Algorithm)
*/

#include<bits/stdc++.h>
using namespace std;

int distance(pair<int,int> a , pair<int,int> b , pair<int,int> c){
  int y1 = a.second - b.second;
  int y2 = a.second - c.second;
  int x1 = a.first - b.first;
  int x2 = a.first - c.first;
  return ((x1 * x1 + y1 * y1) - (x2 * x2 + y2 * y2));
}

int crossProduct(pair<int, int> a , pair<int,int> b , pair<int,int> c){
  int y1 = a.second - b.second;
  int y2 = a.second - c.second;
  int x1 = a.first - b.first;
  int x2 = a.first - c.first;
  return (x1 * y2 - y1 * x2);
}

void convexHull(vector<pair<int,int>>& points){
  pair<int,int> start = points[0];
  for(int i = 1 ; i < points.size() ; ++i){
    if(points[i].first < start.first)start = points[i];
  }
  
  set<pair<int,int>> res , collinearPoints;
  pair<int,int> current = start;
  res.insert(current);
  while(1){
    pair<int,int> nextTarget = points[0];
    for(int i = 1 ; i < points.size() ; ++i){
      if(points[i] == current)continue;
      int val = crossProduct(current , nextTarget , points[i]);
      if(val > 0){
        nextTarget = points[i];
        collinearPoints.clear();
      }
      else if(val == 0){
        if(distance(current , nextTarget , points[i]) < 0){
          collinearPoints.insert(nextTarget);
          nextTarget = points[i];
        }
        else{
          collinearPoints.insert(points[i]);
        }
      }
    }
    
    for(pair<int,int> p : collinearPoints){
      res.insert(p);
    }
    if(nextTarget == start)break;
    res.insert(nextTarget);
    current = nextTarget;
  }
  
  for(pair<int,int> p : res){
    cout << p.first << " " << p.second << endl;
  }
}


int main(void){
  vector<pair<int,int>> points = {{0, 3}, {2, 2}, {1, 1}, {2, 1}, {3, 0}, {0, 0}, {3, 3}};
  convexHull(points);
  return 0;
}
