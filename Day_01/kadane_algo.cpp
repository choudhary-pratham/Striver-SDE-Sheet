#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long sum = 0,maxi = 0;
    for(int i=0;i<n;i++)
    {
        sum+=arr[i];
        maxi = max(maxi,sum);
        if(sum<0) sum=0;
    }
    return maxi;
    /* Printing the subarray with maximum sum*/
    sum=0;
    for (int i = 0; i < n; i++)
    {
        sum+=arr[i];
        if(sum>0 && sum<=maxi)
        {
            cout<<arr[i]<<" ";
        }
        else
        {
            sum=0;
        }
        if(sum == maxi) break;
    }
}