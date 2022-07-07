#include<algorithm>
class DSU{
    
private:
    vector<int>rank,parent;
    
public:
    DSU(int n)
    {
        for(int i=0;i<=n;i++)
        {
            rank.push_back(0);
            parent.push_back(i);
        }
    }
    
public:
    int find_Par(int node)
    {
        if(parent[node] == node)
        {
            return node;
        }
        return parent[node] = find_Par(parent[node]);
    }
    
public:
    void unionRank(int u,int v)
    {
        int pu = find_Par(u);
        int pv = find_Par(v);
        
        if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else 
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};

bool comp(vector<int>&a,vector<int>&b)
{
    return a[2]<b[2];
}
int kruskalMST(int n, int m, vector<vector<int>> &graph) {
	// Write your code here.
    int min_weight = 0;
    DSU dsu(n+1);
    sort(graph.begin(),graph.end(),comp);
    for(int i=0;i<m;i++)
    {
        int source = graph[i][0];
        int target = graph[i][1];
        int weight = graph[i][2];
        
        if(dsu.find_Par(source) != dsu.find_Par(target))
        {
            dsu.unionRank(source,target);
            min_weight += weight;
        }
    }
    return min_weight;
}