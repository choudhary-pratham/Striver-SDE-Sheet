#include<limits.h>
#include<queue>
vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // Write your code here.
    vector<pair<int,int>>adj[n+1];
    for(int i=0;i<m;i++)
    {
        adj[g[i].first.first].push_back({g[i].first.second,g[i].second});
        adj[g[i].first.second].push_back({g[i].first.first,g[i].second});
    }
    vector<int>key(n+1,INT_MAX),mst(n+1,0),parent(n+1,-1);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,1});
    key[1] = 0;
    while(!pq.empty())
    {
        int node = pq.top().second;
        pq.pop();
        mst[node] = 1;
        for(auto it:adj[node])
        {
            int target = it.first;
            int weight = it.second;
            if(mst[target] == 0 && key[target] > weight)
            {
                key[target] = weight;
                pq.push({key[target],target});
                parent[target] = node;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for(int i=2;i<=n;i++)
    {
        ans.push_back({{parent[i],i},key[i]});
    }
    return ans;
}
