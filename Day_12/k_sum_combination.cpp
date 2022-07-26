#include<queue>
#include<algorithm>
vector<int> kMaxSumCombination(vector<int> &a, vector<int> &b, int n, int k){
	// Write your code here.
    sort(a.begin(),a.end(),greater<int>());
    sort(b.begin(),b.end(),greater<int>());
    vector<vector<int>>vis(n,vector<int>(n,0));
    priority_queue<pair<int,pair<int,int>>>pq;
    pq.push({a[0]+b[0],{0,0}});
    vector<int>ans;
    while(k--)
    {
        auto it = pq.top();
        pq.pop();
        int sum = it.first;
        int i = it.second.first;
        int j = it.second.second;
        ans.push_back(sum);
        if(i+1<n && vis[i+1][j] == 0)
        {
            pq.push({a[i+1]+b[j],{i+1,j}});
            vis[i+1][j] = 1;
        }
        if(j+1<n && vis[i][j+1] == 0)
        {
            pq.push({a[i]+b[j+1],{i,j+1}});
            vis[i][j+1] = 1;
        }
    }
    return ans;
}