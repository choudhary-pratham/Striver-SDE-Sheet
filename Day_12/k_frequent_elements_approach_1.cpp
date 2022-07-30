#include<queue>
#include<map>
#include<algorithm>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    priority_queue<pair<int,int>>pq;
    map<int,int>mpp;
    for(int i=0;i<arr.size();i++)
    {
        mpp[arr[i]]++;
        
    }
    for(auto it:mpp)
    {
        pq.push({it.second,it.first});
    }
    vector<int>ans;
    for(int i=0;i<k;i++)
    {
        int val = pq.top().second;
        pq.pop();
        ans.push_back(val);
    }
    sort(ans.begin(),ans.end());
    return ans;
}