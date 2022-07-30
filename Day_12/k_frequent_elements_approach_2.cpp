#include<map>
#include<algorithm>
vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    // Write your code here.
    vector<int>ans;
    map<int,int>mpp;
    for(auto it:arr) mpp[it]++;
    vector<int>bucket[n+1];
    for(auto it: mpp) bucket[it.second].push_back(it.first);
    for(int i=n;i>=0 && k>0;i--)
    {
        if(bucket[i].size() == 0) continue;
        for(auto it:bucket[i])
        {
            if(k == 0) break;
            ans.push_back(it);
            k--;
        }
    }
    sort(ans.begin(),ans.end());
    return ans;
}