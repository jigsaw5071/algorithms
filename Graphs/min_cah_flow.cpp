/*
@Shubham Sharma
-06/12/2016
*/

/*
Minimum Cash Flow among the friends those who have borrowed money from each other

The alorithm works as:
1. First calculate the net cash flow of each person by (total credit)-(total debt)
2. Settle the amount of either maximum creditor or maximum debtor (whichever is minimum)
3. Then continue with the remaining and when the net amount of every element is 0 Then
cash flow is minimised
4. Time Complexity is O(V^2)
5. Space Complexity is O(V+E)

This also supports tail call optimization
*/

#include<bits/stdc++.h>
using namespace std;

/*
utility function to get min index
*/
int _get_min_index(vector<int> V){
    int min_index=0;
    for(int i=1;i<V.size();++i){
        if(V[i]<V[min_index]){
            min_index=i;
        }
    }
    return min_index;
}

/*
utility function to find the maximum index
*/
int _get_max_index(vector<int> V){
    int max_index=0;
    for(int i=1;i<V.size();++i){
        if(V[i]>V[max_index]){
            max_index=i;
        }
    }
    return max_index;
}



/*
utility fuction for the minimum cash flow
*/

void _min_cashFlow(vector<int>& _net_amount,vector<list<pair<int,int>>>& result){
    
    int min_credit_index=_get_min_index(_net_amount);
    int max_credit_index=_get_max_index(_net_amount);
    
    if(_net_amount[min_credit_index]==0 && _net_amount[max_credit_index]==0){
        return ;
    }
    
    int min_credit=_net_amount[min_credit_index]*-1;
    int max_credit=_net_amount[max_credit_index];
    
    int min=(min_credit <max_credit)?min_credit:max_credit;
    _net_amount[max_credit_index]-=min;
    _net_amount[min_credit_index]+=min;
    
    result[min_credit_index].push_back(make_pair(max_credit_index,min));
    _min_cashFlow(_net_amount,result);
}

/*
utility wrapper function for the min cash flow
*/
vector<list<pair<int,int>>> _min_cashFlow_wrapper(vector<list<pair<int,int>>>& G,const int V){
 vector<list<pair<int,int>>> result(V);
 vector<int> _net_amount(V,0);
 for(int i=0;i<V;++i){
     for(auto iter=G[i].begin();iter!=G[i].end();++iter){
         _net_amount[iter->first]+=iter->second;
         _net_amount[i]-=iter->second;
     }
 }

 _min_cashFlow(_net_amount,result); 
 return result;
}

int main(void){
    int V,E;
    cin>>V>>E;
    vector<list<pair<int,int>>> G(V);
    for(int i=0;i<E;++i){
        int u,v,w;
        cin>>u>>v>>w;
        G[u].push_back(make_pair(v,w));
    }
    vector<list<pair<int,int>>> result=_min_cashFlow_wrapper(G,V);
    for(int i=0;i<V;++i){
        for(auto iter =result[i].begin();iter!=result[i].end();++iter){
            cout<<i<<" is paying "<<iter->second<<" to "<<iter->first<<endl;
        }
    }
    return 0;
}
