#include<bits/stdc++.h>
bool comp(pair<int,int>&a,pair<int,int>&b)
{
    double x = (double)a.second/(double)a.first;
    double y = (double)b.second/(double)b.first;
    return x>y;
}

double maximumValue (vector<pair<int, int>>& items, int n, int w)
{
    // Write your code here.
    // ITEMS contains {weight, value} pairs.
    sort(items.begin(),items.end(),comp);
    double ans=0.0;
    for(int i=0;i<n;i++)
    {
        if(items[i].first<=w)
        {
            ans += ((double)items[i].second);
            w -= items[i].first;
        }
        else
        {
            ans += (((double)items[i].second/(double)items[i].first)*double(w));
            break;
        }
    }
    return ans;
}