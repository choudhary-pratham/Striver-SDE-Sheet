#include<map>
vector<int> countDistinctElements(vector<int> &arr, int k) 
{
    // Write your code here
    vector<int>ans;
    map<int,int>mpp;
    for(int i=0;i<k;i++) mpp[arr[i]]++;
    ans.push_back(mpp.size());
    int i=1;
    int j=k;
    while(j<arr.size())
    {
        mpp[arr[i-1]]--;
        if(mpp[arr[i-1]] == 0) mpp.erase(arr[i-1]);
        mpp[arr[j]]++;
        ans.push_back(mpp.size());
        i++;
        j++;
    }
    return ans;
}
