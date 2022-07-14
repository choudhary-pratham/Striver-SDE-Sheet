#include<queue>
vector<int> slidingWindowMaximum(vector<int> &nums, int &k)
{
    int n = nums.size();
    deque<int>dq;
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        // removing out of bounds
        if(!dq.empty() && (dq.front() == (i-k))) dq.pop_front();
        //removing all the elements less than the current element the deque to maintain the decreasing order
        while(!dq.empty() && (nums[dq.back()] <= nums[i]))dq.pop_back();
        
        // pushing the current index after popping all the elements lesser than it
        dq.push_back(i);
        
        if(i>=k-1) ans.push_back(nums[dq.front()]);
    }
    return ans;
}