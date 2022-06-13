void f(int ind,int n,int sum,int k,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans)
{
    //base case
    if(ind == n)
    {
        if(sum == k) ans.push_back(ds);
        return;
    }
    //pick
    ds.push_back(arr[ind]);
    f(ind+1,n,sum+arr[ind],k,arr,ds,ans);
    ds.pop_back();
    
    //not pick
    f(ind+1,n,sum,k,arr,ds,ans);
}

vector<vector<int>> findSubsetsThatSumToK(vector<int> arr, int n, int k)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>ds;
    f(0,n,0,k,arr,ds,ans);
    return ans;
}