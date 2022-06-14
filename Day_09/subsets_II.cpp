#include<algorithm>
void f(int ind,int n,vector<int>&arr,vector<int>&ds,vector<vector<int>>&ans)
{
    ans.push_back(ds);
    for(int i = ind;i<n;i++)
    {
        if(i!=ind && arr[i] == arr[i-1]) continue;
        ds.push_back(arr[i]);
        f(i+1,n,arr,ds,ans);
        ds.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    // Write your code here.
    vector<vector<int>>ans;
    vector<int>ds;
    sort(arr.begin(),arr.end());
    f(0,n,arr,ds,ans);
    return ans;
}