/*
author : Shubham Sharma
Date : 26/10/2017
*/

/**========================== FRACTIONAL KNAPSACK =========================================
=> This accounts for taking fractional values of the weights also.
=> So it exhibits greedy property.
=> !Important : Only one quantity of every element is present in the data
=> Time complexity is O(nlogn)
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct Item{
    int value;
    int weight;
};

double getMaximumValue(vector<Item>& items , const int W){
    sort(items.begin() , items.end() , [](Item& x , Item& y){
        double rx = (double)x.value / (double)x.weight;
        double ry = (double)y.value / (double)y.weight;
        return rx > ry;
    });
    
    int currentWeight = 0;
    double ans = 0.0;
    for(int i = 0 ; i < items.size() ; ++i){
        if(currentWeight + items[i].weight <= W){
            currentWeight += items[i].weight;
            ans += items[i].value;
        }
        else{
            double rem = W - currentWeight;
            ans += (double)items[i].value * (rem / (double) items[i].weight);
            break;
        }
    }
    return ans;
}

int main(void){
    vector<Item> items = {{60, 10}, {100, 20}, {120, 30}};
    const int W = 50;
    cout << "Maximum value in Knapsack is  : " << getMaximumValue(items , W) << endl;
    return 0;
}
