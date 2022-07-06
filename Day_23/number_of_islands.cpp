class DSU{
private:
    vector<int>size,rank,parent;
    
public:
    DSU(int n)
    {
        for(int i=0;i<=n;i++)
        {
            parent.push_back(i);
            size.push_back(1);
            rank.push_back(0);
        }
    }

public:
    int findPar(int u)
    {
        if(parent[u] == u)
        {
            return u;
        }
        return parent[u] = findPar(parent[u]);
    }

public:
    void unionSize(int u,int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        
        if(pu == pv) return;
        if(size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else{
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
    
public:
    void unionRank(int u,int v)
    {
        int pu = findPar(u);
        int pv = findPar(v);
        
        if(pu == pv) return;
        if(rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if(rank[pv] < rank[pu])
        {
            parent[pv] = pu;
        }
        else{
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
int getTotalIslands(int** arr, int n, int m)
{
   // Write your code here.
    DSU dsu(n*m+1);
    int ans = 0;
    int dx[] = {1,-1,0,0,-1,1,-1,1};
    int dy[] = {0,0,1,-1,1,-1,-1,1};
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j] == 1)
            {
                ans++;
                int ind1 = (i*m)+(j+1);
                for(int dir = 0;dir<8;dir++)
                {
                    int newx = i + dx[dir];
                    int newy = j + dy[dir];
                    int ind2  = newx*m + (newy+1);
                    if(newx>=0 && newy>=0 && newx<n && newy<m && arr[newx][newy] == 1 && dsu.findPar(ind1)!=dsu.findPar(ind2))
                    {
                        ans--;
                        dsu.unionSize(ind1,ind2);
                    }
                }
            }
        }
    }
    return ans;
}
