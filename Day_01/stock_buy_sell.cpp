#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int mini = prices[0],pro = 0;
    for(auto it:prices)
    {
        pro = max(pro,it-mini);
        mini = min(mini,it);
    }
    return pro;
}