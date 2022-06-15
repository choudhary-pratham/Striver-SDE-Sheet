void f(int row,int n,vector<vector<int>>&board,vector<vector<int>>&ans,vector<int>&top,vector<int>&leftdiagonal,vector<int>&rightdiagonal)
{
    if(row >= n)
    {
        vector<int>inter;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                inter.push_back(board[i][j]);
            }
        }
        ans.push_back(inter);
        return ;
    }
    for(int col = 0;col<n;col++)
    {
        if(top[col] == 0 && leftdiagonal[n-1+col-row] == 0 && rightdiagonal[row+col] == 0)
        {
            top[col] = 1;
            leftdiagonal[n-1+col-row] = 1;
            rightdiagonal[row+col] = 1;
            board[row][col] = 1;
            f(row+1,n,board,ans,top,leftdiagonal,rightdiagonal);
            board[row][col] = 0;
            top[col] = 0;
            leftdiagonal[n-1+col-row] = 0;
            rightdiagonal[row+col] = 0;
        }
    }
        
}

vector<vector<int>> solveNQueens(int n) {
    // Write your code here.
    vector<vector<int>>board(n,vector<int>(n,0));
    vector<vector<int>>ans;
    vector<int>top(n,0),leftdiagonal(2*n-1,0),rightdiagonal(2*n-1,0);
    f(0,n,board,ans,top,leftdiagonal,rightdiagonal);
    return ans;
}