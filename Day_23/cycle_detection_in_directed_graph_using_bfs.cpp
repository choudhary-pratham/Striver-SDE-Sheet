#include<queue>
void create_adjacency_list(vector<int>adj[],vector<pair<int,int>>&edges,int n)
{
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i].first].push_back(edges[i].second);
    }
}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here
    vector<int>adj[n+1];
    create_adjacency_list(adj,edges,n);
    vector<int>Indegree(n+1,0);
    for(int i=1;i<=n;i++)
    {
        for(auto it :adj[i])
        {
            Indegree[it]++;
        }
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
    {
        if(Indegree[i] == 0) q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        count++;
        for(auto it:adj[node])
        {
            Indegree[it]--;
            if(Indegree[it] == 0) q.push(it);
        }
    }
    if(count == n) return false;
    return true;
    return 0;
}