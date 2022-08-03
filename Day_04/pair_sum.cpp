#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
    vector<vector<int>>ans;
    sort(arr.begin(),arr.end());
    int n = arr.size();
    int left = 0;
    int right = n-1;
    while(left<right)
    {
        if(arr[left] + arr[right] < s) left++;
        else if(arr[left] + arr[right] > s) right--;
        else{
            int counter;
            if(arr[left] == arr[right])
            {
                int cnt = 0;
                for(int i=0;i<n;i++)
                {
                    if(arr[i] == arr[left]) cnt++;
                }
                counter = (cnt*(cnt-1))/2;
            }
            else{
                int cnt1 = 0,cnt2 = 0;
                for(int i=0;i<n;i++)
                {
                    if(arr[i] == arr[left]) cnt1++;
                    else if(arr[i] == arr[right]) cnt2++;
                }
                counter = cnt1*cnt2;
            }
            vector<int>p(2,0);
            while(counter)
            {
                p[0] = arr[left];
                p[1] = arr[right];
                ans.push_back(p);
                counter--;
            }
            
            while(left < right && arr[left] == p[0]) left++;
            
            while(left < right && arr[right] == p[1]) right--;
        }
    }
    return ans;
}