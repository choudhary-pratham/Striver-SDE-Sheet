#include <bits/stdc++.h> 
int uniqueSubstrings(string input)
{
    //Write your code here
    int n = input.size();
    set<int>mpp;
    int left = 0,right = 0;
    int count=0;
    while(right<n)
    {
        if(mpp.find(input[right]) != mpp.end())
        {
            while(left<right && mpp.find(input[right]) != mpp.end())
            {
                mpp.erase(input[left]);
                left++;
            }
        }
           mpp.insert(input[right]);
           count = max(count,right-left+1);
           right++;
    }
    return count;
}