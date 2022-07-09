int maximumProduct(vector<int> &arr, int n)
{
	// Write your code here
    int ans = arr[0],maxi = 1,mini = 1;
    for(int i=0;i<n;i++)
    {
        if(arr[i] < 0) swap(maxi,mini);
        maxi = max(maxi*arr[i],arr[i]);
        mini = min(mini*arr[i],arr[i]);
        ans = max(maxi,ans);
    }
    return ans;
}
