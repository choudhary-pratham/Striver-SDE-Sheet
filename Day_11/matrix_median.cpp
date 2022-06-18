int countLessThanEqualToMid(vector<int>&arr,int m,int mid)
{
    int low = 0;
    int high = m-1;
    while(low<=high)
    {
        int m = (low+high)>>1;
        if(arr[m]<=mid) low = m+1;
        else high = m-1;
    }
    return low;
}

int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 1;
    int high = 1e9;
    int n = matrix.size();
    int m = matrix[0].size();
    while(low<=high)
    {
        int mid = (low+high)>>1;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            cnt+=countLessThanEqualToMid(matrix[i],m,mid);
        }
        if(cnt<=(n*m)/2) low = mid+1;
        else high = mid-1;
    }
    return low;
}