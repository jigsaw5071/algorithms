#include<iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size() > b.size())return findMedianSortedArrays(b , a);
        cout << findKth(2 , a , b) << endl;
        int n = a.size() + b.size();
        double ans = findKth((n + 1) / 2 , a , b);
        if(n%2 == 0){
            ans = (ans + findKth(n / 2 + 1 , a , b)) / 2.0;
        }
        return ans;
        
    }
    
    int findKth(int k , vector<int>& a , vector<int>& b){
        if(a.size() == 0)return b[k - 1];
        if(b.size() == 0)return a[k - 1];
        int l = 0 , r = a.size();
        while(l <= r){
            int px = l + (r - l)/2;
            int py = k - px;
            if(py < 0){
                r = px - 1; continue;
            }
            if(py > b.size()){
                l = px + 1; continue;
            }
            int maxLeftX = (px == 0 ? INT_MIN : a[px - 1]);
            int minRightX = (px == a.size() ? INT_MAX :a[px]);
            
            int maxLeftY = (py == 0 ? INT_MIN : b[py - 1]);
            int minRightY = (py == b.size() ? INT_MAX : b[py]);
            if(maxLeftX <= minRightY && maxLeftY <= minRightX){
                return max(maxLeftX , maxLeftY);
            }
            else if(maxLeftX > minRightY){
                r = px - 1;
            }
            else{
               l = px + 1;
            }
            
        }
    }
};

int main(void){
return 0;
}
