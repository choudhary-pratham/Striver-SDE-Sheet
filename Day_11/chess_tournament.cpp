int isPossible(vector<int>&arr,int n,int c,int dist)
{
    int co_ord = arr[0],players=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]-co_ord>=dist)
        {
           co_ord = arr[i];
           players++; 
        }
        if(players == c) return true;
    }
    return false;
}


int chessTournament(vector<int> arr , int n ,  int c){
	// Write your code here
    sort(arr.begin(),arr.end());
    int low = 1;
    int high = arr[n-1]-arr[0];
    int res = -1;
    while(low<=high)
    {
        int mid = (low+high)>>1;
        if(isPossible(arr,n,c,mid))
        {
            res  = mid;
            low = mid+1;
        }
        else
        {
            high = mid-1;
        }
    }
    // high can also be returned as the final ans
    return res;
}