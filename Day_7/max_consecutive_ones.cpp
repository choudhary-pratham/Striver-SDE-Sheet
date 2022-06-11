int longestSubSeg(vector<int> &arr , int n, int k){
    // Write your code here.
    int i=0,zerocount=0;
    int maxi = 0;
    for(int j=0;j<n;j++)
    {
        if(arr[j] == 0)
        {
            zerocount++;
        }
        while(zerocount>k)
        {
            if(arr[i] == 0) zerocount--;
            i++;
        }
        maxi = max(maxi,j-i+1);
    }
    return maxi;
}
