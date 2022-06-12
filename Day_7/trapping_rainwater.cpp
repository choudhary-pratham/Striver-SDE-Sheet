#include <bits/stdc++.h> 
long getTrappedWater(long *arr, int n){
    // Write your code here.
    int left=0,right = n-1;
    long leftMax=0,rightMax=0,res=0;
    while(left<=right)
    {
        if(arr[left]<=arr[right])
        {
            if(arr[left] >= leftMax) leftMax = arr[left];
            else res += (leftMax-arr[left]);
            left++;
        }
        else
        {
            if(arr[right] >= rightMax) rightMax = arr[right];
            else res += (rightMax - arr[right]);
            right--;
        }
    }
    return res;
}