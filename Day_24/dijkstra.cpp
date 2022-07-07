#include<limits>
#include<queue>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    vector<int>dist(vertices,INT_MAX);
    vector<pair<int,int>>adj[vertices];
    for(int i=0;i<edges;i++)
    {
        adj[vec[i][0]].push_back({vec[i][1],vec[i][2]});
        adj[vec[i][1]].push_back({vec[i][0],vec[i][2]});
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
    pq.push({0,source});
    dist[source] = 0;
    while(!pq.empty())
    {
        int distance = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        
        for(auto it:adj[node])
        {
            if(distance + it.second < dist[it.first])
            {
                dist[it.first] = distance + it.second;
                pq.push({dist[it.first],it.first});
            }
        }
    }
    return dist;
}
