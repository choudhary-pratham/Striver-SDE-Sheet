#include<bits/stdc++.h>
bool wordBreak(vector < string > & arr, int n, string & target) {
    // Write your code here.
    int size = target.size();
    unordered_set<string>hashset(arr.begin(),arr.end());
    vector<bool> dp(size+1,false);
    dp[size] = true;
    for(int ind = size - 1;ind>=0;ind--)
    {
        string sub="";
        for(int i=ind;i<size;i++)
        {
            sub+=target[i];
            if(hashset.find(sub) != hashset.end())
            {
                if(dp[i+1] == 1) dp[ind]= 1;
            }
        }
    }
    return dp[0];
}