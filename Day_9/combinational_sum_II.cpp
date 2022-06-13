#include<algorithm>
void f(int ind,int n,int target,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans)
{
    if(target == 0) 
    {
       ans.push_back(ds);
       return;
    }
    for(int i=ind;i<n;i++)
    {
        if(i!=ind && arr[i] == arr[i-1]) continue;
        if(arr[i]>target) break;
        ds.push_back(arr[i]);
        f(i+1,n,target-arr[i],arr,ds,ans);
        ds.pop_back();
    }
}


vector<vector<int>> combinationSum2(vector<int> &arr, int n, int target)
{
	// Write your code here.
    sort(arr.begin(),arr.end());
    vector<vector<int>>ans;
    vector<int>ds;
    f(0,n,target,arr,ds,ans);
    return ans;
}
