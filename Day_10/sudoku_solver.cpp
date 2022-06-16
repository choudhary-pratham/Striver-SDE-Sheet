bool isPossible(int matrix[9][9],int row,int col,int c)
{
    for(int i=0;i<9;i++)
    {
        if(matrix[i][col] == c) return false;
        if(matrix[row][i] == c) return false;
        if(matrix[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
    }
    return true;
}


bool isItSudoku(int matrix[9][9]) {
    // Write your code here.
    for(int row=0;row<9;row++)
    {
        for(int col=0;col<9;col++)
        {
            if(matrix[row][col] == 0)
            {
                for(int i=1;i<=9;i++)
                {
                    if(isPossible(matrix,row,col,i))
                    {
                        matrix[row][col] = i;
                        if(isItSudoku(matrix) == true)
                        {
                            return true;
                        }
                        else
                        {
                            matrix[row][col] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
