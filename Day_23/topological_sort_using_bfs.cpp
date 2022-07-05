#include<queue>
void create_adjacency_list(vector<int>adj[],vector<vector<int>>&edges)
{
    for(int i=0;i<edges.size();i++)
    {
        adj[edges[i][0]].push_back(edges[i][1]);
    }
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<int>ans;
    vector<int>indegree(v,0);
    queue<int>q;
    vector<int>adj[v];
    create_adjacency_list(adj,edges);
    for(int i=0;i<v;i++)
    {
        for(auto it:adj[i])
        {
            indegree[it]++;
        }
    }
    for(int i=0;i<v;i++)
    {
        if(indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        ans.push_back(node);
        for(auto it:adj[node])
        {
            indegree[it]--;
            if(indegree[it] == 0) q.push(it);
        }
    }
    return ans;
}