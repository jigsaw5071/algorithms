/*
author : Shubham Sharma
Date : 25/10/2017
Ref : http://www.geeksforgeeks.org/greedy-algorithms-set-1-activity-selection-problem/
*/

/** ============== ACTIVITY SELECTION PROBLEM ============================================
=> This problem can be done using exhaustive search with optimizations using DP
=> Interesting way to look at this is using Greedily
=> You are given start-times and end-times of n activities . You need to find the maximum number of non-overlapping intervals. Another way of phrasing this is that you need to perform maximum number of activities subjected to the condition that you can do only one activity at a time.
=> The solution which comes from heuristics states that if I sort the activity by end time because In this way only I can ensure maximum space for the rest of the activities.
=> You can prove easily this by using contradiction.
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Interval{
  int start;
  int end;
};

int main(void){
  vector<Interval> intervals = {{5, 9}, {1, 2}, {3, 4}, {0, 6},{5, 7}, {8, 9}};
  sort(intervals.begin() , intervals.end() , [](Interval& x , Interval& y){
    return ((x.start == y.start)?(x.end < y.end):(x.start < y.start));
  });
  
  vector<Interval> ans;
  ans.push_back(intervals[0]);
  for(int i = 1 ; i < intervals.size() ; ++i){
    Interval t = ans[ans.size() - 1];
    if(intervals[i].start >= t.end){
      ans.push_back(intervals[i]);
    }
    if(intervals[i].end < t.end){
      while(ans.size() > 0 && intervals[i].end < ans[ans.size() - 1].end)ans.pop_back();
      ans.push_back(intervals[i]);
    }
  }
  
  for(auto& interval : ans){
    cout << interval.start << "->" << interval.end << "  ";
  }
  
  
  return 0;
}
