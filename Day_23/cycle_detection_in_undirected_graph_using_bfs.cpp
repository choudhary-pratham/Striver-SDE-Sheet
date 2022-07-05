#include<queue>
void create_adjacency_list(vector<int>adj[],vector<vector<int>>&edges,int m)
{
    for(int i=0;i<m;i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
        adj[edges[i][1]].push_back(edges[i][0]);
    }
}

bool check_cycle(int i,vector<int>adj[],vector<int>&vis)
{
    queue<pair<int,int>>q;
    q.push({i,-1});
    vis[i] = 1;
    while(!q.empty())
    {
        auto p = q.front();
        int node = p.first;
        int par = p.second;
        q.pop();
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push({it,node});
                vis[it] = 1;
            }
            else if(it!=par)
            {
                return true;
            }
        }
    }
    return false;
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    vector<int>adj[n+1];
    vector<int>vis(n+1,0);
    create_adjacency_list(adj,edges,m);
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            if(check_cycle(i,adj,vis) == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
