bool isSafe(int node,vector<vector<int>>&mat,vector<int>&color,int n,int colori)
{
    for(int j = 0; j < n; j++)
    {
        if(mat[node][j] == 1 && color[j] == colori) return false;
    }
    return true;
}

bool check_possibility(int node,vector<vector<int>>&mat,vector<int>&color,int n,int m)
{
    if(node == n) return true;
    
    for(int i = 1; i <= m; i++)
    {
        if(isSafe(node,mat,color,n,i) == true)
        {
            color[node] = i;
            if(check_possibility(node+1,mat,color,n,m) == true) return true;
            color[node] = 0;
        }
    }
    return false;
}


string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int>color(n,0);
    if(check_possibility(0,mat,color,n,m) == true) return "YES";
    return "NO";
}