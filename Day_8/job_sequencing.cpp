#include<bits/stdc++.h>
bool comp(vector<int>&a,vector<int>&b)
{
    return a[1]>b[1];
}
int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    int n = jobs.size();
    sort(jobs.begin(),jobs.end(),comp);

    int maxi=jobs[0][0];
    for(int i=0;i<n;i++)
    {
        maxi = max(maxi,jobs[i][0]);
    }
    vector<int>slot(maxi+1,0);
    int maxProfit = 0;
    for(int i=0;i<n;i++)
    {
        for(int j = jobs[i][0];j>=1;j--)
        {
            if(slot[j] == 0)
            {
                maxProfit += jobs[i][1];
                slot[j] = i+1;
                break;
            }
        }
    }
    return maxProfit;
}
