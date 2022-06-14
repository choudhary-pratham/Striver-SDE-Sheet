void f(int ind,vector<int>&arr,int sum,vector<int>&ans)
{
    //base case
    if(ind == arr.size())
    {
        ans.push_back(sum);
        return ;
    }
    //pick
    f(ind+1,arr,sum+arr[ind],ans);
    //not_pick
    f(ind+1,arr,sum,ans);
}

vector<int> subsetSum(vector<int> &num)
{
    // Write your code here.
    vector<int>ans;
    f(0,num,0,ans);
    sort(ans.begin(),ans.end());
    return ans;
}