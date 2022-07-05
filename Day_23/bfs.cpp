#include<queue>
#include<algorithm>
void create_adjacency_list(vector<int>adj[],vector<pair<int,int>>&edges)
{
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
        adj[edges[i].second].push_back(edges[i].first);
    }
}
void print_bfs(int i,vector<int>adj[],vector<int>&ans,vector<int>&vis)
{
    queue<int>q;
    q.push(i);
    vis[i] = 1;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                q.push(it);
                vis[it]=1;
            }
        }
        ans.push_back(node);
    }
}
vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    vector<int>ans;
    vector<int>vis(vertex,0);
    vector<int>adj[vertex];
    create_adjacency_list(adj,edges);
    for(int i=0;i<vertex;i++)
    {
        sort(adj[i].begin(),adj[i].end());
        if(!vis[i])
        {
            print_bfs(i,adj,ans,vis);
        }
    }
    return ans;
}